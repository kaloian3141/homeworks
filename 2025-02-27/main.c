#include <stdio.h>
#include "graph.h"


int main()
{
    Graph * g = init_graph(5);
    addEdgeDirectional(g,0,1);
    addEdgeDirectional(g,0,2);
    addEdgeDirectional(g,1,3);
    addEdgeDirectional(g,1,4);
    addEdgeDirectional(g,3,2);
    printf("%d", is_cyclic(g));
}