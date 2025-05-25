#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pqueue.h"

typedef struct Agent
{
    char agent_name;
    int agent_pos[2];
    char destination;
    int destination_pos[2];
}Agent;

Agent * init_agent(char name, int * pos, char destination, int * destination_pos);
Agent ** get_agents(char ** grid, int row_size, int col_size, int numb_of_agents);
int ** A_star(char ** grid, int row_size, int col_size, Agent * agent, int * steps, Agent ** agents, int numb_of_agents);
int h(int x, int y, int nx, int ny);
int ** get_path(int *** parent, int * start, int * end, int steps);
int is_agent(Agent ** agents, int numb_of_agents, int x, int y);
void tests();
int main()
{
    tests();
}

//инициализация на един агент
Agent * init_agent(char name, int * pos, char destination, int * destination_pos)
{
    Agent * new_agent = (Agent*)malloc(sizeof(Agent));
    new_agent->agent_name = name;
    new_agent->agent_pos[0] = pos[0];
    new_agent->agent_pos[1] = pos[1];
    new_agent->destination = destination;
    new_agent->destination_pos[0] = destination_pos[0];
    new_agent->destination_pos[1] = destination_pos[1];
    return new_agent;
}

//взимането на всички агенти в grid и слагането им в масив
Agent ** get_agents(char ** grid, int row_size, int col_size, int numb_of_agents)
{
    Agent ** agents = (Agent**)malloc(sizeof(Agent*) * numb_of_agents);
    int ** agent_starts = (int**)malloc(sizeof(int*)*numb_of_agents);
    int ** destinations = (int**)malloc(sizeof(int*)*numb_of_agents);
    for(int i = 0; i < numb_of_agents; i++)
    {
        agent_starts[i] = (int*)calloc(2, sizeof(int));
        destinations[i] = (int*)calloc(2, sizeof(int));
    }

    for(int i = 0; i < col_size; i++) 
    {
        for(int j = 0; j < row_size; j++) 
        {
            char ch = grid[i][j];
            if (ch >= '1' && ch <= '1' + numb_of_agents) 
            {
                int index = ch - '1';
                agent_starts[index][0] = i;
                agent_starts[index][1] = j;
            } 
            else if(ch >= 'A' && ch <= 'A' + numb_of_agents) 
            {
                int index = ch - 'A';
                destinations[index][0] = i;
                destinations[index][1] = j;
            }
        }
    }
    for(int i = 0; i < numb_of_agents; i++) 
    {
        agents[i] = init_agent('1' + i, agent_starts[i], 'A' + i, destinations[i]);
        free(agent_starts[i]);
        free(destinations[i]);
    }
    free(agent_starts);
    free(destinations);
    return agents;
}

int h(int x, int y, int nx, int ny) 
{
    return abs(x - nx) + abs(y - ny);
}

