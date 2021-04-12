#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>

#define failed NULL

typedef struct node *tree;
struct node{
    char *label;
    tree leftmostchild, rightsibling, parent;
};



tree E();
tree ET();
tree C();
tree CT();
tree S();
tree ST();
tree A();
tree X();


tree makeNode0(char *x);
tree makeNode1(char *x, tree t);
tree makeNode3(char *x, tree t1, tree t2, tree t3);
tree makeNode4(char *x, tree t1, tree t2, tree t3, tree t4);
void traverse(tree root);


tree make0(tree root, char *x);



#endif