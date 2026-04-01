#ifndef _QUEUE_H_
#define _QUEUE_H_

#define TEST_QUEUE 0

#if TEST_QUEUE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_N (5)

typedef struct _qelement {
	int r;
	int c;
}QElement;

//성능이 중요한 경우에는 함수 포인터 등록하여 사용하지 말고 별도로 사용
typedef int (*enQ_fn)(QElement, struct _arrQuene*);
typedef QElement* (*deQ_fn) (struct _arrQuene*);

typedef struct _arrQuene {
	int capacity;
	int front;
	int rear;
	QElement* nodes;
	enQ_fn enqueue;
	deQ_fn dequeue;
}ArrQueue;

ArrQueue* Create_ArrQueue(int capacity, enQ_fn enQ, deQ_fn deQ);

int EnQueue(QElement data, ArrQueue* queue);
QElement* DeQueue(ArrQueue* queue);

//Circular Queue
int Circular_EnQueue(QElement data, ArrQueue* queue);
QElement* Circular_DeQueue(ArrQueue* queue);

/*다른 분들이 만든 코드*/
int Circular_EnQueue_prac(QElement data, ArrQueue* queue);
QElement* ArrQueue_DeQueue_Circ(ArrQueue* q);

void print_queue(ArrQueue* queue);
void print_circular_queue(ArrQueue* queue);
//typedef struct _qnode {
//	QElement data;
//	struct _qnode* prev;
//	struct _qnode* next;
//}QNode;

#endif
#endif // 0


