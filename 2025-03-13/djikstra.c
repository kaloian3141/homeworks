#include <stdio.h>
#include <limits.h>
#include "../utils/graph.h"


int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k);
int find_min(int* dist, int size, int* visited);
void dijkstra(Graph* g, int start);

int main() 
{
    Graph *g = init_graph(5);
    addEdgeDirectional(g, 0, 1, 10);
    addEdgeDirectional(g, 0, 3, 5);
    addEdgeDirectional(g, 1, 2, 1);
    addEdgeDirectional(g, 1, 3, 2);
    addEdgeDirectional(g, 3, 2, 9);
    addEdgeDirectional(g, 3, 1, 3);
    addEdgeDirectional(g, 3, 4, 2); 
    addEdgeDirectional(g, 2, 4, 4);
    addEdgeDirectional(g, 4, 0, 7);
    addEdgeDirectional(g, 4, 2, 6);

    dijkstra(g, 0);
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k)
{
    int * dist = (int*)malloc((n+1) * sizeof(int));
    int *visited = (int*)calloc((n+1), sizeof(int));
    for (int i = 1; i < n+1; i++) 
    {
        dist[i] = INT_MAX;
    }
    dist[k] = 0;
    for(int i = 1; i < n+1; i++) 
    {
        int min = INT_MAX, minindex = 0;
        for(int j = 1; j < n+1; j++)
        {
            if(!visited[j] && min > dist[j])
            {
                min = dist[j];
                minindex = j;
            }
        }
        visited[minindex] = 1;
        for(int j = 0; j < timesSize; j++) 
        {
            int from = times[j][0];
            int to = times[j][1]; 
            int w = times[j][2];
            if(from == minindex && !visited[to] && dist[to] > dist[from] + w) 
            {
                dist[to] = dist[from] + w;
            }
        }
    }
    int maxTime = 0;
    for(int i = 1; i < n+1; i++) 
    {
        if (dist[i] == INT_MAX) 
        {
            free(dist);
            free(visited);
            return -1; 
        }

        if (dist[i] > maxTime) 
            maxTime = dist[i];
    }
    free(dist);
    free(visited);
    return maxTime;

}

int find_min(int* dist, int size, int* visited) 
{
    int min = INT_MAX;
    int minIndex = 0;
    for (int i = 0; i < size; i++) 
    {
        if (!visited[i] && min > dist[i]) 
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(Graph* g, int start) 
{
    int *visited = (int*)calloc(g->numVertices, sizeof(int));
    int *dist = (int*)malloc(g->numVertices*sizeof(int));

    for (int i = 0; i < g->numVertices; i++) 
    {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;

    for (int i = 0; i < g->numVertices; i++) 
    {
        int min = find_min(dist, g->numVertices, visited);
        visited[min] = 1;

        Vertex *it = g->adjList[min];
        while(it != NULL) 
        {
            int from = min;
            int to = it->val;
            int w = it->weight;

            if(dist[to] > dist[from] + w) 
            {
                dist[to] = dist[from] + w;

            }

            it = it->next;
        }
    }

    for(int i = 0; i < g->numVertices; i++) 
    {
        printf("%d: %d\n", i, dist[i]);
    }
    printf("\n");
}