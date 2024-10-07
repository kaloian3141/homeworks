#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char firstname[50];     
    struct Node *father;   
    struct Node *mother;   
    struct Node *married_to; 
} Node;


Node* createNode(char *name) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error alocating memory.\n");
        exit(1);
    }
    strcpy(newNode->firstname, name);
    newNode->father = NULL;
    newNode->mother = NULL;
    newNode->married_to = NULL;
    return newNode;
}


void print_family_member(Node *member)
{
    
    printf("Member name: %s\n", member->firstname);
    if(member->father != NULL)
        printf("father's name: %s\n", member->father->firstname);
    else
        printf("father's name: %s\n", "Unknown");
    if(member->mother != NULL)
        printf("mother's name: %s\n", member->mother->firstname);
    else
        printf("mother's name: %s\n", "Unknown");
    if(member->married_to != NULL)
        printf("who is merried to: %s\n", member->married_to->firstname);
    else
        printf("who is merried to: %s\n", "Unknown");
}
int main(void) {
    Node *father = createNode("Borislav");
    Node *mother = createNode("Maria");
    Node *me = createNode("Kaloyan");

    me->father = father;
    me->mother = mother;
    father->married_to = mother;
 
    print_family_member(father);
    print_family_member(mother);
    print_family_member(me);
    free(me);
    free(father);
    free(mother);   
}