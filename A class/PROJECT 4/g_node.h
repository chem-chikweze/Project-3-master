#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;
typedef struct node *NodePtr;
typedef struct node *Bstptr;

struct node
{
    void *v;
    void *p;
    NodePtr left, right;

    int (*compareTo)(const void *, const void *);
    void (*freeObject)(void *);
    char *(*toString)(void *);
};

NodePtr createNode(void *obj1, void *obj2);
void freeNode(NodePtr node, void (*freeObject)(void *));
void delete (Bstptr head, NodePtr node) ;

NodePtr min_succesor(NodePtr head);

#endif