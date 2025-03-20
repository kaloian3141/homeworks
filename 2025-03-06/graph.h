#ifndef GRAPH_H
#define GRAPH_H
#include"..\utils\queue.h"
#include"..\utils\vector.h"
typedef struct Vertex {
    int val;
    struct Vertex* next;
} Vertex;

typedef struct Graph {
    int numVertices;
    Vertex **adjList;
} Graph;

Vertex* init_vertex(int val);
Graph* init_graph(int numVertices);
void addEdgeDirectional(Graph*graph, int from, int to);
void addEdge(Graph* graph, int from, int to);
void printGraph(Graph *graph);
void BFS(Graph * g);
vector* findVerticesAtDistanceN(Graph* g, int start, int N);
#endif