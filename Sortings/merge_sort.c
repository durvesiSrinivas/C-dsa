#include<stdio.h>
int size;    //size as global
void merge_sort(int [], int , int);       //declaration of functions
void merge(int [], int, int , int);


int main(){
int i;
printf("enter size of array\n");
scanf("%d", &size);          //read size of array
int arr[size];                      //initialise array with size        
printf("\n enter elements of array\n");

    for(i=0;i<size; i++){
          scanf("%d", &arr[i]);               //read elements of array
       }
merge_sort(arr, 0, size-1);               //call mergesort with left and right index

  printf("\n elements of array after merging:\n");
  
  for(i=0;i<size; i++){
         printf("%d ", arr[i]);                 // print array arr
       }  
    
    
   return 0; 
    }
    
void merge_sort(int arr[] , int l , int r){
        if(l<r){                                   //call recursively until left not equals to right 
            int mid= (l+r)/2;
            merge_sort(arr, l, mid );             //divide 1st array upto mid
            merge_sort(arr, mid +1, r);       //divide 2nd array upto right
            merge(arr, l, mid, r);                  //merge 1st and 2nd array elements 
            }
      }
        
    void merge(int arr[], int lf, int md, int rt){
    int p=lf, q=md+1, k=lf, temp[size], j;        //initialise p,q to starting index of two arrays
    
    while(p<=md && q<=rt  ){              //check condition if p,q are inside last index of two arrays
          if(arr[p]<arr[q]){   
                 temp[k]=arr[p];                   //get lowest element of both arrays and store in temporary array from 0 increasgly
                 p++ ;
           } else{                                       // check if 2nd array  of q index is greatest then store arr of q in temp array
                 temp[k]=arr[q];
                 q++;  
           }
                   k++;  
          }
    
              while(p<=md){                          //if some elements remain in 1st array copy all elements to temp
                         temp[k]=arr[p];
                          p++; 
                          k++;    
              }
    
        while(q<=rt){                          //if some elements remain in 2nd array copy all elements to temp
                   temp[k]=arr[q];
                   q++;
                   k++;                        
                 }    
          
          for(j=lf; j<=rt; j++){           // copy again 1st and 2nd array elements to arr again for sorting them in recursive stack                
                      
                      arr[j]=temp[j];        // at last all the sorted elements are stored in arr can print from main method
                      
                      }      
                      
                            
                                        
        }    
        
    
    