// А* алгоритъм който търси и връща минималния път от агент до дестинация
int ** A_star(char ** grid, int row_size, int col_size, Agent * agent, int * steps, Agent ** agents, int numb_of_agents)
{
    int start[2] = {agent->agent_pos[0], agent->agent_pos[1]};
    int end[2] = {agent->destination_pos[0], agent->destination_pos[1]};
    int **visited = (int**)malloc(sizeof(int*) * col_size);
    int ***parent = (int***)malloc(sizeof(int**) * col_size);
    int ** g = (int**)malloc(sizeof(int*) * col_size);
    for(int i = 0; i < col_size; i++)
    {
        visited[i] = (int*)calloc(row_size, sizeof(int));
        parent[i] = (int**)malloc(sizeof(int*) * row_size);
        g[i] = (int*)calloc(row_size, sizeof(int));     
        for(int j = 0; j < row_size; j++)
        {
            g[i][j] = INT_MAX;
            parent[i][j] = (int*)calloc(2, sizeof(int));
        }
    }
    parent[start[0]][start[1]][0] = -1;
    parent[start[0]][start[1]][1] = -1;
    g[start[0]][start[1]] = 0;
    PQueue * queue = init_pq();
    int * start_pos = (int*)malloc(2 * sizeof(int));
    if(start_pos == NULL)
    {
        printf("Error alocating memory\n");
    }
    start_pos[0] = start[0];
    start_pos[1] = start[1];
    int key = h(start[0], start[1], end[0], end[1]);
    pqInsert(queue, (int*)start_pos, key);
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int found = 0;
    while(queue->size > 0)
    {
        PQNode * current = deleteMin(queue);
        int * current_pos = (int*)current->data;
        if(!visited[current_pos[0]][current_pos[1]])
        {
            visited[current_pos[0]][current_pos[1]] = 1;
            if(current_pos[0] == end[0] && current_pos[1] == end[1])
            {
                found = 1;
                break;
            }

            for(int d = 0; d < 4; d++)
            {
                int neibours[2] = {current_pos[0] + directions[d][0], current_pos[1] + directions[d][1]};
                if(neibours[0] >= 0 && neibours[0] < col_size && neibours[1] >= 0 && neibours[1] < row_size)
                {
                    if(!visited[neibours[0]][neibours[1]] && grid[neibours[0]][neibours[1]] != '#' && !is_agent(agents, numb_of_agents, neibours[0], neibours[1]))
                    {
                        int new_g = g[current_pos[0]][current_pos[1]] + 1;
                        int new_h = h(neibours[0], neibours[1], end[0], end[1]);
                        int new_f = new_h + new_g;
                        
                        if(new_g < g[neibours[0]][neibours[1]])
                        {
                            g[neibours[0]][neibours[1]] = new_g;
                            parent[neibours[0]][neibours[1]][0] = current_pos[0];
                            parent[neibours[0]][neibours[1]][1] = current_pos[1];
                        }
                        int * next = malloc(2 * sizeof(int));
                        next[0] = neibours[0];
                        next[1] = neibours[1];
                        pqInsert(queue, (int*)next, new_f);
                    }
                }
            }
            free(current->data);
            free(current);
            
        }
    }
    
    *steps = g[end[0]][end[1]];
    int ** path = NULL;
    if(found)
    {
        
        path = get_path(parent, start ,end, *steps);
    }

    for(int i = 0; i < col_size; i++)
    {
        free(visited[i]);
        for(int j = 0; j < row_size; j++)
        {
            free(parent[i][j]);
        }
        free(parent[i]);
        free(g[i]);
    }
    free(parent);
    free(g);
    free(visited);
    free(queue);
    return path;
}

//от parent масив се създава path масив който е пътя от агент до дестинация
int ** get_path(int *** parent, int * start, int * end, int steps)
{
    int ** path = (int**)malloc((steps + 1) * sizeof(int *));
    for(int i = 0; i <= steps; i++)
    {
        path[i] = (int*)malloc(2 * sizeof(int));  
    }

    int x = end[0];
    int y = end[1];
    for(int i = steps; i >= 0; i--)
    {
        path[i][0] = x;
        path[i][1] = y;

        int px = parent[x][y][0];
        int py = parent[x][y][1];

        x = px;
        y = py;
    }

    return path;
}

//проверява дали в дадена позиция има агент
int is_agent(Agent ** agents, int numb_of_agents, int x, int y)
{
    for(int i = 0; i < numb_of_agents; i++)
    {
        if(agents[i]->agent_pos[0] == x && agents[i]->agent_pos[1] == y)
        {
            return 1;
        }
    }
    return 0;
}



//тестваме отделни части от програмата
void tests()
{
    char * grid[] = {
        "    A  B  C  D",
        "              ",
        "#### ##### ###",
        "              ",
        "####### ######",
        "       2      ",
        "   1     3   4"
    };
    int row_size = strlen(grid[0]);
    int col_size = sizeof(grid) / sizeof(grid[0]);
    int numb_of_agents = 4;
    Agent ** agents = get_agents(grid, row_size, col_size, numb_of_agents);
    for(int i = 0; i < numb_of_agents; i++)
        {
            printf("Agent %c from (%d,%d) to %c at (%d,%d):\n", 
                agents[i]->agent_name, agents[i]->agent_pos[0], agents[i]->agent_pos[1], 
                agents[i]->destination, agents[i]->destination_pos[0], agents[i]->destination_pos[1]);
            int steps = 0;
            int ** path = A_star(grid, row_size, col_size, agents[i], &steps, agents, numb_of_agents);
            if(path == NULL)
            {
                printf("there is no path from %c to %c\n", agents[i]->agent_name, agents[i]->destination);
            }
            else
            {
                for(int step = 0; step <= steps; step++)
                {
                    printf("  Step %d: (%d,%d)\n", step, path[step][0], path[step][1]);
                }

            }
        }
}
