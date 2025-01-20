#include <stdio.h>
#include "dialogs.h"

int main()
{

    vector* inventory = init_vector(5);
    item sword = {"Sword", 1};
    item coins = {"Coins", 10};
    push(inventory, sword);
    push(inventory, coins);

    dialog_Node* root = init_dialog_Node("Welcome to the town of Fantasytown. How can I help you?", 3);
    root->player_answers[0] = "I want to buy armor.";
    root->player_answers[1] = "Nevermind.";
    root->player_answers[2] = "I want to sell my sword";

    item light_armor_requirement = {"Coins", 5};
    item heavy_armor_requirement = {"Coins", 15};
    item sword_selling_requiremet = {"Sword", 1};
    item price_for_sword = {"Coins", -20};


    root->next_dialogs[0] = init_dialog_Node("I have some armors. Do you want light or heavy armor?", 2);
    root->next_dialogs[1] = init_dialog_Node("Alright, have a nice day!", 0);

    root->next_dialogs[0]->player_answers[0] = "light armor please";
    root->next_dialogs[0]->player_answers[1] = "heavy armor please";

    root->next_dialogs[0]->next_dialogs[0] = init_dialog_Node("here is your light armor", 1);
    root->next_dialogs[0]->next_dialogs[1] = init_dialog_Node("here is your heavy armor", 1);

    push(root->next_dialogs[0]->next_dialogs[0]->item_requirements, light_armor_requirement);
    push(root->next_dialogs[0]->next_dialogs[1]->item_requirements, heavy_armor_requirement);

    root->next_dialogs[0]->next_dialogs[0]->next_dialogs[0] = root;
    root->next_dialogs[0]->next_dialogs[1]->next_dialogs[0] = root;

    root->next_dialogs[2] = init_dialog_Node("I will buy it for 20 Coins", 1);
    push(root->next_dialogs[2]->item_requirements, sword_selling_requiremet);
    root->next_dialogs[2]->next_dialogs[0] = init_dialog_Node("Here is your reward", 1);
    push(root->next_dialogs[2]->next_dialogs[0]->item_requirements, price_for_sword);
    root->next_dialogs[2]->next_dialogs[0]->next_dialogs[0] = root;

    play_dialogue(root, inventory);

    free_dialogue(root);
    free_vector(inventory);
    return 0;
}