
#include "g_node.h"

NodePtr createNode(void *obj1, void *obj2)
{
    NodePtr temp = (NodePtr)malloc(sizeof(NODE));
    temp->v = obj1;
    temp->p = obj2;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void freeNode(NodePtr node, void (*freeObject)(void *))
{
    if (node == NULL)
        return;
    (*freeObject)(node->p);
    (*freeObject)(node->v);
    free(node);
}

Bstptr createList(int (*compareId)(const void *, const void *),
                  char *(*toString)(void *),
                  void (*freeObject)(void *))
{
    Bstptr temp;
    temp = (Bstptr)malloc(sizeof(NODE));
    temp->v = NULL;
    temp->p = NULL;
    temp->left = NULL;
    temp->right = NULL;
    temp->compareTo = compareId;
    temp->toString = toString;
    temp->freeObject = freeObject;
    return temp;
}

int *compareInt(const void *x, const void *y)
{
    return (*(int *)x) - (*(int *)y);
}

int *compareId(const void *x, const void *y)
{
    // COULD BE DANGEROUS AS WE ARE ASSIGNING GENERIC "v" TO "int"
    int k1, k2;
    k1 = ((NodePtr)x)->v;
    k2 = ((NodePtr)y)->v;
    return k1 - k2;
}

Bstptr lookup(Bstptr head, void *v)
{
    if (head == NULL)
        return NULL;

    while (compareTo(head->v, v) != 0)
    {
        /* code */
    }
}
void insert(Bstptr t, NodePtr node) {}
int delete (Bstptr t, void *v) {}