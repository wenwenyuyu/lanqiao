#include<iostream>

using namespace std;

int n, k;
int a[100010];

//单个长度越长，获得的数量越少，是个减函数
//求二分数据的最大值

bool check(int len){
    int sum = 0;
    for(int i = 1; i <= n; i++) sum += a[i]/len;
    return sum >= k;
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    int l = 0, r = 1e8;
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid; 
    }
    printf("%d", l < 1 ? 0 : l);
}