// linear search
#include<stdio.h>
int linear_search(int[],int, int, int);
int size;

int main(){
printf("enter size of array\n");
scanf("%d", &size);
int arr[size], i, key, index=-1;
printf("enter array elements of array\n");        
for(i=0; i<size; i++){
    scanf("%d", &arr[i]);
     }
printf("enter key elements of array\n");     
 scanf("%d", &key);
 
 index= linear_search(arr, 0, size-1, key);
         
             if(index!=-1){
                 printf("element found at index %d\n",index);
                 }else{
                     printf("element not there in array\n");
                     }    
             
                     
    return 0;
    }
    
    int linear_search(int arr[], int l, int h,  int key){
               int i, loc;
               for(i=0; i<size; i++){
                   if(arr[i]==key){
                       loc=i;
                       break;        
                       }
                   }
               
        if(arr[loc]==key){
        return loc;
              }else{
                  return -1;
                  }        
        
        }
