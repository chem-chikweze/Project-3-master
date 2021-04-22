

//   TuplePtr snap1 = createTuple("SNAP", 4, 0);
//     snap1 = fill(5, snap1, "12345", "C. Brown", "12 Apple St.", "555-1234");
//     snaptable = insert(snaptable, snap1);
//     TuplePtr snap2 = createTuple("SNAP", 4, 0);
//     snap2 = fill(5, snap2, "67890", "L. Van Pelt", "34 Pear Ave.", "555-5678");
//     snaptable = insert(snaptable, snap2);
//     TuplePtr snap3 = createTuple("SNAP", 4, 0);
//     snap3 = fill(5, snap3, "12345", "C. Brown", "12 Apple St.", "555-1234");
//     snaptable = insert(snaptable, snap3);

    
//     Bstptr snapbst = createBst(snap1->loc, snap1);
//     snapbst = insertNode(snapbst, createBst(snap1->loc, snap1));
//     snapbst = insertNode(snapbst, createBst(snap2->loc, snap2));
//     snapbst = insertNode(snapbst, createBst(snap3->loc, snap3));

//     List snaplist = (List)calloc(3,sizeof(struct list));
//     snaplist[0].key = snap1->row[2];
//     snaplist[1].key = snap2->row[2];
//     snaplist[2].key = snap3->row[2];
//     snaplist[0].value = snap1;
//     snaplist[1].value = snap2;
//     snaplist[2].value = snap3;

    
//     TuplePtr cp1 = createTuple("CP", 2, 0);
//     cp1 = fill(3, cp1, "CS101", "CS100");
//     cptable = insert(cptable, cp1);
//     TuplePtr cp2 = createTuple("CP", 2, 0);
//     cp2 = fill(3, cp2, "EE200", "EE005");
//     cptable = insert(cptable, cp2);
//     TuplePtr cp3 = createTuple("CP", 2, 0);
//     cp3 = fill(3, cp3, "EE200", "CS100");
//     cptable = insert(cptable, cp3);
//     TuplePtr cp4 = createTuple("CP", 2, 0);
//     cp4 = fill(3, cp4, "CS120", "CS101");
//     cptable = insert(cptable, cp4);
//     TuplePtr cp5 = createTuple("CP", 2, 0);
//     cp5 = fill(3, cp5, "CS121", "CS120");
//     cptable = insert(cptable, cp5);
//     TuplePtr cp6 = createTuple("CP", 2, 0);
//     cp6 = fill(3, cp6, "CS205", "CS101");
//     cptable = insert(cptable, cp6);
//     TuplePtr cp7 = createTuple("CP", 2, 0);
//     cp7 = fill(3, cp7, "CS206", "CS121");
//     cptable = insert(cptable, cp7);
//     TuplePtr cp8 = createTuple("CP", 2, 0);
//     cp8 = fill(3, cp8, "CS206", "CS205");
//     cptable = insert(cptable, cp8);

//     Bstptr cpbst = createBst(cp1->loc, cp1);
//     cpbst = insertNode(cpbst, createBst(cp2->loc, cp2));
//     cpbst = insertNode(cpbst, createBst(cp3->loc, cp3));
//     cpbst = insertNode(cpbst, createBst(cp4->loc, cp4));
//     cpbst = insertNode(cpbst, createBst(cp5->loc, cp5));
//     cpbst = insertNode(cpbst, createBst(cp6->loc, cp6));
//     cpbst = insertNode(cpbst, createBst(cp7->loc, cp7));
//     cpbst = insertNode(cpbst, createBst(cp8->loc, cp8));

//     TuplePtr cdh1 = createTuple("CDH", 3, 0);
//     cdh1 = fill(4, cdh1, "CS101", "M", "9AM");
//     cdhtable = insert(cdhtable, cdh1);
//     TuplePtr cdh2 = createTuple("CDH", 3, 0);
//     cdh2 = fill(4, cdh2, "CS101", "W", "9AM");
//     cdhtable = insert(cdhtable, cdh1);
//     TuplePtr cdh3 = createTuple("CDH", 3, 0);
//     cdh3 = fill(4, cdh3, "CS101", "F", "9AM");
//     cdhtable = insert(cdhtable, cdh3);
//     TuplePtr cdh4 = createTuple("CDH", 3, 0);
//     cdh4 = fill(4, cdh4, "EE200", "Tu", "10AM");
//     cdhtable = insert(cdhtable, cdh4);
//     TuplePtr cdh5 = createTuple("CDH", 3, 0);
//     cdh5 = fill(4, cdh5, "EE200", "W", "1PM");
//     cdhtable = insert(cdhtable, cdh5);
//     TuplePtr cdh6 = createTuple("CDH", 3, 0);
//     cdh6 = fill(4, cdh6, "EE200", "Th", "10AM");
//     cdhtable = insert(cdhtable, cdh6);

