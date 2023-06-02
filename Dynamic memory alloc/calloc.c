#include<stdio.h>
#include<stdlib.h>

int  main(){
int *ptr, i, n=5;

ptr= (int *) calloc (n, sizeof(int));

printf("enter elements of dynamic memory:\n");
for(i=0; i<n; i++){
    scanf("%d", (ptr+i));
    }    

printf("elements of dynamic memory are:\n");
    for(i=0; i<n; i++){
    printf("%d ", *(ptr+i));
    }    
      free(ptr);      
    return 0;
    }
