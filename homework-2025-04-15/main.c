#include <stdio.h>
#include "graph.h"

int main()
{
    Graph * g = init_graph(4);
    add_city(g, "London");
    add_city(g, "Sofia");
    add_city(g, "Burgas");
    add_city(g, "Paris");
    addEdgeDirectional(g, "London", "Sofia", 2);
    addEdgeDirectional(g, "Sofia", "Burgas", 1);
    addEdgeDirectional(g, "Burgas", "Paris", 4);
    addEdgeDirectional(g, "Sofia", "Paris", 3);
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
    find_paths(g, "London", "Paris", 3, 7);
}
