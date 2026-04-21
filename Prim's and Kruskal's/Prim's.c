#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX 50001

typedef struct Edge {
    int dest;
    int weight;
    struct Edge* next;
} Edge;

typedef struct {
    Edge* head[MAX];
    int V;
} Graph;

typedef struct {
    int v;
    int key;
} HeapNode;

typedef struct {
    int size;
    int capacity;
    int *pos;
    HeapNode **array;
} MinHeap;

Edge* newEdge(int dest, int weight) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->dest = dest;
    e->weight = weight;
    e->next = NULL;
    return e;
}

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    for (int i = 0; i < V; i++)
        graph->head[i] = NULL;
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Edge* e = newEdge(dest, weight);
    e->next = graph->head[src];
    graph->head[src] = e;

    e = newEdge(src, weight);
    e->next = graph->head[dest];
    graph->head[dest] = e;
}

HeapNode* newHeapNode(int v, int key) {
    HeapNode* node = (HeapNode*)malloc(sizeof(HeapNode));
    node->v = v;
    node->key = key;
    return node;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (HeapNode**)malloc(capacity * sizeof(HeapNode*));
    return heap;
}

void swapHeapNode(HeapNode** a, HeapNode** b) {
    HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size &&
        heap->array[left]->key < heap->array[smallest]->key)
        smallest = left;

    if (right < heap->size &&
        heap->array[right]->key < heap->array[smallest]->key)
        smallest = right;

    if (smallest != idx) {
        HeapNode *smallestNode = heap->array[smallest];
        HeapNode *idxNode = heap->array[idx];

        heap->pos[smallestNode->v] = idx;
        heap->pos[idxNode->v] = smallest;

        swapHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

HeapNode* extractMin(MinHeap* heap) {
    if (heap->size == 0) return NULL;

    HeapNode* root = heap->array[0];
    HeapNode* lastNode = heap->array[heap->size - 1];

    heap->array[0] = lastNode;

    heap->pos[root->v] = heap->size - 1;
    heap->pos[lastNode->v] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

void decreaseKey(MinHeap* heap, int v, int key) {
    int i = heap->pos[v];
    heap->array[i]->key = key;

    while (i && heap->array[i]->key < heap->array[(i - 1) / 2]->key) {
        heap->pos[heap->array[i]->v] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->v] = i;

        swapHeapNode(&heap->array[i],
                     &heap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

int isInMinHeap(MinHeap *heap, int v) {
    return heap->pos[v] < heap->size;
}

int primMST(Graph* graph) {
    int V = graph->V;
    int key[V];
    MinHeap* heap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        key[v] = INT_MAX;
        heap->array[v] = newHeapNode(v, key[v]);
        heap->pos[v] = v;
    }

    key[0] = 0;
    decreaseKey(heap, 0, key[0]);
    heap->size = V;

    int total_weight = 0;

    while (heap->size > 0) {
        HeapNode* minNode = extractMin(heap);
        int u = minNode->v;
        total_weight += minNode->key;

        Edge* crawl = graph->head[u];
        while (crawl != NULL) {
            int v = crawl->dest;

            if (isInMinHeap(heap, v) &&
                crawl->weight < key[v]) {
                key[v] = crawl->weight;
                decreaseKey(heap, v, key[v]);
            }
            crawl = crawl->next;
        }
    }

    return total_weight;
}

Graph* generateGraph(int V) {
    Graph* graph = createGraph(V);

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V && j < i + 5; j++) {
            int weight = rand() % 100 + 1;
            addEdge(graph, i, j, weight);
        }
    }
    return graph;
}

int main() {
    srand(time(NULL));

    printf("Vertices\tTime (seconds)\n");

    for (int size = 10000; size <= 50000; size += 10000) {
        Graph* graph = generateGraph(size);

        clock_t start = clock();
        primMST(graph);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%d\t\t%f\n", size, time_taken);
    }

    return 0;
}
