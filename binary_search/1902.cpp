#include<iostream>
#include<memory.h>

using namespace std;

int n, m;
const int N = 1010;
int p[N][N];
bool vis[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool check(int x, int y, int pa){
    if(x == n - 1) return true;
    vis[x][y] = true;
    for(int i = 0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        //printf("%d %d %d\n", a, b, pa);
        if(a >= 0 && a < n && b >= 0 && b < m && !vis[a][b] && p[a][b] <= pa){
            if(check(a, b, pa)) return true;
        }
    }
    return false;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
         scanf("%d", &p[i][j]);
    
    int l = -1, r = 1001;
    while(l + 1 < r){
        memset(vis, false, sizeof vis);
        int mid = (l + r)/2;
        if(check(0, 0, mid)) r = mid;
        else l = mid;
    }

    printf("%d", r);
    return 0;
}