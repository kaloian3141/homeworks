#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {
    int val;
    int weight;
    struct Vertex* next;
} Vertex;

typedef struct Graph {
    int numVertices;
    Vertex **adjList;
} Graph;

Vertex* init_vertex(int val, int weight);

Graph* init_graph(int numVertices);

void addEdgeDirectional(Graph*graph, int from, int to, int weight);
void addEdge(Graph* graph, int from, int to, int weight);

void printGraph(Graph *graph);


#endif