#ifndef QUEUE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct QUEUE *queue;
struct QUEUE
{
    char *label;
    int count;
    queue next;
    queue prev;
};

int isEmptyQ();
queue* newqueue(char* data);
queue dequeue();
queue* enqueue(char* data, queue first, queue last);
int isEmptyQ(queue first);
char* peekQ(queue first);
int size(queue first);
void displayQ();

#endif // DEBUG