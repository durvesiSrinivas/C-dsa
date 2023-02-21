#include<stdio.h>
#include<stdlib.h>

void createAt_end(int );
void deleteAt_end();
void traverse();
void createAt_start(int);
void deleteAt_start();
int size_List();

struct node {
int data;
struct node *next;
};

struct node *head=NULL, *newnode, *tail_top=NULL, *iterate=NULL;
int size=0;


int main(){
int ch=-1, num=0;
do{
printf("\n");
printf("Enter your choice\n");
printf("1. create node at end\n");
printf("2. create node at start\n");
printf("3. delete node at end\n");
printf("4. delete node at start\n");
printf("5. traverse\n");
printf("6. size of list\n");
printf("0. exit\n");
scanf("%d", &ch);
printf("\n");

switch (ch)
{
case 1:
    printf("enter number");
    scanf("%d", &num);
    createAt_end(num);    
    break;
case 2:
    printf("enter number");
    scanf("%d", &num);
    createAt_start(num);
    break;
case 3:
    deleteAt_end();
    break;
case 4:
    deleteAt_start();
    break;
case 5:
    traverse();
    break;
case 6:
     printf("%d",size_List());
    break;


case 0:
    printf("----exiting----");
    break;


default:
    printf("enter correct choice");
    break;
}



}while(ch!=0);


}

void createAt_end(int num){
if(head==NULL){

newnode= (struct node *) malloc(sizeof(struct node));
newnode->data=num;
newnode->next=NULL;
head=iterate=tail_top=newnode;
size++;

printf("created at end success");
}else{

newnode= (struct node *) malloc(sizeof(struct node));
newnode->data=num;
newnode->next=NULL;
tail_top->next=newnode;
tail_top=newnode;
size++;
printf("created at end success");
}


}


void deleteAt_end(){

if(head==NULL){
printf("linked list is empty" );

}else{
     if(size<=1){

     tail_top= iterate=head=NULL;
     printf("deleted at end success" );
     }else{
     iterate=head;

     while (iterate->next->next!=NULL)
     {
        iterate= iterate->next;
     }
     
     tail_top=iterate;
     tail_top->next=NULL;
     size--;
     printf("deleted at end success" );

}

}

}


void traverse(){
    if(head==NULL){
printf("linked list is empty" );

}else{
     iterate=head;
    while (iterate!=NULL)
    {
      printf("%d ", iterate->data);
      iterate=iterate->next; 
    }
    

    }
}



void createAt_start(int num){

if(head==NULL){
newnode= (struct node *) malloc(sizeof(struct node));
head=iterate=tail_top=newnode;
newnode->data=num;
newnode->next=NULL;
size++;
printf("created at start success");


}else{
iterate=head;
newnode= (struct node *) malloc(sizeof(struct node));
newnode->data=num;
head=newnode;
newnode->next=iterate;
iterate=newnode;
size++;
printf("created at start success");

    
}

}




void deleteAt_start(){

    if(head==NULL){
printf("linked list is empty" );

}else{
  iterate=head;

   head= head->next;
   iterate=head;
   size--;
printf("deleted at start success" );



}
}

int size_List(){
    return size;
}