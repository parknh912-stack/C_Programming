#if	0
#include "DLL.h"
int main(void) {
	DLLNode* Head;
	DLLNode* Tail;
	Head = Create_DLLNode("Head");
	Tail = Create_DLLNode("Tail");
	Head->next = Tail;
	Tail->prev = Head;

	//Append_DLLNode("Cat", &Tail);
	//Append_DLLNode("Dog", &Tail);
	//Append_DLLNode("Rabbit", &Tail);

	Append_DLLNode2("Cat", Tail);
	Append_DLLNode2("Dog", Tail);
	Append_DLLNode2("Rabbit", Tail);
	print_DLLNode2(Head);
	print_DLLNode(Head);

	DLLNode* result;
	result = Search_DLLNode2("Rabbit", Head, Tail);
	/*result = Search_DLLNode3("Cat", Head);*/
	if (result == NULL) {
		printf("\nNot Founded! \n");
	}
	else
		printf("\nFounded : %s\n", result->data);

	print_DLLNode3(Tail);
	print_DLLNode(Head);
	Delete_DLLNode("Dog", Head);
	print_DLLNode(Head);
	//Delete_DLLNode("Horse", Head);
	//print_DLLNode(Head);

	InsertFront_DLLNode("TARGET", Head);
	print_DLLNode(Head);

	result = Search_DLLNode3("TARGET", Head);
	InsertBefore_DLLNode("MEGA", result);
	print_DLLNode(Head);
	InsertAfter_DLLNode("TERA", result);
	print_DLLNode(Head);

	InsertNode_DLLNode("1",Tail->prev,Tail);// = AppendNode
	InsertNode_DLLNode("2", Head, Head->next);// = InsertFront
	DLLNode* target = Search_DLLNode("TARGET", Head);
	InsertNode_DLLNode("3", target, target->next);// = InsertAfter
	InsertNode_DLLNode("4", target->prev, target);// = InsertBefore

	print_DLLNode(Head);

	free(Head); free(Tail);
	Head = Tail = NULL;
	return 0;
}
#endif


//우선순위 큐
#if 0

#include "DLL.h"

int main(void) {
	DLLNode* Head;
	DLLNode* Tail;
	Head = Create_DLLNode("Head");
	Tail = Create_DLLNode("Tail");
	Head->next = Tail;
	Tail->prev = Head;

	Enqueue("Dog", Head, Tail);
	Enqueue("Cat", Head, Tail);
	Enqueue("Tiger", Head, Tail);
	Enqueue("Elephant", Head, Tail);

	for (int i = 0; i < 5; ++i) {
		DLLNode* temp = Dequeue(Head,Tail);
		if (temp != NULL) printf("%s ", temp->data);
		else printf("NULL");
		free(temp);
	}
	printf("\n");
	return 0;
}

#endif
