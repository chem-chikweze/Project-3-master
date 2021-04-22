#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "g_tuple.h"

typedef struct node NODE;
typedef struct node *NodePtr;
typedef struct node *Bstptr;

struct node
{
    int v;
    TuplePtr p;
    NodePtr left, right;

    int (*compareStr)(const void *, const void *);
    void (*freeObject)(void *);
    // char *(*toString)(void *);
};

NodePtr createNode(void *obj1, void *obj2);
void freeNode(NodePtr node, void (*freeObject)(void *));
Bstptr createBst(int obj1, TuplePtr obj2);
void deleteNode (Bstptr head, TuplePtr node) ;
NodePtr lookupNode(Bstptr head, TuplePtr v);
NodePtr min_succesor(NodePtr head);

#endif