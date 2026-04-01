#if 0

#include "Tree.h"

Heap* Heap_Create(int capacity) {
	Heap* temp = (Heap*)calloc(1, sizeof(Heap));
	if (temp == NULL) return NULL;

	temp->nodes = (HeapNode*)calloc(capacity, sizeof(int));
	if (temp->nodes == NULL) {
		free(temp);
		return NULL;
	}
	temp->capacity = capacity;
	temp->usedsize = 0;
	return temp;
}

void Heap_InsertNode(Heap* heap, HeapElement data) {
	HeapNode* Node = heap->nodes;
	Node[heap->usedsize].data = data;
	int child = heap->usedsize++;

	//개선. overflow 검사
	if (heap->usedsize >= heap->capacity) {
		printf("overflow");
		return;
	}

	//개선. index가 0으로 가서는 안된다.
	while ((child / 2 > 0) && (Node[child / 2].data > Node[child].data)) {
		int temp_data = Node[child / 2].data;
		Node[child / 2].data = Node[child].data;
		Node[child].data = temp_data;

		child /= 2;
	}
}

//효율적인 동작
//부모에 있는 값을 자식으로 내리는 동작만 하고 마지막에 한번만 data를 써준다.
//즉, 입력 후 교환이 아니라, 먼저 index를 찾고, 한번만 넣는다.
void Heap_InsertNode2(Heap* heap, HeapElement data) {

	if (heap->usedsize >= heap->capacity) {
		printf("overflow");
		return;
	}

	int index = heap->usedsize++;
	HeapNode* Node = heap->nodes;
	while (index > 1 && Node[index / 2].data > data) {
		Node[index] = Node[index / 2];
		index /= 2;
	}
	heap->nodes[index].data = data;	//입력은 1번만
}

void Heap_Print(Heap* heap) {
	for (int i = 1; i < heap->usedsize; ++i) {
		(void)printf("%d ", heap->nodes[i].data);
	}printf("\n\n");
}
void Heap_Print_to_capacity(Heap* heap) {
	for (int i = 1; i < heap->capacity; ++i) {
		(void)printf("%d ", heap->nodes[i].data);
	}printf("\n\n");
}
/*
1. usedsize 줄이면서, underflow 검사
2. 첫번째 data -> result
3. L_index = n*2+ 0    R_index = n*2 + 1
   L <-> R 비교해서, 왼쪽이 크면 1, 오른쪽이 크면 0
   idx : root부터 시작하여 점차 증가
   child_index : idx * 2 + a
*/
HeapNode Heap_Delete(Heap* heap) {
	if ((--(heap->usedsize)) < 1) {
		printf("Underflow\n");
		return;
	}
	HeapNode* Node = heap->nodes;
	HeapNode result = Node[1];
	int idx = 1;
	int next_idx = Heap_MinChild(heap, idx);

	while (next_idx != 0) {		//자식 노드가 존재할 때
		if (Node[heap->usedsize].data < Node[next_idx].data) {
			break;   //자식이 더 크면 중단
		}
		Node[idx] = Node[next_idx];				//자식노드의 값을 부모노드에 대입
		idx = next_idx;							//자식노드의 index로 변경
		next_idx = Heap_MinChild(heap, idx);	//다음 자식노드끼리 비교
	}
	Node[idx] = Node[heap->usedsize];    //최고 깊이 가장 우측 노드의 데이터를 index에 대입
	//Node[heap->usedsize].data = 0;  //없어도 됌              //최고 깊이 가장 우측 노드의 데이터 초기화
	return result;
}

int Heap_MinChild(Heap* heap, int idx) {
	int L = idx * 2;
	int R = L + 1;
	if (L > heap->usedsize) return 0;	//자식노드 X
	if (R > heap->usedsize) return L;	//L 만 있을때 -> L 반환
	if (heap->nodes[L].data > heap->nodes[R].data)
		return R;	//R이 더 작은 경우
	return L;		//L이 더 작은 경우
}


int Heap_Delete2(Heap* heap) {
	if ((--(heap->usedsize)) < 1) {
		printf("Underflow\n");
		return -1;
	}
	HeapNode* Node = heap->nodes;
	int result = Node[1].data;
	int idx = 1;
	int next_idx;
	int a = Heap_MinChild(heap, idx);

	while (idx * 2 < heap->usedsize) {
		next_idx = idx * 2;
		if (next_idx + 1 <= heap->usedsize && Node[next_idx].data > Node[next_idx + 1].data) {
			next_idx++;
		}
		if (Node[idx].data < Node[next_idx].data) break;
		idx = next_idx;
	}
	Node[idx].data = Node[heap->usedsize].data;	//최고 깊이 가장 우측 노드의 데이터를 index에 대입
	Node[heap->usedsize].data = 0;				//최고 깊이 가장 우측 노드의 데이터 초기화
	return result;
}

