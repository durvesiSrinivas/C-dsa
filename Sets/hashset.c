#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE_BUK 10

struct nodes {
    int data;
    struct nodes* next;
};

struct hash_set {
    struct nodes* buckets[SIZE_BUK];
};

struct hash_set* set = NULL;

void insert(int);
void delete(int);
void search(int);
bool contains(int);
void create_hashset();
int hash_fun(int);
void traverse_buk();
void print_elements();

int i, ch = -1, num = 0;

int main() {
    create_hashset(); // Call create_hashset to allocate memory before starting the program

    do {
        printf("\n");
        printf("\n");
        printf("enter your choice\n");
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. search\n");
        printf("4. contains\n");
        printf("5. traverse hashset\n");
        printf("6. print elements of hashset\n");
        printf("0. exit\n");
        scanf("%d", &ch);
        printf("\n");

        switch (ch) {
            case 1:
                printf("enter the element\n");
                scanf("%d", &num);
                insert(num);
                break;
            case 2:
                printf("enter key to delete\n");
                scanf("%d", &num);
                delete(num);
                break;
            case 3:
                printf("enter key to search\n");
                scanf("%d", &num);
                search(num);
                break;
            case 4:
                printf("enter key to find\n");
                scanf("%d", &num);
                if (contains(num) == true) {
                    printf("key contains in hashset - true\n");
                }
                if (contains(num) == false) {
                    printf("key contains in hashset - false\n");
                }
                break;
            case 5:
                traverse_buk();
                break;
            case 6:
                print_elements();
                break;
            case 0:
                printf("exiting ....\n");
                break;
            default:
                printf("enter correct choice\n");
                break;
        }
    } while (ch != 0);

    free(set);
    return 0;
}

int hash_fun(int key) {
    int index = key % SIZE_BUK;
    return index;
}

void create_hashset() {
    set = (struct hash_set*)malloc(sizeof(struct hash_set)); // Allocate memory for struct because you are using a pointer
    for (i = 0; i < SIZE_BUK; i++) {
        set->buckets[i] = NULL; // Make all pointer array elements NULL at the start
    }
}

void insert(int key) {
    bool bl = contains(key);
    if (bl == true) {
        printf("Duplicate elements are not allowed\n");
        return;
    }
    int index = hash_fun(key);
    struct nodes* newnode = (struct nodes*)malloc(sizeof(struct nodes));
    newnode->data = key;
    newnode->next = set->buckets[index];
    set->buckets[index] = newnode;

    printf("Inserted element successfully\n");
}

void delete(int key) {
    int index = hash_fun(key);

    if (contains(key) == true) {
        struct nodes* curr = NULL;
        struct nodes* prev = NULL;
        curr = set->buckets[index];
        while (curr != NULL) {
            if (curr->data == key) {
                if (prev == NULL) {
                    set->buckets[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                free(curr);
                printf("Deleted key %d in buk [%d]\n", key, index);
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    if (contains(key) == false) {
        printf("Key %d does not exist in buk [%d]\n", key, index);
    }
}

void search(int key) {
    int index = hash_fun(key);
    struct nodes* curr = NULL;
    curr = set->buckets[index];
    while (curr != NULL) {
        if (curr->data == key) {
            printf("Found key %d in buk [%d]\n", key, index);
            return;
        }
        curr = curr->next;
    }

    printf("Not found in buk [%d]\n", index);
}

bool contains(int key) {
    int index = hash_fun(key);
    struct nodes* node = set->buckets[index];
    while (node != NULL) {
        if (node->data == key) {
            return true;
        }
        node = node->next;
    }
    return false;
}

void traverse_buk() {
    int i;
    struct nodes* iterate;
    for (i = 0; i < SIZE_BUK; i++) {
        iterate = set->buckets[i];
        printf("buk [%d] =", i);
        while (iterate != NULL) {
            printf(" | %d | ", iterate->data);
            iterate = iterate->next;
        }
        printf("\n");
    }

    printf("Traverse completed\n");
}

void print_elements() {
    int i;
    struct nodes* iterate;
    for (i = 0; i < SIZE_BUK; i++) {
        iterate = set->buckets[i];
        while (iterate != NULL) {
            printf("%d ", iterate->data);
            iterate = iterate->next;
        }
    }
}
key){
            return true;
            }
        node = node->next;    
        }
    return false;
    }
    
void traverse_buk(){
    int i;
    struct nodes *iterate;
    
for(i=0; i<SIZE_BUK ;i++ ){
    iterate = set->buckets[i];
    printf(" buk [ %d ] =", i);
    while( iterate!=NULL ){
        printf(" | %d | ", iterate->data);
        iterate=iterate->next;
             }
        printf("\n");
    }    

  printf("traverse completed\n");    
}

    void print_elements(){
      
      int i;
      struct nodes* iterate;
      
        for(i=0; i<SIZE_BUK; i++){
          iterate= set->buckets[i];
            while(iterate!=NULL){
                      printf(" %d ", iterate->data);                     
                      iterate= iterate->next;
             }
              
           }
    
       }    