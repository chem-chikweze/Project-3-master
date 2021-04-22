#include "g_node.h"

void freeNode(NodePtr node, void (*freeObject)(void *))
{
    if (node == NULL)
        return;
    (*freeObject)(node->p);
    free(node);
}

void freeObject(void* node){
    free(node);
}



Bstptr createBst(int obj1, TuplePtr obj2)
{
    Bstptr temp = (Bstptr)malloc(sizeof(NODE));
    temp->v = obj1;
    temp->p = obj2;
    temp->left = NULL;
    temp->right = NULL;
    // temp->toString = toString;
    return temp;
}
Bstptr newBst(Bstptr obj2)
{
    Bstptr temp = (Bstptr)malloc(sizeof(NODE));
    temp->v = obj2->v;
    temp->p = obj2->p;
    temp->left = obj2->left;
    temp->right = obj2->right;
    // temp->toString = toString;
    return temp;
}

NodePtr lookupNode(Bstptr head, TuplePtr v)
{
    Bstptr temp = head;
    if(v==NULL){
        printf("insert: node==null");
        return NULL;
    }else if(temp==NULL){
        printf("insert: head==null");
        return NULL;
    }else
    {
        printf("here");
        while(temp!=NULL)
        {
            if((v->loc - head->v) < 0){
                printf("\nlookupnode: loc: %d", v->loc);
                temp = temp->left;
            }
            else if((v->loc - head->v) > 0){
                printf("\nlookupnode: rloc: %d", v->loc);
                temp = temp->right;
            }else if((v->loc - head->v) == 0){
                return temp;
            }
        }
        printf("\nlookupnode: 3null");
        return NULL;
    }
}

Bstptr insertNode(Bstptr head, Bstptr node) 
{ 
    if(head == NULL)
    {
        return newBst(node);
    }

    if((node->p->loc - (head)->p->loc) < 0)
    {
        head->left = insertNode((head)->left, node);
    }
    else if((node->p->loc - (head)->p->loc) > 0)
    {
        head->right = insertNode((head)->right, node);            
    }
    // printf("U %d %d\n", head->v, node->v);
    return head;
     
}    


void deleteNode(Bstptr head, TuplePtr node) 
{
    printf("\n");
    printTuple(node);

    NodePtr to_be_deleted = lookupNode(head, node);
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

void printTree(NodePtr head){
    printf("%s", head->p->row[0]);
    if(head->left != NULL){
        printTree(head->left);
    }
    if(head->right != NULL){
        printTree(head->right);
    }
}