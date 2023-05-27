#include<stdio.h>
#include<stdlib.h>


void push(int);
void pop();
void peek();
void display();
void size_stack();


struct node
{
    int data;
    struct node *next;
    
};


struct node *newnode, *head=NULL,*tail_top=NULL,  *iterate=NULL; 
int size=0;



void main(){
int ch=-1, num=0; 
do{
printf("\n");
printf("1. push\n");
printf("2. pop\n");
printf("3. peek \n");
printf("4. display\n");
printf("5. size\n");
printf("0. exit\n");
scanf("%d", &ch);
printf("\n");


switch (ch)
{
case 1:
    printf("enter number\n");
    scanf("%d", &num);
      push(num);
    break;
case 2:
       pop(); 
    break;
case 3:
   peek();
    break;
case 4:
      display();
    break;
case 5:
      size_stack();
    break;
case 0:
   printf("------exiting-----\n");
    break;

default:
    printf("invalid choice \n");
    break;
}



}while(ch!=0);
}




void push(int num){

if(head==NULL){
    
newnode= (struct node *) malloc(sizeof(struct node));
newnode->data=num;
newnode->next=NULL;
head=iterate=tail_top=newnode;
size++;



}else{
newnode= (struct node *) malloc(sizeof(struct node));
newnode->data=num;
newnode->next=NULL;
tail_top->next=newnode;
tail_top=newnode;
size++;

}

}



void pop(){

if(head==NULL){

printf("stack is empty\n");


}else if(size>=2){
iterate=head;
while (iterate->next!=tail_top)
{   
    iterate=iterate->next;
}
printf("poped item %d", tail_top->data);
tail_top=iterate;
tail_top->next=NULL;
size--;

}else{
printf("poped item %d", tail_top->data);
head=iterate=tail_top=NULL;
size--;
}

}


void peek(){
if(head==NULL){

printf("stack is empty\n");


}else{
printf("top item %d", tail_top->data);

}

}
void display(){

if(head==NULL){

printf("stack is empty\n");


}else{

     iterate=head;
     while (iterate!=NULL)
     {
        printf("%d ", iterate->data);
        iterate=iterate->next;
     }
     

  }
    
}


void size_stack(){
 if(size==0){
   printf("stack size is empty");
 }else{
  printf("%d", size);
 }
}
