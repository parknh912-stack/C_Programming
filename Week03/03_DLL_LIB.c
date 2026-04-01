
#if	1
#include "DLL.h"

DLLNode* Create_DLLNode(DLLElement data) {
	DLLNode* newnode = NULL;
	newnode = (DLLNode*)calloc(1, sizeof(DLLNode));
	if (newnode == NULL) {
		exit(1);
	}
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

void Append_DLLNode(char* data, DLLNode** tail) {
	if (*tail == NULL) return;
	else {
		DLLNode* curr = NULL;
		DLLNode* newnode = Create_DLLNode(data);
		for (curr = *tail; curr->next != NULL; curr = curr->next);
		curr->next = newnode;
		newnode->prev = curr;
		*tail = newnode;
	}
}

void Append_DLLNode2(DLLElement data, DLLNode* tail) {
	DLLNode* newnode = Create_DLLNode(data);
	if (newnode == NULL) return;
	newnode->prev = tail->prev;
	newnode->next = tail;
	tail->prev->next = newnode;
	tail->prev = newnode;

}

void Append_DLLNode3(DLLElement data, DLLNode* tail) {
	DLLNode* newnode = Create_DLLNode(data);
	DLLNode* prenode = tail->prev;
	if (newnode == NULL) return;
	newnode->prev = prenode;
	newnode->next = tail;
	prenode->next = newnode;
	tail->prev = newnode;		//참조를 해야함. 별도의 메모리에 newnode를 넣는걸 바라는게 아님

}
//temp부터 읽는거임 (head, tail 포함)
void print_DLLNode(DLLNode* temp) {
	DLLNode* curr = NULL;
	for (curr = temp; curr != NULL; curr = curr->next) {
		printf("%s ", curr->data);
	}
	printf("\n");
}
//temp부터 읽는거임 (head, tail 미포함)
void print_DLLNode2(DLLNode* temp) {
	DLLNode* curr = NULL;
	for (curr = temp->next; curr->next != NULL; curr = curr->next) {
		printf("%s ", curr->data);
	}
	printf("\n");
}

//tail부터 읽는거임
void print_DLLNode3(DLLNode* tail) {
	DLLNode* curr = NULL;
	for (curr = tail; curr != NULL; curr = curr->prev) {
		printf("%s ", curr->data);
	}
	printf("\n");
}
DLLNode* Search_DLLNode(DLLElement data, DLLNode* temp) {
	if (temp == NULL) return NULL;

	DLLNode* curr = NULL;
	for (curr = temp; curr->prev != NULL; curr = curr->prev);	//맨 앞으로 이동
	for (; curr != NULL; curr = curr->next) {		//맨 뒤로 가면서
		if (strcmp(curr->data, data) == 0) {		//문자열 비교
			return curr;
		}
	}
	return NULL;
}

DLLNode* Search_DLLNode2(DLLElement data, DLLNode* head, DLLNode* tail) {
	if (head == NULL) return NULL;

	DLLNode* curr = head->next;
	for (; curr != tail; curr = curr->next) {		//tail 전까지
		if (!strcmp(curr->data, data)) {		//문자열 비교
			return curr;
		}
	}
	return NULL;
}
//Head만 필요 + Head < nodes < Tail 범위에서만 찾음
DLLNode* Search_DLLNode3(DLLElement data, DLLNode* head) {
	if (head == NULL) return NULL;

	DLLNode* curr = head->next;
	for (; curr->next != NULL; curr = curr->next) {		//맨 뒤로 가면서
		if (!strcmp(curr->data, data)) {		//문자열 비교
			return curr;
		}
	}
	return NULL;
}
int Delete_DLLNode(DLLElement data, DLLNode* Head) {
	DLLNode* delnode = Search_DLLNode3(data, Head);
	if (delnode == NULL) return 1;
	delnode->next->prev = delnode->prev;
	delnode->prev->next = delnode->next;

	delnode->prev = NULL;
	delnode->next = NULL;
	free(delnode);
	return 0;
}

void InsertFront_DLLNode(DLLElement data, DLLNode* Head) {
	DLLNode* newnode = Create_DLLNode(data);
	newnode->prev = Head;
	newnode->next = Head->next;

	Head->next->prev = newnode;
	Head->next = newnode;
}

void InsertBefore_DLLNode(DLLElement data, DLLNode* target) {
	DLLNode* newnode = Create_DLLNode(data);
	if (newnode == NULL) return;
	newnode->prev = target->prev;
	newnode->next = target;
	target->prev->next = newnode;
	target->prev = newnode;
}

void InsertAfter_DLLNode(DLLElement data, DLLNode* target) {
	DLLNode* newnode = Create_DLLNode(data);
	if (newnode == NULL) return;
	newnode->prev = target;
	newnode->next = target->next;
	target->next->prev = newnode;
	target->next = newnode;
}

//prenode - nextnode
//prenode - <newnode> - nextnode
void InsertNode_DLLNode(DLLElement data, DLLNode* prenode, DLLNode* nextnode) {
	DLLNode* newnode = Create_DLLNode(data);
	if (newnode == NULL) return;
	newnode->prev = prenode;
	newnode->next = nextnode;
	prenode->next = newnode;
	nextnode->prev = newnode;
}

void Destroy_DLLNode(DLLNode** temp) {
	DLLNode* curr = NULL;
	for (curr = *temp; curr != NULL; curr = curr->prev);
	for (; curr != NULL; curr = curr->next) {
		
		free(curr);
		curr = NULL;
	}
}


//Enqueue - 문자열 오름차순으로 정렬되도록
//알맞은 위치에 노드 삽입
//CreateNode, InsertNode - 기존함수 사용
//Search_PrevNode - 새로운 함수로 사용
void Enqueue(DLLElement data, DLLNode* Head, DLLNode* Tail) {
	if (Head == NULL) return;
	if (Tail == NULL) return;
	
	DLLNode* temp = Search_PrevNode(data, Head, Tail);
	if (temp == NULL) exit(1);
	InsertNode_DLLNode(data, temp, temp->next);
}

//Dequeue - DLL 맨앞의 있는 노드를 반환
//Head->next, Head->next->prev 수정해야함
DLLNode* Dequeue(DLLNode* Head, DLLNode* Tail) {
	if (Head->next == Tail) return NULL;
	DLLNode* temp = Head->next;
	Head->next = temp->next;
	temp->prev = Head;
	return temp;
}

//Search_PrevNode - 새로운 노드가 삽입될 위치의
//이전 노드 주소를 반환하는 함수
DLLNode* Search_PrevNode(DLLElement data, DLLNode* head, DLLNode* tail) {
	for (DLLNode* curr = head->next; curr != NULL; curr = curr->next) {
		if (strcmp(data, curr->data) < 0)	//B를 넣는다면, C를 찾는거다. 즉, data가 더
			return curr->prev;
	}
	return tail->prev;	//조건이 없으면 맨 마지막에 넣으면 되는거였구나...
}
#endif // 0

