#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define N 5

void enqueue(int, int);  // Function for enqueue Taking two parameters num and priority 
int* dequeue();         // dequeue returning pointer Address of array
void display();         //Display function Prince all structure array data
void peek();             //Peak function to return top of the queue i.e  front of queue
int isempty();           //queue empty function returns 1 if true else Return  0 
int isfull();             //queue full function Returns 1 if true else returns 0  
int lowest_priority();    //to find Highest priority in structure array

struct queue              //Structure array of size 'N' variable
{
	int data;
	int priority;
}p_queue_a[N];

int  front = -1, rear = -1, size = 0, i, j;
int* drarr;              // Pointer variable to store return array address 

void main() {
	int num = 0, prior = 0, ch = -1;

	do {
		printf("enter your choice \n");
		printf("1. enqueue \n");
		printf("2. dequeue \n");
		printf("3. display \n");
		printf("4. peek \n");
		printf("5. size of queue \n");
		printf("0. exit \n");
		scanf("%d", &ch);
		printf("\n");


		switch (ch)
		{
		case 1: printf("enter number , priority \n");
			scanf("%d,%d", &num, &prior);
			enqueue(num, prior);
			break;

		case 2:
			drarr = dequeue();     //dequeue returns constant array address, it can accessed by pointer drarr
			
			printf("dequed - %d , priority - %d \n", drarr[0], drarr[1]); // Accessing global array through Pointer drarr
			
			printf("success \n");

			break;

		case 3:
			display();
			break;
		
		case 4:
			peek();
			break;

		case 5:
			printf("size of queue %d \n", size);      // Size variable 
			break;

		case 0: printf("----exiting-----\n");
			break;


		default: printf("enter correct choice\n");
			break;
		}


	} while (ch != 0);

}

void enqueue(int eqnum, int eprior) {

	if (isfull()) {

		printf("queue is full \n");
	}
	else if (isempty()) {

		front = rear = 0;
		p_queue_a[rear].data = eqnum;
		p_queue_a[rear].priority = eprior;
		size++;
		printf("success\n");
	}
	else {

		rear++;
		p_queue_a[rear].data = eqnum;
		p_queue_a[rear].priority = eprior;
		size++;
		printf("success \n");
		
	}

	

}



int* dequeue() {

	int  ph = lowest_priority();  // Getting lost priority value in an array 
	static int darr[2] = { 0,0 };     //Initializing global array that has a scope of programm runtime 

	if (isempty()) {

		printf("queue is empty\n");
		darr[0] = 0;
		darr[1] = 0;

	}
	else if (front == rear)
	{
		darr[0] = p_queue_a[rear].data;
		darr[1] = p_queue_a[rear].priority;
		rear = front = -1;
		size++;
		printf("success \n");


	}
	else {


		for (i = front; i <= rear; i++) 
		{           

			if (ph == p_queue_a[i].priority) {   //Find matching priority ph value to priority in queue

				darr[0] = p_queue_a[i].data;         // Place the highest priority data and priority in static array 0 and 1 index. 
				darr[1] = p_queue_a[i].priority;      
				break;
			}

		}

		if (i < rear) {                    // Shift the values from deleted index To end of array
			for (j = i; j < rear; j++) {

				p_queue_a[j].data = p_queue_a[j + 1].data;
				p_queue_a[j].priority = p_queue_a[j + 1].priority;

			}

		}
		
		rear--;               // decrease size and rear
		size--;
	}

	return darr;
}



void display() {


	if (isempty()) {

		printf("queue is empty\n");

	}
	else {

		int i;
		for (i = front; i <= rear; i++) {

			printf("| %d | data - %d | priority - %d |\n", i, p_queue_a[i].data, p_queue_a[i].priority);
		}

		printf("success \n");
	}
}
void peek() {


	if (isempty()) {

		printf("queue is empty\n");

	}
	else {

		printf("} data- %d | priority - %d |\n", p_queue_a[front].data, p_queue_a[front].priority);
		printf("success \n");
	}

}

int isempty() {

	if (front == -1 && rear == -1) {

		return 1;
	}
	else {
		return 0;
	}

}


int isfull() {

	if (rear == (N - 1)) {

		return 1;
	}
	else {
		return 0;
	}

}



int lowest_priority() {              //Find the highest priority value in a queue 

	int lop = p_queue_a[0].priority, i;

	for (i = front; i <= rear; i++) {

		if (lop > p_queue_a[i].priority) {

			lop = p_queue_a[i].priority;
		}

	}

	return lop;

}



