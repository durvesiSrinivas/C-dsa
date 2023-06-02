#include<stdio.h>
#include<stdlib.h>

int n;

int main() {
    int i,j,k;
    
    // Prompt the user to enter the size of dynamic memory
    printf("Enter the size of dynamic memory: ");
    scanf("%d", &n);
    
    int *ptr, *ptr2;
    
    // Allocate memory using calloc for 'n' elements of type int
    ptr = (int*) calloc(n, sizeof(int));
    
    // Prompt the user to enter elements for dynamic memory
    printf("Enter elements of dynamic memory:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }
    
      // Print the elements of dynamic memory before realloc
    printf("Elements of dynamic memory before realloc:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    } 
    
      printf("\nEnter no of elements to increase size :\n");
      scanf("%d", &k);
    
    // Reallocate memory for 'n+2' elements of type int
    ptr2 = (int*) realloc(ptr, (n + k) * sizeof(int));
    
    // Check if reallocation was successful
    if (ptr2 == NULL) {
        printf("Reallocation not possible\n");
        free(ptr2);
    }
    
    // Prompt the user to enter new elements for the extra allocated memory
    printf("\nEnter new extra allocated memory elements:\n");
    for (j = i; j < (n + k); j++) {  // start from last ith index where previous index stoped reading integers 
        scanf("%d", ptr2 + j);
    }
    
   
    
    // Print the elements of dynamic memory after realloc
    printf("Elements of dynamic memory after realloc:\n");
    for (i = 0; i < (n + k); i++) {
        printf("%d ", *(ptr2 + i));
    } 
   
   // Free the allocated memory
   free(ptr2);
    
   return 0;   
}
