// #ifndef __G_TUPLE_H
// #define __G_TUPLE_H
#include "g_node.h"
#include "g_node.c"

TuplePtr createTuple(char* na, int l, int k){
    TuplePtr tup = (TuplePtr) malloc(sizeof(TUPLE));
    tup->name = na;
    tup->col = l;   // number of columns
    tup->key = k;   // primary key
    tup->loc = 0;
    tup->row = (char **) calloc(l, sizeof(char *));
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

    char** row = (char **) calloc(num-1, sizeof(char *));
    for(i=1; i <num; i++){
        row[i-1] = va_arg(va_list, char*);
    }
    int hash_index = hash(row[0]);
    // printf("%d", hash_index);
    while( table[hash_index] != NULL) {
      if(strcmp(table[hash_index]->key, row[0]) == 0){
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

// int hashcode(TuplePtr data){
//     int kindex = data->key;
//     char** k_string = data->row;
//     int sum = 0;
//     for(int i =0; i < data->col; i++){
//         sum += sum_string(k_string[i]);
//     }
//     int ret = abs(sum)  % SIZE;
//     data->loc = ret;
//     return ret;
// }

int hashcode(TuplePtr data){
    char* k_string = data->row[0];
    int sum = 0;
    int len = strlen(k_string);
    for(int i =0; i < len; i++){
        sum += k_string[i];
    }
    int ret = abs(sum)  % SIZE;
    data->loc = ret;
    return ret;
}

int hash(char* data){
    // printf("hashcode test: %s\n", k_string);
    int sum = sum_string(data);
    return (int) abs(sum)  % SIZE;
}

void printTuple(TuplePtr data){
    printf("Printing tuple:\n");

    if(data==NULL) {
        printf("null\n");
        return;
    }
    int size = data->col;
    printf("Tuple: \t");
    for(int i=0; i< size; i++){
        printf("  %s", data->row[i]);
    }
    printf("\t%d", data->loc);
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
      ++hash_index;
      hash_index %= SIZE;
   }
   return NULL;        
}

HashTable insert(HashTable table, TuplePtr data){
    int hash_index = hashcode(data);
    while(table[hash_index] != NULL) {
        if(strcmp(table[hash_index]->key, data->row[data->key]) == 0){
            if(data->row[0] != NULL) {
                if(strcmp(table[hash_index]->value->row[0],data->row[0]) == 0){
                    if(data->row[1] != NULL){
                        if(strcmp(table[hash_index]->value->row[1],data->row[1]) == 0){
                            if(data->row[2] != NULL){
                                if(strcmp(table[hash_index]->value->row[2],data->row[2]) == 0){
                                    if(data->row[3] != NULL){
                                        if(strcmp(table[hash_index]->value->row[3],data->row[3]) == 0){
                                            return table;
                                        }
                                    }
                                    return table;
                                }
                            }
                            printf("%d", data->loc);
                            return table;
                        }
                    }
                }
            }
        }
        // printf("NEXT %sb%s %s2\n",table[hash_index]->value->name, table[hash_index]->value->row[1],data->row[1]);         
        //go to next cell
        ++hash_index;
        //wrap around the table
        hash_index %= SIZE;   
    }
    table[hash_index] = (struct table* )malloc(sizeof(struct table));
    table[hash_index]->key = data->row[data->key];
    table[hash_index]->value = data;
    data->loc = hash_index;
    return table;
}

HashTable delete(HashTable table, TuplePtr data){

    int hash_index = hashcode(data);
    int to_delete = 1;
    while(table[hash_index] != NULL) {
        if(strcmp(table[hash_index]->key, data->row[data->key]) == 0)
        {
            TuplePtr data_del = table[hash_index]->value;
            for(int i = 0; i < table[hash_index]->value->col; i++){
                if(strcmp(table[hash_index]->value->row[i], data->row[i]) == 0 ){
                    continue;
                }else if(strcmp(data->row[i], "*") == 0){
                    continue;
                }else{
                    to_delete = 0;
                }
            }
            if(to_delete){
                table[hash_index]->value = NULL;
                table[hash_index]->key = NULL;
                table[hash_index] = NULL;
                data->name = NULL;
                data->row = NULL;
                // printf("not null lol\n");
                return table;
            }
        }
        ++hash_index;
        hash_index %= SIZE;
    }
    if(table[hash_index] == NULL){
        printf("\nTable is null now: %d \n", hash_index);
        // printTable(table);
        return NULL;
    }
}

void printTable(HashTable head){
    for(int i =0; i < SIZE; i++){
        if(head[i] != NULL){
            printTuple(head[i]->value);
        }
    }
}

void writeTree(Bstptr head, FILE *fp){
    int i = 0;
    while (i < 3)
    {
        if(head->p != NULL){
        fputs(head->p->row[i], fp);
        fputs("\t", fp);
        i++;
        }
    }
    fputs("\n", fp);
    if(head->left != NULL){
        writeTree(head->left, fp);
    }
    if(head->right != NULL){
        writeTree(head->right, fp);
    }
}

HashTable deleted(int num, ...){
    va_list va_list;
    int i;
    va_start(va_list, num);
    Bstptr tree = va_arg(va_list, Bstptr);
    HashTable table = va_arg(va_list, HashTable);

    char** row_del = (char **) calloc(num-1, sizeof(char *));
    for(i=2; i <num; i++){
        row_del[i-2] = va_arg(va_list, char*);
    }
    int hash_index = hash(row_del[0]);

    TuplePtr sub_tup = createTuple(tree->p->name, num-2, 0);
    sub_tup->loc = hash_index;
    sub_tup->row = row_del;

    if(sub_tup != NULL){
        printTuple(sub_tup);
    }
    HashTable ret =  delete(table, sub_tup);
    
    if(ret != NULL){
    return ret;
    }else {
        printf("what's going on");
        return NULL;
    }
//       if(strcmp(table[hash_index]->key, row[0]) == 0){
//           TuplePtr tuple = table[hash_index]->value;
//           int j = tuple->col;
//           for(int i =0; i< j; i++){
//               if(strcmp(tuple->row[i], row_del[i]) != 0 ){
//                   if(strcmp(row[i], "*") != 0){
//                       printf("deleted: not a part");
//                       return;
//                   }
//               }
//           }
//           TuplePtr data_del = table[hash_index]->value;
//           table[hash_index] = NULL;
//           return ;
//       }
//       //go to next cell
//       ++hash_index;
//       //wrap around the table
//       hash_index %= SIZE;
//    }
//    return ;
}

int main(){
    HashTable csgtable = (HashTable)calloc(SIZE, sizeof(struct table));
    HashTable snaptable = (HashTable)calloc(SIZE, sizeof(struct table));
    HashTable cptable = (HashTable)calloc(SIZE, sizeof(struct table));
    HashTable cdhtable = (HashTable)calloc(SIZE, sizeof(struct table));
    HashTable crtable = (HashTable)calloc(SIZE, sizeof(struct table));

    printf("First we create and insert the data into tables using generics and dynamic arguements:\n");
    TuplePtr csg1 = createTuple("CSG", 3, 0);
    csg1 = fill(4, csg1, "CS101", "12345", "A");
    csgtable = insert(csgtable, csg1);
    TuplePtr csg2 = createTuple("CSG", 3, 0);
    csg2 = fill(4, csg2, "CS101", "67890", "B");
    csgtable = insert(csgtable, csg2);
    TuplePtr csg3 = createTuple("CSG", 3, 0);
    csg3 = fill(4, csg3, "EE200", "12345", "C");
    csgtable = insert(csgtable, csg3);
    TuplePtr csg4 = createTuple("CSG", 3, 0);
    csg4 = fill(4, csg4, "EE200", "22222", "B+");
    csgtable = insert(csgtable, csg4);
    TuplePtr csg5 = createTuple("CSG", 3, 0);
    csg5 = fill(4, csg5, "CS101", "33333", "A-");
    csgtable = insert(csgtable, csg5);
    TuplePtr csg6 = createTuple("CSG", 3, 0);
    csg6 = fill(4, csg6, "PH100", "67890", "C+");
    csgtable = insert(csgtable, csg6);

    Bstptr csgbst = createBst(csg1->loc, csg1);
    csgbst = insertNode(csgbst, createBst(csg2->loc, csg2));
    csgbst = insertNode(csgbst, createBst(csg4->loc, csg4));
    csgbst = insertNode(csgbst, createBst(csg3->loc, csg3));
    csgbst = insertNode(csgbst, createBst(csg5->loc, csg5));
    csgbst = insertNode(csgbst, createBst(csg6->loc, csg6));

    TuplePtr l4 = search(csgtable, csg6);
    printTable(csgtable);
    csgtable = deleted(5, csgbst, csgtable, "CS101", "*", "*");
    printf("hey\n");

    printTable(csgtable);

    // printf("Reprinting will show null: \n");
    // if(csgtable != NULL){
    // l4 = search(csgtable, csg6);
    // }
    // printTuple(l4);
    // printf(":");
}