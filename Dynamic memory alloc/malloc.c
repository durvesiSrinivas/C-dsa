#include<stdio.h>
# include<stdlib.h>

int main(){

int *ptr, i, n=5;

    ptr= (int *) malloc(sizeof( int ) * n);    
   printf("enter elements of array:\n");
       for(i=0; i<n; i++){
            scanf("%d", (ptr+i));
            }
   printf("elements of dynamic malloc :\n");
             for(i=0; i<n; i++){
                  printf("%d ", *(ptr+i));
              }         
         free(ptr);           
    
    return 0;
    }
