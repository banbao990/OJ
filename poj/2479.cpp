/***********************
 * author:      banbao *
 * language:    c++/c  *
 ***********************/

// link : http://poj.org/problem?id=2479

/*
 * bbq: 最大连续子段和
 *      蛮力算法 : 枚举左右边界
 *                 O(n^3)
 *      分治算法 ：不跨边界 + 跨边界
 *                 O(nlogn)
 *      动态规划算法 : C[i]表示A[1,i]中包含A[i]的向前连续最大值, 解为 max{C[i]}
 *                 O(n)
 * bbq : 本题为求两段不相交的最大连续子段和
 *       dp前后各求一次即可
*/

 /* library */
#include <stdio.h>
#include <cstdio>
#include <malloc.h>
#include <algorithm>
#include <cmath>
#include <cstring>
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
#include <iostream>
using namespace std;

/* micros */
#define lowbit(x) ((x)&(-x))
#define leftson(x) ((x<<1)+1)
#define rightson(x) ((x<<1)+2)
#define parent(x) ((x-1)>>1)
#define mid(x,y) (((x)+(y))>>1)

/* functions */
template<class T>
inline int ABS(T a) { return a < 0 ? -a : a; }
template<class T>
inline void MYSWAP(T &a, T &b) {
    T c = a;
    a = b;
    b = c;
}
void init();

/* pragmas */
#pragma warning(disable:4996)

/* const variables */
const int INF_INT = 1 << 29;
const double PI = acos((double)-1);
const double INF = 1e20;
const double EPS = 1e-6;

/* code start here */
//  T<=30, 2<=N<=50000, |a[i]| <= 10000
const int MAXN = 60000;
int a[MAXN];
int C1[MAXN], C2[MAXN];// dp前, dp后
int B1[MAXN], B2[MAXN];// a[1,i]最大子段和, a[i,N]

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        // input
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) scanf("%d", a + i);
        // deal, ->
        C1[1] = a[1];
        B1[1] = a[1];
        for (int i = 2; i <= N; ++i) {
            int lastAddEnd = C1[i - 1] + a[i];
            if (lastAddEnd > a[i]) C1[i] = lastAddEnd;
            else C1[i] = a[i];
        }
        for (int i = 2; i <= N; ++i) {
            if (C1[i] > B1[i - 1]) B1[i] = C1[i];
            else B1[i] = B1[i - 1];
        }
        // deal, <-
        C2[N] = a[N];
        B2[N] = a[N];
        for (int i = N - 1; i >= 2; --i) {
            int lastAddEnd = C2[i + 1] + a[i];
            if (lastAddEnd > a[i]) C2[i] = lastAddEnd;
            else C2[i] = a[i];
        }
        for (int i = N - 1; i >= 2; --i) {
            if (C2[i] > B2[i + 1]) B2[i] = C2[i];
            else B2[i] = B2[i + 1];
        }
        // ans
        int ans = B1[1] + B2[2];
        for (int i = 2; i < N; ++i) {
            int now = B1[i] + B2[i + 1];
            if (now > ans) ans = now;
        }
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}

void init() {
}

/*
Maximum sum
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 46492		Accepted: 14377

Description
Given a set of n integers: A={a1, a2,..., an}, we define a function d(A) as below:
d(A) = max{ sum{a[i,j]}, sum{a[l,m]}} (1<=i<=j<l<=m<=N)
Your task is to calculate d(A).

Input

The input consists of T(<=30) test cases. 
The number of test cases (T) is given in the first line of the input. 
Each test case contains two lines. The first line is an integer n(2<=n<=50000).
The second line contains n integers: a1, a2, ..., an. (|ai| <= 10000).
There is an empty line after each case.

Output

Print exactly one line for each test case. The line should contain the integer d(A).
Sample Input

1

10
1 -1 2 2 3 -3 4 -4 5 -5
Sample Output

13
Hint

In the sample, we choose {2,2,3,-3,4} and {5}, then we can get the answer. 

Huge input,scanf is recommended.
Source

POJ Contest,Author:Mathematica@ZSU
*/
