//vector implementation   in c 
#include<stdio.h>
#include<stdlib.h>

void add(int);
void remove_last();
void set(int, int);
void delete_at(int);
void get(int);
void search(int);
void traverse();

int  count=-1, * ptr, * ptr2, n=5 ;
 

int main(){
int ch=-1, num=0, index=0 ;
ptr= (int *) malloc(n * sizeof(int)); 
    
      do{
      printf("\n");
      printf("enter your choice\n");
      printf("1. add element\n");
      printf("2. remove element\n");
      printf("3. insert at index\n");
      printf("4. remove at index\n");
      printf("5. get element at index\n");    
      printf("6. search element\n"); 
      printf("7. traverse elements\n"); 
      printf("0. exit\n");
      scanf("%d", &ch);
      printf("\n");  
      switch(ch){
                case 1: printf("enter element\n");
                              scanf("%d", &num);
                              add(num);
                              break;  
                case 2:  remove_last();
                              break;                                  
                case 3: printf("enter index and  element to insert\n");
                              scanf("%d%d",&index, &num);
                              set(index,num);
                              break;                                  
                case 4:  printf(" enter index to delete  element\n");
                              scanf("%d", &num);
                              delete_at(num);
                              break;                                   
                case 5:  printf("enter index to get element\n");
                              scanf("%d", &num);
                              get(num);
                              break;                                  
                case 6:  printf("enter  element to search\n");
                              scanf("%d", &num);
                              search(num);
                               break;                                  
                case 7: traverse();
                              break;   
                 case 0:  printf("exiting....\n");
                                  free(ptr);
                                  break;                                   
                       }               
          }while(ch!=0);    
   
       return 0;
  }
    
   
void add(int num){
       count++;
       ptr[count]=num;
       if(count==(n-1)){
        n= (n + (n*30)/100) ;
        ptr2 =  ( int *) realloc( ptr , n * sizeof(int) );
        if(ptr2 == NULL ){
               printf("reallocate is not possible\n");
               free(ptr2);
               return ; 
         }
            ptr=ptr2;
        } 
   printf("added success\n");             
    }
    
void remove_last(){
    int num;
    num=ptr[count];
    count-- ;
    printf("removed element at last %d\n", num);    
   }
   
   
void set(int index, int num){
    if(index<0 || index>count ){
             printf("index is not in range\n");     
             return;        
        }else{
           int i = count;
           while(i >= index){
               ptr[ i+1 ] = ptr[ i ];
               i--;  
               }
           ptr[index]=num;
           count++;
           printf("inserted element success\n");                             
                }
    }
    
void delete_at(int index){
    int i;
    if(index<0 || index>count){
        printf("index is not in range\n");
        return;
        }
        int num=ptr[index];
    for(i=index; i<=count; i++){
        ptr[i]=ptr[i+1];
          }
    count--; 
    printf("deleted element %d at index %d\n",num,index);
    }
    
    
void get(int index){
    printf("element at index %d is %d \n", index, ptr[index]);
    
    }
void search(int key){
    int i;
    for(i=0 ; i<=count; i++){
          if(key==ptr[i]){
              printf("element %d found at %d\n",key,  i);
              break;
              }
        }
    
    
    }
    
    
void traverse(){
    int i;
    for(i=0 ; i<=count; i++){
     printf(" %d -  %d\n", i, ptr[i]);
           }         
    }
    
    