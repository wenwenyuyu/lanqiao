#include<iostream>
#include<memory.h>

using namespace std;

const int N = 1000010;
int n, m;
int r[N], d[N], s[N], t[N];
int num[N];

bool check(int end){
    memset(num, 0, sizeof num);
    for(int i = 1; i <= end; i++){
        num[s[i]] += d[i];
        num[t[i] + 1] -= d[i];
    }    

    for(int i = 1; i <= n; i++){
        num[i] += num[i - 1];
        if(num[i] > r[i]) return false;
    }
    return true;
}
//最大化
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", r + i);
    for(int i = 1; i <= m; i++) scanf("%d%d%d", d + i, s + i, t + i);
    if(check(m)){
        printf("0");
        return 0;
    }
    int l = 0, r = 1e6 + 1;
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }

    printf("-1\n%d", r);
    return 0;
}