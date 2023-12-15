#include<iostream>

using namespace std;

using LL = long long;
const int N = 1010;
int n, c;
LL res = 0;
LL a[N], sum[N];

void dfs(int index, LL weight){

    if(weight + sum[index] <= res) return;
    res = max(weight, res);
    if(index == 0) return;
    if(weight + a[index] <= c)
        dfs(index - 1, weight + a[index]);
    dfs(index - 1, weight);
}

int main(){
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }
    dfs(n, 0);
    cout << res;
}