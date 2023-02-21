#include<stdio.h>
#define size 5
void push(int);
int pop();
int peek();
void display(); \\ display function

int stack[size];
int top=-1;


void main(){

int ch=-1, num=0;
do{
printf("\n");    
printf("enter your choice\n");
printf("1. push\n");
printf("2. peek\n");
printf("3. pop\n");
printf("4. display\n");
printf("0. exit\n");
scanf("%d", &ch);
printf("\n");
switch (ch)
{
case 1:
    printf(" Enter number \n");
    scanf("%d", &num);
    push(num);
    
    break;

case 2:
       printf("%d \n",peek());

    break;
case 3:
        pop();
       break;
case 4: 
       display();
    
       break;
case 0:
      printf("-----exiting----\n");
    break;


default:
       printf("NAN-select only above choice\n");
    break;
}


}while(ch!=0);

}

void push(int num){
     if(top>=size-1){
       printf("stack is overflow\n");
        return;
     }else{
       top++;
       stack[top]=num;
        printf("pushed success\n");
     }
      
}
int pop(){
 if (top==-1)
 {
    printf("underflow\n");
    
 }else{
    int t=top;
    top--;    
    return stack[t];

 }
 
}

int peek(){
if(top==-1){
   
   printf("stack is empty\n");
   

}else{
    return stack[top];   
}


}


void display(){
    int i;
    for ( i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
    
}
