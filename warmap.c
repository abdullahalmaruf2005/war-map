#include <stdio.h>
#include <string.h>

#define MAX 30

char grid[MAX][MAX];
int visited[MAX][MAX];
int m, n, count;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    visited[x][y] = 1;
    count++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny] && grid[nx][ny] != '#') {
            dfs(nx, ny);
        }
    }
}

int main() {
   
        scanf("%d %d", &m, &n);
        memset(visited, 0, sizeof(visited));
        
        int startX = 0, startY = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf(" %c", &grid[i][j]);
                if (grid[i][j] == '@') {
                    startX = i;
                    startY = j;
                }
            }
        }
        count = 0;
        dfs(startX, startY);
        printf("can went %d km\n", count);
    }
