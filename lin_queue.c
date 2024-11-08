#include <stdio.h>
#define N 100
int queue[N];
int front = -1, rear = -1;
void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("Overflow\n");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        queue[++rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow.\n");
        return;
    }
    if (front == rear)
        front = rear = -1;
    else
        front++;
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
int main()
{
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    dequeue();
    display();
    return 0;
}
