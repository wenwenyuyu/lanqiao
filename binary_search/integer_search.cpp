#include<iostream>

using namespace std;

const int N = 1e6 + 10;
int q[N];

int find(int *arr, int target, int length){
    int l = 0, r = length + 1;
    while(l + 1 < r){
        int mid = (l + r) >> 1;
        if(arr[mid] >= target) r = mid; //最小化
        else l = mid;
    }
    return arr[r] == target ? r : -1;
}

int main(){
    int n, m, k;
    scanf("%d%d", &n , &m);
    for(int i = 1; i <= n; ++i){
        scanf("%d", q + i);
    }

    while(m--){
        scanf("%d", &k);
        int res = find(q, k, n);
        printf("%d ", res);
    }
    return 0;
}