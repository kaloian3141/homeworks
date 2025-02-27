#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


Graph* init_graph(int numVertices) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*)calloc(numVertices, sizeof(int));
    }

    return graph;
}

void addEdgeDirectional(Graph*graph, int from, int to) {
    graph->adjMatrix[from][to] = 1;
}

void addEdge(Graph* graph, int from, int to) {
    addEdgeDirectional(graph, from, to);
    addEdgeDirectional(graph, to, from);
}

void printGraph(Graph *graph) {
    printf("# ");
    for(int i = 0; i < graph->numVertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d ", i);
        for(int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
int is_vartex_in_unique(vector * list, int val)
{
    for(int i = 0; i < list->size; i++)
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
        if(is_vartex_in_unique(unique, i))
        {
            printf("%d ", i);
            push(unique, i);
        }
        for(int j = 0; j < graph->numVertices; j++)
        {
            if(graph->adjMatrix[i][j] == 1)
            {
                if(is_vartex_in_unique(unique, j))
                {
                    printf("%d ", j);
                    push(unique, j);
                }
            }
        }
    }
}
void DFS_R(Graph * g, vector * unique, int start)
{
    if(is_vartex_in_unique(unique, start))
    {
        printf("%d ", start);
        push(unique, start);
    }
    for(int i = 0; i<g->numVertices; i++)
    {
        if(g->adjMatrix[i][start] == 1)
        {
            if(is_vartex_in_unique(unique, i))
            {
                printf("%d ", i);
                push(unique, i);
                DFS_R(g, unique, i);
            }
        }
    }
}
void DFS(Graph * g)
{
   vector * v = init_vector(g->numVertices);
   DFS_R(g, v, 0);
}
