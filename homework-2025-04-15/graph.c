#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "vector.h"

Vertex* init_vertex(char * city, int cost) 
{
    Vertex* vertex =  (Vertex*)malloc(sizeof(Vertex));
    vertex->city = strdup(city);
    vertex->cost = cost;
    vertex->next = NULL;

    return vertex;
}

Graph* init_graph(int numVertices) 
{
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Vertex**)calloc(numVertices, sizeof(Vertex*));
    graph->activeVertices_size = 0;
    graph->activeVertices = (char**)calloc(numVertices, sizeof(char*));

    return graph;
}

int is_city_in_graph(Graph * g, char * city)
{
    for(int i = 0; i < g->activeVertices_size; i++)
    {
        if(!strcmp(g->activeVertices[i], city))
        {
            return 1;
        }
    }
    return 0;
}

int get_index_from_city_names(Graph * g, char * city)
{
    for(int i = 0; i < g->activeVertices_size; i++)
    {
        if(!strcmp(g->activeVertices[i], city))
        {
            return i;
        }
    }
    return -1;
}

void add_city(Graph *g, char * city)
{
    if(!is_city_in_graph(g, city))
    {
        g->activeVertices[g->activeVertices_size] = strdup(city);
        g->activeVertices_size++;
    }
}

void addEdgeDirectional(Graph * g, char * from, char * to, int cost) 
{
    Vertex* new_vertex = init_vertex(to, cost);
  
    add_city(g, from);
    add_city(g, to); 
    int from_index = get_index_from_city_names(g, from);
    Vertex * it = g->adjList[from_index];
    if(it == NULL)
    {
        g->adjList[from_index] = new_vertex;  
        return;
    }
    while (it->next != NULL)
    {
        it = it->next;
    }
    
    it->next = new_vertex;
    
}

void addEdge(Graph* graph, char * from, char * to, int weight) 
{
    addEdgeDirectional(graph, from, to, weight);
    addEdgeDirectional(graph, to, from, weight);
}

Vertex * duplicate_vertex(Vertex * v)
{
    Vertex* new_v = (Vertex*)malloc(sizeof(Vertex));
    new_v->city = strdup(v->city);
    new_v->cost = v->cost;
    new_v->next = NULL;
    return new_v;
}

Vertex* append_to_path(Vertex* path, Vertex* to_add) 
{
    Vertex* copy = duplicate_vertex(to_add);
    if(!path) 
    {
        return copy;
    }
    Vertex* current = path;
    while(current->next) 
    {
        current = current->next;
    }
    current->next = copy;
    return path;
}

void pop_last_vertex(Vertex ** path)
{
    if(*path == NULL) 
        return;
    if((*path)->next == NULL) 
    {
        free_path(*path);
        return;
    }

    Vertex* prev = *path;
    Vertex* it = (*path)->next;
    while(it->next)
    {
        prev = it;
        it = it->next;
    }
    prev->next = NULL;
    free_path(it);
    return;
    
}

void free_path(Vertex* path) 
{
    while(path) 
    {
        Vertex* tmp = path;
        path = path->next;
        free(tmp->city);
        free(tmp);
    }
}

void free_paths(vector * paths)
{
    for(int i = 0; i < paths->size; i++) 
    {
        if(paths->arr[i])
            free_path(paths->arr[i]);
    }
    free_vector(paths);
}

void print_paths(vector * paths) 
{
    for(int i = 0; i < paths->size; i++) 
    {
        printf("Path %d: ", i+1);
        Vertex* it = paths->arr[i];
        while(it != NULL) 
        {
            printf("%s", it->city);
            if(it->next) 
            {
                printf(" --%d-->", it->next->cost);  
            }   
            
            it = it->next;
        }

        printf(" Total cost: %d\n", get_total_cost(paths->arr[i]));
    }
}

int get_total_cost(Vertex * path)
{
    int total_cost = 0;
    Vertex * it = path;
    while(it!=NULL)
    {
        if(it->next != NULL)
        {
            total_cost += it->next->cost;
        }
        it = it->next;
    }
    return total_cost;
}

int get_total_transfers(Vertex * path)
{
    int total_transfers = 0;
    Vertex * it = path;
    while(it!=NULL)
    {
        total_transfers++;
        it = it->next;
    }
    return total_transfers;
}

void swap(Vertex** a, Vertex ** b)
{
    Vertex * temp = *a;
    *a = *b;
    *b = temp;
}

void sort_paths(vector * paths)
{
    int swapped = 0;
    for(int i = 0; i < paths->size - 1; i++) 
    {
        swapped = 0;
        for(int j = 0; j < paths->size - i - 1; j++) 
        {
            if((get_total_cost(paths->arr[j]) > get_total_cost(paths->arr[j+1])) || 
              (get_total_cost(paths->arr[j]) == get_total_cost(paths->arr[j+1]) && get_total_transfers(paths->arr[j]) > get_total_transfers(paths->arr[j+1]))) 
            {
                swap(&paths->arr[j], &paths->arr[j+1]);
                swapped = 1;
            }

        }
        if(swapped == 0)
            break;
    }
}

void push_vertex_in_path(Vertex ** current_path, Vertex * current_v)
{
    if(*current_path == NULL)
    {
        *current_path = current_v;
        return;
    }
    Vertex * it = *current_path;
    while(it->next != NULL)
    {
        it = it->next;
    }
    it->next = current_v;    
    
}

Vertex * duplicate_path(Vertex * path)
{
    Vertex* path_copy = NULL;
    Vertex* it = path;
    while(it != NULL) 
    {
        path_copy = append_to_path(path_copy, it);
        it = it->next;
    }
    return path_copy;
}

void dfs_R(Graph* g, char * from, char * to, int max_transfers, int max_cost, int current_transfer,
           int current_cost, vector * paths, Vertex * current_path, int current_start, int current_vertex_cost)
{
    if(current_cost > max_cost || current_transfer > max_transfers)
    {
        return;
    }
    Vertex * current_v = init_vertex(g->activeVertices[current_start], current_vertex_cost);
    push_vertex_in_path(&current_path, current_v);
    if(!strcmp(g->activeVertices[current_start], to))
    {
        Vertex * path_copy = duplicate_path(current_path);
        push(paths, path_copy);
        pop_last_vertex(&current_path);
        return;
    }
    Vertex * it = g->adjList[current_start];
    while(it != NULL)
    {

        dfs_R(g, from, to, max_transfers, max_cost, current_transfer+1, current_cost+it->cost, paths, current_path, get_index_from_city_names(g, it->city), it->cost);

        it = it->next;
    }
    pop_last_vertex(&current_path);

}


void find_paths(Graph* g, char * from, char * to, int max_transfers, int max_cost)
{
    if(!is_city_in_graph(g, from) || !is_city_in_graph(g, to))
    {
        printf("Cities not in graph\n");
        return;
    }
    vector * paths = init_vector(g->numVertices);
    int start_index = get_index_from_city_names(g, from);
    dfs_R(g, from, to, max_transfers, max_cost, 0, 0, paths, NULL, start_index, 0);
    sort_paths(paths);
    print_paths(paths);
    free_paths(paths);
}