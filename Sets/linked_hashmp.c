#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 10

// Function prototypes
void insert(char *, char *);
void delete(char *);
void search(char *);
void iterate();
void print();
int hashfun(char *);
bool contains(char *);
void create_linkedhashmap();

// Structure definition for a node in the linked list
struct node {
    char key[50];
    char value[50];
    struct node *next;
    struct node *after;
    struct node *before;
};

// Structure definition for the linked hashmap
struct linked_hashmap {
    struct node *linked_hashmap[SIZE];
};

// Global variables
struct linked_hashmap *lnk_hashmap;
struct node *head;
struct node *tail;

int main() {
    // Variable declarations
    int ch = -1;
    char kstr[50], vstr[50];

    // Create the linked hashmap
    create_linkedhashmap();

    do {
        // Print menu options
        printf("\n");
        printf("\n");
        printf("Choose the correct option\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Iterate\n");
        printf("5. Print\n");
        printf("6. Contains\n");
        printf("0. Exit\n");
        scanf("%d", &ch);
        printf("\n");

        switch (ch) {
            case 1:
                printf("Enter key: \n");
                scanf("%s", kstr);
                printf("Enter value: \n");
                scanf("%s", vstr);
                insert(kstr, vstr);
                break;
            case 2:
                printf("Enter key to delete: \n");
                scanf("%s", kstr);
                delete(kstr);
                break;
            case 3:
                printf("Enter key to search: \n");
                scanf("%s", kstr);
                search(kstr);
                break;
            case 4:
                iterate();
                break;
            case 5:
                print();
                break;
            case 6:
                printf("Enter key to check: \n");
                scanf("%s", kstr);
                printf("%s \n", contains(kstr) ? "true" : "false");
                break;
            case 0:
                printf("Exiting....\n");
                break;
            default:
                printf("Invalid option. Please enter a correct option.\n");
                break;
        }
    } while (ch != 0);

    // Free the allocated memory for the linked hashmap
    free(lnk_hashmap);

    return 0;
}

// Function to insert a key-value pair into the linked hashmap
void insert(char *key, char *value) {
    int index = hashfun(key);

    // Check if the key already exists
    if (contains(key)) {
        printf("Duplicate keys are not allowed.\n");
        return;
    }

    // Create a new node and initialize its values
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->key, key);
    strcpy(newnode->value, value);
    newnode->next = lnk_hashmap->linked_hashmap[index];
    lnk_hashmap->linked_hashmap[index] = newnode;

    // Update the linked list pointers
    if (head == NULL) {
        head = tail = newnode;
        newnode->before = NULL;
        newnode->after = NULL;
    } else if (head != NULL) {
        tail->after = newnode;
        tail->after->before = tail;
        tail = newnode;
        tail->after = NULL;
    }

    printf("Insertion successful.\n");
}

// Function to delete a key-value pair from the linked hashmap
void delete(char *key) {
    int index = hashfun(key);

    if (contains(key)) {
        struct node *curr = NULL;
        struct node *prev = NULL;

        curr = lnk_hashmap->linked_hashmap[index];

        // Traverse the linked list to find the node with the given key
        while (curr != NULL) {
            if (strcmp(curr->key, key) == 0) {
                // Handle different cases for deletion based on the node's position in the list
                if (prev == NULL) {
                    if ((curr == head) && (curr == tail)) {
                        lnk_hashmap->linked_hashmap[index] = NULL;
                    } else if (curr == head) {
                        curr->after->before = NULL;
                        head = curr->after;
                    } else if (curr == tail) {
                        curr->before->after = NULL;
                        tail = curr->before;
                    } else {
                        curr->before->after = curr->after;
                        curr->after->before = curr->before;
                    }

                    lnk_hashmap->linked_hashmap[index] = curr->next;
                } else {
                    if (curr == head) {
                        curr->after->before = NULL;
                        head = curr->after;
                    } else {
                        curr->after->before = curr->before;
                        curr->before->after = curr->after;
                    }

                    prev->next = curr->next;
                }

                free(curr);
                printf("Deleted key '%s' in bucket [%d].\n", key, index);
                return;
            }

            prev = curr;
            curr = curr->next;
        }
    }
}

// Function to search for a key in the linked hashmap
void search(char *key) {
    int index = hashfun(key);
    struct node *iterate = lnk_hashmap->linked_hashmap[index];

    if (contains(key)) {
        while (iterate != NULL) {
            if (strcmp(iterate->key, key) == 0) {
                printf("Key '%s' found in bucket [%d].\n", key, index);
                return;
            }
            iterate = iterate->next;
        }
    } else {
        printf("Key does not exist in bucket [%d].\n", index);
    }
}

// Function to iterate over the linked hashmap and print its contents
void iterate() {
    int i;
    struct node *iterate;

    for (i = 0; i < SIZE; i++) {
        iterate = lnk_hashmap->linked_hashmap[i];
        printf("Bucket [%d] - ", i);

        while (iterate != NULL) {
            printf("| %s,%s | ", iterate->key, iterate->value);
            iterate = iterate->next;
        }

        printf("\n");
    }

    printf("Iteration complete.\n");
}

// Function to print the key-value pairs in the linked list order
void print() {
    struct node *iterate = head;
    printf("[ ");

    while (iterate != NULL) {
        printf("%s, %s\n", iterate->key, iterate->value);
        iterate = iterate->after;
    }

    printf(" ] \n");
    printf("Print completed.\n");
}

// Function to check if a key exists in the linked hashmap
bool contains(char *key) {
    int index = hashfun(key);
    struct node *iterate = lnk_hashmap->linked_hashmap[index];

    while (iterate != NULL) {
        if (strcmp(iterate->key, key) == 0) {     //strcmp function returns 0 if equal strings are checked this way because string is array pointed by pointer of its variable 
            return true;
        }
        iterate = iterate->next;
    }
    return false;
}

// Function to create the linked hashmap
void create_linkedhashmap() {
    lnk_hashmap = (struct linked_hashmap *)malloc(sizeof(struct linked_hashmap));
    int i;
    head = NULL, tail = NULL;
    for (i = 0; i < SIZE; i++) {
        lnk_hashmap->linked_hashmap[i] = NULL;
    }
}

// Function to compute the hash value for a key
int hashfun(char *key) {
    unsigned long hash = 5381;
    int c;

    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

   int index = hash%SIZE;
  
    return index;
}
;
}
