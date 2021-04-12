#ifndef TRIO_H
#define TRIO_H

#include <stdlib.h>
#include <stdio.h>

typedef struct nole *trio;
struct nole{
    char *label;
    int term;
    trio left, right;
};

trio n(plate k);
trio n0(char* lab, int t);
void display_trio(trio tree);


trio laster(trio root);
void lastleft(trio root);

void preorder(trio rt);
#endif