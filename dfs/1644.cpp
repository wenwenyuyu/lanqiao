#include<iostream>

using namespace std;

const int N = 20;
int n, m, total = 0;
int dx[] = {2, 1, -1, -2};
int dy[] = {1, 2, 2, 1};
int g[N][N];

void dfs(int x, int y){
    if(x == n && y == m){
        total++;
        return;
    }

    for(int i = 0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a > n || b > m) continue;
        dfs(a, b);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    dfs(0, 0);
    printf("%d", total);
}