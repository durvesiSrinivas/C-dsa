#include <stdio.h>
#define N 5

void enqueue(int);
void dequeue();
void display();
void peek();

int queue[N], front = -1, rear = -1;

int main()
{
    int ch = -1, num = 0;

    do
    {
        printf("\n");
        printf("enter your choice\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. peek\n");
        printf("4. display\n");
        printf("0. exit\n");
        scanf("%d", &ch);
        printf("\n");

        switch (ch)
        {
        case 1:

            printf("enter an number");
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
        case 0:
            printf("-----exiting-----");
            break;

        default:
            printf("enter a valid choice");
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
        printf("inserted successfully");
    }
    else if (rear == N - 1)
    {

        printf("queue is overflow");
    }
    else
    {
        rear++;
        queue[rear] = num;
        printf("inserted successfully");
    }
}

void dequeue()
{

    if (front == -1 && rear == -1)
    {

        printf("queue is empty");
    }
    else if (front == rear)
    {
        printf("dequeued element is %d", queue[front]);
        front = rear = -1;
    }
    else
    {

        printf("dequeued element is %d", queue[front]);
        front++;
    }
}

void peek()
{

    if (front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else
    {

        printf("top element is %d", queue[front]);
    }
}
void display()
{

    if (front == -1 && rear == -1)
    {

        printf("queue is empty");
    }
    else
    {
        int i;
        for (i = front; i <= rear; i++)
        {

            printf("%d", queue[i]);
        }
    }
}
