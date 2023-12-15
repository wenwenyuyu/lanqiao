#include<iostream>

using namespace std;

int a[100010], b[100010];
int n;

void m_sort(int l, int r){
    if(l == r) return;
    int mid = (l + r) >> 1;
    m_sort(l, mid);
    m_sort(mid + 1, r);

    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for(i = l; i <= r; i++) a[i] = b[i];
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    m_sort(0, n - 1);
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}