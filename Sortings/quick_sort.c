#include<stdio.h>

// Function to partition the array
int partition(int arr[], int lb, int ub);

// Function to perform quicksort
void quick_sort(int arr[], int lb, int ub);

// Function to swap two elements
void swap(int *a, int *b);

int main() {
    int size, i, j;

    printf("Enter size of the array: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter elements of the array: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nElements of the array before sorting:\n");
    for(j = 0; j < size; j++) {
        printf("%d ", arr[j]);
    }

    quick_sort(arr, 0, size-1); // calling quicksort method, with 0 and size-1 as lb and ub

    printf("\nElements of the array after quick sort:\n");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Partition function for quicksort
int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    // Continue partitioning until start and end cross each other
    while(start < end) {
        // Move start pointer to the right until an element greater than pivot is found
        while(arr[start] <= pivot) {
            start++;
        }

        // Move end pointer to the left until an element smaller than or equal to pivot is found
        while(arr[end] > pivot) {
            end--;
        }

        // Swap the elements at start and end indices if start is still less than end
        if(start < end) {
            swap(&arr[start], &arr[end]);
            continue;  // Continue skip one step, start with next iteration of the outer while loop ,because loop starts with same value again after swap
        }
    }

    // Swap the pivot element with the element at the end index , arr[lb] first element as pivot 
    swap(&arr[end], &arr[lb]);

    // Return the index of the pivot element after swap of end and pivot
    return end;
}

// Quicksort function, lb is lower bound , ub is upper bound 
void quick_sort(int arr[], int lb, int ub) {
    if(lb < ub) {
        // Partition the array and get the pivot index to loc variable 
        int loc = partition(arr, lb, ub);

        // Recursively sort the left and right subarrays
        quick_sort(arr, lb, loc - 1);
        quick_sort(arr, loc + 1, ub);
    }
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
