#include <stdio.h>

void dfs(int);

int n, i, j, a[10][10], vis[10];

int main() {
    printf("enter the number of vertices\n");
    scanf("%d", &n);

    printf("enter the adjacency matrix\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
    }

    printf("dfs traversal\n");
    dfs(1);

    int countVisited = 0;
    for (i = 1; i <= n; i++) {
        if (vis[i] == 1) {
            countVisited++;
        }
    }

    if (countVisited == n)
        printf("\nGraph is connected\n");
    else
        printf("\nGraph is not connected\n");

    return 0;
}

void dfs(int v) {
    vis[v] = 1;
    printf("%d ", v);
    for (j = 1; j <= n; j++) {
        if (a[v][j] == 1 && vis[j] == 0) {
            dfs(j);
        }
    }
}
