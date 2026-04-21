#include <stdio.h>
#include <stdlib.h>

struct E {
    int s, d, w;
};

int f(int p[], int i) {
    if (p[i] == i)
        return i;
    return f(p, p[i]);
}

void u(int p[], int x, int y) {
    int xr = f(p, x);
    int yr = f(p, y);
    p[xr] = yr;
}

int cmp(const void* a, const void* b) {
    return ((struct E*)a)->w - ((struct E*)b)->w;
}

int main() {
    int V = 4, E = 5;

    struct E e[] = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    qsort(e, E, sizeof(e[0]), cmp);

    int p[V];
    for (int i = 0; i < V; i++)
        p[i] = i;

    struct E r[V];
    int i = 0, j = 0;

    while (j < V - 1 && i < E) {
        struct E ne = e[i++];

        int x = f(p, ne.s);
        int y = f(p, ne.d);

        if (x != y) {
            r[j++] = ne;
            u(p, x, y);
        }
    }

    printf("Edge\tW\n");
    for (i = 0; i < j; i++)
        printf("%d-%d\t%d\n", r[i].s, r[i].d, r[i].w);

    return 0;
}
