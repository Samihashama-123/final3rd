#include <stdio.h>
#define INF 99999
#define MAX 100

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int distance[MAX], visited[MAX], i, j, min, u;

    for(i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[start] = 0;

    for(i = 0; i < n - 1; i++) {
        min = INF;
        u = -1;

        for(j = 0; j < n; j++) {
            if(!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(j = 0; j < n; j++) {
            if(!visited[j] && graph[u][j] && distance[u] + graph[u][j] < distance[j]) {
                distance[j] = distance[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from source vertex %d:\n", start);
    for(i = 0; i < n; i++) {
        printf("To vertex %d: %d\n", i, distance[i]);
    }
}

int main() {
    int n, i, j, graph[MAX][MAX], start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (enter 0 for no edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}