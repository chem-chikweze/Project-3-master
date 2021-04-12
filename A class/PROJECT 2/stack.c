#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.c"
#include "queue.c"
#include "stack.h"
#include "trio.c"

plate newPlate(char *data, int t)
{
    plate temp = (plate)malloc(sizeof(struct stack));
    temp->label = data;
    temp->next = NULL;
    temp->terminal = t;
    return temp;
}

int isEmpty(plate top)
{
    if (top == NULL)
    {
        //printf"\nisEmpty: 1");
        return 1;
    }
    else
    {
        return 0;
        //printf"\nisEmpty: 0");
    }
}

char *peek(plate top)
{
    if (isEmpty(top) == 0)
    {
        //printf"\nPeek: 1 %s", top->label);
        return top->label;
    }
    else
    {
        //printf"\nPeek: 0 empty");
        return NULL;
    }
}

plate pop(plate top)
{
    if (isEmpty(top))
    {
        //printf"\nPop: 0 empty");
        return NULL;
    }
    else
    {
        //printf"\nPop: 1 pop: %s", top->label);
        top = top->next;
        // //printf"\nPop: 1 pop: %s", top->label);
        //printf"\nPop: 1 newtop: %s", top->label);
        return top;
    }
}

// plate push(char* data, plate top){
//     plate new = newPlate(data);
//     if(new == NULL || data == NULL){
//         //printf"\nPush: 0 null arg");
//         return NULL;
//     }
//     plate temp = top;
//     top = new;
//     top->next = temp;
//     // //printf"\nPush: 1 %s", top->next->label);
//     return top;
// }

plate push(plate new, plate top)
{
    if (new == NULL || top == NULL)
    {
        //printf"\nPush: 0 null arg");
        return NULL;
    }
    plate temp = top;
    top = new;
    // top->next = (plate) malloc(sizeof(struct stack));
    top->next = temp;
    // //printf"\nPush: 1 %s", top->label);
    return top;
}

plate push2(plate new, plate top)
{
    if (new == NULL || top == NULL)
    {
        //printf"\nPush: 0 null arg");
        return NULL;
    }
    plate temp = new;
    plate tnext;
    while (temp != NULL)
    {
        tnext = temp->next;
        top = push(temp, top);
        //printf"\nPush: 1 %s", top->label);
        temp = tnext;
    }
    return top;
}

void display(plate top)
{
    plate temp = top;
    while (temp != NULL)
    {
        //printf"\nDIS: %s", temp->label);
        temp = temp->next;
    }
}

plate Stack;
trio parsetree;

void syntactic()
{
    E_table = newPlate("C", 0);
    E_table = push(newPlate("ET", 0), E_table);

    ET_table = newPlate("|", 1);
    ET_table = push(newPlate("E", 0), ET_table);

    C_table = newPlate("S", 0);
    C_table = push(newPlate("CT", 0), C_table);

    CT_table = newPlate(".", 1);
    CT_table = push(newPlate("C", 0), CT_table);

    S_table = newPlate("A", 0);
    S_table = push(newPlate("ST", 0), S_table);

    ST_table = newPlate("*", 1);
    ST_table = push(newPlate("ST", 0), ST_table);

    A_table = newPlate("(", 1);
    A_table = push(newPlate("E", 0), A_table);
    A_table = push(newPlate(")", 1), A_table);

    Ax_table = newPlate("X", 0);
    
    
    X_table = newPlate("X", 1);


    //printf"\nsyntactic");
}

plate table(char *label, char next)
{
    if (strcmp(label, "E") == 0)
    {
        if (next == '(' || (next >= 'a' && next <= 'z'))
        {
            return E_table;
        }
        else if (next == ')' || next == '$'  )
        {
            plate empty = newPlate("eps", 1);
            return empty;
        }
        
        else
        {
            return NULL;
        }
    }
    if (strcmp(label, "ET") == 0)
    {
        if (next == '|')
        {
            return ET_table;
        }
        else if (next == ')' || next == '$'   )//(next >= 'a' && next <= 'z'))
        {
            plate empty = newPlate("eps", 1);
            return empty;
        }
        else
        {
            return NULL;
        }
    }

    if (strcmp(label, "C") == 0)
    {
        if (next == '(' || (next >= 'a' && next <= 'z'))
        {
            return C_table;
        }
        else if (next == ')' || next == '.' ||next == '$' )
        {
            plate empty = newPlate("eps", 1);
            return empty;
        }
        else
        {
            return NULL;
        }
    }

    if (strcmp(label, "CT") == 0)
    {
        if (next == '.')
        {
            return CT_table;
        }
        else if (next == ')' || next == '.' ||next == '$' )//|| (next >= 'a' && next <= 'z'))
        {
            plate empty = newPlate("eps", 1);
            return empty;
        }
        else
        {
            return NULL;
        }
    }

    if (strcmp(label, "S") == 0)
    {
        if (next == '(' || (next >= 'a' && next <= 'z'))
        {
            return S_table;
        }
        else if (next == ')' || next == '.' ||next == '$' )
        {
            plate empty = newPlate("eps", 1);
            return empty;
        }
        else
        {
            return NULL;
        }
    }

    if (strcmp(label, "ST") == 0)
    {
        if (next == '*')
        {
            return ST_table;
        }
        else if (next == ')' || next == '.' ||next == '$' )
        {
            plate empty = newPlate("eps", 1);
            return empty;
        }
        // else if ( next == ')'|| next == '$' || (next >= 'a' && next <= 'z')) //next == '|'|| next == '.'||  (next >= 'a' && next <= 'z'))
        // {
        //     plate empty = newPlate("eps", 1);
        //     return empty;
        // }
        else
        {
            return NULL;
        }
    }

    if (strcmp(label, "A") == 0)
    {
        if (next == '(') // || (next >= 'a' && next <= 'z'))
        {
            return A_table;
        }
        else if ((next >= 'a' && next <= 'z'))
        {
            return Ax_table;
        }
        else if (next == ')' || next == '.' ||next == '$' )
        {
            plate empty = newPlate("eps", 1);
            return empty;
        }
        else
        {
            return NULL;
        }
    }

    if (strcmp(label, "X") == 0)
    {
        // return NULL;
        if ((next >= 'a' && next <= 'z'))
        {
            char *ptr = malloc(2 * sizeof(char));
            ptr[0] = next;
            ptr[1] = '\0';
            //printf"\nkchar %s ", ptr);
            return newPlate(ptr, 1);
        }
        else if (next == ')' || next == '.' ||next == '$' )
        {
            plate empty = newPlate("eps", 1);
            return empty;
        }
        else
        {
            return NULL;
        }
    }
}

