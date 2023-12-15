#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

const int N = 200010;
struct Point
{
    double x, y;
}a[N], b[N];

bool cmp(Point &a, Point &b){
    if(a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}

bool cmpy(Point &a, Point &b){
    return a.y < b.y;
}

double dis(Point &a, Point &b){
    double x = (a.x - b.x) * (a.x - b.x);
    double y = (a.y - b.y) * (a.y - b.y);
    return sqrt(x + y);
}

double solve(int l, int r){
    if(l == r) return 2e9;
    if(l + 1 == r) return dis(a[l], a[r]);
    int mid = (l + r) >> 1;
    double d = min(solve(l, mid), solve(mid + 1,  r));

    int k = 0;
    for(int i = l; i <= r; i++){
        if(abs(a[mid].x - a[i].x) < d)
          b[k++] = a[i];
    }
    sort(b, b + k, cmpy);
    for(int i = 0; i < k - 1; i++){
        for(int j = i + 1; j < k && b[j].y - b[j].y < d; j++)
         d = min(d, dis(b[i], b[j]));
    }

    return d;
}

int n;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lf%lf", &a[i].x, &a[i].y);
    sort(a, a + n, cmp);
    printf("%.4f", solve(0, n - 1));
    
}