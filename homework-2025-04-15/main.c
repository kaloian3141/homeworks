#include <stdio.h>
#include "graph.h"

int main()
{
    Graph * g = init_graph(5);
    add_city(g, "London");
    add_city(g, "Sofia");
    add_city(g, "Burgas");
    add_city(g, "Paris");
    add_city(g, "Madrid");
    addEdgeDirectional(g, "London", "Sofia", 2);
    addEdgeDirectional(g, "Sofia", "Burgas", 1);
    addEdgeDirectional(g, "Burgas", "Paris", 4);
    addEdgeDirectional(g, "Madrid", "London", 7);
    addEdgeDirectional(g, "Paris", "London", 1);
    addEdgeDirectional(g, "Madrid", "Sofia", 1);
    addEdgeDirectional(g, "Paris", "Madrid", 2);
    for(int i = 0; i < g->numVertices; i++)
    {
        printf("%s:", g->activeVertices[i]);
        Vertex* it = g->adjList[i];
        while(it != NULL)
        {            
            printf("-> %d, %s ",it->cost, it->city);
            it = it->next;
        }
        printf("\n");
        
    }
    find_paths(g, "Madrid", "London", 6, 9);
}
