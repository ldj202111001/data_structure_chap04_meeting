#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 8
#define MAX_NAME 10

typedef struct Meeting {
    char name[10];
    char s[2];
}meeting;

typedef meeting element;

typedef struct Circle_Queue {
    int rear; //후단
    int front; //앞단
    element client[MAX_SIZE];   // 구조체 배열
}queue;


void error()
{
    printf("error");
}

void init_queue(queue* q)
{
    q->rear = 0;
    q->front = 0;
}

int is_empty(queue* q)
{
    return q->rear == q->front;
}

int is_full(queue* q)
{
    return q->front == (q->rear + 1) % MAX_SIZE;
}

void enqueue(queue* q, element val) // 큐 삽입, 매개변수: 큐, 삽입할 값
{
    if (is_full) // 포화상태라면
    {
        error();
    }

    q->rear = (q->rear + 1) % MAX_SIZE;  // rear를 증가

    q->client[q->rear] = val;

}

element dequeue(queue* q)   // 값을 리턴해야됨
{
    if (is_empty(q))
    {
        error();
    }

    q->front = (q->front + 1) % MAX_SIZE;  // front를 증가

    return q->client[q->front];
}

int main()
{
    queue m; // male queue
    queue f; // female queue

    meeting p;  // 입력할 때
    meeting q;  // 출력할 때

    init_queue(&m);
    init_queue(&f);          // 남자큐와 여자큐 초기화

    while (1)
    {
        printf("고객의 이름(-1입력시 종료): ");
        scanf("%s", p.name);

        if (strcmp(p.name, "-1") == 0)
            break;
        else
        {
            printf("성별 입력(m/f): ");
            scanf("%s", p.s);
            if (strcmp(p.s, "m") == 0) // 남자입력  1.여자큐가 비어있을때   2.여자큐가 비어있지 않을 때
            {
                printf("man");
                if (is_empty(&f)) // 여자 큐가 비어있다면 1.남자enqueue 2.여자dequeue
                {
                    printf("아직 여자쪽에 대상자가 없습니다.\n");
                    enqueue(&m, p);
                }
                else // 여자 큐가 비어있지 않다, 매치를 성사시킨다.
                {
                    q = dequeue(&f);
                    printf("커플 탄생: %s 와 %s\n", p.name, q.name);
                }
            }
            else if (strcmp(p.s, "f") == 0) // 여자입력  1.남자큐가 비어있을때   2.남자큐가 비어있지 않을 때
            {
                if (is_empty(&m)) // 남자 큐가 비어있다면 1.여자enqueue 2.남자dequeue
                {
                    printf("아직 남자쪽에 대상자가 없습니다.\n");
                    enqueue(&m, p);
                }
                else // 남자 큐가 비어있지 않다, 매치를 성사시킨다.
                {
                    q = dequeue(&m);
                    printf("커플 탄생: %s 와 %s\n", p.name, q.name);
                }
            }
            else
            {
                printf("성별을 잘못입력하였습니다.\n");
            }

        }

    }

    printf("미팅 주선 프로그램을 종료합니다.\n");


}