#include<stdio.h>
#include<string.h>
#include"queue.h"
#include "pqueue.h"
#include<limits.h>
#ifdef _WIN32
    #include<windows.h>
#else
    #include<unistd.h>
#endif

void print_grid(char ** grid, int row_size, int col_size);
void BFS(char ** grid, int row_size, int col_size);
void Dijkstra(char ** grid, int row_size, int col_size);
void A_star(char ** grid, int row_size, int col_size);
int h(int x, int y, int nx, int ny);
char ** copy_grid(char ** grid, int row_size, int col_size);
void free_grid(char ** grid, int row_size, int col_size);

int main()
{
    char *grid[] = 
    {
        "      #     E",
        "    #   #    ",
        "     #  #    ",
        "    #        ",
        "S   #        "
    };
    int row_size = strlen(grid[0]);
    int col_size = sizeof(grid) / sizeof(grid[0]);
    
    while(1)
    {
        print_grid(grid, row_size, col_size);
        int choice = 0;
        printf("1.Find Path\n");
        printf("2.Exit\n");
        scanf("%d", &choice);
        if(choice == 1)
        {
            while(1)
            {
                int algorithm_choice = 0;
                printf("Choose algorithm\n");
                printf("1.A*\n");
                printf("2.Dijkstra\n");
                printf("3.BFS\n");
                scanf("%d", &algorithm_choice);
                if(algorithm_choice == 1)
                {
                    char ** temp_grid = copy_grid(grid, row_size, col_size);
                    A_star(temp_grid, row_size, col_size);
                    free_grid(temp_grid, row_size, col_size);
                    break;
                }
                if(algorithm_choice == 2)
                {
                    char ** temp_grid = copy_grid(grid, row_size, col_size);
                    Dijkstra(temp_grid, row_size, col_size);
                    free_grid(temp_grid, row_size, col_size);
                    break;
                }
                if(algorithm_choice == 3)
                {
                    char ** temp_grid = copy_grid(grid, row_size, col_size);
                    BFS(temp_grid, row_size, col_size);
                    free_grid(temp_grid, row_size, col_size);
                    break;
                }
                else
                {
                    printf("Invalid choice\n");
                }
            }
        }
        if(choice == 2)
        {
            break;
        }
        else{
            printf("Invalid choice\n");
        }
    }
}

void print_grid(char ** grid, int row_size, int col_size)
{
    for(int i = 0; i < col_size; i++)
    {
        printf("%s\n", grid[i]);
    }
}

char ** copy_grid(char ** grid, int row_size, int col_size)
{
    char ** new_grid = (char**)malloc(sizeof(char*) * col_size);
    for(int i = 0; i < col_size; i++)
    {
        new_grid[i] = strdup(grid[i]);
    }
    return new_grid;
}

void free_grid(char ** grid, int row_size, int col_size)
{
    for(int i = 0; i < col_size; i++)
    {
        free(grid[i]);
    } 
    free(grid);
}

