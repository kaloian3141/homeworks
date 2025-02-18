#include"quad_tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


Node * init_node(float min_X, float max_X, float min_Y, float max_Y)
{
    Node * tree = (Node *)malloc(sizeof(Node));
    tree->min_X = min_X;
    tree->max_X = max_X;
    tree->min_Y = min_Y;
    tree->max_Y = max_Y;
    tree->figure_count = 0;
    tree->figures = NULL;
    tree->is_Leaf = 1;
       for (int i = 0; i < 4; i++) {
        tree->children[i] = NULL;
    }
    return tree;

}

Figure * create_circle(float x, float y, float r, char *name)
{
    Figure * circle = (Figure *)malloc(sizeof(Figure));
    circle->name = (char *)malloc(strlen(name) + 1);
    strcpy(circle->name, name);
    circle->x = x;   
    circle->y = y;
    circle->radius = r;
    return circle;
}

Figure * create_square(float x, float y, float side, char *name)
{
    Figure * square = (Figure *)malloc(sizeof(Figure));
    square->name = (char *)malloc(strlen(name) + 1);
    strcpy(square->name, name);
    square->x = x;
    square->y = y;
    square->side = side;
    return square;
}

void insert_figure(Node * root, Figure * figure)
{
    if (figure->x > root->max_X || figure->x < root->min_X || figure->y > root->max_Y || figure->y < root->min_Y)
    {
        return;
    }
    if(root->is_Leaf)
    {
        if(root->figure_count == 0)
        {
            root->figures = (Figure**)malloc(sizeof(Figure*) * 10);
            if(root->figures == NULL)
            {
                printf("Error alocating memory");
                exit(1);
            }
            root->figures[0] = figure;
            root->figure_count++;
        }
        if(root->figure_count < 10)
        {
            root->figures[root->figure_count] = figure;
            root->figure_count++;
        }
        if(root->figure_count >= 10)
        {
            split_node(root);
            insert_figure(root, figure);
        }
    
    }
    else 
    {
        for(int i = 0; i<4;i++)
        {
            insert_figure(root->children[i], figure);
        }
    }
    
}

void split_node(Node * root)
{
    float mid_X = (root->min_X + root->max_X) / 2;
    float mid_Y = (root->min_Y + root->max_Y) / 2;

    root->children[0] = init_node(root->min_X, mid_X, root->min_Y, mid_Y);
    root->children[1] = init_node(mid_X, root->max_X, root->min_Y, mid_Y);
    root->children[2] = init_node(root->min_X, mid_X, mid_Y, root->max_Y);
    root->children[3] = init_node(mid_X, root->max_X, mid_Y, root->max_Y);

    root->is_Leaf = 0;
    for (int i = 0; i < root->figure_count; i++) 
    {
        Figure * current_figure = root->figures[i];
        for (int j = 0; j < 4; j++) 
        {
            Node* current_quadrant = root->children[j];
            
            if (current_figure->x >= current_quadrant->min_X && current_figure->x <= current_quadrant->max_X && current_figure->y >= current_quadrant->min_Y && current_figure->y <= current_quadrant->max_Y) 
            {
                insert_figure(current_quadrant, current_figure);
                break;
            }
        }
    }
    root->figures = NULL;
    root->figure_count = 0;
}

void built_tree(Node * root, Figure ** figure, int figures_count)
{   
    for(int i = 0; i<figures_count;i++)
    {
        insert_figure(root, figure[i]);
    }
}

void find_overlaps_recursive(Node *root, Overlaps ** overlaps, int *count, int *capacity) 
{
    if (root->is_Leaf) 
    {
        for (int i = 0; i < root->figure_count; i++) 
        {
            for (int j = i + 1; j < root->figure_count; j++) 
            {
        
                if (are_figures_overlaps(root->figures[i], root->figures[j])) 
                {
                    printf("2");
                    if(*count>*capacity)
                    {
                        *capacity *= 2;
                        overlaps = (Overlaps**)realloc(overlaps, sizeof(Overlaps*) * (*capacity));
                        if (overlaps == NULL) 
                            {
                                printf("Failed to allocate memory\n");
                                exit(1);
                            }
                    }
                    overlaps[*count]->figure1 = root->figures[i];
                    overlaps[*count]->figure2 = root->figures[j];
                    *count++;
                    
                    
                }
            }
        }
    } 
    else 
    {
        for (int i = 0; i < 4; i++) 
        {
            if (root->children[i]) 
            {
                find_overlaps_recursive(root->children[i], overlaps, count, capacity);
            }
        }
    }
}

Overlaps**find_overlaps(Node *root, int *out_count) 
{
    int count = 0;
    int capacity = 10;
    Overlaps**overlaps = (Overlaps **)malloc(sizeof(Overlaps*) * capacity);
    if (overlaps == NULL) 
    {
        printf("Failed to allocate memory\n");
        exit(1);
    }
    find_overlaps_recursive(root, overlaps, &count, &capacity);
    *out_count = count;
    return overlaps;
}

    

int are_figures_overlaps(Figure * figure1, Figure * figure2)
{
    if (figure1->shape == SQUARE && figure2->shape == SQUARE) 
    {
        return are_squares_overlaps(figure1, figure2);
    } 
    else if(figure1->shape == CIRCLE && figure2->shape == CIRCLE) 
    {
        return are_circles_overlaps(figure1, figure2);
    } 
    else if(figure1->shape == SQUARE && figure2->shape == CIRCLE) 
    {
        return are_square_circle_overlaps(figure1, figure2);
    } 
    else if(figure1->shape == CIRCLE && figure2->shape == SQUARE) 
    {
        return are_square_circle_overlaps(figure2, figure1);
    }
    return 0;
}

int are_squares_overlaps(Figure * sq1, Figure * sq2)
{
    if(sq1->x + sq1->side / 2 < sq2->x - sq2->side / 2 || sq1->x - sq1->side / 2 > sq2->x + sq2->side / 2 ||
        sq1->y + sq1->side / 2 < sq2->y - sq2->side / 2 || sq1->y - sq1->side / 2 > sq2->y + sq2->side / 2)
        return 0;
    else return 1;
}

int are_circles_overlaps(Figure * crl1, Figure * crl2)
{   
    if(crl1->x + crl1->radius < crl2->x - crl2->radius || crl1->x - crl1->radius > crl2->x + crl2->radius ||
        crl1->y + crl1->radius < crl2->y - crl2->radius || crl1->y - crl1->radius > crl2->y + crl2->radius)
        return 0;
    else return 1;
    
}

int are_square_circle_overlaps(Figure * sq, Figure * crl)
{
    if(sq->x + sq->side / 2 < crl->x - crl->radius || sq->x - sq->side / 2 > crl->x + crl->radius ||
        sq->y + sq->side / 2 < crl->y - crl->radius || sq->y - sq->side / 2 > crl->y + crl->radius)
        return 0;
    else return 1;
}
