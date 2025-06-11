#ifndef PATH_FINDING_H
#define PATH_FINDING_H

typedef struct Agent
{
    char agent_name;
    int agent_pos[2];
    char destination;
    int destination_pos[2];
}Agent;

Agent * init_agent(char name, int * pos, char destination, int * destination_pos);
Agent ** get_agents(char ** grid, int row_size, int col_size, int numb_of_agents);
void free_agents(Agent ** agents, int numb_of_agents);
int ** A_star(char ** grid, int row_size, int col_size, Agent * agent,
                int * steps, Agent ** agents, int numb_of_agents, int path_with_agents);
int h(int x, int y, int nx, int ny);
int ** get_path(int *** parent, int * start, int * end, int steps);
int is_agent(Agent ** agents, int numb_of_agents, int x, int y);
int are_agents_in_destinations(Agent ** agents, int numb_of_agents);
int is_agent_in_destination(Agent * agent);
void print_grid(char ** grid, int row_size, int col_size);
void move_agents(char ** grid, int row_size, int col_size, Agent ** agents, int numb_of_agents);
void move_agent(char ** grid, int row_size, int col_size, Agent * agent, int ** path, char symbol_under_agent);
char ** copy_grid(char ** grid, int row_size, int col_size);
int are_grid_same(char ** grid, char ** prev_grid, int row_size, int col_size);
int get_numb_of_agents(char ** grid, int row_size, int col_size);

#endif