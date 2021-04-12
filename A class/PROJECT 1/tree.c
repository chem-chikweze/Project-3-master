#include <stdio.h>
#include <stdlib.h>

#include "tree.h"



node* newSet(){
    node* temp = (node *)malloc(sizeof(node));
    if(temp == NULL ){
        // printf("no tree created");
        return NULL;
    }
    temp = newNodeParent(0, NULL);
    // printf("\ntree created");
    return temp;
}

node* newNodeParent(int data, node* par){
    node *s = (node *)malloc(sizeof(node));
    if(s == NULL){
        //  printf("\n-newNodeParent: null child created");
        return NULL;    
    }
    s->state = data;
    s->parent = par;
    s->left = NULL;
    s->right = NULL;
    s->balanceFactor = 0;
    //  printf("\n+newNodeParent: node %i created, parent: %i balance: %i", data, par, s->balanceFactor);
    //  printf("\n%i",s);
    return s;
}

void newTree(){
    node* state = (node *)malloc(sizeof(node));
    if(state == NULL) printf("No node created");
    //  printf("\n+newTree");
    state = newNodeParent(0, NULL);
    AVLTree->root = state;
    //  printf("\n%i",AVLTree->root);
}

void insert(int state) { 
    //  printf("\n");
    if(AVLTree->root == NULL){
        //  printf("\nSCREAAAAAAAAAAAAAAAAM");
        AVLTree->root = newNodeParent(0, NULL);
    }
    insertf(state, AVLTree->root); 
}

void insertf(int state, node* parent)
{
    if(parent == NULL){
        printf("yaya");
    }
    if(state < parent->state){
        if(parent->left == NULL){
            parent->left = newNodeParent(state, parent);
            //  printf("\nleft");
            updateBalance(parent->left);
        } else {
            insertf(state,parent->left);
        }
    }
    else if(state > parent->state){
        if(parent->right == NULL){
            parent->right = newNodeParent(state, parent);
            //  printf("\nright");
            updateBalance(parent->right);
        } else {
            insertf(state,parent->right);
        }
    } else{
        //  printf("\nAlready entered");
    }  
}

void updateBalance(node *d){
    if(d->balanceFactor > 1 || d->balanceFactor < -1){
        rebalance(d);
    }
    if(d->parent != NULL){
        if(d->balanceFactor == 0){}
        else if(isLeftChild(d)){
            d->parent->balanceFactor +=1;
            //  printf("\nupdatebal: lchild parent: %i", d->parent->balanceFactor);
        }
        else if(isRightChild(d)){
            d->parent->balanceFactor -= 1;
            //  printf("\nupdatebal : rchild parent: %i", d->parent->balanceFactor);
        }
        if(d->parent->balanceFactor != 0){
            // //  printf("\nwow %i", d->parent->balanceFactor);
            updateBalance(d->parent);
        }
    }
}

void rebalance(node * r){
    if(r->balanceFactor < 0){
        if(r->right->balanceFactor > 0){
            rotateright(r->right);
            rotateleft(r);
            // r=r->parent;
            //  printf("\nrebalance: new r is: %i", r->state);
            //  printf("\nrebalance: new r is: %i", r->parent->state);
            // printf("rebalance: new r is: %i", r->state);
            //  //  printf("\nrebalance: rl ");
        }else{
            rotateleft(r);
            //  printf("\nrebalance: l ");
        }
    }
    else if(r->balanceFactor > 0){
        if(r->left->balanceFactor < 0){
            //  printf("\nrebalance: lr ");
            rotateleft(r->left);
            //  printf("\nrebalance: lr ");
            rotateright(r);
            //  printf("\nrebalance: lr ");
        }else{
            rotateright(r);
            //  printf("\nrebalance: r ");
        }
    }
    else{}
}

void rotateleft(node *oldroot){
    node *newroot = oldroot->right;
    oldroot->right = newroot->left;
    if(newroot->left != NULL){
        newroot->left->parent = oldroot;
    }
    newroot->parent = oldroot->parent;
    if(newroot->parent == NULL){
        AVLTree->root = newroot;
    } else if(isLeftChild(oldroot)){
        oldroot->parent->left = newroot;
    }else{
        oldroot->parent->right = newroot;
    }
    newroot->left = oldroot;
    oldroot->parent = newroot;
    // printf("\nrotateleft: newroot %i lefts %i rights: %i", newroot->state, newroot->left->state, newroot->right->state);
    // printf("\n haha: %i, %i, %i", newroot->balanceFactor, newroot->left->balanceFactor, newroot->right->balanceFactor);
    // printf("\nalmost: %i, %i, %i, %i", newroot->balanceFactor, oldroot->balanceFactor, max(newroot->balanceFactor, 0), min(oldroot->balanceFactor, 0));
    int A = oldroot->balanceFactor;
    int B = newroot->balanceFactor;
    oldroot->balanceFactor = A + 1 - min(B, 0);
    newroot->balanceFactor = B + 1 + max(oldroot->balanceFactor, 0);
    printf("\n thaha: %i, %i", newroot->balanceFactor, newroot->left->balanceFactor);//, newroot->right->balanceFactor);
    if(newroot->parent != NULL){
        // printf("\n thaha: %i, %i, %i", newroot->state, newroot->left->state, newroot->parent->state);
    }//, newroot->right->balanceFactor);
    // printf("\n thaha: %i, %i, %i", newroot->balanceFactor, newroot->left->balanceFactor, newroot->right->balanceFactor);
    // printf("\n thaha: %i, %i, %i", oldroot->parent->state, oldroot->state, oldroot->parent->right->state);
    // if(newroot->state == 1){
    //     printf("\ndone: %i %i", newroot->left->state, newroot->right->state);
    //     printf("\ndone2: %i %i %i", newroot->balanceFactor, newroot->left->balanceFactor, newroot->right->balanceFactor);
    // }

}

