#include<iostream>
#include<memory.h>

using namespace std;

using LL = long long;
int n, m, w[200020], v[200020], l[200020], r[200020];
LL s , sn[200020], sv[200020], ans = 1e18;

//W越大，y越小，|s - y|越大
//求W最小值

bool check(int W){
    memset(sn, 0, sizeof sn);
    memset(sv, 0, sizeof sv);
    for(int i = 1; i <= n; i++){
        if(w[i] >= W) sn[i] = sn[i - 1] + 1, sv[i] = sv[i - 1] + v[i];
        else sn[i] = sn[i - 1], sv[i] = sv[i - 1];
    }
    LL y = 0;
    for(int i = 1; i <= m; i++){
        y += (sn[r[i]] - sn[l[i] - 1]) * (sv[r[i]] - sv[l[i] - 1]); //前缀和
    }
    ans = min(ans, llabs(s - y));
    return y <= s;
}

int main(){
    scanf("%d%d%lld", &n, &m, &s);
    for(int i = 1; i <= n; i++) scanf("%d%d", w + i, v + i);
    for(int i = 1; i <= m; i++) scanf("%d%d", l + i, r + i);
    int l = 0, r = 1e6 + 1;
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%lld", ans);
    return 0;
}