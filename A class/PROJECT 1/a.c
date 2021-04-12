#include <string.h>
#include "list.h"
#include "tree.h"
#include "tree.c"

bool checker(char *string, char c){           
    if (*string == c){
        return true;    
    }
    else{
        return false;
    }
}
char state = '0';
bool check(char *string, char c, char s, char state){
    if (*string == c && s == state){
        return true;    
    }else{
        return false;
    }
}

// DFAs
bool Turing(char *str){
    char *ptr =  str;
    if(checker_ptr(ptr, 'T')){
        // printf("T");
        // go to state u
        ptr = ptr +1;
        if(checker_ptr(ptr, 'u')){
            // printf("u");
            ptr = ptr +1;
            if(checker_ptr(ptr, 'r')){
                // printf("r");
                ptr = ptr +1;
                if(checker_ptr(ptr, 'i')){
                    // printf("i");
                    ptr = ptr +1;
                    if(checker_ptr(ptr, 'n')){
                        // printf("n");
                        ptr = ptr +1;
                        if(checker_ptr(ptr, 'g')){
                            // printf("g");
                            ptr = ptr +1;
                            if(checker_ptr(ptr, '\0')){
                                ptr = ptr +1;
                                return true;
                            }else{return false;}
                        }else{return false;}
                    }else{return false;}
                }else{return false;}
            }else{return false;}
        }else{return false;}
    }else{return false;}
}
bool four4(char *str){
    char *ptr =  str;
    if(checker_ptr(ptr, '4')){
        // printf("4");
        ptr = ptr +1;
        if(checker_ptr(ptr, '4')){
            // printf("%s","4");
            ptr = ptr +1;
            if(checker_ptr(ptr, '4')){
                // printf("%s","4");
                ptr = ptr +1;
                if(checker_ptr(ptr, '4')){
                    // printf("%s","4");
                    return true;
                }else {return  false;}
            }else {return  false;}
        }else {return  false;}
    }else {return  false;}
}
bool binary(char *str){
    char state = '0';
    char *ptr = str;
    while (*ptr != '\0') {
        //if ptr is arg 2 and argument 3  equals arg 4
        if(check(ptr, '0', '0', state)){
            ptr+=1;
        }else if(check(ptr, '1', '0', state)){
            // if next char is 1 and we are in 'state' 0
            // go to next character
            ptr+=1;
            // go to state 1
            state = '1';
        }else if(check(ptr, '0', '1', state)){
            ptr+=1;
        }else if(check(ptr, '1', '1', state)){
            ptr+=1;
            state = '0';
        }else if(*ptr != '0' && *ptr != '1'){
            ptr+=1;
        }
    }
    if(state == '1'){
        return true;
    }else {
        return false;   
    }
}
char state1 = '0';
char state2 = '0';
bool bin0odd1(char *str){
    char state1 = '0';
    char state2 = '0';
    char *ptr = str;
    while (*ptr != '\0'){
        if(*ptr == '0'){
            // if ptr is 0 and state1 is 0 go to 1 of state1
            if(check(ptr, '0', '0', state1)){
                ptr+=1;
                state1 = '1';
            }else if(check(ptr, '0', '1', state1)){
                ptr+=1;
                state1 = '0';
            }
        }else if (*ptr == '1'){
            if(check(ptr, '1', '0', state2)){
                ptr+=1;
                state2 = '1';
            }else if(check(ptr, '1', '1', state2)){
                ptr+=1;
                state2 = '0';
            }  
        }else if(*ptr != '0' && *ptr != '1'){
            ptr+=1;
        }
    }
    if(state1 == '0' && state2 == '1'){
        return true;
    }else{
        return false;
    }
    
}
bool even01(char *str){
    char state1 = '0';
    char state2 = '0';
    char *ptr = str;
    while (*ptr != '\0'){
        if(*ptr == '0'){
            // if ptr is 0 and state1 is 0 go to 1 of state1
            if(check(ptr, '0', '0', state1)){
                ptr+=1;
                state1 = '1';
            }else if(check(ptr, '0', '1', state1)){
                ptr+=1;
                state1 = '0';
            }
        }else if (*ptr == '1'){
            if(check(ptr, '1', '0', state2)){
                ptr+=1;
                state2 = '1';
            }else if(check(ptr, '1', '1', state2)){
                ptr+=1;
                state2 = '0';
            }  
        }else if(*ptr != '0' && *ptr != '1'){
            ptr+=1;
        }  
    }
    if(state1 == '0' && state2 == '0'){
        return true;
    }else{
        return false;
    }  
}

// // NFAs
// /*
//     sets
//     going through 'set states'
//     // create set states? on input 'x' current state 'z' go through set 'z'
//     // high big O
//
//     at the end of all state iterations, if an accepting state was reached for the input string, accept.
//     // how do I optimize this for the algorithm that transforms NFAs to DFAs?
// */
// // set
//
//
// // struct nfa{
//    
// //     // state 0 
// //     //     on input x = return {set}
// //     //     on input v = return {zet}
// //     //     on anything except x and v = return set {remain at state 0}
// //     // state x 
// //     //     on input y = {z}
// // }

