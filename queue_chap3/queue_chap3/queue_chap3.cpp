#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 8

typedef char element;

typedef struct Circle_Queue {
    int rear; //후단
    int front; //앞단
    element data[MAX_SIZE];
}queue;

typedef struct client {
    char name[10];
    char s[2];
};

void init_queue(queue *q)
{
    q->rear =  q->front  = 0;
}

int is_empty(queue* q)
{
    return q->rear == q->front;
}

int is_full(queue* q)
{
    return q->front == (q->rear + 1) % MAX_SIZE;
}

int main()
{
    queue m; // male queue
    queue f; // female queue
    printf("hello");
}
