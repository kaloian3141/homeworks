#include"quad_tree.h"
#include<stdio.h>


int main()
{
    Node * tree = init_node(-1000, 1000, -1000, 1000);
    Figure * crl1 = create_circle(52, 65, 10, "crl1");
    Figure * crl2 = create_circle(19, -4, 14, "crl2");
    Figure * sq1 = create_square(765, 10, 10, "sq1");
    Figure * sq2 = create_square(10, 10, 10, "sq2");
    Figure * sq3 = create_square(11, 11, 10, "sq3");
    insert_figure(tree, crl1);
    insert_figure(tree, crl2);
    insert_figure(tree, sq1);
    insert_figure(tree, sq2);
    insert_figure(tree, sq3);
}