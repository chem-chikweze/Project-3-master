#include "g_node.h"

typedef struct bst BST;
typedef struct bst *Bstptr;

struct bst
{
    NodePtr head;

    int (*compareTo)(const void *, const void *);
    void (*freeObject)(void *);
    char *(*toString)(void *);
};

/* constructor */
Bstptr createBST(int (*compareTo)(const void *, const void *),
                  char *(*toString)(void *),
                  void (*freeObject)(void *));

Bstptr lookup(Bstptr t, void *v);
void insert(Bstptr t, NodePtr node);
int delete (Bstptr t, void *v);
