#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 5


void enqueue_front(int);      //enqueue from front of queue
void enqueue_rear(int);       //enqueue from rear of queue
void dequeue_front();         // dequeue from front of queue
void dequeue_rear();          //dequeue from rear
void get_front();             // get front
void get_rear();             //get rear
void display();             //display queue items from front to rear
int isempty();             // queue is empty
int isfull();                // queue is full


int arr[N];                   //array queue
int front = -1, rear = -1;




void main() {

	int ch = -1, num = 0;


	do {
		printf("\n");
		printf("enter your choice\n");
		printf("1. enqueue front\n");
		printf("2. enqueue rear\n");
		printf("3. dequeue front\n");
		printf("4. dequeue rear\n");
		printf("5. get front\n");
		printf("6. get rear\n");
		printf("7. display\n");
		printf("0. exit\n");
		scanf("%d", &ch);
		printf("\n");



		switch (ch)
		{
		case 1:
			printf("enter number\n");
			scanf("%d", &num);
			enqueue_front(num);
			break;
		case 2:
			printf("enter number\n");
			scanf("%d", &num);
			enqueue_rear(num);
			break;
		case 3:
			dequeue_front();
			break;
		case 4:
			dequeue_rear();
			break;
		case 5:
			get_front();
			break;
		case 6:
			get_rear();
			break;
		case 7:
			display();
			break;

		case 0:
			printf("-----exiting------");
			break;

		default:
			printf("enter correct choice\n");
			break;
		}

	} while (ch != 0);


}




void enqueue_front(int num) {

	if (isempty()) {           //If empty make front and rear zero insert num
		front = rear = 0;        
		arr[front] = num;
		printf("success\n");
	}
	else if (isfull()) {         
		printf("queue is full\n");
	}
	else if (front == 0) {          //To insert both the front backwards 
		front = (N - 1);            //If it is in 0 Send the front to last index 
		arr[front] = num;
		printf("success\n");

	}
	else {

		front--;             // move front backwards insert 
		arr[front] = num;
		printf("success\n");
	}


}



void enqueue_rear(int num) {

	if (isempty()) {    //If empty make front and rear zero index insert num

		front = rear = 0;
		arr[rear] = num;
		printf("success\n");
	}
	else if (isfull()) {

		printf("queue is full\n");

	}
	else {

		rear++;     //Move rear forward tw insert 
		arr[rear] = num;
		printf("success\n");
	}


}


void dequeue_front() {

	if (isempty()) {

		printf("queue is empty\n");
	}
	else if (front == (N - 1)) {      //If Front is last index Make front zero index 

		printf("dequeued- %d\n", arr[front]);
		front = 0;
		printf("success\n");

	}
	else if (front == rear) {     //If front == rear ,dequeue and  make front and rear -1 

		printf("dequeued- %d\n", arr[front]);
		front = rear = -1;
		printf("success\n");
	}
	else if (front == (N - 1)) {      //If front equals to last index Make front 0 index   

		printf("dequeued- %d\n", arr[front]);
		front = 0;
		printf("success\n");
	}
	else {

		printf("dequeued- %d\n", arr[front]);
		front++;                               //To delete move front forward 
		printf("success\n");
	}

}


void dequeue_rear() {

	if (isempty()) {

		printf("queue is empty\n");

	}
	else if (front == rear) {

		printf("dequeued %d\n", arr[rear]);
		front = rear = -1;
		printf("success\n");
	}
	else {

		printf("dequeued- %d\n", arr[rear]);
		rear--;                                //To delete move rear backwards 
		printf("success\n");

	}


}

void get_front() {

	if (isempty()) {

		printf("queue is empty\n");

	}
	else {


		printf("front- %d", arr[front]);    //Get Front index 

	}
}


void get_rear() {

	if (isempty()) {

		printf("queue is empty\n");

	}
	else {


		printf("rear- %d", arr[rear]);    //Get rear index 

	}
}

void display() {


	if (isempty()) {

		printf("queue is empty\n");

	}
	else {

		int i = front;

		while (i != rear) {

			printf("%d ", arr[i]);

			i = ((i + 1) % N);        //Formula to revolve around the circular queue 
		}
		printf("%d \n", arr[i]);

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

	if ((front == 0) && (rear == (N - 1))) {    //If front is 0 and rear is in lost index 

		return 1;

	}
	else if (front == (rear + 1)) {         //if front index equals rear+1 i.e followed back of front index

		return 1;
	}
	else {

		return 0;
	}


}



