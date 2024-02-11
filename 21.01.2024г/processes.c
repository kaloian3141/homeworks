#include "processes.h"
#include <stdio.h>
int processescount = 0;
Process processes[5];
int nextprocessid() {
    if (processescount<5) {
        static int nextID = 1;
        return nextID++;
    } else {
        return 0; 
    }
}
int createnewprocess(char name[]) 
{
    if (processescount < 5) 
      {
        int Id = nextprocessid();
          processes[processescount].id = Id;
          for (int i=0;i<=30 && name[i]!='\0';i++) 
            {
                processes[processescount].name[i] = name[i];
            }
          processescount++;
          return Id;
      }
    else 
      {
        printf("too many processes.\n");
        return 0;
      }  
}

void stopprocess(int processId) 
{
    int is_deleted = 0;
    for (int i=0;i<processescount;i++) 
    {
        if (processes[i].id == processId) 
        {
            for (int j=i;j<processescount-1;j++)
              {
                processes[j] = processes[j+1];
              }
            processescount--;
            printf("Process %d stopped.\n", processId);
            is_deleted = 1;
        }
    }
    if(is_deleted==0)
    {
      printf("Process with ID %d not found.\n", processId);
    }
  

}