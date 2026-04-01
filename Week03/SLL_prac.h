#if 0
#ifndef _SLL_H_PRAC_
#define _SLL_H_PRAC_
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef int ElementType;
typedef struct _sllnode {
	ElementType data;
	struct _sllnode* next;
}SLL_Node;

void print_SLLNode(SLL_Node* Head);
SLL_Node* SLL_CreateNode(ElementType data);
SLL_Node* SLL_CreateNode1(ElementType* data);
void SLL_AppendNode(SLL_Node** temp, SLL_Node* newnode);
void SLL_AppendNode1(SLL_Node** H, SLL_Node** T, SLL_Node* newnode);

#endif
#endif // 0

