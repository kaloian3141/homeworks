#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

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


int is_cyclic_R(Graph *g, int start, int* visited, int* dist, int* parent) 
{
    visited[start] = 1;
    Vertex *it = g->adjList[start];

    while (it != NULL) 
    {
        if (!visited[it->val]) 
        {
            dist[it->val] = dist[start] + 1;
            parent[it->val] = start;
            if(is_cyclic_R(g, it->val, visited, dist, parent)) 
            {
                return 1;
            }
        } 
        else 
        {
            int i = start;
            while(parent[i] != -1) 
            {
                if (parent[i] == it->val) 
                {
                    return 1;
                }
                i = parent[i];
            }
        }
        it = it->next;
    }

    return 0;
}

int is_cyclic(Graph *g) {
    int *visited = (int*)calloc(sizeof(int),g->numVertices);
    int *dist = (int*)calloc(sizeof(int), g->numVertices);
    int *parent = (int*)malloc(sizeof(int)*g->numVertices);

    int numIslands = 0;
    for (int i = 0; i < g->numVertices; i++) {
        if (!visited[i]) {
            numIslands++;
            parent[i] = -1;
            if (is_cyclic_R(g, i, visited, dist, parent)) {
                return 1;
            }   
        }
    }

    free(visited);
    free(dist);
    free(parent);

    return 0;

}
