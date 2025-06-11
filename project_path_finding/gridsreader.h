#ifndef GRIDREADER_H
#define GRIDREADER_H
#include<stdio.h>


char * read_line(FILE * fp);
char ** read_one_grid_from_file(FILE * fp);
char *** read_grids_from_file(char * file_name);
int get_grid_size(char ** grid);
int get_grids_count(char *** grids);
void free_grids(char *** grids, int grids_count, int * grid_size);
void free_grid(char ** grid, int grid_size);
#endif