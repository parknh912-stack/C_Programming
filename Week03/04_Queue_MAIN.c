#include "QUEUE.h"

#if TEST_QUEUE == 1
#include "QUEUE.h"

int main(void) {
	ArrQueue* Queue = Create_ArrQueue(5);
	//printf("%d %d\n", Queue->capacity, sizeof(*Queue->nodes));
	
	//nodes는 배열이다.
#if 0
	Queue->nodes[1].r = 1;
	Queue->nodes[1].c = 2;
	printf("%d %d\n", Queue->nodes[1].r, Queue->nodes[1].c);
	Queue->nodes[1] = (QElement){ 3,4 };
	printf("%d %d\n", Queue->nodes[1].r, Queue->nodes[1].c);
	(Queue->nodes + 1)->r = 5;
	(Queue->nodes + 1)->c = 6;
	printf("%d %d\n", Queue->nodes[1].r, Queue->nodes[1].c);
	(*(Queue->nodes + 1)).r = 7;
	(*(Queue->nodes + 1)).c = 8;
	printf("%d %d\n", Queue->nodes[1].r, Queue->nodes[1].c);
#endif
	QElement data = { 1,2 };
	for (int i = 0; i <= 5; ++i) {
		print_queue(Queue);
		EnQueue(data, Queue);
		data.r+=2;
		data.c+=2;
	}
	return 0;
}
#endif // 1

#if TEST_QUEUE == 2


int main(void) {
	/*Queue와 관련된 함수를 만들어서, 구조체에 함수포인터로 저장함.*/
	//ArrQueue* Queue = Create_ArrQueue(5, EnQueue, DeQueue);
	/*Circular ver*/
	ArrQueue* Queue = Create_ArrQueue(5, Circular_EnQueue, Circular_DeQueue);

	for (int i = 0; i < 5; ++i) {
		int r = Queue->enqueue((QElement) { i + 1, i + 1 }, Queue);
	}
	printf("front : %d, rear : %d\n", Queue->front, Queue->rear);
	print_circular_queue(Queue);
	/*
	* DeQueue 함수 구현
	* 구조체에 함수 포인터 넣어서, Queue로 호출하게 바꿈
	*/
	QElement* data;
	for (int i = 0; i < 3; ++i) {
		data = Queue->dequeue(Queue);
		if (data != NULL) printf("DQ %d %d\n", data->r, data->c);
	}
	printf("front : %d, rear : %d\n", Queue->front, Queue->rear);
	print_circular_queue(Queue);

	for (int i = 0; i < 2; ++i) {
		int r = Queue->enqueue((QElement) { i + 1, i + 1 }, Queue);
	}
	printf("front : %d, rear : %d\n", Queue->front, Queue->rear);
	print_circular_queue(Queue);

	for (int i = 0; i < 4; ++i) {
		data = Queue->dequeue(Queue);
		if (data != NULL) printf("DQ %d %d\n", data->r, data->c);

	}
	printf("front : %d, rear : %d\n", Queue->front, Queue->rear);
	print_circular_queue(Queue);

	for (int i = 0; i < 3; ++i) {
		int r = Queue->enqueue((QElement) { i + 1, i + 1 }, Queue);
	}
	printf("front : %d, rear : %d\n", Queue->front, Queue->rear);
	print_circular_queue(Queue);
	return 0;
}
#endif
