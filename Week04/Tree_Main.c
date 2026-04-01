#define TEST 0

//Tree
#if TEST == 1
#include "TREE.h"
/*메인 함수*/
int main(void) {
	TreeNode* Root = NULL;
	Root = Tree_CreateNode('/');

	Root->left = Tree_CreateNode('+');
	Root->left->left = Tree_CreateNode('4');
	Root->left->right = Tree_CreateNode('3');

	Root->right = Tree_CreateNode('*');
	Root->right->left = Tree_CreateNode('1');
	Root->right->right = Tree_CreateNode('2');


	Tree_PreOrder(Root);	printf("\n");
	//Tree_PreOrder_2(Root);
	//Tree_PreOrder_3(Root);
	Tree_InOrder(Root);		printf("\n");
	Tree_PostOrder(Root);	printf("\n");

	Tree_DestroyNode(Root);
	if (Root)
		printf("NULL입니다.\n");
	return 0;
}
#endif

//Heap
#if TEST == 2

int main() {
	Heap* heap = Heap_Create(20);
	HeapElement ary[11] = { 2,8,52,13,37,67,161,17,43,88 };

	memcpy(heap->nodes + 1, ary, sizeof(ary));
	heap->usedsize = 11;

	//(void)printf("\n%d ", heap->nodes[1].data);
	//(void)printf("\n%d ", heap->nodes[heap->usedsize].data);

	Heap_InsertNode2(heap, 7);
	Heap_Print(heap);

	while ((heap->usedsize) > 0) {
		printf("root value = < %d >\n", Heap_Delete(heap).data);
		Heap_Print(heap);
	}

	/*---teacher---*/
	//HeapNode data;
	//for (int i = 0; i < 14; ++i)
	//{
	//	if (Heap_Delete_teacher(heap, &data)) {
	//		printf("%d ", data.data);
	//	}
	//	//Heap_Print_teacher(heap);
	//}
	/*--- ---*/

	//Heap_Print_to_capacity(heap);
	//printf("%d",heap->usedsize);
	return 0;
}
#endif
