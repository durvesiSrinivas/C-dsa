#include<stdio.h>

int size;
int binary_search(int [], int, int, int);

int main() {
    int i, key, loc = -1;

    // Input the size of the array
    printf("enter size of array\n");
    scanf("%d", &size);

    // Create an array of the given size
    int arr[size];

    // Input the sorted elements of the array
    printf("enter sorted elements of array\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the key to find
    printf("enter key to find\n");
    scanf("%d", &key);

    // Check if the key is within the range of the array
    if ((key < arr[0]) || (key > arr[size - 1])) {
        printf("element not in range of array");
    } else {
        // Perform binary search on the array
        printf("key is in range of array, search is possible\n");
        loc = binary_search(arr, 0, size - 1, key);
        if (loc != -1) {
            printf("element found at %d\n", loc);
        } else {
            printf("element not there in array\n");
        }
    }

    return 0;
}

// Binary search algorithm
int binary_search(int arr[], int lb, int ub, int key) {
    if (lb <= ub) {
        int mid = (lb + ub) / 2;

        if (key == arr[mid]) {
            return mid;  // Key found at the middle index
        } else if (key < arr[mid]) {
            // Key is smaller, search in the left half
            return binary_search(arr, lb, mid - 1, key);
        } else {
            // Key is larger, search in the right half
            return binary_search(arr, mid + 1, ub, key);
        }
    }

    return -1;  // Key not found
}
