#if 0
#ifndef _TREE_H_
#define _TREE_H_

/*Common Header*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char TElement;
typedef struct _treenode {
	TElement data;
	struct _treenode* left;
	struct _treenode* right;
}TreeNode;

TreeNode* Tree_CreateNode(TElement data);

/* Heap*/
typedef int HeapElement;
typedef struct _heapnode {
	HeapElement data;
}HeapNode;

typedef struct _heap {
	HeapNode* nodes;
	int capacity;
	int usedsize;
}Heap;

/*---Heap---*/
Heap* Heap_Create(int capacity);
void Heap_InsertNode(Heap* heap, HeapElement data);
void Heap_InsertNode2(Heap* heap, HeapElement data);

void Heap_Print(Heap* heap);
void Heap_Print_to_capacity(Heap* heap);

HeapNode Heap_Delete(Heap* heap);
int Heap_MinChild(Heap* heap, int idx);

int Heap_Delete2(Heap* heap);

/*---teacher---*/
Heap* Heap_Create_teacher(int capacity);
static int min_child_idx_teacher(Heap* heap, int left);
int Heap_Delete_teacher(Heap* heap, HeapNode* out);
static int Heap_Resize_teacher(Heap* heap, int additional);
void Heap_Insert_teacher(Heap* heap, HeapNode data);
void Heap_Print_teacher(Heap* heap);

/*---Tree---*/
void Tree_PreOrder(TreeNode* temp);
/*아래 2,3번 방법은 위에 비해 안정적이지 않음.*/
void Tree_PreOrder_2(TreeNode* temp);
void Tree_PreOrder_3(TreeNode* temp);

void Tree_InOrder(TreeNode* temp);
void Tree_PostOrder(TreeNode* temp);

void Tree_DestroyNode(TreeNode* temp);


#endif // !_TREE_H_
#endif // 0
