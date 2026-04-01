#include "SLL_prac.h"

//Head만
#if 0
int main() {
	SLL_Node* Head = NULL;
	ElementType data = 10;

	SLL_AppendNode(&Head, SLL_CreateNode(data));
	SLL_AppendNode(&Head, SLL_CreateNode(40));
	SLL_AppendNode(&Head, SLL_CreateNode(30));
	SLL_AppendNode(&Head, SLL_CreateNode(40));
	/*
	Head = SLL_CreateNode(data);
	Head->next = SLL_CreateNode(20);
	Head->next->next = SLL_CreateNode(30);
	*/
	print_SLLNode(Head);
	return 0;
}
#endif

//Head + Tail
#if 0
int main() {
	SLL_Node* Head = NULL;
	SLL_Node* Tail = NULL;
	ElementType data = 10;

	SLL_AppendNode1(&Head, &Tail, SLL_CreateNode(10));
	SLL_AppendNode1(&Head, &Tail, SLL_CreateNode(20));
	SLL_AppendNode1(&Head, &Tail, SLL_CreateNode(30));
	SLL_AppendNode1(&Head, &Tail, SLL_CreateNode(40));

	print_SLLNode(Head);
	return 0;
}
#endif // 1

//노드 구조 파악
#if 0
int main(void) {
	SLL_Node a, b, c;
	a = (SLL_Node){ 10, &b };
	b = (SLL_Node){ 20, &c };
	c = (SLL_Node){ 30, NULL };
	SLL_Node* Head = &a;
	SLL_Node* curr = NULL;
	printf("%d %d %d\n", Head->data, Head->next->data, Head->next->next->data);

	print_SLLNode(Head);
	return 0;
}
#endif // 0
