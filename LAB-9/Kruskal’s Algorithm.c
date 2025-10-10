#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u;
    int v;
    int w;
} Edge;

int parent[MAX];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[b] = a;
}

int cmp(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    Edge edges[e];
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    qsort(edges, e, sizeof(Edge), cmp);

    int mst_weight = 0;

    for (int i = 0; i < e; i++) {
        int u_set = find(edges[i].u);
        int v_set = find(edges[i].v);

        if (u_set != v_set) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            mst_weight += edges[i].w;
            unionSet(u_set, v_set);
        }
    }

    printf("Total weight of MST: %d\n", mst_weight);

    return 0;
}