int parsertable(char *entry)
{
    char* terminal = entry;
    Stack = newPlate("$", 0);
    Stack = push(newPlate("E", 0), Stack);
    display(Stack);
    //printf"\nfirst");
  
    // char* terminal;
    char next = *terminal;
    parsetree = n(Stack);
    while (strcmp(Stack->label, "$") != 0)
    {
        syntactic();
        // //printf"\nL is : %s", last->label);
        
        if (Stack->terminal == 1)
        {
            
            // lastleft(parsetree);
            // //printf"\nWow: %s", last->label);
            if (strcmp(Stack->label, "eps") == 0)
            {
                Stack = pop(Stack);
            }else{
                //printf"\nterminal: %s %c", Stack->label, next);
                char *ptr = malloc(2 * sizeof(char));
                ptr[0] = next;
                ptr[1] = '\0';
                if (strcmp(Stack->label, ptr) == 0)
                {
                    Stack = pop(Stack);
                    //printf"\nbinally: %c", next);
                    terminal = terminal +1;
                    next = *terminal;
                    if(next == '\0'){
                        next = '$';
                    }

                    // display(Stack);
                    //printf"\nfinally: %c", next);
                }
                else
                {
                    //printf"\nwhere are we: stack: %s char %s", Stack->label, ptr);
                    //printf"\nFailed parsing: different terninals");
                    return 0;
                }
            }
        }
        else if (!Stack->terminal)
        {
            
            //printf"\nstack label: %s char: %c", Stack->label, next);
            if (table(Stack->label, next) == NULL)
            {
                //printf"\nFailed parsing: no table entry");
                return 0;
            }
            else
            {
                lastleft(parsetree);
                plate syn = newPlate("@", 0);
                syn = push2(table(Stack->label, next), syn);
                //printf"\nSynlabel: %s",syn->label);
                
                if(last != NULL){
                    //printf"\naww %s", last->label);
                    if(strcmp(syn->label, "@") != 0){
                        last->left = n(syn);
                        syn = syn->next;
                        //printf"\t %s", last->left->label);
                        if(strcmp(syn->label, "@") != 0){
                            last->left->right = n(syn);
                            syn = syn->next;
                            //printf"\t %s", last->left->right->label);
                            if(strcmp(syn->label, "@") != 0){
                                last->left->right->right =n(syn);
                                syn = syn->next;
                                //printf"\t %s", last->left->right->right->label);
                            }
                        }
                    }
                }
                
                // insert(lastleft(parsetree), syn);
                syntactic();
                syn = table(Stack->label, next);
                //printf"\nSynlabel again: %s",syn->label);
                Stack = pop(Stack);
                
                Stack = push2(syn, Stack);

                // travleft(parsetree);
                               
            }
        }
    }
    //printf"\nHappily parsed\n");
    return 1;
}

void tabler(char* term){
    syntactic();
    char *terminal = term;
    int parse = parsertable(terminal);
    display_trio(parsetree);
}

void run(int choice, char *s){
    
    char quit[] = "quit";
    if(strcmp(s, quit) == 0){
        return ;
    }
    switch (choice){
    case 1:
        recursive(s);
        break;
    case 2:
        tabler(s);
        break;
    }
}
int main()
{
    char *s = malloc(sizeof(char *));
    puts("CSC 173 Project 1 by Chukwubuikem Chikweze");
    printf("\tRecursive descent ");
    printf("\n\tEnter an input (\"quit\" to quit): ");
    scanf("%s", s);
    run(1, s);

    printf("\tTable driven ");
    printf("\n\tEnter an input (\"quit\" to quit): ");
    scanf("%s", s);
    run(2, s); 

    printf("Enter \"quit\" to not repeat");

    return 22;
}