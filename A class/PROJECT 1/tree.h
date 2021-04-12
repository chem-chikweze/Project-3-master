#ifndef TREE_H
#define TREE_H

typedef int bool;
typedef struct avl node;

#define red 0
#define noir 1
#define true 1
#define false 0

struct avl{
    int state;
    int balanceFactor;

    node *left;
    node *right;
    node *parent;
};


struct avl_t{
    node *root;
};
typedef struct avl_t tree;
tree t;
tree *AVLTree = &t;

node *newNode();
void newTree();
node* newSet();
node* newNodeParent(int data, node* par);

void insertf(int state, node *t);
void  insertwithParent(int state, node *parent, node* child);

void updateBalance(node *d);
bool isLeftChild(node *t);
bool isRightChild(node *t);

int min(int lhs, int rhs);
int max(int lhs, int rhs);

void rebalance(node * r);
void rotateleft(node *oldroot);
void rotateright(node *oldroot);

int height(struct avl *x);
void insertf(int state, node *t);
void rebalance(node *t);

void makeEmptyf(node* set);

bool searchf(struct avl* r, int val);
void inorder();
void preorder();
void postorder();
void inorderf(struct avl* r);
void preorderf(struct avl* r);
void postorderf(struct avl* r);




// int height(avl);
// int difference(avl);

// struct avl rr_rotate(avl );
// struct avl ll_rotate(avl );
// struct avl lr_rotate(avl );
// struct avl rl_rotate(avl );

// struct avl balance(avl );
// struct avl insert(char* key );

// void show(avl );
// void inorder(avl );
// void preorder(avl );
// void postorder(avl );


#endif 
