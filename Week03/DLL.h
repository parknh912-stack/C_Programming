#if 1

#ifndef _DLL_H_
#define _DLL_H_
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef char* DLLElement;
typedef struct _dllnode {
	DLLElement data;
	struct _dllnode* prev;
	struct _dllnode* next;
}DLLNode;

DLLNode* Create_DLLNode(DLLElement data);

void Append_DLLNode(char* data, DLLNode** tail);
void Append_DLLNode2(DLLElement data, DLLNode* tail);

// = Append Node + 어디에나 넣을 수 있는 만능
void InsertNode_DLLNode(DLLElement data, DLLNode* prenode, DLLNode* nextnode);

void InsertFront_DLLNode(DLLElement data, DLLNode* Head);
void InsertBefore_DLLNode(DLLElement data, DLLNode* target);
void InsertAfter_DLLNode(DLLElement data, DLLNode* target);

void print_DLLNode(DLLNode* temp);
void print_DLLNode2(DLLNode* temp);
void print_DLLNode3(DLLNode* tail);

DLLNode* Search_DLLNode(DLLElement data, DLLNode* temp);
DLLNode* Search_DLLNode2(DLLElement data, DLLNode* head, DLLNode* tail);
DLLNode* Search_DLLNode3(DLLElement data, DLLNode* head);

int Delete_DLLNode(DLLElement data, DLLNode* Head);

void Enqueue(DLLElement data, DLLNode* Head, DLLNode* Tail);
DLLNode* Dequeue(DLLNode* Head, DLLNode* Tail);
DLLNode* Search_PrevNode(DLLElement data, DLLNode* head, DLLNode* tail);

#endif
#endif // 0

