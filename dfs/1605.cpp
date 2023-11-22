#include<iostream>
#include<memory.h>
using namespace std;

const int N = 6;
int n, m, t;
int sx, sy, fx, fy;
int g[N][N];
int a, b;
int cnt = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void dfs(int x, int y){
    if(x == fx && y == fy) {
        cnt++;
        return;
    }
    for(int i = 0; i < 4; i++){
        int ax = x + dx[i], by = y + dy[i];
        if(ax >= 1 && ax <= n && by >= 1 && by <= m && !g[ax][by]){
            g[ax][by] = 1;
            dfs(ax, by);
            g[ax][by] = 0;
        }
    }

}

int main(){
    scanf("%d%d%d", &n, &m, &t);
    scanf("%d%d%d%d", &sx, &sy, &fx, &fy);

    for(int i = 0; i < t; i++){
        scanf("%d%d", &a, &b);
        g[a][b] = 1;
    }
    g[sx][sy] = 1;
    dfs(sx, sy);
    printf("%d", cnt);
}