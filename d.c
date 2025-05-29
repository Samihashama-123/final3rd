#include <stdio.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX];
int n; // Number of vertices

void DFS(int vertex) {
    int i;
    visited[vertex] = 1;
    printf("%d ", vertex);

    for(i = 0; i < n; i++) {
        if(graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array to 0
    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("DFS traversal starting from vertex %d:\n", start);
    DFS(start);

    return 0;
}