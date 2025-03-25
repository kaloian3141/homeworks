#ifndef GRAPH_H
#define GRAPH_H
#include "../utils/vector.h"
typedef struct Graph {
    int numVertices;
    int **adjMatrix;
} Graph;


Graph* init_graph(int numVertices);
void addEdgeDirectional(Graph*graph, int from, int to);
void addEdge(Graph* graph, int from, int to);
void printGraph(Graph *graph);
void BFS(Graph * g);
void DFS(Graph * g);
#endif