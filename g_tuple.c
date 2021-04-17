// #ifndef __G_TUPLE_H
// #define __G_TUPLE_H

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


TuplePtr createTuple(char* na, int l, int k){
    TuplePtr tup = (TuplePtr) malloc(sizeof(TUPLE));
    tup->name = na;
    tup->col = l;
    tup->key = k;

    tup->row = (char **) calloc(l, sizeof(char *));
    tup->next = NULL;
    
    return tup;
}

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

int hashcode(TuplePtr data){
    int kindex = data->key;
    char* k_string = data->row[kindex];
    // printf("hashcode test: %s\n", k_string);
    int sum = sum_string(k_string);
    return (int) sum/SIZE;
}

int sum_string(char* k_string){
    int sum = 0;
    int len = strlen(k_string);

    for(int i = 0; i < len; i++){
        sum += (int)k_string[i] + ( (int)k_string[i]  * pow(11, i+1));
        // printf("sum_string test: %d\n", sum);
    }
    return sum;
}

TuplePtr lookup(HashTable table, TuplePtr data){
    int hash_index = hashcode(data);

    while( table[hash_index] != NULL) {
      if(strcmp(table[hash_index]->key, data->row[data->key]) == 0){
         return table[hash_index]->value;
      }
      //go to next cell
      ++hash_index;
      //wrap around the table
      hash_index %= SIZE;
   }
   return NULL;        
}

HashTable insert(HashTable table, TuplePtr data){
    int hash_index = hashcode(data);

    while(table[hash_index] != NULL) {
      if(strcmp(table[hash_index]->key, data->row[data->key]) == 0){
         return table;
      }
      //go to next cell
      ++hash_index;
      //wrap around the table
      hash_index %= SIZE;
   }

   table[hash_index] = (struct table* )malloc(sizeof(struct table));
   table[hash_index]->key = data->row[data->key];
   table[hash_index]->value = data;

   return table;
}

TuplePtr delete(HashTable table, TuplePtr data){
    int hash_index = hashcode(data);
    while(table[hash_index] != NULL) {
        if(strcmp(table[hash_index]->key, data->row[data->key]) == 0){
            TuplePtr data_del = table[hash_index]->value;
            table[hash_index] = NULL;
            return data_del;
        }
        //go to next cell
        ++hash_index;
        //wrap around the table
        hash_index %= SIZE;
    }

    return NULL;

}

int main(){
    HashTable csgtable = (HashTable)calloc(50, sizeof(struct table));


    TuplePtr csg = createTuple("CSG", 3, 1);
    csg = fill(4, csg, "CSC 173", "3174", "A");
    csgtable = insert(csgtable, csg);

    TuplePtr a = createTuple("CSG", 3, 1);
    a = fill(4, a, "CSC 173", "1234", "B");
    csgtable = insert(csgtable, a);


    TuplePtr b = createTuple("CSG", 3, 1);
    b = fill(4, b, "CSC 173", "2567", "A");
    csgtable = insert(csgtable, b);

    TuplePtr c = createTuple("CSG", 3, 1);
    c = fill(4, c, "CSC 173", "8213", "A");
    csgtable = insert(csgtable, c);



    // printf("\nkk");
    TuplePtr temp = lookup(csgtable, csg);
    printf("\n%s", temp->name);

    TuplePtr del = delete(csgtable, csg);
    printf("\n%s", del->row[1]);

    TuplePtr nodel = lookup(csgtable, csg);
    if(nodel==NULL){
        printf("\nYay");
    }
    // printf("\n%s", nodel->name);


    // printf("\n%s", temp);
}

// #endif