// #ifndef __G_TUPLE_H
// #define __G_TUPLE_H

#include "g_node.h"
#include "g_node.c"


TuplePtr createTuple(char* na, int l, int k){
    TuplePtr tup = (TuplePtr) malloc(sizeof(TUPLE));
    tup->name = na;
    tup->col = l;   // number of columns
    tup->key = k;   // primary key

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

TuplePtr lookup(int num, ...){
    va_list va_list;
    int i;

    va_start(va_list, num);
    HashTable table = va_arg(va_list, HashTable);
    int key = va_arg(va_list, int);

    char** row = (char **) calloc(num-2, sizeof(char *));
    for(i=2; i <num; i++){
        row[i-2] = va_arg(va_list, char*);
        // printf("%s", row[i-2]);
    }

    int hash_index = hash(row[key]);
    // printf("%d", hash_index);
    while( table[hash_index] != NULL) {
      if(strcmp(table[hash_index]->key, row[key]) == 0){
          TuplePtr tuple = table[hash_index]->value;
          int j = tuple->col;

          for(int i =0; i< j; i++){
              if(strcmp(tuple->row[i], row[i]) != 0 ){
                  if(strcmp(row[i], "*") != 0){
                      printf("hull");
                      return NULL;
                  }
              }
          }
          printTuple(table[hash_index]->value);
          return table[hash_index]->value;
      }
      //go to next cell
      ++hash_index;
      //wrap around the table
      hash_index %= SIZE;
   }
   printf("null");
   return NULL;
}

int hashcode(TuplePtr data){
    int kindex = data->key;
    char* k_string = data->row[kindex];
    // printf("hashcode test: %s\n", k_string);
    int sum = sum_string(k_string);
    data->loc = (int) sum/SIZE;
    return (int) sum/SIZE;
}

int hash(char* data){
    // printf("hashcode test: %s\n", k_string);
    int sum = sum_string(data);
    return (int) sum/SIZE;
}

void printTuple(TuplePtr data){
    char** dpoints = data->row;
    int size = data->col;
    printf("Tuple: \t");
    for(int i=0; i< size; i++){
        printf("  %s", dpoints[i]);
    }
    printf("\n");
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

TuplePtr search(HashTable table, TuplePtr data){
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

TuplePtr deleted(HashTable table, TuplePtr data){
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

TuplePtr delete(int num, ...){
    va_list va_list;
    int i;

    va_start(va_list, num);
    HashTable table = va_arg(va_list, HashTable);
    int key = va_arg(va_list, int);

    char** row = (char **) calloc(num-2, sizeof(char *));
    for(i=2; i <num; i++){
        row[i-2] = va_arg(va_list, char*);
    }

    int hash_index = hash(row[key]);

    while( table[hash_index] != NULL) {
      if(strcmp(table[hash_index]->key, row[key]) == 0){
          TuplePtr tuple = table[hash_index]->value;
          int j = tuple->col;

          for(int i =0; i< j; i++){
              if(strcmp(tuple->row[i], row[i]) != 0 ){
                  if(strcmp(row[i], "*") != 0){
                      return NULL;
                  }
              }
          }
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
    HashTable snaptable = (HashTable)calloc(50, sizeof(struct table));
    HashTable cptable = (HashTable)calloc(50, sizeof(struct table));
    HashTable cdhtable = (HashTable)calloc(50, sizeof(struct table));
    HashTable crtable = (HashTable)calloc(50, sizeof(struct table));


    TuplePtr csg1 = createTuple("CSG", 3, 1);
    csg1 = fill(4, csg1, "CS101", "12345", "A");
    csgtable = insert(csgtable, csg1);
    TuplePtr csg2 = createTuple("CSG", 3, 1);
    csg2 = fill(4, csg2, "CS101", "67890", "B");
    csgtable = insert(csgtable, csg2);
    TuplePtr csg3 = createTuple("CSG", 3, 1);
    csg3 = fill(4, csg3, "EE200", "12345", "C");
    csgtable = insert(csgtable, csg3);
    TuplePtr csg4 = createTuple("CSG", 3, 1);
    csg4 = fill(4, csg4, "EE200", "22222", "B+");
    csgtable = insert(csgtable, csg4);
    TuplePtr csg5 = createTuple("CSG", 3, 1);
    csg5 = fill(4, csg5, "CS101", "33333", "A-");
    csgtable = insert(csgtable, csg5);
    TuplePtr csg6 = createTuple("CSG", 3, 1);
    csg6 = fill(4, csg6, "PH100", "67890", "C+");
    csgtable = insert(csgtable, csg6);

    Bstptr csgbst = createBst(csg1->loc, csg1);
    
    csgbst = insertNode(csgbst, createBst(csg2->loc, csg2));
    csgbst = insertNode(csgbst, createBst(csg3->loc, csg3));
    csgbst = insertNode(csgbst, createBst(csg4->loc, csg4));
    csgbst = insertNode(csgbst, createBst(csg5->loc, csg5));
    csgbst = insertNode(csgbst, createBst(csg6->loc, csg6));


    TuplePtr snap1 = createTuple("SNAP", 4, 0);
    snap1 = fill(5, snap1, "12345", "C. Brown", "12 Apple St.", "555-1234");
    snaptable = insert(snaptable, snap1);
    TuplePtr snap2 = createTuple("SNAP", 4, 0);
    snap2 = fill(5, snap2, "67890", "L. Van Pelt", "34 Pear Ave.", "555-5678");
    snaptable = insert(snaptable, snap2);
    TuplePtr snap3 = createTuple("SNAP", 4, 0);
    snap3 = fill(5, snap3, "12345", "C. Brown", "12 Apple St.", "555-1234");
    snaptable = insert(snaptable, snap3);

    Bstptr snapbst = createBst(snap1->loc, snap1);
    snapbst = insertNode(snapbst, createBst(snap1->loc, snap1));
    snapbst = insertNode(snapbst, createBst(snap2->loc, snap2));
    snapbst = insertNode(snapbst, createBst(snap3->loc, snap3));

    TuplePtr cp1 = createTuple("CP", 2, 0);
    cp1 = fill(3, cp1, "CS101", "CS100");
    cptable = insert(cptable, cp1);
    TuplePtr cp2 = createTuple("CP", 2, 0);
    cp2 = fill(3, cp2, "EE200", "EE005");
    cptable = insert(cptable, cp2);
    TuplePtr cp3 = createTuple("CP", 2, 0);
    cp3 = fill(3, cp3, "EE200", "CS100");
    cptable = insert(cptable, cp3);
    TuplePtr cp4 = createTuple("CP", 2, 0);
    cp4 = fill(3, cp4, "CS120", "CS101");
    cptable = insert(cptable, cp4);
    TuplePtr cp5 = createTuple("CP", 2, 0);
    cp5 = fill(3, cp5, "CS121", "CS120");
    cptable = insert(cptable, cp5);
    TuplePtr cp6 = createTuple("CP", 2, 0);
    cp6 = fill(3, cp6, "CS205", "CS101");
    cptable = insert(cptable, cp6);
    TuplePtr cp7 = createTuple("CP", 2, 0);
    cp7 = fill(3, cp7, "CS206", "CS121");
    cptable = insert(cptable, cp7);
    TuplePtr cp8 = createTuple("CP", 2, 0);
    cp8 = fill(3, cp8, "CS206", "CS205");
    cptable = insert(cptable, cp8);

    Bstptr cpbst = createBst(cp1->loc, cp1);
    cpbst = insertNode(cpbst, createBst(cp2->loc, cp2));
    cpbst = insertNode(cpbst, createBst(cp3->loc, cp3));
    cpbst = insertNode(cpbst, createBst(cp4->loc, cp4));
    cpbst = insertNode(cpbst, createBst(cp5->loc, cp5));
    cpbst = insertNode(cpbst, createBst(cp6->loc, cp6));
    cpbst = insertNode(cpbst, createBst(cp7->loc, cp7));
    cpbst = insertNode(cpbst, createBst(cp8->loc, cp8));

    TuplePtr cdh1 = createTuple("CDH", 3, 0);
    cdh1 = fill(4, cdh1, "CS101", "M", "9AM");
    cdhtable = insert(cdhtable, cdh1);
    TuplePtr cdh2 = createTuple("CDH", 3, 0);
    cdh2 = fill(4, cdh2, "CS101", "W", "9AM");
    cdhtable = insert(cdhtable, cdh1);
    TuplePtr cdh3 = createTuple("CDH", 3, 0);
    cdh3 = fill(4, cdh3, "CS101", "F", "9AM");
    cdhtable = insert(cdhtable, cdh3);
    TuplePtr cdh4 = createTuple("CDH", 3, 0);
    cdh4 = fill(4, cdh4, "EE200", "Tu", "10AM");
    cdhtable = insert(cdhtable, cdh4);
    TuplePtr cdh5 = createTuple("CDH", 3, 0);
    cdh5 = fill(4, cdh5, "EE200", "W", "1PM");
    cdhtable = insert(cdhtable, cdh5);
    TuplePtr cdh6 = createTuple("CDH", 3, 0);
    cdh6 = fill(4, cdh6, "EE200", "Th", "10AM");
    cdhtable = insert(cdhtable, cdh6);

    Bstptr cdhbst = createBst(cdh1->loc, cdh1);
    cdhbst = insertNode(cdhbst, createBst(cdh2->loc, cdh2));
    cdhbst = insertNode(cdhbst, createBst(cdh3->loc, cdh3));
    cdhbst = insertNode(cdhbst, createBst(cdh4->loc, cdh4));
    cdhbst = insertNode(cdhbst, createBst(cdh5->loc, cdh5));
    cdhbst = insertNode(cdhbst, createBst(cdh6->loc, cdh6));


    TuplePtr cr1 = createTuple("CR", 2, 0);
    cr1 = fill(3, cr1, "CS101", "Turing Aud.");
    crtable = insert(crtable, cr1);
    TuplePtr cr2 = createTuple("CR", 2, 0);
    cr2 = fill(3, cr2, "EE200", "25 Ohm Hall");
    crtable = insert(crtable, cr2);
    TuplePtr cr3 = createTuple("CR", 2, 0);
    cr3 = fill(3, cr3, "PH100", "Newton Lab.");
    crtable = insert(crtable, cr3);

    Bstptr crbst = createBst(cr1->loc, cr1);
    crbst = insertNode(crbst, createBst(cr2->loc, cr2));
    crbst = insertNode(crbst, createBst(cr3->loc, cr3));
    

    // printf("\nkk");
    TuplePtr temp = lookup(5, csgtable, 0, "CS101", "12345", "A");
    // printf("\n%s", temp->name);
    printTuple(temp);

    // TuplePtr del = delete(csgtable, csg);
    // printf("\n%s", del->row[1]);

    // TuplePtr nodel = lookup(csgtable, csg);
    if(temp==NULL){
        printf("\nYay\n");
    }
    // printf("\n%s", nodel->name);
    // printf("\n%s", temp);
}

// #endif