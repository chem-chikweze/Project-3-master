#include "g_node.h"
// typedef *compareStr comp;
// typedef *freeObject freed;



// NodePtr createNode(void *obj1, void *obj2)
// {
//     NodePtr temp = (NodePtr)malloc(sizeof(NODE));
//     temp->v = obj1;
//     temp->p = obj2;
//     temp->left = NULL;
//     temp->right = NULL;
//     return temp;
// }

void freeNode(NodePtr node, void (*freeObject)(void *))
{
    if (node == NULL)
        return;
    (*freeObject)(node->p);
    (*freeObject)(node->v);
    free(node);
}

void freeObject(void* node){
    free(node);
}

Bstptr createBst(void *obj1, void *obj2, int (*comparer)(const void *, const void *),
                  void (*freeer)(void *))
{
    Bstptr temp = (Bstptr)malloc(sizeof(NODE));
    temp->v = obj1;
    temp->p = obj2;
    temp->left = NULL;
    temp->right = NULL;
    temp->compareStr = comparer;
    // temp->toString = toString;
    temp->freeObject = freeer;
    return temp;
}

int compareInt(const void *x, const void *y)
{
    int a = (int)(((NodePtr)x)->v);
    int b = (int)(((NodePtr)y)->v);
    // a is new node
    // b is present old node
    return (int)(a-b);
}

int compareStr(const void *x, const void *y)
{
    char* a = (char*)(((NodePtr)x)->v);
    char* b = (char*)(((NodePtr)y)->v);
    return strcmp(a,b);
}

Bstptr lookup(Bstptr head, void *v)
{
    if (head == NULL)
        return NULL;
    if(v == NULL) return NULL;

    while (compareStr(v, head->v) != 0)
    {
        if(compareStr(v, head->v) < 0){
            head = head->left;
        }
        else if(compareStr(v, head->v) > 0){
            head = head->right;
        }
        if(head==NULL) return NULL;
    }
    return head;
}

Bstptr insert(Bstptr head, Bstptr node) {
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
            if(compareStr(node, temp) < 0){
                if (temp->left==NULL){
                    temp->left = node;
                    break;
                }else{
                    temp = temp->left;
                }
            }
            else if(compareStr(node, temp) > 0){
                if (temp->right == NULL){
                    temp->right = node;
                    break;
                }else
                {
                    temp = temp->right;
                }
                
            }     
        }
        printf("%s\n",head->left->v);
        return head;
    }   
}

void inserti(Bstptr head, Bstptr node) {
    if(node==NULL){
        printf("insert: node empty");
        return;
    }
    if(head==NULL){
        head = node;
    }
    while(head!=NULL){
        if(compareInt(node, head) < 0){
            head = head->left;
        }
        else if(compareInt(node, head) > 0){
            head = head->right;
        }
    }
    head = node;
}

void delete(Bstptr head, NodePtr node) 
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

void printall(NodePtr head){
    printf("%s\n", head->v);
    if(head->left != NULL){
        printall(head->left);
    }
    if(head->right != NULL){
        printall(head->right);
    }
}

int main(){
    // NodePtr newNodex = createNode("heaven", "b");
    // NodePtr node2x = createNode("back", "adam");

    Bstptr hea = createBst("heaven", "b", (*compareStr), (*freeObject));
    Bstptr leaf = createBst("back", "adam", (*compareStr), (*freeObject));
    Bstptr leaf1 = createBst("who", "adam", (*compareStr), (*freeObject));
    Bstptr leaf2 = createBst("aaman", "adam", (*compareStr), (*freeObject));
    Bstptr leaf3 = createBst("oleg", "adam", (*compareStr), (*freeObject));

    hea = insert(hea, leaf);
    hea = insert(hea, leaf1);
    hea = insert(hea, leaf2);
    hea = insert(hea, leaf3);
    if(hea->left != NULL){
        printf("\nhello %s", hea->left->p);
    }
    // printf("\nhere is head.left's v %s", hea->left->v);
    printf("\n");
    printall(hea);
    return 1;
}