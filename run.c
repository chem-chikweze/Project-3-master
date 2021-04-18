
// #include "g_node.h"
#include "g_tuple.h"

// #include "g_node.c"
#include "g_tuple.c"


int main(int argc, char const *argv[])
{
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