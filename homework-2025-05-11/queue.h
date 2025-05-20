#ifndef QUEUE_H
#define QUEUE_H

typedef struct QNode
{
    void * val;
    struct QNode *next;
} QNode;

typedef struct Queue
{
    QNode *front;
    QNode *rear;
} Queue;


QNode *create_qnode(void * val);
Queue *init_queue();
void enqueue(Queue *queue, void * val);
void * dequeue(Queue *queue);
void clear_queue(Queue *queue);

#endif