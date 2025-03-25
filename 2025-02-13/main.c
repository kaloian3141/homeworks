#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "../utils/queue.h"

void dfsR(Graph *g, int start, int* visited, int* dist);
void dfs(Graph *g);
void bfs(Graph *g);
int main()
{

    Graph* g = init_graph(5);
    addEdgeDirectional(g,0,1);
    addEdgeDirectional(g,1,2);
    addEdgeDirectional(g,2,3);
    addEdgeDirectional(g,3,4);
    addEdgeDirectional(g,0,4);

    
    
    printGraph(g);
    printf("\n");
    bfs(g);
    printf("\n");
    dfs(g);
    printf("\n");
}
void dfsR(Graph *g, int start, int* visited, int* dist) 
{
    visited[start] = 1;
    printf("%d ", start);
    Vertex *it = g->adjList[start];

    while(it != NULL) 
    {
        if(!visited[it->val]) 
        {
            dist[it->val] = dist[start] + 1;
            dfsR(g, it->val, visited, dist);
        }
        it = it->next;
    }
}

void dfs(Graph *g) 
{
    int *visited = (int*)calloc(sizeof(int),g->numVertices);
    int *dist = (int*)calloc(sizeof(int), g->numVertices);

    for (int i = 0; i < g->numVertices; i++) 
    {
        if (!visited[i]) 
        {
            dfsR(g, i, visited, dist);    
        }
    }
    free(dist);
    free(visited);

}

void bfs(Graph*g) 
{
    int *visited = (int*)calloc(sizeof(int),g->numVertices);
    int *dist = (int*)calloc(sizeof(int), g->numVertices);

    visited[0] = 1;
    Queue* queue = init_queue();
    enqueue(queue, 0);
    printf("%d ",queue->front->val);
    while(queue->front != NULL) 
    {
        int current = dequeue(queue);
        Vertex *it = g->adjList[current];
        while (it != NULL) 
        {
            if(!visited[it->val]) 
            {
                printf("%d ", it->val);
                dist[it->val] = dist[current] + 1;
                visited[it->val] = 1;
                enqueue(queue, it->val);
            }
            it = it->next;
        }
    }
    free(dist);
    free(visited);
}