void rotateright(node *oldroot){
    node *newroot = oldroot->left;
    oldroot->left = newroot->right;
    
    if(newroot->right != NULL){
        newroot->right->parent = oldroot;
    }
    newroot->parent = oldroot->parent;
    if(newroot->parent == NULL){
        AVLTree->root = newroot;
    }else if(isLeftChild(oldroot)){
        oldroot->parent->left = newroot;
    }else{
        oldroot->parent->right = newroot;
    }

    newroot->right = oldroot;
    oldroot->parent = newroot;
    // printf("\nrotateright %i %i", oldroot->balanceFactor, newroot->balanceFactor);
    // printf("\nrotateright %i %i", oldroot->state, newroot->state);

    // printf("\nalmost: %i, %i, %i, %i", newroot->balanceFactor, oldroot->balanceFactor, max(newroot->balanceFactor, 0), min(oldroot->balanceFactor, 0));

    int A = oldroot->balanceFactor;
    int B = newroot->balanceFactor;
    oldroot->balanceFactor = A - 1 - max(B, 0);
    newroot->balanceFactor = B - 1 + min(oldroot->balanceFactor, 0);

    // printf("\n haha: %i, %i", newroot->balanceFactor, newroot->right->balanceFactor);//, newroot->right->balanceFactor);
    // printf("\n haha: %i, %i", newroot->state, newroot->right->state);//, newroot->right->balanceFactor);

    // printf("\n thaha: %i, %i, %i", newroot->balanceFactor, newroot->left->balanceFactor, newroot->right->balanceFactor);
    // printf("\n thaha: %i, %i, %i", oldroot->parent->state, oldroot->state, oldroot->parent->left->state);
}

bool isLeftChild(node *d){
    if(d->parent != NULL && d->parent->left == d) return true;
    return false;
}

bool isRightChild(node *d){
    if(d->parent != NULL && d->parent->right == d) return true;
    return false;
}

bool isEmpty() { 
    if(AVLTree == NULL){
        // printf("\ntree does not exist yet."); 
        return true;
    }else{return AVLTree->root == NULL; }
}
void makeEmpty() { 
    makeEmptyf(AVLTree->root);
}
void makeEmptyf(node* set) { 
    if(set == NULL){
        // printf("\ntree does not exist yet."); 
        return;
    }else{
        set = NULL; 
    }
}


int max(int lhs, int rhs){
    if(lhs>rhs) return lhs;
    return rhs;
}

int min(int lhs, int rhs){
    if(lhs<rhs) return lhs;
    return rhs;
}

bool search(int val)
{
    return searchf(AVLTree->root, val);
}

bool searchf(node * r, int val){
    bool found = false;
    while ((r != NULL) && !found)
    {
        int rval = r->state;
        if (val < rval)
            r = r->left;
        else if (val > rval)
            r = r->right;
        else
        {
            found = true;
            break;
        }
        found = searchf(r, val);
    }
    return found;
}

void preorder(){
    preorderf(AVLTree->root);
}
void preorderf(node* r)
{
    if (r != NULL)
    {
        printf("\npre %i ",r->state);
        preorderf(r->left);
        preorderf(r->right);
    }else return;
}


void postorder(){
    postorderf(AVLTree->root);
}
void postorderf(node* r)
{
    if (r != NULL)
    {
        postorder(r->left);
        postorder(r->right);
        printf("\npost %i \n",r->state);
    }else return;
}

void inorder(){
    inorderf(AVLTree->root);
}
void inorderf(node* r)
{
    if (r != NULL)
    {
        inorderf(r->left);
        printf("\nyay %i \t",r->state);
        inorderf(r->right);
    }else return;
}

/*
int main(){
    // makeEmpty();
    newTree();
    // insert(7);
    insert(1);
    insert(-1);

    insert(11);
    insert(2);
    insert(5);
    insert(6);
    insert(7);
    insert(-23);
    insert(1);
    insert(1);
    insert(1);
    insert(-34);
    inorder();
    // insert(2);
    // int a = search(92);
    // printf("\n%i", a);
    // insert(3);
    // insert(1);

    
    // insert(0);
    // insert(-1);

    // inorder();
    // printf("%i", AVLTree->root->state);

}

    // if(oldroot == AVLTree->root){
    //     AVLTree->root = newroot;
    // }else{
    //     if(isLeftChild(oldroot)){
    //         oldroot->parent->left = newroot;
    //     }else{
    //         oldroot->parent->right = newroot;
    //     }
    // }



    // insert(92);
    // insert(-1);
    // insert(2);
    // // printf("\n");
    


    // insert(5);
    // insert(6);
    // insert(7);
    // insert(1);
    // insert(1);
    // insert(1);
    // insert(1);
    // insert(19);

    // if(AVLTree->root->left == NULL){
    //     printf("\n root left %i ", AVLTree->root->state);
    // }
    references;
    https://courses.cs.washington.edu/courses/cse373/06sp/handouts/lecture12.pdf
    https://www.freecodecamp.org/news/avl-tree-insertion-rotation-and-balance-factor/

    */