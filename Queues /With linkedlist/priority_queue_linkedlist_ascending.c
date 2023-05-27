#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 5

void enqueue(int, int);
void dequeue();
void display();
void peek();
int lowestpriority();     //lowest priority i.e find min number in array algorithm 
int isempty();
int isfull();

struct node {

	int data;
	int priority;
	struct node *next;

};

struct node *newnode = NULL, * head = NULL, * tail = NULL, * iterate = NULL, * iterate2=NULL;
int arr[2] = { 0,0 };
int size = 0, i = 0;


void main() {

	int enumr=0, eprior=0, ch=-1;


	do {

		printf("enter your choice \n");
		printf("1. enqueue\n");
		printf("2. dequeue\n");
		printf("3. display\n");
		printf("4. peek\n");
		printf("5. size\n");
		printf("0. exit\n");
		scanf("%d", &ch);
		printf("\n");

		switch (ch)
		{
		case 1:
			printf("enter data and priority \n");
			scanf("%d,%d",&enumr, &eprior );
			enqueue(enumr, eprior);
			break;
		
		case 2:

			dequeue();
			break;

		case 3:

			display();
			break;

		case 4:

			peek();
			break;

		case 5:
			printf("size of queue %d\n",size);
			break;

		case 0:

			printf("----exiting------\n");
			break;

		default:
			printf("enter correct choice");
			break;
		}


	} while (ch != 0);

   
}


void enqueue(int enumr, int eprior) {

	if (isfull()) {

		printf("queue is full\n");
	}
	else if (isempty()) {

		newnode = (struct node*)malloc(sizeof(struct node));
			if (newnode == NULL) {     //to free pointer if malloc fails to alocate memory and returns null 

				free(newnode);
				newnode = NULL;
			}
			else {
				newnode->data = enumr;
				newnode->priority = eprior;
				newnode->next = NULL;
				head= tail = newnode;
				
				size++;
			}

	}
	else {
		newnode = (struct node*)malloc(sizeof(struct node));
		if (newnode == NULL) {

			free(newnode);
			newnode = NULL;
		}
		else {

			newnode->data = enumr;
			newnode->priority = eprior;
			newnode->next = NULL;
			tail->next = newnode;
			tail = newnode;
			size++;
		}

	}
}


void dequeue() {

	

	if (isempty()) {

		printf("queue is empty \n");

	}else if (head==tail) {      // if single node present in queue is there delete after storing data and priority in gglobal array

		arr[0] = head->data;
		arr[1] = head->priority;
		head = tail = NULL;
		size--;

		printf("data- %d |priority- %d \n", arr[0], arr[1]);
		

	}else {
		int prl = lowestpriority();   //return lowest priority number in whole queue 
		iterate2 = iterate = head;     // start from starting of list

		while (iterate!=NULL) {         

			if(prl == iterate->priority) {      // if lowest node found in queue store those values in array
			
				arr[0] = iterate->data;
				arr[1] = iterate->priority;
				break;                          // iterate stops at lowest priority index in lis5
			} 
			iterate = iterate->next;           
		}

		if (iterate==head) {      // if above iterate stops at head

			head = head->next;
			size--;
		}else if (iterate==tail) {             // if above iterate stops at tail

			while (iterate2->next!=tail) {      // get iterate2 behind tail delete last node

			iterate2 =	iterate2->next;
			 
			}
		      iterate2->next=NULL;
			  tail = iterate2;
			  size--;
		}
		else {                         // if iterate stops between head and tail

		
			while (iterate2->next != iterate ) {  // bring iterate2 behind iterate     

			  iterate=	iterate2->next;
			}
			iterate2->next = iterate->next;     //connect behind and before nodes link and delete iterate node
			size--;
		}
		printf("data- %d |priority- %d \n", arr[0], arr[1]);   //print array stored values
	}

	
}



void display() {

	iterate = head;
	i = 0;
	while(iterate!=NULL){
	
		printf("| %d |data- %d |priority- %d |\n", i, iterate->data, iterate->priority);
		i++;
		iterate = iterate->next;
	}

}


void peek() {
	iterate = head;
	printf("| data- %d | priority- %d\n", iterate->data, iterate->priority );
    
}



int lowestpriority() {
	iterate = head;
	int lp= iterate->priority ;


	while (iterate!=NULL) {     //min number in queue algorithm
		if ( iterate->priority<=lp) {

			lp = iterate->priority;
		}
		iterate= iterate->next;
	}
	return lp;
}



int isempty() {

	if (head==NULL) {

		return 1;
	}
	else {

		return 0;
	}

}



int isfull() {

	if (size==N) {

		return 1;
	}
	else {

		return 0;
	}


}

