#ifndef STACK_H
#define STACK_H

typedef struct stack *plate;
struct stack
{
    char *label;
    plate next;
    int terminal;
};

plate table(char* label, char next);

plate newPlate(char* data, int t);
int isEmpty(plate top);
char* peek(plate top);
plate pop(plate top);
plate push(plate new, plate top);
void display(plate top);
int parsertable(char* terminal);
plate table(char* label, char next);
void run(int choice, char *s);
// void travleft(plate root);
void tabler(char* term);
int count = 0;

plate E_table;
plate ET_table;
plate C_table;
plate CT_table;
plate S_table;
plate ST_table;
plate A_table;
plate Ax_table;
plate X_table;


#endif