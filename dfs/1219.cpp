#include<iostream>

using namespace std;

const int N = 15;
int n, cnt;
int g[N][N];
int a[N];
bool col[N], dei[2*N], fdei[2 * N  + 1];

void print(){
    if(cnt <= 3){
        for(int i = 0; i < n; i++) printf("%d ", a[i]);
        printf("\n");
    }
}
void dfs(int x){
    if(x == n){
        cnt++;
        print();
        return;
    }
    // (0, 1) col[1] dei(1, 0) fdei(1, 2)(2, 3)(3, 4)
    for(int i = 1; i <= n; i++){
        if(col[i] || dei[i + x] || fdei[x - i + n]) continue;
        a[x] = i;
        col[i] = 1, dei[i + x] = 1, fdei[x - i + n] = 1;
        dfs(x + 1);
        col[i] = dei[i + x] = fdei[x - i + n] = 0;
    }

}

int main(){
    scanf("%d", &n);
    dfs(0);
    printf("%d", cnt);
}