//     Bstptr cdhbst = createBst(cdh1->loc, cdh1);
//     cdhbst = insertNode(cdhbst, createBst(cdh2->loc, cdh2));
//     cdhbst = insertNode(cdhbst, createBst(cdh3->loc, cdh3));
//     cdhbst = insertNode(cdhbst, createBst(cdh4->loc, cdh4));
//     cdhbst = insertNode(cdhbst, createBst(cdh5->loc, cdh5));
//     cdhbst = insertNode(cdhbst, createBst(cdh6->loc, cdh6));

//     TuplePtr cr1 = createTuple("CR", 2, 0);
//     cr1 = fill(3, cr1, "CS101", "Turing Aud.");
//     crtable = insert(crtable, cr1);
//     TuplePtr cr2 = createTuple("CR", 2, 0);
//     cr2 = fill(3, cr2, "EE200", "25 Ohm Hall");
//     crtable = insert(crtable, cr2);
//     TuplePtr cr3 = createTuple("CR", 2, 0);
//     cr3 = fill(3, cr3, "PH100", "Newton Lab.");
//     crtable = insert(crtable, cr3);

//     Bstptr crbst = createBst(cr1->loc, cr1);
//     crbst = insertNode(crbst, createBst(cr2->loc, cr2));
//     crbst = insertNode(crbst, createBst(cr3->loc, cr3));
    
//     TuplePtr temp = search(csgtable, csg6);

//     printf("A search for CS101 12345 A\n");
//     TuplePtr l1 = search(csgtable, csg1);

//     printf("A search for 12345, C. Brown, 12 Apple St., 555-1234\n");
//     TuplePtr l2 = search(snaptable, snap1);

//     printf("A search for CS101 CS100\n");
//     TuplePtr l3 = search(cptable, cp1);

//     printf("A search for CS101 M 9AM\n");
//     TuplePtr l4 = search(cdhtable, cdh1);

//     printTuple(l1);
//     printTuple(l2);
//     printTuple(l3);
//     printTuple(l4);

//     printf("Deleting the four sample rows: ");
//     delete(csgtable, csg1);
//     delete(snaptable, snap1);
//     delete(cptable, cp1);
//     delete(cdhtable, cdh1);

//     l1 = search(csgtable, csg1);
//     l2 = search(snaptable, snap1);
//     l3 = search(cptable, cp1);
    //     l4 = search(cdhtable, cdh1);
    //     printf("Reprinting will show null: \n");
    //     printTuple(l1);
//     printTuple(l2);
//     printTuple(l3);
//     printTuple(l4);

//     printf("Saving the data base to files using C");
//     FILE *fp;
//     fp = fopen("test.txt", "w+");
//     char* dstring = "chem";

//     fputs("\n\t\tCSG TABLE\n", fp);
//     writeTree(csgbst, fp);
//     fputs("\n\t\tSNAP TABLE\n", fp);
//     writeTree(snapbst, fp);
//     fputs("\n\t\tCP TABLE\n", fp);
//     writeTree(cpbst, fp);
//     fputs("\n\t\tCDH TABLE\n", fp);
//     writeTree(cdhbst, fp);

//     fclose(fp);
//     printf("\nData base is saved to test.txt");


//     printf("\nWhat grade does student name have in course ?\n");
//     printf("\nEnter Student name: \n");
//     char name[100];
//     fgets(name, 100, stdin);
 
//     printf("\nEnter Course name: \n");
//     char course[100];
//     fgets(course, 100, stdin);
//     printf("hey");
//     TuplePtr t1 = NULL;
//     for(int i = 0; i<3; i++){
//         if(strcmp(snaplist[i].key, name)){
//             t1 = snaplist[i].value;
//         }
//     }
//     Bstptr temp2 = NULL;
//     if(temp != NULL){
//         temp2 = lookupNode(csgbst, t1);
//     }
//     printf("The grade is: %s", temp2->p->row[2]);