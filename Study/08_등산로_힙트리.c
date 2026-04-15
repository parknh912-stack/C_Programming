#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int HeapElement;
typedef struct _heapnode {
    HeapElement r;
    HeapElement c;
    HeapElement cost;
}HeapNode;

typedef struct _heap {
    HeapNode* nodes;
    int capacity;
    int usedsize;
}Heap;

int Heap_Delete(Heap* heap, HeapNode* data);
void Heap_Insert(Heap* heap, HeapNode data);
void Heap_Print(Heap* heap);
Heap* Heap_Create(int capacity);

#if 01
// 등산로
#define MAX_N (100 + 2)
#define INF (10000)
int map[MAX_N][MAX_N];
int cost[MAX_N][MAX_N]; //해당 좌표까지의 비용 저장
int N;
int dR, dC; // 산 정상 좌표
typedef struct _node {
    int r;
    int c;
}node;
node Queue[MAX_N * MAX_N * 10];
int front, rear;

Heap* heap;
void inputData(void) {
    (void)scanf("%d", &N);
    (void)scanf("%d %d", &dR, &dC);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cost[i][j] = INF;
        }
    }

    front = rear = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            (void)scanf("%d", &map[i][j]);
            if ((i == 1) || (i == N) || (j == 1) || (j == N)) {
                cost[i][j] = map[i][j] * map[i][j];
                HeapNode data = (HeapNode){ i,j,cost[i][j] };
                Heap
            }
        }
    }
}

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int BFS(void) {
    int nR, nC, i;
    node curr;
    int nCost; // curr -> (nR, nC)로 가는 추가비용

    while (front != rear) {
        curr = Queue[front++];
        //if (curr.r == dR && curr.c == dC) continue; // 정상에 도착했으면 탐색 더 X

        for (i = 0; i < 4; i++) {
            nR = curr.r + dx[i];
            nC = curr.c + dy[i];

            if (nR < 1 || nR > N || nC < 1 || nC > N) continue; // 경계 검사

            nCost = map[curr.r][curr.c] - map[nR][nC];
            if (nCost < 0) nCost *= nCost;

            if (cost[nR][nC] > cost[curr.r][curr.c] + nCost) {
                cost[nR][nC] = cost[curr.r][curr.c] + nCost;
                Queue[rear++] = (node){ nR, nC };
            }
        }
    }
    return cost[dR][dC];
}

int main(void) {
    (void)freopen("J1111.txt", "r", stdin);
    inputData();
    printf("%d\n", BFS());
    printf("front = %d\n", front);
    return 0;
}



Heap* Heap_Create(int capacity) {
    Heap* temp = (Heap*)calloc(1, sizeof(Heap));
    if (temp == NULL) {
        return NULL;
    }
    temp->nodes = (HeapNode*)calloc(capacity + 1, sizeof(HeapNode));
    if (temp->nodes == NULL) {
        free(temp);
        return NULL;
    }
    temp->capacity = capacity + 1;
    temp->usedsize = 0;
    return temp;
}

static int min_child_idx(Heap* heap, int left) {
    int usedsize = heap->usedsize;
    if (left > usedsize) return 0; // 자식 노드 아예 없음
    if (left + 1 > usedsize) return left; // 왼쪽 자식만 있음
    HeapNode* nodes = heap->nodes + left;
    return left + (nodes[0].data > nodes[1].data);
}

int Heap_Delete(Heap* heap, HeapNode* out) {
    if (heap->usedsize < 1) {
        printf("Underflow\n");
        return 0;
    }

    HeapNode* nodes = heap->nodes;
    *out = nodes[1];
    HeapNode last = nodes[heap->usedsize--];

    int idx = 1;
    int child = 0;
    while ((child = min_child_idx(heap, idx * 2)) != 0) {  // 자식노드 없으면 break
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
static int Heap_Resize(Heap* heap, int additional) {
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
void Heap_Insert(Heap* heap, HeapNode data)
{
    if (heap->usedsize >= (heap->capacity)) {
        printf("Overflow!\n");
        if (!Heap_Resize(heap, 2)) return;
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

void Heap_Print(Heap* heap) {
    for (int i = 1; i <= heap->usedsize; ++i) {
        printf("%d ", heap->nodes[i].data);
    }
    printf("\n");
}


#endif
#endif // 0



