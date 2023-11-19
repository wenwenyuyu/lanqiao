#include<iostream>

using namespace std;

double a, b, c, d;
double res = 0.00;

double f(double x){
    return a * x * x * x + b * x * x + c * x + d;
}

double find(double l, double r){
    
    while(r - l > 1e-3){
        double mid = (l + r) / 2;
        if(f(mid) * f(r) < 0) l = mid; //最大化
        else r = mid;
    }
    
    return l;
}

int main(){
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

    for(int i = -100; i < 100; ++i){
        double y1 = f(i), y2 = f(i + 1);
        if(!y1) printf("%.2f ", i * 1.0);
        if(y1 * y2 < 0) printf("%.2f ", find(i, i + 1));
    }
    return 0;
}