void BFS(char ** grid, int row_size, int col_size)
{
    int start[2];
    int end[2];
    int ** visited = (int**)malloc(sizeof(int*) * col_size);
    int *** parent = (int***)malloc(sizeof(int**) * col_size);
    for(int i = 0; i < col_size; i++)
    {
        visited[i] = (int*)calloc(row_size, sizeof(int));
        parent[i] = (int**)malloc(sizeof(int*)* row_size);
        for(int j = 0; j < row_size; j++)
        {
            parent[i][j] = (int*)calloc(2, sizeof(int));
            if(grid[i][j] == 'S')
            {
                start[0] = i;
                start[1] = j;
            }
            if(grid[i][j] == 'E')
            {
                end[0] = i;
                end[1] = j;
            }
        }
    }
    visited[start[0]][start[1]] = 1;
    parent[start[0]][start[1]][0] = -1;
    parent[start[0]][start[1]][1] = -1;
    Queue * queue = init_queue();
    int *start_pos = (int*)malloc(2 * sizeof(int));
    start_pos[0] = start[0];
    start_pos[1] = start[1];
    enqueue(queue, (int*)start_pos);
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int found = 0;

    while(queue->front != NULL)
    {
        int * current = (int*)dequeue(queue);
        if(current[0] == end[0] && current[1] == end[1])
        {
            found = 1;
            free(current);
            break;
        }

        for(int d = 0; d < 4; d++)
        {
            int neibours[2] = {current[0] + directions[d][0], current[1] + directions[d][1]};
            if(neibours[0] >= 0 && neibours[0] < col_size && neibours[1] >= 0 && neibours[1] < row_size)
            {
                if(!visited[neibours[0]][neibours[1]] && grid[neibours[0]][neibours[1]] != '#')
                {
                    visited[neibours[0]][neibours[1]] = 1;
                    parent[neibours[0]][neibours[1]][0] = current[0];
                    parent[neibours[0]][neibours[1]][1] = current[1];
                    int *next = (int*)malloc(2 * sizeof(int));
                    next[0] = neibours[0];
                    next[1] = neibours[1];
                    enqueue(queue, next);
                    if(grid[current[0]][current[1]] == ' ')
                    {
                       grid[current[0]][current[1]] = '.';
                    }
                }
            }
        }
        system("cls");
        print_grid(grid, row_size, col_size);
        #ifdef _WIN32
            Sleep(300); 
        #else
            sleep(0.3);
        #endif
        free(current);
    }

    if(found)
    {
        int cx = end[0], cy = end[1];
        while(parent[cx][cy][0] != -1)
        {
            if(grid[cx][cy] != 'E')
            {
                grid[cx][cy] = 'X';
            }
            int px = parent[cx][cy][0];
            int py = parent[cx][cy][1];
            cx = px;
            cy = py;

            system("cls");
            print_grid(grid, row_size, col_size);
            #ifdef _WIN32
            Sleep(300); 
            #else
                sleep(0.3);
            #endif
        }
    }
    else
    {
        printf("there is no path from S to E\n");
    }

    for(int i = 0; i < col_size; i++)
    {
        free(visited[i]);
        for(int j = 0; j < row_size; j++)
        {
            free(parent[i][j]);
        }
        free(parent[i]);
    }
    free(parent);
    free(visited);
    free(start_pos);
    clear_queue(queue);
    free(queue);
    return;
}

