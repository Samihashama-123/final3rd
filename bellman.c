#include <stdio.h>
#include <limits.h>
#define MAX 100

struct Edge {
    int u, v;
    int weight;
};

void bellmanFord(struct Edge edges[], int V, int E, int s) {
    int dist[MAX];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[s] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Graph contains a negative-weight cycle\n");
            return;
        }
    }
 printf("\nVertex\tDistance from Source %d\n", s);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    printf("Enter each edge as: from to weight\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    bellmanFord(edges, V, E, source);

    return 0;
}
