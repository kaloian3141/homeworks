#ifndef QUAD_TREE_H
#define QUAD_TREE_H

typedef enum {
    SQUARE,
    CIRCLE
}Shape;


typedef struct Figure
{
    float x, y;
    char * name;
    Shape shape;
    union{
        float radius;
        float side;
    }; 
}Figure;

typedef struct Node {
    float min_X, max_X, min_Y, max_Y;
    struct Node *children[4];
    Figure **figures;
    int figure_count;
    int is_Leaf;
} Node;

typedef struct Overlaps
{
    Figure * figure1;
    Figure * figure2;
}Overlaps;



Node * init_node(float min_X, float max_X, float min_Y, float max_Y);
Figure * create_circle(float x, float y, float r, char *name);
Figure * create_square(float x, float y, float side, char *name);
void insert_figure(Node * root, Figure * figure);
void built_tree(Node * root, Figure ** figure, int figures_count);
void split_node(Node * root);
Overlaps**find_overlaps(Node *root, int *out_count);
void find_overlaps_recursive(Node *root, Overlaps ** overlaps, int *count, int *capacity);
int are_figures_overlaps(Figure * figure1, Figure * figure2);
int are_squares_overlaps(Figure * sq1, Figure * sq2);
int are_circles_overlaps(Figure * crl1, Figure * crl2);
int are_square_circle_overlaps(Figure * sq, Figure * crl);
#endif
