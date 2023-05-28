#include<stdio.h>

// Declare a global variable for the size of the array
int size;

// Function prototype for the insertion sort
void insertion_sort(int[]);

int main() {
    // Prompt the user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Declare an array of given size and an index variable
    int arr[size], i;

    // Prompt the user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the elements of the array before sorting
    printf("Elements of the array before sorting: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Call the insertion_sort function to sort the array
    insertion_sort(arr);

    // Display the elements of the array after sorting
    printf("\nElements of the array after sorting: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Implementation of the insertion sort algorithm
void insertion_sort(int arr[]) {
    int i, j;

    for(i = 1; i < size; i++) {
        int temp = arr[i];
        for(j = i - 1; j >= 0 && arr[j] > temp; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}
