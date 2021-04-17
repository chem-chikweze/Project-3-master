// #ifndef __G_TUPLE_H
// #define __G_TUPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// typedef struct unit_pew *col_ptr;
// struct unit_pew{
//     enum {is_int, is_float, is_str} type;
//     union{int i_val; float f_val; char* s_val;}val;

//     // row next;
// };

typedef struct tuple TUPLE;
typedef struct tuple *TuplePtr;
struct tuple{
    char* name;
    int col;
    char** row;
    TuplePtr next;

    // col_ptr row;
};

TuplePtr createTuple(char* na, int l){
    TuplePtr tup = (TuplePtr) malloc(sizeof(TUPLE));
    tup->name = na;
    tup->col = l;

    tup->row = (char **) calloc(l, sizeof(char *));
    tup->next = NULL;
    
    return tup;
}

// TuplePtr fillTuple(TuplePtr tup ){
// }

TuplePtr fill(int num, ...){
    va_list va_list;
    int i;

    va_start(va_list, num);

    TuplePtr h = va_arg(va_list, TuplePtr);

    for(i = 1; i <= h->col; i++){
        h->row[i-1] = va_arg(va_list, char*);
    }

    va_end(va_list);
    return h;
}

int main(){
    TuplePtr csg = createTuple("CSG", 3);
    csg = fill(3, csg, "CSC 173", "31531764", "A");
    printf("%s", csg->row[0]);
}

// #endif