bool eback(char *str){
    char *ptr = str;
    node *set = newSet();

    while (*ptr != '\0'){
        // printf("%c", *ptr);
        char choice = *ptr;
        switch (choice){
            case 'b':
                insertf(0, set);
                if(searchf(set, 0)){
                    insertf(1, set);
                    // printf("\nWoo%c", choice);
                }
                ptr = ptr + 1;
                break;
            case 'a':
                insertf(0, set);
                if(searchf(set, 1)){
                    insertf(2, set);
                    // printf("\nWoo%c", choice);
                }
                ptr+=1;
                break;
            case 'c':
                insertf(0, set);
                if(searchf(set, 2)){
                    insertf(3, set);
                    // printf("\nWoo%c", choice);
                }
                ptr+=1;
                break;
            case 'k':
                insertf(0, set);
                if(searchf(set, 3)){
                    insertf(4, set);
                    // printf("\nWoo%c", choice);
                    // printf("%c", *ptr+1);
                    if(*ptr+1 == 'l' && searchf(set, 4)){
                        insertf(5, set);
                    }
                }
                ptr+=1;
                break;
            default:
                insertf(0, set);
                ptr+=1;
                break;
        }
    }

    // inorderf(set);
    if(searchf(set, 5)){
        return true;
    }else{
        return false;
    }
}

bool containsback(char *str){
    char *ptr = str;
    node *set = newSet();

    while (*ptr != '\0'){
        // printf("%c", *ptr);
        char choice = *ptr;
        switch (choice){
            case 'b':
                insertf(0, set);
                if(searchf(set, 0)){
                    insertf(1, set);
                    // printf("\nWoo%c", choice);
                }
                ptr+=1;
                break;
            case 'a':
                insertf(0, set);
                if(searchf(set, 1)){
                    insertf(2, set);
                    // printf("\nWoo%c", choice);
                }
                ptr+=1;
                break;
            case 'c':
                insertf(0, set);
                if(searchf(set, 2)){
                    insertf(3, set);
                    // printf("\nWoo%c", choice);
                }
                ptr+=1;
                break;
            case 'k':
                insertf(0, set);
                if(searchf(set, 3)){
                    insertf(4, set);
                    // printf("\nWoo%c", choice);
                    // printf("%c", *ptr+1);
                }
                ptr+=1;
                break;
            default:
                insertf(0, set);
                ptr+=1;
                break;
        }
    }

    // inorderf(set);
    if(searchf(set, 4)){
        return true;
    }else{
        return false;
    }
}

bool washington(char *str){
    char *ptr = str;
    node *set = newSet();
    node *reject = newSet();
    while (*ptr != '\0'){
        char choice = *ptr;
        switch (choice){
            case 'w':
                if(searchf(set, 18)){
                    insertf(19, set);
                    insertf(19, reject);
                }
                insertf(0, set);
                insertf(18, set);
                // printf("%c", choice);
                ptr+=1;
                break;
            case 'a':
                if(searchf(set, 1)){
                    insertf(2, set);
                    insertf(2, reject);
                    // printf("\nWoo%c", choice);
                }
                insertf(0, set);
                insertf(1, set);
                // printf("%c", choice);
                ptr+=1;
                break;
            case 's':
                if(searchf(set, 14)){
                    insertf(15, set);
                    insertf(15, reject);
                    // printf("\nWoo%c", choice);
                }
                insertf(0, set);
                insertf(14, set);
                // printf("%c", choice);
                ptr+=1;
                break;
            case 'h':
                if(searchf(set, 5)){
                    insertf(6, set);
                    insertf(6, reject);
                    // printf("\nWoo%c", choice);
                }
                insertf(0, set);
                insertf(5, set);
                // printf("%c", choice);
                ptr+=1;
                break;
            case 'i':
                if(searchf(set, 7)){
                    insertf(8, set);
                    insertf(8, reject);
                }
                insertf(0, set);
                insertf(7, set);
                // printf("%c", choice);
                ptr+=1;
                break;
            case 'n':
                if(searchf(set, 10)){
                    insertf(11, set);
                    insertf(11, reject);
                }
                if(searchf(set, 9)){
                    insertf(10, set);
                    insertf(10, reject);
                }
                insertf(0, set);
                insertf(9, set);
                // printf("%c", choice);
                ptr+=1;
                break;
            case 'g':
                if(searchf(set, 3)){
                    insertf(4, set);
                    insertf(4, reject);
                }
                insertf(0, set);
                insertf(3, set);
                // printf("%c", choice);
                ptr+=1;
                break;
            case 't':
                if(searchf(set, 16)){
                    insertf(17, set);
                    insertf(17, reject);
                }
                insertf(0, set);
                insertf(16, set);
                // printf("%c", choice);
                ptr+=1;
                break;
            case 'o':
                if(searchf(set, 12)){
                    insertf(13, set);
                    insertf(13, reject);
                }
                insertf(0, set);
                insertf(12, set);
                // printf("%c", choice);
                ptr+=1;
                break;
            default:
                insertf(0, set);
                ptr+=1;
                break;
        }
    }

    // inorderf(reject);
    if(reject->left != NULL || reject->right != NULL){
        return true;
    }else{
        return false;
    }
}

