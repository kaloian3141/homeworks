#include<stdio.h>
#include"..\utils\graph.h"

int universal_sink(Graph *g);
int main()
{
    Graph * g = init_graph(5);
    addEdgeDirectional(g,0,1,1);
    addEdgeDirectional(g,2,1,1);
    addEdgeDirectional(g,3,1,1);
    addEdgeDirectional(g,4,1,1);
    addEdgeDirectional(g,2,3,1);
    printf("%d\n",universal_sink(g));
}

int universal_sink(Graph *g)
{
    for(int current = 0; current < g->numVertices; current++)
    {
        if(g->adjList[current] == NULL)
        {
            int incoming_edges = 0; 
            for(int i = 0; i<g->numVertices; i++)
            {
                if(i != current)
                {
                    Vertex * it = g->adjList[i];
                    while(it != NULL)
                    {
                        if(it->val == current)
                        {
                            incoming_edges++;
                            break;
                        }
                        it = it->next;
                    }
                    
                }
            }
            if(incoming_edges == g->numVertices-1)
            {
                return current;
            }
        }
        
    }
    return -1;
}

