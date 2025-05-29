#include <stdio.h>

int a[20][20], visited[20], n;

void bfs(int v) {
    int queue[20], front = 0, rear = 0, i;

    visited[v] = 1;
    queue[rear++] = v;

    while (front < rear) {
        v = queue[front++];
        for (i = 1; i <= n; i++) {
            if (a[v][i] && !visited[i]) {
                printf("\n %d->%d", v, i);
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, count = 0;

    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        for (j = 1; j <= n; j++)
            a[i][j] = 0;
    }

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%1d", &a[i][j]);

    bfs(1);

    for (i = 1; i <= n; i++) {
        if (visited[i])
            count++;
    }

    if (count == n)
        printf("\nGraph is connected\n");
    else
        printf("\nGraph is not connected\n");

    return 0;
}