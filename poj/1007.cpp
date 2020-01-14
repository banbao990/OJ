
/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1007                        *
 **********************************************************************/

/*
 * bbq: maxlength > 50
 *      归并排序求逆序数
*/

#include <iostream>
using namespace std;
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <bitset>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#pragma warning(disable:4996)
const int INF = 1 << 25;
const double inf_d = 1e10;
const double eps = 1e-6;
//freopen("test.txt", "w", stdout);

const int MAXN = 200;
//const int MAXN = 101000;
char *b;
int ans = 0;

void merge(char *a, int left, int right) {
    int m = (left + right) >> 1;
    int l = left, r = m + 1, k = l;
    while (l <= m && r <= right) {
        // = 保证稳定性
        if (a[l] <= a[r]) b[k++] = a[l++];
        else {
            ans += (r - k);
            b[k++] = a[r++];
        }
    }
    while (l <= m) b[k++] = a[l++];
    while (r <= right) b[k++] = a[r++];
    for (k = left; k <= right; ++k) a[k] = b[k];
    return;
}

void divide(char *a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) >> 1;
    divide(a, l, m);
    divide(a, m + 1, r);
    merge(a, l, r);
    return;
}

void merge_sort(char *a, int n) {
    b = new char[n];
    divide(a, 0, n - 1);
    delete b;
}

struct Node {
    int index, val;
    bool operator < (const Node &b) const {
        if (val != b.val) return val < b.val;
        return index < b.index;
    }
    Node() {}
    Node(int _index, int _val) :index(_index), val(_val) {}
};

int main() {
    int N, M;
    char a[MAXN][MAXN];
    char _a[MAXN][MAXN];
    Node node[MAXN];
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) scanf("%s", a[i]);
    memcpy(_a, a, sizeof(a));
    for (int i = 0; i < M; ++i) {
        ans = 0;
        merge_sort(a[i], N);
        node[i] = Node(i, ans);
    }
    sort(node, node + M);
    for (int i = 0; i < M; ++i)
        printf("%s\n", _a[node[i].index]);
    system("pause");
    return 0;
}
