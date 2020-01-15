/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2299                        *
 **********************************************************************/
/*
 * bbq: 归并排序求逆序数
*/
#include <iostream>
using namespace std;
#include <stdio.h>
#include <malloc.h>
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
//const int INF = 1 << 25;
const double inf_d = 1e10;
const double eps = 1e-6;
template<class T>
inline int ABS(T a) { return a < 0 ? -a : a; }
template<class T>
inline void MYSWAP(T &a, T &b) {
    T c = a;
    a = b;
    b = c;
}

//freopen("test.txt", "w", stdout);

//const int MAXN = 1000000;
const int MAXN = 100;
const int MAXM = 111;

void init();
/* parameters, functions begin */
/* parameters,functions end */


static int A[MAXN];
static int B[MAXN];
static long ans;

void merge(int left, int right) {
    int m = (left + right) >> 1;
    int l = left, r = m + 1, k = left;
    
    while (l <= m && r <= right) {
        if (A[l] <= A[r]) B[k++] = A[l++];
        else {
            B[k++] = A[r++];
            ans += (r - k);
        }
    }
    while (l <= m) B[k++] = A[l++];
    while (r <= right)B[k++] = A[r++];
    for (int i = left; i <= right; ++i) A[i] = B[i];
}

void divide(int l, int r) {
    if (l == r) return;
    int m = (l + r) >> 1;
    divide(l, m);
    divide(m + 1, r);
    merge(l, r);
}
/* long 999999999 */
int main() {
    //freopen("test.txt", "w", stdout);
    int N;
    while ((cin >> N) && N) {
        ans = 0;
        for (int i = 0; i < N; ++i) cin >> A[i];
        divide(0, N - 1);
        cout << ans << endl;
    }
    system("pause");
    return 0;
}

void init() {}
