// #ifndef __G_TUPLE_H
// #define __G_TUPLE_H
#include "g_tuple.h"

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

TuplePtr search(int num, ...){
    va_list va_list;
    int i;

    va_start(va_list, num);
    TuplePtr h = va_arg(va_list, TuplePtr);
    char** row;
    for(i = 1; i <= num; i++){
        row[i-1] = va_arg(va_list, char*);
    }
    va_end(va_list);

    // having h and desired row characterisics, lookup.


    return h;
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



// #endif