/*--- 강사님 버전 ---*/
#if 1
Heap* Heap_Create_teacher(int capacity) {
	Heap* temp = (Heap*)calloc(1, sizeof(Heap));
	if (temp == NULL) {
		return NULL;
	}
	temp->nodes = (HeapNode*)calloc(capacity + 1, sizeof(HeapNode));
	if (temp->nodes == NULL) {
		free(temp);
		return NULL;
	}
	temp->capacity = capacity;
	temp->usedsize = 0;
	return temp;
}

static int min_child_idx_teacher(Heap* heap, int left) {
	int usedsize = heap->usedsize;
	if (left > usedsize) return 0; // 자식 노드 아예 없음
	if (left + 1 > usedsize) return left; // 왼쪽 자식만 있음
	HeapNode* nodes = heap->nodes + left;
	return left + (nodes[0].data > nodes[1].data);
}

int Heap_Delete_teacher(Heap* heap, HeapNode* out) {
	if (heap->usedsize < 1) {
		printf("Underflow\n");
		return 0;	//0이면 underflow
	}

	HeapNode* nodes = heap->nodes;
	*out = nodes[1];	//포인터로, return을 대신하여 값을 받아온다.
	HeapNode last = nodes[heap->usedsize--];

	int idx = 1;
	int child = 0;
	while ((child = min_child_idx_teacher(heap, idx * 2)) != 0) {  // 자식노드 없으면 break
		if (nodes[child].data > last.data) {
			break;
		}
		nodes[idx] = nodes[child];
		idx = child;
	}
	nodes[idx] = last;
	return 1;
}

// 성공 시 1, 실패 시 0 반환
static int Heap_Resize_teacher(Heap* heap, int additional) {
	int new_capacity = heap->capacity + additional;
	HeapNode* new_nodes = realloc(heap->nodes, (new_capacity) * sizeof(HeapNode));
	if (new_nodes == NULL) {
		printf("Memory allocation failed\n");
		return 0;
	}
	heap->nodes = new_nodes;
	heap->capacity = new_capacity;
	return 1;
}

// 효율적인 동작을 함 (부모에 있는 값을 자식으로 내리는 동작만 하고, 마지막에 한 번만 data를 저장함)
void Heap_Insert_teacher(Heap* heap, HeapNode data)
{
	if (heap->usedsize >= (heap->capacity)) {
		printf("Overflow!\n");
		if (!Heap_Resize_teacher(heap, 2)) return;
	}

	int index = ++heap->usedsize;
	HeapNode* nodes = heap->nodes;
	while (index > 1 && nodes[index / 2].data > data.data)
	{
		nodes[index] = nodes[index / 2];
		index >>= 1;  //  index /= 2;  //  컴파일러가 최적화해줌
	}

	nodes[index] = data;
}

void Heap_Print_teacher(Heap* heap) {
	for (int i = 1; i <= heap->usedsize; ++i) {
		printf("%d ", heap->nodes[i].data);
	}
	printf("\n");
}
#endif


/* 이하 Tree 자료구조 */
/* TreeNode를 만드는 함수*/
TreeNode* Tree_CreateNode(TElement data) {
	TreeNode* newnode = (TreeNode*)calloc(1, sizeof(TreeNode));
	if (newnode == NULL) return NULL;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

/*제일 안전, but 한번 더 내려감 -> 함수호출이 잦다*/
/* 성능차이는 크지 않다 */
/* 일반적으로 사용함*/
void Tree_PreOrder(TreeNode* temp) {
	if (temp == NULL) return;
	printf("%c ", temp->data);
	Tree_PreOrder(temp->left);
	Tree_PreOrder(temp->right);
}

/*만약, 맨 처음이 NULL이면 터진다. 함수호출은 적은편*/
void Tree_PreOrder_2(TreeNode* temp) {
	printf("%c ", temp->data);
	if (temp->left)
		Tree_PreOrder_2(temp->left);
	if (temp->right)
		Tree_PreOrder_2(temp->right);
	return;
}

/*특정 케이스에서, 내려간다음에 NULL의 data를 읽을 수 있다.*/
void Tree_PreOrder_3(TreeNode* temp) {
	printf("%c ", temp->data);
	if ((temp->left == NULL) && (temp->right == NULL))
		return;
	Tree_PreOrder_3(temp->left);
	Tree_PreOrder_3(temp->right);

}

// 중위 순회 : LEFT ROOT RIGHT
void Tree_InOrder(TreeNode* temp) {
	if (temp == NULL) return;

	Tree_InOrder(temp->left);		//L
	printf("%c ", temp->data);		//ROOT
	Tree_InOrder(temp->right);		//R
}

// 후위 순회 : LEFT RIGHT ROOT
void Tree_PostOrder(TreeNode* temp) {
	if (temp == NULL) return;

	Tree_PostOrder(temp->left);		//L
	Tree_PostOrder(temp->right);	//R
	printf("%c ", temp->data);		//ROOT
}

//후위 순회로 들어가서, Leap부터 free 해버리면 될듯?
void Tree_DestroyNode(TreeNode* temp) {
	if (temp == NULL) return;

	Tree_DestroyNode(temp->left);
	Tree_DestroyNode(temp->right);

	free(temp);
	temp = NULL;
}
#endif // 0