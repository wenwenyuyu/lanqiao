#include<iostream>

using namespace std;

int a, w, m;

// 第一个月还完w还剩 s = a(1+x)-w
// 第二个月 s = s(1+x) - w
// x越大, s越大
bool check(double x){
    double s = a;
    for(int i = 1; i <= m; i++)
        s = s * (1 + x) - w;
    return s >= 0;
}

int main(){
    scanf("%d%d%d", &a, &w, &m);
    double l = 0, r = 1;
    while(r - l > 1e-5){
        double mid = (l + r)/2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%.1lf", r * 100);
}