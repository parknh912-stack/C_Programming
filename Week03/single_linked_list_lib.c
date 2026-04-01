#if 0
#include "SLL_prac.h"

void print_SLLNode(SLL_Node* Head) {
	SLL_Node* curr = NULL;
	for (curr = Head; curr != NULL; curr = curr->next) {
		printf("%d ", curr->data);
	}
}
void print_SLLNode1(SLL_Node* curr) {
	for (; curr != NULL; curr = curr->next) {
		printf("%d ", curr->data);
	}
}
SLL_Node* SLL_CreateNode(ElementType data) {
	SLL_Node* newnode = (SLL_Node*)calloc(1, sizeof(SLL_Node));
	if (newnode == NULL) exit(1);

	newnode->data = data;
	newnode->next = NULL;
	return newnode;	//값을 받아서, 새로운 노드를 만들고, 주소를 반환,
}

SLL_Node* SLL_CreateNode1(ElementType* data) {
	SLL_Node* newnode = (SLL_Node*)calloc(1, sizeof(SLL_Node));
	if (newnode == NULL) {
		exit(1);
		//return NULL;
	}
	newnode->data = *data;
	newnode->next = NULL;
	return newnode;
}

void SLL_AppendNode(SLL_Node** temp, SLL_Node* newnode) {
	if (temp == NULL) return;	//리스트 자체가 없는 경우 → 아무것도 안 함
	if (*temp == NULL) {		//리스트가 비어 있는 경우 → newnode가 첫 노드가 됨
		*temp = newnode;
	}
	else {	//리스트에 노드가 있는 경우 -> 리스트 뒤에 추가
		SLL_Node* curr = NULL;
		for (curr = *temp; curr->next != NULL; curr = curr->next);	//리스트 끝까지 이동 strcat과 비슷하네
		curr->next = newnode;
	}
}

void SLL_AppendNode1(SLL_Node** H, SLL_Node** T, SLL_Node* newnode) {
	if (*H == NULL) {	//리스트가 비었어 -> Tail이 헤드가 되고, 
		*H = newnode;
		*T = newnode;
	}
	else {
		(*T)->next = newnode;	//테일의 다음 노드로, newnode 넣은후
		*T = newnode;	//테일을 업데이트 하는거
	}
}
#endif // 0
