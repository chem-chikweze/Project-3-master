#include "g_BST.h"

Bstptr createList(int (*compareId)(const void *, const void *),
                  char *(*toString)(void *),
                  void (*freeObject)(void *))
{
    Bstptr temp;
    temp = (Bstptr)malloc(sizeof(BST));
    temp->head = NULL;
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

Bstptr lookup(Bstptr t, void *v)
{
    if (t == NULL)
        return NULL;
    if (t->head == NULL)
        return NULL;

    while (compareTo(t->head->v, v))
    {
        /* code */
    }
}
void insert(Bstptr t, NodePtr node) {}
int delete (Bstptr t, void *v) {}