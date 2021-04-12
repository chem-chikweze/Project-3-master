#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;
typedef struct node *NodePtr;

struct node
{
    void *v;
    void *p;
    NodePtr left, right;
};

NodePtr createNode(void *obj1, void *obj2);
void freeNode(NodePtr node, void (*freeObject)(void *));

#endif