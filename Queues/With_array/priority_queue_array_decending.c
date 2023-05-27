#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define N 5

void enqueue(int, int);  // inserting into queue in arbitary -ranadom way
int dequeue();           // delete and pop item in a priority way from high er to lower number
int get_high_priority(); // return the highest priority in decending order
void peek();             // get highest priority data, top of queue
void display();          // print total queue
int isempty();           // check queue is empty
int isfull();            // check queue is full
void size_queue();       // get size of queue

struct node
{ // creating struct array of size 5
    int data;
    int priority;

} p_queue_d[N];

int front = -1, rear = -1, size = 0;

void main()
{

    int ch = -1, num = 0, priority_num = 0;
    do
    {
        printf("\n");
        printf("Enter your choice\n");
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. peek\n");
        printf("4. display\n");
        printf("5. size\n");
        printf("0. exit\n");
        scanf("%d", &ch);
        printf("\n");

        switch (ch)
        {
        case 1:
            printf("enter number and priority\n");
            scanf("%d,%d", &num, &priority_num);
            enqueue(num, priority_num);
            break;
        case 2:
            printf("dequed %d \n", dequeue());
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            size_queue();
            break;

        case 0:
            printf("----exiting----");
            break;

        default:
            printf("enter correct choice");
            break;
        }
    } while (ch != 0);
}

void enqueue(int num, int priority_num)
{
    if (isempty())
    {
        front = rear = 0;
        p_queue_d[rear].data = num;
        p_queue_d[rear].priority = priority_num;
        size++;
        printf("success\n");
    }
    else if (isfull())
    {
        printf("queue is full\n");
    }
    else
    {
        rear++;
        p_queue_d[rear].data = num;
        p_queue_d[rear].priority = priority_num;
        size++;
        printf("success\n");
    }
}

int dequeue()
{
    int i, j, pnum = 0, hp = get_high_priority();

    if (isempty())
    {
        printf("queue is empty\n");
    }
    else if (front == rear)
    {

        pnum = p_queue_d[front].data;
        front = rear = -1;
    }
    else
    {
        for (i = front; i<=rear; i++)
        {
            if (hp == p_queue_d[i].priority)
            {
                pnum = p_queue_d[i].data;
                break;
            }
        }

        if (i<rear) {
            for (j = i; j < rear; j++)
            {
                p_queue_d[j].data = p_queue_d[j + 1].data;
                p_queue_d[j].priority = p_queue_d[j + 1].priority;
            }

        }

        

        rear--;
    }
    return pnum;
}
int get_high_priority()
{
    int p = p_queue_d[0].priority, i;
    for (i = front; i<=rear ; i++)
    {
        if (p <= p_queue_d[i].priority)
        {
            p = p_queue_d[i].priority;
        }
    }

    return p;
}
void peek()
{
    if (isempty())
    {
        printf("queue is empty\n");
    }
    else
    { 
       printf("peek elements\n");
       printf("data- %d  ",p_queue_d[front].data);
       printf("priority- %d  \n", p_queue_d[front].priority);
    }
}
void display()
{
    if (isempty())
    {
        printf("queue is empty\n");
    }
    else
    {
        int i;
        for (i = front; i < rear; i++)
        {
            printf("%d -| data-%d |priority-%d |\n", i, p_queue_d[i].data, p_queue_d[i].priority);
        }
    }
}
int isempty()
{

    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull()
{
    if (rear == (N - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void size_queue()
{
    if (size == -1)
    {

        printf("queue is empty\n");
    }
    else
    {
        printf("size of queue is %d", size);
    }
}
