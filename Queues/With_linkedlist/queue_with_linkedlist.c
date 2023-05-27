#include <stdio.h>
#include <stdlib.h>

void enqueue(int);
void dequeue();
void display();
void peek();
void size_stack();

struct node
{
  int data;
  struct node *next;
};

struct node *newnode, *front = NULL, *rear = NULL, *iterate = NULL;

int size = 0, num = 0;

int main()
{
  int ch = -1;
  do
  {
    printf("\n");
    printf("1. enqueue\n");
    printf("2. dequeue\n");
    printf("3. peek\n");
    printf("4. display\n");
    printf("5. size of stack\n");
    printf("0. exit \n");
    printf("\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("enter number\n");
      scanf("%d", &num);
      enqueue(num);
      break;
    case 2:
      dequeue();
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
      printf("-----exiting----\n");
      break;

    default:
      printf("enter correct choice\n");
      break;
    }

  } while (ch != 0);
}

void enqueue(int num)
{
  if (front == NULL)
  {

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    front = newnode;
    iterate = newnode;
    rear = newnode;
    size++;
  }
  else
  {

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    rear->next = newnode;
    rear = newnode;
    size++;
  }
}

void dequeue()
{

  if (front == NULL)
  {

    printf("queue is empty\n");
  }
  else
  {
    if (size <= 1)
    {
      printf("dequeued item %d\n", front->data);
      front = iterate = rear = NULL;
      size--;
    }
    else
    {
      iterate = front;
      printf("dequeued item %d\n", front->data);
      front = front->next;
      iterate = front;
      size--;
    }
  }
}

void display()
{
  if (front == NULL)
  {

    printf("queue is empty");
  }
  else
  {
    iterate = front;

    while (iterate != NULL)
    {
      printf("%d ", iterate->data);
      iterate = iterate->next;
    }
  }
}

void peek()
{
  if (front == NULL)
  {
    printf("queue is empty\n");
  }
  else
  {

    printf("%d \n", front->data);
  }
}

void size_stack()
{

  if (front == NULL)
  {

    printf("queue is empty\n");
  }
  else
  {

    printf("%d \n", size);
  }
}
