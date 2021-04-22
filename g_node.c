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
    printf("alm");
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
        while(temp!=NULL)
        {
            if((v->loc - head->v) < 0){
                temp = temp->left;
            }
            else if((v->loc - head->v) > 0){
                temp = temp->right;
            }else if((v->loc - head->v) == 0){
                return temp;
            }
        }
        return NULL;
    }
}

Bstptr insertNode(Bstptr head, Bstptr node) {
    Bstptr temp = head;
    if(node==NULL){
        printf("insert: node==null");
        return temp;
    }else if(temp==NULL){
        printf("insert: head==null");
        temp = node;
        return temp;
    }else
    {
        while(temp!=NULL)
        {
            if((node->v - head->v) < 0){
                temp = temp->left;
            }
            else if((node->v - head->v) > 0){
                temp = temp->right;
            }     
        }
        temp = node;
        printf("%d\n",head->v);
        return head;
    }
}

void deleteNode(Bstptr head, TuplePtr node) 
{
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

void printall(NodePtr head){
    printf("%d\n", head->v);
    if(head->left != NULL){
        printall(head->left);
    }
    if(head->right != NULL){
        printall(head->right);
    }
}

// int main(){
//     // NodePtr newNodex = createNode("heaven", "b");
//     // NodePtr node2x = createNode("back", "adam");

//     Bstptr hea = createBst("heaven", "b");
//     Bstptr leaf = createBst("back", "adam");
//     Bstptr leaf1 = createBst("who", "adam");
//     Bstptr leaf2 = createBst("aaman", "adam");
//     Bstptr leaf3 = createBst("oleg", "adam");

//     hea = insertNode(hea, leaf);
//     hea = insertNode(hea, leaf1);
//     hea = insertNode(hea, leaf2);
//     hea = insertNode(hea, leaf3);
//     if(hea->left != NULL){
//         printf("\nhello %s", hea->left->p);
//     }
//     // printf("\nhere is head.left's v %s", hea->left->v);
//     printf("\n");
//     printall(hea);
//     return 1;
// }