void Dijkstra(char ** grid, int row_size, int col_size)
{
    int start[2], end[2];
    int ** visited = (int**)malloc(sizeof(int*) * col_size);
    int ** distance = (int**)malloc(sizeof(int*) * col_size);
    int *** parent = (int***)malloc(sizeof(int**) * col_size);
    for(int i = 0; i < col_size; i++)
    {
        visited[i] = (int*)calloc(row_size, sizeof(int));
        distance[i] = (int*)malloc(sizeof(int) * row_size);
        parent[i] = (int**)malloc(sizeof(int*) * row_size);
        for(int j = 0; j < row_size; j++)
        {
            distance[i][j] = INT_MAX; 
            parent[i][j] = (int*)calloc(2, sizeof(int));
            parent[i][j][0] = -1;
            parent[i][j][1] = -1;
            if(grid[i][j] == 'S')
            {
                start[0] = i;
                start[1] = j;
            }
            if(grid[i][j] == 'E')
            {
                end[0] = i;
                end[1] = j;
            }
        }
    }

    distance[start[0]][start[1]] = 0;
    while(1)
    {
        int min_dist = INT_MAX;
        int min_index[2] = {-1, -1};

        for(int i = 0; i < col_size; i++)
        {
            for(int j = 0; j < row_size; j++)
            {
                if(!visited[i][j] && distance[i][j] < min_dist)
                {
                    min_dist = distance[i][j];
                    min_index[0] = i;
                    min_index[1] = j;
                }
            }
        }

        if(min_index[0] == -1) 
            break; 

        visited[min_index[0]][min_index[1]] = 1;

        if(min_index[0] == end[0] && min_index[1] == end[1])
            break;

        int directions[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        for(int d = 0; d < 4; d++)
        {
            int neibours[2] = {min_index[0] + directions[d][0], min_index[1] + directions[d][1]};

            if(neibours[0] >= 0 && neibours[0] < col_size && neibours[1] >= 0 && neibours[1] < row_size)
            {
                if(!visited[neibours[0]][neibours[1]] && grid[neibours[0]][neibours[1]] != '#')
                {
                    if(distance[min_index[0]][min_index[1]] + 1 < distance[neibours[0]][neibours[1]])
                    {
                        distance[neibours[0]][neibours[1]] = distance[min_index[0]][min_index[1]] + 1;
                        parent[neibours[0]][neibours[1]][0] = min_index[0];
                        parent[neibours[0]][neibours[1]][1] = min_index[1];
                        if(grid[neibours[0]][neibours[1]] == ' ')
                        {
                            grid[neibours[0]][neibours[1]] = '.';
                        }
                    }
                }
            }
        }

        system("cls");
        print_grid(grid, row_size, col_size);
        #ifdef _WIN32
            Sleep(300); 
        #else
            sleep(0.3);
        #endif
    }

    if(distance[end[0]][end[1]] != INT_MAX)
    {
        int cx = end[0], cy = end[1];
        while(parent[cx][cy][0] != -1)
        {
            if(grid[cx][cy] != 'E')
            {
                grid[cx][cy] = 'X';
            }
            int px = parent[cx][cy][0];
            int py = parent[cx][cy][1];
            cx = px;
            cy = py;

            system("cls");
            print_grid(grid, row_size, col_size);
            #ifdef _WIN32
            Sleep(300); 
            #else
                sleep(0.3);
            #endif
        }
    }
    else
    {
        printf("there is no path from S to E");
    }
     
    for(int i = 0; i < col_size; i++)
    {
        free(visited[i]);
        free(distance[i]);
        for(int j = 0; j < row_size; j++)
        {
            free(parent[i][j]);
        }
        free(parent[i]);
    }
    free(visited);
    free(distance);
    free(parent);
    return;
}

int h(int x, int y, int nx, int ny) 
{
    return abs(x - nx) + abs(y - ny);
}

void A_star(char ** grid, int row_size, int col_size)
{
    int start[2], end[2];
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
            if(grid[i][j] == 'S')
            {
                start[0] = i;
                start[1] = j;
            }
            if(grid[i][j] == 'E')
            {
                end[0] = i;
                end[1] = j;
            }
        }
    }
    parent[start[0]][start[1]][0] = -1;
    parent[start[0]][start[1]][1] = -1;
    g[start[0]][start[1]] = 0;
    PQueue * queue = init_pq();
    int * start_pos = (int*)malloc(2 * sizeof(int));
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
                    if(!visited[neibours[0]][neibours[1]] && grid[neibours[0]][neibours[1]] != '#')
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
                        if(grid[current_pos[0]][current_pos[1]] == ' ')
                        {
                            grid[current_pos[0]][current_pos[1]] = '.';
                        }
                        
                    }
                }
            }
            system("cls");
            print_grid(grid, row_size, col_size);
            #ifdef _WIN32
            Sleep(300); 
            #else
                sleep(0.3);
            #endif
            free(current->data);
            free(current);
        }
    }

    if(found)
    {
        int cx = end[0], cy = end[1];
        while(parent[cx][cy][0] != -1)
        {
            if(grid[cx][cy] != 'E')
                grid[cx][cy] = 'X';
            int px = parent[cx][cy][0];
            int py = parent[cx][cy][1];
            cx = px;
            cy = py;

            system("cls");
            print_grid(grid, row_size, col_size);
            #ifdef _WIN32
                Sleep(300); 
            #else
                sleep(0.3);
            #endif
        }
    }
    else
    {
        printf("There is no path from S to E\n");
    }

    for(int i = 0; i < col_size; i++)
    {
        free(visited[i]);
        free(g[i]);
        for(int j = 0; j < row_size; j++)
        {
            free(parent[i][j]);
        }
        free(parent[i]);
    }
    free(g);
    free(start_pos);
    free(visited);
    free(parent);
}

