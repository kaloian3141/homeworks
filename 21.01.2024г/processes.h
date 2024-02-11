#ifndef PROCESSES_H
#define PROCESSES_H

typedef struct{
  int id;
  char name[31];
}Process;
extern Process processes[5];
extern int processescount;
int nextprocessid();
int createnewprocess(char name[]);
void stopprocess(int processId);
#endif