bool containsChem(char *str){
    char *ptr = str;
    node *set = newSet();
    while (*ptr != '\0'){
        char choice = *ptr;
        switch (choice){
            case 'c':
                insertf(0, set);
                if(searchf(set, 0)){
                    insertf(1, set);
                }
                ptr+=1;
                break;
            case 'h':
                insertf(0, set);
                if(searchf(set, 1)){
                    insertf(2, set);
                }
                ptr+=1;
                break;
            case 'e':
                insertf(0, set);
                if(searchf(set, 2)){
                    insertf(3, set);
                }
                ptr+=1;
                break;
            case 'm':
                insertf(0, set);
                if(searchf(set, 3)){
                    insertf(4, set);
                }
                ptr+=1;
                break;
            default:
                insertf(0, set);
                ptr += 1;
                break;
        }
    }

    // inorderf(set);
    if(searchf(set, 4)){
        return true;
    }else{
        return false;
    }
}

struct dfa{
    char *str;
    bool value;;
};
typedef struct dfa DFA;

struct nfa{
    char *str;
    bool value;
};
typedef struct nfa NFA;

void run(int choice, char *s){
    
    char quit[] = "quit";
    if(strcmp(s, quit) == 0){
        return ;
    }
    DFA * a = (DFA *)malloc(sizeof(DFA));
    a->str = s;
    NFA * b = (NFA *)malloc(sizeof(NFA));
    b->str = s;
    switch (choice){
        case 1:
            a->value = Turing_ptr(s);
            break;
        case 2:
            a->value = four4_ptr(s);
            break;
        case 3:
            a->value = binary_ptr(s);
            break;
        case 4:
            a->value = bin0odd1_ptr(s);
            break;
        case 5:
            a->value = even01_ptr(s);
            break;
        case 6:
            b->value = eback(s);
            break;
        case 7:
            b->value = containsback(s);
            break;
        case 8:
            b->value = washington(s);
            break;
        case 9:
            b->value = containsChem(s);
            break;

        default:
            break;
    }

    if(choice <= 5){
        if(a->value == 1){
            printf("Accepted. \n");
        }else{
            printf("Not Accepted.");
        }
    }else if(choice == 8){
        if(b->value == 1){
            printf("Not a partial anagram of washington. \n");
        }else{
            printf("Is a partial anagram of washington");
        }
    }else{
        if(b->value == 1){
            printf("Accepted. \n");
        }else{
            printf("Not Accepted.");
        }
    }
}

int main(){
    char *s = malloc(sizeof(char *));
    puts("CSC 173 Project 1 by Chukwubuikem Chikweze");
    printf("\tTesting DFA that recognizes strings exactly the string \"Turing\" ");
    printf("\n\tEnter an input (\"quit\" to quit): ");
    scanf("%s", s);
    run(1, s);
    printf("\n\tTesting DFA that recognizes strings that start with four 4's");
    printf("\n\tEnter an input (\"quit\" to quit): ");
    scanf("%s", s);
    run(2, s);
    printf("\n\tTesting DFA that recognizes strings with an odd number of 1's ");
    printf("\n\tEnter an input (\"quit\" to quit): ");
    scanf("%s", s);
    run(3, s);
    printf("\n\tTesting DFA with an even number of 0's and an odd number of 1's");
    printf("\n\tEnter an input (\"quit\" to quit): ");
    scanf("%s", s);
    run(4, s);
    printf("\n\tTesting DFA that recognizes strings of even number of 0s and 1s");
    printf("\n\tEnter an input (\"quit\" to quit): ");
    scanf("%s", s);
    run(5, s);
    
    printf("\n\tTesting NFA that recognizes strings ending in \"back\" ");
    printf("\n\tEnter an input (\"quit\" to quit): ");
    scanf("%s", s);
    run(6, s);
    printf("\n\tTesting NFA that recognizes strings that contain \"back\" ");
    printf("\n\tEnter an input (\"quit\" to quit): ");
    scanf("%s", s);
    run(7, s);
    printf("\n\tTesting NFA that recognizes strings that are not partial anagrams of \"washington\" ");
    printf("\n\tEnter an input (\"quit\" to quit): ");
    scanf("%s", s);
    run(8, s);
    printf("\n\tTesting NFA with my nickname, \"chem\" contained in it");
    printf("\n\tEnter an input (\"quit\" to quit): ");
    scanf("%s", s);
    run(9, s);
    
    printf("\n%s", "The End.");
    return 0;
}


