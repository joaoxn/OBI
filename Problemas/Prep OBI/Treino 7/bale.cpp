// 100/100 - https://judge.beecrowd.com/pt/runs/code/49115819
// Contagem de Inversões: MergeSort - O(nlogn)
#include <bits/stdc++.h>
using namespace std;

int n;
int v[100001];
int c = 0;

void merge(int left, int right) {
    int mid = (left+right)>>1;

    queue<int> lv;
    queue<int> rv;
    for (int i = left; i <= mid; i++) lv.push(v[i]);
    for (int i = mid+1; i <= right; i++) rv.push(v[i]);

    int k = left;
    while (!lv.empty() && !rv.empty()) {
        if (lv.front() <= rv.front()) {
            v[k++] = lv.front();
            lv.pop();
        } else {
            v[k++] = rv.front();
            rv.pop();
            c += lv.size();
        }
    }
    while (!lv.empty()) {
        v[k++] = lv.front();
        lv.pop();
    }
    while (!rv.empty()) {
        v[k++] = rv.front();
        rv.pop();
    }
}

void mergeSort(int left, int right) {
    if (left >= right) return;
    int mid = (left+right)>>1;
    mergeSort(left,mid);
    mergeSort(mid+1,right);
    merge(left,right);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", v+i);
    }

    mergeSort(0,n-1);
    printf("%d\n", c);
}