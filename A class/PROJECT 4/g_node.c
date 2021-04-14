
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

void freeNode(NodePtr node)
{
    if (node == NULL)
        return;
    free(node->p);
    free(node->v);
    free(node);
}

Bstptr createBst(int (*comparison_function)(const void *, const void *))
{
    Bstptr temp;
    temp = (Bstptr)malloc(sizeof(NODE));
    temp->v = NULL;
    temp->p = NULL;
    temp->left = NULL;
    temp->right = NULL;
    temp->compair = comparison_function;
    return temp;
}

Bstptr lookup(Bstptr head, void *v)
{
    Bstptr temp = head;
    if (head == NULL)
        return NULL;
    if(v == NULL) return NULL;

    while (temp->compair(head->v, v) != 0)
    {
        if(temp->compair(head->v, v) < 0){
            head = head->left;
        }
        else if(temp->compair(head->v, v) > 0){
            head = head->right;
        }
        if(head==NULL) return NULL;
    }
    return head;
}

void insert(Bstptr head, NodePtr node) {
    NodePtr temp = head;
    if(node==NULL){
        printf("insert: node empty");
        return;
    }
    if(head==NULL){
        head = node;
    }
    while(head!=NULL){
        if(temp->compair(head->v, node->v) < 0){
            head = head->left;
        }
        else if(temp->compair(head->v, node->v) > 0){
            head = head->right;
        }
    }
    head = node;
}

void delete (Bstptr head, NodePtr node) 
{
    NodePtr to_be_deleted = lookup(head, node->v);
    // null null
    if(to_be_deleted->left == NULL && to_be_deleted->right == NULL){
        to_be_deleted = NULL;
    }
    // left null
    else if(to_be_deleted->left != NULL && to_be_deleted->right == NULL){
        to_be_deleted = to_be_deleted->left;
        to_be_deleted->left = NULL;
    }
    // null right
    else if(to_be_deleted->left == NULL && to_be_deleted->right != NULL){
        to_be_deleted = to_be_deleted->right;
        to_be_deleted->right = NULL;
    }
    // left right
    else {
        NodePtr succ = min_succesor(to_be_deleted);
        if(succ == NULL){
            printf("delete: something went wrong in min_successor");
            return;
        }
        succ->left = to_be_deleted->left;
        succ->right = to_be_deleted->right;
        to_be_deleted = succ;
        succ = NULL;
    }
}

NodePtr min_succesor(NodePtr head)
{
    if(head == NULL) return NULL;
    if(head->right != NULL)
    {
        NodePtr hright = head->right;
        while(hright->left != NULL)
        {
            hright = hright->left;
        }
        return hright;
    }
    return NULL;
}

// int compareInt(const void* n, const void* m) {
//     return (int) n + (int)m;
// }
// int (*functionPtr)(int,int);

// functionPtr = &addInt;

int compareInt(const void *x, const void *y)
{
    NodePtr a = (NodePtr)x;
    NodePtr b = (NodePtr)y;

    return (int)b->v - (int)a->v;
    // return (*(int *)x) - (*(int *)y);
}

// int *compareId(const void *x, const void *y)
// {
//     // COULD BE DANGEROUS AS WE ARE ASSIGNING GENERIC "v" TO "int"
//     // int k1, k2;
//     // k1 = (int) ((NodePtr)x)->v;
//     // k2 = (int) ((NodePtr)y)->v;
//     // return (k1 - k2)&;
//     return 0;
// }


int main(){
    printf("Test");
    Bstptr csg = createBst((compareInt));
    return 1;
}