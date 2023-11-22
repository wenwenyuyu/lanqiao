#include<iostream>

using namespace std;

int n, w;
const int N = 300;
int w[N], t[N];

bool check(double W){
    
}

int main(){
    scanf("%d%d", &n, &w);
    for(int i = 1; i <= n; i++) scanf("%d%d", w + i, t + i);
    double l = 0, r = 1e6 + 1;
    while(r - l > 1e-4){
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
}