#include<iostream>

using namespace std;

int l, n, m;
int a[50050];

//跳跃距离越大，移走石头越多，增函数
//求跳跃距离最大值

bool check(int step){
    int cnt = 0, last = 0;
    for(int i = 1; i <= n + 1; i++){
        if(a[i] - a[last] < step) cnt++;
        else last = i;
    }
    return cnt <= m;
}

int main(){
    scanf("%d%d%d", &l, &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    a[n + 1] = l;
    int l = 0, r = 1e9 + 1;
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%d", l);
}