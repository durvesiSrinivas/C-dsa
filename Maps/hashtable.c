#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 10

void insert(int, char *);
void delete(int);
void search(int);
int hashfun(int);
void traverse();
void print_table();
void create_hashtable();
bool contains(int);

struct node {
    int key;
    char value[50];
    struct node* next;
};

struct hashtable {
    struct node *hashtable[SIZE];
};

struct hashtable *table;

int main() {
    int ch = -1, dnum = 0;
    char vnum[50];

    create_hashtable();

    do {
        printf("\n");
        printf("\n");
        printf("enter your choice\n");
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. search\n");
        printf("4. traverse\n");
        printf("5. print\n");
        printf("6. contains\n");
        printf("0. exit\n");
        scanf("%d", &ch);
        printf("\n");

        switch(ch) {
            case 1:
                printf("enter key \n");
                scanf("%d", &dnum);
                printf("enter value\n");
                scanf("%s", vnum);
                insert(dnum, vnum);
                break;

            case 2:
                printf("enter key to delete\n");
                scanf("%d", &dnum);
                delete(dnum);
                break;

            case 3:
                printf("enter key to search\n");
                scanf("%d", &dnum);
                search(dnum);
                break;

            case 4:
                traverse();
                break;

            case 5:
                print_table();
                break;

            case 6:
                printf("enter key\n");
                scanf("%d", &dnum);

                if (contains(dnum) == true) {
                    printf("key %d contains in bucket %d\n", dnum, hashfun(dnum));
                } else {
                    printf("key %d does not contain in bucket %d\n", dnum, hashfun(dnum));
                }
                break;

            case 0:
                printf("exiting...\n");
                break;

            default:
                printf("enter correct choice\n");
                break;
        }
    } while (ch != 0);

    free(table);
    return 0;
}

void insert(int key, char* value) {
    // Check if the key already exists
    if (contains(key) == true) {
        printf("Duplicate keys not allowed\n");
        return;
    } else {
        int index = hashfun(key);

        // Create a new node and insert it at the beginning of the linked list in the corresponding bucket
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->key = key;
        strcpy(newnode->value, value);                 //using strcpy function to copy valu pointer string to struct string array value 
        newnode->next = table->hashtable[index];
        table->hashtable[index] = newnode;

        printf("Insertion successful\n");
    }
}

void delete(int key) {
    int index = hashfun(key);

    if (contains(key) == true) {
        struct node* curr = NULL;
        struct node* prev = NULL;
        curr = table->hashtable[index];

        // Search for the key in the linked list and delete it
        while (curr != NULL) {
            if (curr->key == key) {
                if (prev == NULL) {
                    table->hashtable[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                free(curr);
                printf("Deleted key %d at bucket [%d]\n", key, index);
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    } else {
        printf("Key %d does not exist\n", key);
    }
}

void search(int key) {
    if (contains(key) == true) {
        int index = hashfun(key);
        struct node* iterate = table->hashtable[index];
        
        // Search for the key in the linked list and print the bucket index if found
        while (iterate != NULL) {
            if (iterate->key == key) {
                printf("Key %d found at bucket [%d]\n", key, index);
                return;
            }
            iterate = iterate->next;
        }
    } else {
        printf("Key %d does not exist\n", key);
    }
}

int hashfun(int key) {
    // Calculate the hash value (bucket index) for the given key
    int index = (key + 31) % SIZE;
    return index;
}

void traverse() {
    struct node* iterate;
    int i;
    
    for (i = 0; i < SIZE; i++) {
        iterate = table->hashtable[i];
        printf("Bucket [%d] - ", i);

        // Traverse the linked list in each bucket and print the key-value pairs
        while (iterate != NULL) {
            printf("| %d, %s | ", iterate->key, iterate->value);
            iterate = iterate->next;
        }
        printf("\n");
    }

    printf("Traversal complete\n");
}

void print_table() {
    struct node* iterate;
    int i;
    printf("[ ");

    for (i = 0; i < SIZE; i++) {
        iterate = table->hashtable[i];

        // Traverse the linked list in each bucket and print the key-value pairs
        while (iterate != NULL) {
            printf("| %d, %s | ", iterate->key, iterate->value);
            iterate = iterate->next;
        }
    }

    printf("]\n");
    printf("Print elements complete\n");
}

void create_hashtable() {
    // Allocate memory for the hashtable structure
    table = (struct hashtable*)malloc(sizeof(struct hashtable));

    int i;
    for (i = 0; i < SIZE; i++) {
        // Initialize each bucket in the hashtable to NULL
        table->hashtable[i] = NULL;
    }
}

bool contains(int key) {
    int index = hashfun(key);
    struct node* iterate = table->hashtable[index];

    // Search for the key in the linked list of the corresponding bucket
    while (iterate != NULL) {
        if (iterate->key == key) {
            return true;
        }
        iterate = iterate->next;
    }
    return false;
}
