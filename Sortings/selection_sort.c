#include <stdio.h>

int size;

void selection_sort(int[]);

int main() {
    // Prompt the user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    // Declare an array of the given size and other variables
    int arr[size], i, j;
    
    // Prompt the user to enter the elements of the array
    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Print the elements of the array before sorting
    printf("Elements of the array before sorting:\n");
    for (j = 0; j < size; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
    
    // Call the selection_sort function to sort the array
    selection_sort(arr);
    
    // Print the elements of the array after sorting
    printf("Elements of the array after sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

// Function to perform selection sort on the array
void selection_sort(int arr[]) {
    int i, j, min;
    for (i = 0; i < size; i++) {
        min = i;
        
        // Find the minimum element in the unsorted part of the array
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        
        // Swap the minimum element with the current element if necessary
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
