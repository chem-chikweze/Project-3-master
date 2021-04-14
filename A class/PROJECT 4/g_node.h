#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;
typedef struct node *NodePtr;
typedef struct node *Bstptr;
typedef void (*comparePairs)(void* n, void* m);


struct node
{
    void *v;
    void *p;
    NodePtr left, right;

    comparePairs compair;

};

NodePtr createNode(void *obj1, void *obj2);
void freeNode(NodePtr node);
Bstptr createBst(int (*compareId)(const void *, const void *));
void delete (Bstptr head, NodePtr node) ;

NodePtr min_succesor(NodePtr head);

#endif