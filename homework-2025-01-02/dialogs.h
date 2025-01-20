#ifndef DIALOGS_H
#define DIALOGS_H
#include "vector.h"


typedef struct dialog_Node
{
    char current_line[50];
    char ** player_answers;
    struct dialog_Node ** next_dialogs;
    int answers_num;
    vector* item_requirements;
} dialog_Node;

dialog_Node * init_dialog_Node(char * NPC_line, int answers_num);
void play_dialogue(dialog_Node * root, vector * inventory);
void free_dialogue(dialog_Node * node);

#endif