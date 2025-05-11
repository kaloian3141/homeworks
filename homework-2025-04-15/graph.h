#ifndef GRAPH_H
#define GRAPH_H

#include "vector.h"
typedef struct vector vector;
typedef struct Vertex {
    char * city;
    int cost;
    struct Vertex* next;
} Vertex;

typedef struct Graph {
    int numVertices;
    int activeVertices_size;
    char ** activeVertices;
    Vertex **adjList;
} Graph;

Vertex* init_vertex(char * city, int cost);
Graph* init_graph(int numVertices);
void addEdgeDirectional(Graph*graph, char * from, char * to, int weight);
void add_city(Graph *g, char * city);
int is_city_in_graph(Graph * g, char * city);
int get_index_from_city_names(Graph * g, char * city);
void addEdge(Graph* graph, char * from, char * to, int weight);
void find_paths(Graph* g, char * from, char * to, int max_transfers, int max_cost);
void free_paths(vector * paths);
void free_path(Vertex* path);
Vertex* append_to_path(Vertex* path, Vertex* to_add);
Vertex * duplicate_vertex(Vertex * v);
void pop_last_vertex(Vertex ** path);
void print_paths(vector * paths);
void dfs_R(Graph* g, char * from, char * to, int max_transfers, int max_cost, int current_transfer,
    int current_cost, vector * paths, Vertex * current_path, int current_start, int current_vertex_cost);
void swap(Vertex** a, Vertex ** b);
int get_total_transfers(Vertex * path);
int get_total_cost(Vertex * path);
void sort_paths(vector * paths);
Vertex * duplicate_path(Vertex * path);
void push_vertex_in_path(Vertex ** current_path, Vertex * current_v);

#endif