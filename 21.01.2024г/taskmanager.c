#include "processes.h"
#include <stdio.h>

int main(void) {
    while(1) 
    {
        printf("\n1. Create new process\n");
        printf("2. List all processes\n");
        printf("3. Stop process\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        if(choice==1)
        {
          char name[31];
          printf("process name: ");
          scanf("%s", name);
          createnewprocess(name);
        }
        else if(choice==2)
          {
            printf("List of processes:\n");
            for (int i=0;i < processescount;i++) {
                printf("ID: %d, Name: %s\n", processes[i].id, processes[i].name);
            }
          }
        else if(choice==3)  
          {
            int processId;
            printf("ID to stop: ");
            scanf("%d", &processId);
            stopprocess(processId);
          }
        else if(choice==4)
            break;
         else
           printf("Invalid choice.\n");

        }
    return 0;
}