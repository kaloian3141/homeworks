#include <stdio.h>

int main(void) {
    unsigned char rooms = 0;

    while (1) {
        printf("1. Switch lights\n");
        printf("2. Print state\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int room;
            scanf("%d", &room);
            unsigned char current_room = 1 << (room - 1);
            int isLightOn = (rooms & current_room) != 0;
            if (isLightOn) {
               rooms = rooms & (~current_room);
            } else {
              rooms = rooms | current_room;
            }
        } else if (choice == 2) {
            printf("The light is on in rooms: ");
            for (int i = 0; i < 8; i++) {
                if ((rooms & (1 << i)) !=0) {
                    printf("%d ", i + 1);
                }
            }
            printf("\n");
        } else if (choice == 3) {
            break;
        } else {
            printf("\nInvalid choice");
        }
    } 

    return 0;
}