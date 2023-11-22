#include<iostream>

using namespace std;

int k, l;
const int N = 100010;
long long x[N];

int check(long long w){
    int cnt = 0;
    long long sum = 0;
    for(int i = 1; i <= l; ++i){
        sum += x[i];
        if(sum < 0) sum = 0;
        if(sum >= w){
            sum = 0;
            cnt++;
        }
    }
    return cnt;
}

int main(){
    scanf("%d%d", &l, &k);
    for(int i = 1; i <= l; i++) scanf("%lld", x + i);
    //最小
    long long l = 0, r = 1e18 + 1;
    while(l + 1 < r){
        long long mid = (l + r) / 2;
        if(check(mid) > k) l = mid;
        else if(check(mid) == k) r = mid;
        else r = mid;
    }
    long long min_d = check(r) == k ? r : -1;
    if(min_d == -1){
        printf("-1");
        return 0;
    }
    //最大
    l = 0, r = 1e18 + 1;
    while(l + 1 < r){
        long long mid = (l + r) / 2;
        if(check(mid) < k ) r = mid;
        else if(check(mid) == k) l = mid;
        else l = mid;
    }
    long long max_d = check(l) == k ? l : -1;
    if(max_d == -1){
        printf("-1");
        return 0;
    }
    printf("%lld %lld", min_d, max_d);
}