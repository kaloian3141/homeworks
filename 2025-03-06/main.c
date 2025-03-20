#include <stdio.h>
#include "graph.h"

int main()
{
    Graph * g = init_graph(6);
    addEdge(g, 0, 1);
    addEdge(g, 0, 4); 
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 4);
    addEdge(g, 3, 5);
    addEdge(g, 4, 5);
    vector * vertexes = findVerticesAtDistanceN(g, 0, 2);
    print_vector(vertexes);
    printf("\n");
}