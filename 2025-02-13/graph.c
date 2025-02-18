#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
Vertex* init_vertex(int val) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->val = val;
    vertex->next = NULL;

    return vertex;
}

Graph* init_graph(int numVertices) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Vertex**)calloc(numVertices, sizeof(Vertex*));

    return graph;
}

void addEdgeDirectional(Graph*graph, int from, int to) {
    Vertex* new_vertex = init_vertex(to);
    new_vertex->next = graph->adjList[from];
    graph->adjList[from] = new_vertex;
}

void addEdge(Graph* graph, int from, int to) {
    addEdgeDirectional(graph, from, to);
    addEdgeDirectional(graph, to, from);
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Vertex* it = graph->adjList[i];
        printf("Neighbors of %d: ", i);
        while (it != NULL)
        {
            printf("%d ", it->val);
            it = it->next;
        }
        printf("\n");
    }
}
int is_vartex_in_unique(vector * list, int val, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(list->arr[i] == val)
        return 0;
    }
    return 1;
}
void BFS(Graph * graph)
{
    vector * unique = init_vector(graph->numVertices);
    for (int i = 0; i < graph->numVertices; i++)
    {
        Vertex* it = graph->adjList[i];
        if(is_vartex_in_unique(unique, i, graph->numVertices))
        {
            printf("%d ", i);
            push(unique, i);
        }
        while(it != NULL)
        {
            if(is_vartex_in_unique(unique, it->val, graph->numVertices))
            {
                printf("%d ", it->val);
                push(unique, it->val);
            }
            it = it->next;
        }
    }
}
