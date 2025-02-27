#include "graph.h"
#include <stdio.h>


int main()
{

    Graph* g = init_graph(5);
    addEdgeDirectional(g,0,1);
    addEdge(g,0,2);
    addEdge(g,0,4);
    addEdge(g,3,4);
    addEdge(g,2,1);
    addEdge(g,2,3);
    BFS(g);
    printf("\n");
    DFS(g);
}