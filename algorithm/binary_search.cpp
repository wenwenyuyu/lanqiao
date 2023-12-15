#include<iostream>

using namespace std;

const int N = 1e6 + 10;
int a[N];
int n, m;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    int l = -1, r = n;
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(a[mid] >= m) r = mid;
        else l = mid;
    }
    printf("%d", a[r] == m ? r : -1);
    return 0;
}