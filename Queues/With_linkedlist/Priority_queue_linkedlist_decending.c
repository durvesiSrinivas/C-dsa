#define _CRT_SECURE_NO_WARNINGS     //For scanf Secure warnings 
#include<stdio.h>
#include<stdlib.h>
#define N 5                        //The size of linked list up to 5 



void enqueue(int, int);            //enqueue function with two parameters data and priority 
void dequeue();                    //dequeue function 
void display();                    // display all Data in linked list 
int peek();                         //To display top element in queue i.e First element 
int highest_priority();            // find highest number priority in queue
int isempty();                     //queue is empty return 1 else 2 
int isfull();                      //queue is full return 1 else 2 

struct node {

	int data;
	int priority;
	struct node* next;

};

struct node *newnode, *head=NULL, *iterate = NULL, *iterate2 = NULL, *tail = NULL;
int size = 0, arr[2] = { 0,0 };

void main() {

	int enumr = 0, epriorty = 0, ch = -1;



	do {

		printf("1. enqueue\n");
		printf("2. dequeue\n");
		printf("3. display\n");
		printf("4. peek\n");
		printf("0. exit\n");
		scanf("%d", &ch);
		printf("\n");

		switch (ch) {

		case 1:
			printf("enter data and priority\n");
			scanf("%d,%d", &enumr, &epriorty);
			enqueue(enumr, epriorty);
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


		case 0:
			printf("-----exiting-----");
			break;


		default:
			printf("enter valid choice\n");
			break;
		}



	} while (ch != 0);

}


void enqueue(int enumr, int epriorty) {

	if (isfull()) {

		printf("queue is full\n");


	}
	else if (isempty()) {

		newnode = (struct node*)malloc(sizeof(struct node));
		if (newnode == NULL) {              //Free malloc memory if malloc returns null i.e if it fails to alocate it return null else gives warnings
			free(newnode);
			newnode = NULL;
		}else {
			newnode->data = enumr;
			newnode->priority = epriorty;
			newnode->next = NULL;
			head = newnode;
			tail = newnode;
			size++;
		}
	}
	else {

		newnode = (struct node *)malloc(sizeof(struct node));
		if (newnode == NULL) {
			free(newnode);
			newnode = NULL;
		}
		else {
			newnode->data = enumr;
			newnode->priority = epriorty;
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

	}
	else if (head == tail) {       //If there is single element then head equals to tail return data and priority make head and tail null
		iterate = head;
		printf("| data- %d | priority- %d |\n", head->data, head->priority);
		head = iterate = tail = NULL;
		size--;
	}
	else {


		int prh = highest_priority();      // get highest priority in whole queue
		iterate = iterate2 = head;         // get iterate and iterate2 to head -starting position

		while (iterate != NULL)      //loop until iterate value equal to null
		{ 
			if (prh == iterate->priority) {      // if highpriority node found store values in static arr indexes

				arr[0] = iterate->data;
				arr[1] = iterate->priority;
				break;
			}
			iterate = iterate->next;
		}


		if (iterate == head) {    //if above iterate stops at starting head node then delete first node
			head = head->next;
		}
		else if (iterate == tail)         //if above iterate stops at last node then take iterate2 to behind of iterate
		{
			while(iterate2->next!=iterate){
				iterate2=iterate2->next;
			}
			iterate2->next = NULL;            //delete last node using iterate2 and tail
			tail = iterate2;

		}
		else {
              
			while (iterate2->next!=iterate) {   // if iterate stops between head and tail take iterate2 behind iterate

				iterate2 = iterate2->next;       
			}

			iterate2->next = iterate->next;     // connect behind and before chain links of iterate amd delete iterate node 

		}

		
		printf("| data- %d | priority- %d |\n", arr[0], arr[1]);
		size--;

	}

}


void display() {

	if (isempty()) {


		printf("queue is empty\n");

	}
	else {
		iterate = head;
		int i = -1;
		while (iterate != NULL) {
			i++;
			printf("| %d | data-%d |priority- %d |\n", i, iterate->data, iterate->priority);
			iterate = iterate->next;
		}

	}

}



int peek() {

	if (isempty()) {

		printf("queue is empty\n");

	}
	else {

		printf("| data- %d | priority- %d |\n", head->data, head->priority);

	}


}



int highest_priority() {
	iterate = head;
	int hp = iterate->priority;  // make first element priority as hp variable

	while (iterate != NULL) {             

		if (hp <= iterate->priority) {   //loop through queue and make ph value high priority value just like max number in arry algorithm

			hp = iterate->priority;
		}

		iterate = iterate->next;
	}
	return hp;
}




int isempty() {

	if (head == NULL) {

		return 1;
	}
	else {

		return 0;
	}

}




int isfull() {

	if (size == N) {

		return 1;
	}
	else {

		return 0;
	}
}



