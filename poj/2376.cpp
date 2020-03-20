/***********************
 * author:      banbao *
 * language:    c++/c  *
 ***********************/

// link : http://poj.org/problem?id=2376

/*
 * bbq: 选择最少的区间覆盖[1,T]
 *      贪心算法, 优先选择开始时间早,结束时间晚的奶牛
 *      注意 : 区间不是端点表示"时间段"而不是"时刻"
 *      注意 i 的回溯
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
const int MAXN = 26000;
const int MAXT = 1001000;
struct node {
    int l, r;
    // 优先选择开始时间早,结束时间晚的奶牛
    bool operator < (const node &b) {
        if (l != b.l) return l < b.l;
        return r > b.r;
    }
};

node a[MAXN];

void solve() {
    int N, T;
    scanf("%d %d", &N, &T);
    int X = 0, Y = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &a[i].l, &a[i].r);
        if (a[i].l == 1) X = 1;
        if (a[i].r == T) Y = 1;
    }
    // 不能覆盖整个区间
    if (!X || !Y) {
        printf("-1\n");
        return;
    }
    sort(a, a + N);
    int ans = 1;
    int nowR = a[0].r, maxR = a[0].r;
    for (int i = 1; i < N; ++i) {
        // 能够被选择
        if (a[i].l <= nowR + 1) {
        // 看看能否更新最大值
            if (a[i].r > maxR) {
                maxR = a[i].r;
                // 成功选出方案
                if (maxR >= T) {
                    break;
                    ++ans;
                }
            }
        }
        // 不能够被选择
        else {
            // 看看之前有没有选出来, 如果没有选出来则没有方案
            if (nowR == maxR) break;
            nowR = maxR;
            ++ans;
            --i;// 这里需要回溯一下,因为现在不能使用的点可能在更新nowR之后就看可以使用了
        }
    }
    if (nowR != maxR) ++ans;
    // 看看有没有选出方案
    if (maxR < T) ans = -1;
    printf("%d\n", ans);
    return;
}

int main() {
    solve();
    system("pause");
    return 0;
}

void init() {
}
/*
Cleaning Shifts
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 47026		Accepted: 11082

Description

Farmer John is assigning some of his N (1 <= N <= 25,000) cows 
to do some cleaning chores around the barn.
He always wants to have one cow working on cleaning things up
and has divided the day into T shifts (1 <= T <= 1,000,000),
the first being shift 1 and the last being shift T.

Each cow is only available at some interval of times
during the day for work on cleaning. 
Any cow that is selected for cleaning duty will work 
for the entirety of her interval.

Your job is to help Farmer John assign some cows to shifts
so that (i) every shift has at least one cow assigned to it,
and (ii) as few cows as possible are involved in cleaning. 
If it is not possible to assign a cow to each shift, print -1.

Input

* Line 1: Two space-separated integers: N and T

* Lines 2..N+1: Each line contains the start and end times
of the interval during which a cow can work. 
A cow starts work at the start time and finishes after the end time.

Output

* Line 1: The minimum number of cows Farmer John needs to hire 
or -1 if it is not possible to assign a cow to each shift.
Sample Input

3 10
1 7
3 6
6 10
Sample Output

2

Hint

This problem has huge input data,use scanf() instead of cin 
to read data to avoid time limit exceed.

INPUT DETAILS:

There are 3 cows and 10 shifts. Cow #1 can work shifts 1..7, 
cow #2 can work shifts 3..6, and cow #3 can work shifts 6..10.

OUTPUT DETAILS:

By selecting cows #1 and #3, all shifts are covered. 
There is no way to cover all the shifts using fewer than 2 cows.
Source

USACO 2004 December Silver
*/