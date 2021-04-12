
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

