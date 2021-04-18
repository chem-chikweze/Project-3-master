#ifndef __G_TUPLE_H
#define __G_TUPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

// typedef struct unit_pew *col_ptr;
// struct unit_pew{
//     enum {is_int, is_float, is_str} type;
//     union{int i_val; float f_val; char* s_val;}val;
//     // row next;
// };
int SIZE = 1009;

// a tuple struct
typedef struct tuple TUPLE;
typedef struct tuple *TuplePtr;
struct tuple{
    char* name;
    int col;
    int key;
    char** row;
    TuplePtr next;

    // col_ptr row;
};

// the hashtable of tuple structures
typedef struct table** HashTable;
struct table{
    char* key;
    TuplePtr value;
};

TuplePtr createTuple(char* na, int l, int k);
TuplePtr fill(int num, ...);
int hashcode(TuplePtr data);
int sum_string(char* k_string);



#endif