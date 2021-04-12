
#include "queue.h"




// queue first = NULL;
// queue last = NULL;
queue grammer[2];
queue* newqueue(char* data){
    queue first = (queue)malloc(sizeof(struct QUEUE));
    queue last = (queue)malloc(sizeof(struct QUEUE));

    first->label = data;

    first->next = NULL;
    first->prev = last;
    last->next = first;
    last->prev = NULL;
    last->label = NULL;

    first->count = 0;
    
    grammer[0] = first;
    grammer[1] = last;
    // printf("\nGrammer 0: %s", grammer[0]->label);
    // printf("\nGrammer 1: %s", grammer[1]->label);
    // printf("\nhey");
    return grammer;
}
/////
queue dequeue(queue first){
    if(isEmptyQ(first)){
        printf("\nDequeue: 0 empty");
        return NULL;
    }else{
        printf("\nDequeue: 1 pop: %s", first->label);
        queue temp = first;

        first = first->prev;
        first->next = NULL;
        printf("\nDequeue: 1 newfirst: %s", first->label);
        first->count = first->count-1;
        return first;
    }
}

queue* enqueue(char* data, queue first, queue last){
    if(first ==  NULL){
        return newqueue(data);
    }

    queue new = (queue)malloc(sizeof(struct QUEUE));
    new->label = data;
    if(last->next != NULL && last->label == NULL){
        last->next->prev = new;
        new->next = last->next;
        new->prev = last;
        last->next = new;
        first->count = first->count+1;

        grammer[0] = first;
        grammer[1] = last;
        return grammer;
    }
}

int isEmptyQ(queue first){
    if(first== NULL){
        printf("\nq.isEmpty: 1");
        return 1;
    }else{
        return 0;
        printf("\nq.isEmpty: 0");
    }
}

char* peekQ(queue first){
    if(isEmptyQ(first) == 0){
        printf("\nq.Peek: 1 %s", first->label);
        return first->label;
    }else{
        printf("\nq.Peek: 0 empty");
        return NULL;
    }
}

int size(queue first){
    return first->count;
}

void displayQ(queue first){
    queue temp = first;
    
    while( temp != NULL && temp->label != NULL){
        printf("\nq.DIS: %s", temp->label);
        temp = temp->prev;
    }
    printf("\nq.DIS: done?");
}
queue* qE;
// int main(){
    
//     qE = enqueue("ET", qE[0], qE[1]);
//     qE = enqueue("C", qE[0], qE[1]);

//     queue* qET;
//     qET = newqueue("|");
//     qET = enqueue("E", qE[0], qE[1]);

//     queue* C;
//     qE = newqueue("C");
//     qE = enqueue("S", qE[0], qE[1]);
//     qE = enqueue("CT", qE[0], qE[1]);

//     queue* CT;
//     qET = newqueue(".");
//     qET = enqueue("C", qE[0], qE[1]);

//     queue* qS;
//     qE = enqueue("A", qE[0], qE[1]);
//     qE = enqueue("ST", qE[0], qE[1]);

//     queue* qST;
//     qET = newqueue("*");
//     qET = enqueue("ST", qE[0], qE[1]);

//     queue* qA;
//     qE = enqueue("(", qE[0], qE[1]);
//     qE = enqueue("E", qE[0], qE[1]);
//     qE = enqueue(")", qE[0], qE[1]);

//     queue* qX;
//     // ET = newqueue("*");
//     // ET = enqueue("ST", E[0], E[1]);

    


//     displayQ(qE[0]);
// }