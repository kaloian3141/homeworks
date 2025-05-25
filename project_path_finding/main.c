#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Agent
{
    char agent_name;
    int agent_pos[2];
    char destination;
    int destination_pos[2];
}Agent;

Agent * init_agent(char name, int * pos, char destination, int * destination_pos);
Agent ** get_agents(char ** grid, int row_size, int col_size, int numb_of_agents);

int main()
{
    char * grid[] = {
        "    A  B  C  D",
        "              ",
        "    ##########",
        "              ",
        "   1  2  3   4"
    };
    int row_size = strlen(grid[0]);
    int col_size = sizeof(grid) / sizeof(grid[0]);
    Agent ** agents = get_agents(grid, row_size, col_size, 4);
    

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