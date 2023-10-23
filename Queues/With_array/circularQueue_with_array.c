#include <stdio.h>
#define N 5

void enqueue(int);
void dequeue();
void display();
void peek();
void size_queue();
int queue[N];
int ch = -1, size = 0, num = 0, front = -1, rear = -1;

void main()
{
    

    do
    {

        printf("\n");
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
            printf("enter number\n");
            scanf("%d", &num);
            enqueue(num);
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
            size_queue();
            break;
        case 0:
            printf("----exitiing----\n");
            break;

        default:
            printf("enter correct choice\n");
            break;
        }

    } while (ch != 0);
}

void enqueue(int num)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = num;
        size++;
    }
    else if ((rear + 1) % N == front) // (rear+1)%N  - modulas formula is used to get next index number from rear variable and,

    {                              // also to cycle count  from N variable back to 0 if rear variable exceeds N,
        printf("queue is full\n"); // same cycle applies  for rear and front variable to cycle in circle after reaching N.
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = num;
        size++;
    }
}

void dequeue()
{

    if (rear == -1 && front == -1)
    {

        printf("queue is empty\n");
    }
    else if (front == rear)
    {
        printf("%d \n", queue[front]);
        front = rear = -1;
        size = 0;
    }
    else
    {
        printf("%d \n", queue[front]);
        front = (front + 1) % N;
        size--;
    }
}

void display()
{

    if (front == -1 && rear == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        int i = front;
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d ", queue[i]);
    }
}
void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("%d ", queue[front]);
    }
}
void size_queue()
{
    printf("%d", size);
}
