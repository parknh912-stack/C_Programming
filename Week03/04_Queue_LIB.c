#include "QUEUE.h"
#if TEST_QUEUE


ArrQueue* Create_ArrQueue(int capacity, enQ_fn enQ, deQ_fn deQ) {
	ArrQueue* newQueue = (ArrQueue*)malloc(sizeof(ArrQueue));
	if (newQueue == NULL) return NULL;

	newQueue->nodes = (QElement*)calloc(capacity, sizeof(QElement));
	if (newQueue->nodes == NULL) {
		free(newQueue);
		return NULL;
	}
	newQueue->capacity = capacity;
	newQueue->front = 0;
	newQueue->rear = 0;
	newQueue->enqueue = enQ;
	newQueue->dequeue = deQ;
	return newQueue;
}
/*
* Data와 Queue를 받아서, nodes[queue->rear]에 data를 저장하고 1증가
* rear와 capacity가 같아지면 -> Overflow
*/
int EnQueue(QElement data, ArrQueue* queue) {
	if (queue->rear == queue->capacity) {
		printf("!+Overflow+!\n");
		return 0;
	}
	queue->nodes[queue->rear++] = data;
	return 1;
}

/*
* ArrQueue* queue를 받아서, front의 data를 반환하고, front는 1증가
* front가 계속 증가하다가 rear와 동일해지면 Underflow
* 주의) temp 만들어서 return &temp 해버리면, 안됌
* Why? : 함수가 끝나면 사라져버린다.
*/
QElement* DeQueue(ArrQueue* queue) {
	if (queue->front >= queue->rear) {
		printf("!+UnderFlow+!\n");
		return NULL;
	}
	return &queue->nodes[queue->front++];	//정석
}

/*Circular */
int Circular_EnQueue(QElement data, ArrQueue* queue) {
	int next = (queue->rear + 1) % queue->capacity;
	if (next == queue->front) {
		printf("!+Overflow+!\n");
		return 0;
	}
	queue->nodes[queue->rear] = data;
	queue->rear = next;
	printf("EQ %d %d\n", data.r, data.c);
	return 1;
}

int Circular_EnQueue_prac(QElement data, ArrQueue* queue) {
	int* rear = &queue->rear;
	int next = (*rear + 1) % queue->capacity;
	if (next == queue->front) {
		printf("!+Overflow+!\n");
		return 0;
	}
	queue->nodes[*rear] = data;
	*rear = next;
	printf("EQ %d %d\n", data.r, data.c);
	return 1;
}

QElement* Circular_DeQueue(ArrQueue* queue) {
	if (queue->front == queue->rear) {
		printf("!+UnderFlow+!\n");
		return NULL;
	}
	QElement* temp = &queue->nodes[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	return temp;
}
/*진수님 코드 (내 코드가 더 낫다)*/
QElement* ArrQueue_DeQueue_Circ(ArrQueue* q)
{
	int next_front = ((q->front + 1) % q->capacity);
	QElement* ret;

	if (q->front == q->rear)
		return NULL;

	ret = &q->nodes[q->front];
	q->front = next_front;

	return ret;
}

void print_queue(ArrQueue* queue) {
	printf("===Current Queue===\n");
	for (int i = queue->front; i < queue->rear; ++i) {
		printf("%d %d\n", queue->nodes[i].r, queue->nodes[i].c);
	}printf("\n");
}

void print_circular_queue(ArrQueue* queue) {
	printf("===Current Queue===\n");
	for (int i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity) {
		printf("%d %d\n", queue->nodes[i].r, queue->nodes[i].c);
	}printf("\n");
}

#endif // 0



