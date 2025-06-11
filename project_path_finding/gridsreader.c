#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "gridsreader.h"

//четем един ред 
char * read_line(FILE * fp)
{
    int ch;
    int capacity = 100;
    int size = 0;
    char *line = (char*)malloc(sizeof(char) * capacity);
    while((ch = fgetc(fp)) != EOF && ch != '\n') 
    {
        line[size] = ch;
        size++;
        if(size >= capacity) 
        {
            capacity *= 2;
            char * new_line = (char*)realloc(line, sizeof(char) * capacity);
            line = new_line;
        }
    }

    if(ch == EOF && size == 0) 
    {
        free(line);
        return NULL;
    }

    line[size] = '\0';
    return line;
}

//четем един grid
char ** read_one_grid_from_file(FILE * fp)
{
    int size = 0;
    int capacity = 10;
    char ** grid = (char**)malloc(sizeof(char*) * capacity); 
    char * line = read_line(fp);
    while(1)
    {
        if(line == NULL)
        {
            break;
        }
        if(line[0] == '_') 
        {
            free(line);
            break;
        }
        if(line[0] == '-' || line[0] == ' ')
        {
            free(line);
            continue;
        }
        if(line[0] == '|')
        {
            char * grid_line = (char*)malloc(sizeof(char) * strlen(line));
            int index = 0;
            for(int i = 1; line[i] != '\0'; i++) 
            {
                if(line[i] == '|')
                {
                    break;
                }
                grid_line[index] = line[i];
                index++;
                
            }
            grid_line[index] = '\0';
            free(line);
            if(size >= capacity) 
            {
                capacity *= 2;
                char ** new_grid = (char**)realloc(grid, sizeof(char*) * capacity);
                grid = new_grid;
            }
            grid[size] = grid_line;
            size++;
        }
        line = read_line(fp);
    }
    if(size == 0)
    {
        free(grid);
        return NULL;
    }
    grid = (char**)realloc(grid, sizeof(char*) * (size + 1));
    grid[size] = NULL;
    return grid;

}

// Четем всички grids от файла
char *** read_grids_from_file(char * file_name)
{
    FILE * fp;
    fp = fopen(file_name, "r");
    if(fp == NULL)
    {
        printf("file not opened\n");
        exit(1);
    }
    int size = 0;
    int capacity = 10;
    char *** grids = (char***)malloc(capacity * sizeof(char**));
    while(1)
    {
        char ** grid = read_one_grid_from_file(fp);
        
        if(grid == NULL)
        {
            break;
        }
        if(size >= capacity)
        {
            capacity *= 2;
            char ***new_grids = (char***)realloc(grids, capacity * sizeof(char**));
            grids = new_grids;
        }
        grids[size] = grid;
        size++;
    }
    fclose(fp);
    grids = (char***)realloc(grids, sizeof(char**) * (size + 1));
    grids[size] = NULL;
    return grids;   
}

//Взимаме размера на един grid(col_size)
int get_grid_size(char ** grid)
{
    int size = 0;
    for(size = 0; grid[size] != NULL; size++)
    {

    }
    return size;
}

//Взимаме броя на grids
int get_grids_count(char *** grids)
{
    int size = 0;
    for(size = 0; grids[size] != NULL; size++)
    {

    }
    return size;
}

//Освобождава паметта на всички grid-ове
void free_grids(char *** grids, int grids_count, int * grid_size)
{
    for(int i = 0; i < grids_count; i++)
    {
        free_grid(grids[i], grid_size[i]);
    }
    free(grids);
}

//Освобождава паметта на един grid
void free_grid(char ** grid, int grid_size)
{
    for(int i = 0; i < grid_size; i++)
    {
        free(grid[i]);
    }
    free(grid);
}

