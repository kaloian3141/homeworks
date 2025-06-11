#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "path_finding.h"
#include "gridsreader.h"

int main()
{
    char *** grids = read_grids_from_file("grids.txt");
    int grids_count = get_grids_count(grids);
    int * grids_size = (int*)malloc(grids_count * sizeof(int));
    for(int i = 0; i < grids_count; i++)
    {
        grids_size[i] = get_grid_size(grids[i]);
    }
    for(int i = 0; i < grids_count; i++)
    {
        int col_size = grids_size[i];
        int row_size = strlen(grids[i][0]);
        int numb_of_agents = get_numb_of_agents(grids[i], row_size, col_size);
        Agent ** agents = get_agents(grids[i], row_size, col_size, numb_of_agents);
        move_agents(grids[i], row_size, col_size, agents, numb_of_agents);
        free_agents(agents, numb_of_agents);
        
    }
    free_grids(grids, grids_count, grids_size);
    free(grids_size);
}
