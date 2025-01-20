#include "dialogs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

dialog_Node * init_dialog_Node(char * NPC_line, int answers_num)
{
    dialog_Node * node = (dialog_Node *)malloc(sizeof(dialog_Node));
    if(node == NULL)
    {
        printf("Error allocating memory\n");
        exit(1);
    }

    node->answers_num = answers_num;
    strcpy(node->current_line, NPC_line);
    node->item_requirements = init_vector(2);
    node->player_answers = (char **)malloc(sizeof(char *) * answers_num);
    if(node->player_answers == NULL)
    {
        printf("Error allocating memory\n");
        exit(1);
    }

    node->next_dialogs = (dialog_Node **)malloc(sizeof(dialog_Node *) * answers_num);
    if(node->next_dialogs == NULL)
    {
        printf("Error allocating memory\n");
        exit(1);
    }

    for(int i = 0; i<answers_num; i++)
    {
        node->player_answers[i] = NULL;
        node->next_dialogs[i] = NULL;
    }

    return node;
}

void update_inventory(vector *inventory, vector *requirements) 
{
    for (int i = 0; i<requirements->size; i++) 
    {
        item required_item = getAt(requirements, i);
        for (int j = 0; j<inventory->size; j++) 
        {
            if (strcmp(inventory->arr[j].name, required_item.name) == 0) 
            {
                inventory->arr[j].count -= required_item.count;
                break;
            }
        }
    }
}
int check_requirements(vector *inventory, vector *requirements) 
{
    for(int i = 0; i<requirements->size; i++) 
    {
        int found = 0;
        for(int j = 0; j<inventory->size; j++) 
        {
            if(strcmp(getAt(requirements, i).name, getAt(inventory, j).name) == 0)
            {
                if(getAt(inventory, j).count >= getAt(requirements, i).count) 
                {
                    found = 1;
                    break;
                }
            }
        }
        if(!found) 
        {
            return 0; 
        }
    }
    return 1; 
}

void play_dialogue(dialog_Node *root, vector* inventory) 
{
    if(root == NULL) 
    {
        printf("Dialogue ended.\n");
        return;
    }
    print_vector(inventory);

    printf("NPC: %s\n", root->current_line);

    if(root->answers_num == 0)
    {
        printf("Dialogue ended.\n");
        return;
    }

    else if(root->answers_num == 1) 
    {
        if(root->player_answers[0] != NULL) 
        {
            printf("Player (auto): %s\n", root->player_answers[0]);
        }
         update_inventory(inventory, root->next_dialogs[0]->item_requirements);
        play_dialogue(root->next_dialogs[0], inventory);
    }

    else if(root->answers_num > 1) 
    {
        for(int i = 0; i<root->answers_num; i++) 
        {
            printf("%d. %s\n", i+1, root->player_answers[i]);
        }

        int choice = 0;
        while(1) 
        {
            printf("Option: ");
            scanf("%d", &choice);
            getchar();
            if(choice >= 1 && choice <= root->answers_num)
                break;
            else 
            {
                printf("Invalid choice.\n");
            }
        }
        if(check_requirements(inventory, root->next_dialogs[choice-1]->item_requirements)) 
        {
            printf("Player: %s\n", root->player_answers[choice-1]);
            update_inventory(inventory, root->next_dialogs[choice-1]->item_requirements);
            play_dialogue(root->next_dialogs[choice-1], inventory);
            
        }
        else
        {
            printf("You do not have the required items for this choice.\n");
            play_dialogue(root, inventory);
            return;
        }
    }
}

void free_dialogue(dialog_Node *node) 
{
    if(node == NULL) return;

    for(int i = 0; i<node->answers_num; i++) 
    {
        free(node->player_answers[i]);
        free_dialogue(node->next_dialogs[i]);
    }

    free_vector(node->item_requirements);
    free(node->player_answers);
    free(node->next_dialogs);
    free(node);
}