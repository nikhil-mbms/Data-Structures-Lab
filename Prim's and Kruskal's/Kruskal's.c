#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EDGES 300000

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int V, E;
    Edge* edge;
} Graph;

typedef struct {
    int parent;
    int rank;
} Subset;

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int compare(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

Graph* generateGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    int maxEdges = V * 5;
    graph->V = V;
    graph->E = 0;
    graph->edge = (Edge*)malloc(maxEdges * sizeof(Edge));

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V && j < i + 5; j++) {
            graph->edge[graph->E].src = i;
            graph->edge[graph->E].dest = j;
            graph->edge[graph->E].weight = rand() % 100 + 1;
            graph->E++;
        }
    }

    return graph;
}

int kruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V];

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0;
    int i = 0;
    int total_weight = 0;

    while (e < V - 1 && i < graph->E) {
        Edge next = graph->edge[i++];

        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

        if (x != y) {
            result[e++] = next;
            total_weight += next.weight;
            Union(subsets, x, y);
        }
    }

    free(subsets);
    return total_weight;
}

int main() {
    srand(time(NULL));

    printf("Vertices\tTime (seconds)\n");

    for (int size = 10000; size <= 50000; size += 10000) {
        Graph* graph = generateGraph(size);

        clock_t start = clock();
        kruskalMST(graph);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%d\t\t%f\n", size, time_taken);

        free(graph->edge);
        free(graph);
    }

    return 0;
}
