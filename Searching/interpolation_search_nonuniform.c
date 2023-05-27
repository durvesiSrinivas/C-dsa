// interpolation search nonuniform
#include<stdio.h>

int size; // Variable to store the size of the array

// Function declaration for interpolation search
int ipl(int [], int, int, int);

int main() {
    printf("enter size of array\n");
    scanf("%d", &size);
    
    int arr[size], i, key, loc=-1;
    printf("enter elements of array\n");   
    for(i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("enter key to find array\n");
    scanf("%d", &key);
    
    // Check if key is within the range of the array
    if(key < arr[0]  || key > arr[size-1]) {
        printf("key is not in range search is not possible\n");
    } else {
        // Perform interpolation search
        loc = ipl(arr, 0, size-1, key);
        
        // Check if element is found or not
        if(loc != -1) {
            printf("element found at %d\n", loc);  
        } else {
            printf("element not in array");            
        }
    }         
                                          
    return 0;
}

// Interpolation search function
int ipl(int arr[], int l, int h, int key) {
    // Check if the current segment is valid and if the key is within the range
    if(l <= h && key >= arr[l] && key <= arr[h]) {
        // Calculate the position using interpolation formula
        int pos = l + ((key - arr[l]) * (h - l)) / (arr[h] - arr[l]);
        
        // If key is found at the calculated position
        if(arr[pos] == key) {
            return pos;
        } else if(arr[pos] < key) {
            // If key is greater, search in the right segment
            return ipl(arr, pos+1, h, key);
        } else {
            // If key is smaller, search in the left segment
            return ipl(arr, l, pos-1, key);
        }
    }
    
    // Key is not found within the current segment
    return -1;
}
