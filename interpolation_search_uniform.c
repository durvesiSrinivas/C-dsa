#include<stdio.h>

// Function to perform interpolation search
int ipl(int [], int, int, int);

int size, index = -1;

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size], i, key;

    printf("Enter the elements of the sorted uniformly distributed array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key element to find: ");
    scanf("%d", &key);

    // Check if the key is within the range of the array
    if (key < arr[0] || key > arr[size - 1]) {
        printf("Key is not in the range of the array. Search is not possible.\n");
    } else {
        printf("Key is within the range of the array. Search is possible.\n");

        // Perform interpolation search
        index = ipl(arr, 0, size - 1, key);

        if (index != -1) {
            printf("Element found at index %d.\n", index);
        } else {
            printf("Element not found in the array.\n");
        }
    }

    return 0;
}

// Interpolation search algorithm
int ipl(int arr[], int l, int h, int key) {
    // Calculate the interpolation position
    int loc = (int)(l + ((double)(key - arr[l]) / (arr[h] - arr[l])) * (h - l));

    // Check if the key is found at the interpolation position
    if (arr[loc] == key) {
        return loc; // Key found at index return loc
    } else {
        return -1; // Key not found
    }
}

    

