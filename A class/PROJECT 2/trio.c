
#include "trio.h"
trio n(plate k){
    trio root;
    root = (trio) malloc(sizeof(struct nole));
    root->label = k->label;
    root->term =k->terminal;
    root->left = NULL;
    root->right = NULL;
    return root;
}

trio n0(char* lab, int t){
    trio root;
    root = (trio) malloc(sizeof(struct nole));
    root->label = lab;
    root->term =t;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void display_trio(trio root){
    if(root == NULL){
        return;
    }

    while (root)
    {
        //printf"  ");
        if(root->label != NULL){
            printf("\n%s ", (root->label));
        }

        if(root->left){
            //printf"  ");
            display_trio(root->left);
        }
        //printf"  ");
        root = root->right;
    }
}

trio last;
void lastleft(trio root){

    preorder(root);
    
    // / last = NULL;
    // if(root == NULL){
    //     //printf"\nKo syn");
    //     return ;
    // }
    // last = NULL;
    // last = laster(root);
    // if(last == NULL){
    //     trio t = root;
    //     while(t != NULL){
    //         laster(t);
    //         t = t->right;
    //     }
    // }else{
    //     return;
    // }
}

void preorder(trio rt) {
    
  
  if(rt->term == 0 && rt->left == NULL){
      last = rt;
      return;
  }
  if (rt->left != NULL) {
    trio temp = rt->left;
    last = laster(temp);
    if(last != NULL) return;
    while (temp != NULL) {
      preorder(temp);
      temp = temp->right;
    }
  }
}


trio laster(trio root){
    if(root == NULL){
        //printf"No syn");
        return NULL;
    }else if(root->term == 1){
        if(root->right != NULL){
            return laster(root->right);
        }else{
            //printf"\n1No syn %s", root->label);
            return NULL;
        }
    }else if(root->term == 0){
        if(root->left != NULL){
            return laster(root->left);
        }else
            return root;
    }
}