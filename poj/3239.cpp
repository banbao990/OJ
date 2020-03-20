/***********************
 * author:      banbao *
 * language:    c++/c  *
 ***********************/

// link : http://poj.org/problem?id=3239
/*
 * bbq: 爬山法
 * description: n皇后问题(八皇后问题推广)
 * question: 为啥这题不重启也能过
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
#define One 1
#define Two 2
#define Three 3
#define Four 4
#define Five 5
#define Six 6
#define Seven 7
#define Eight 8
#define Nine 9

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
#define MAXN 350

int N;
int a[MAXN];
int conflict;// 记录全局的冲突数目(0等价OK)
int v[MAXN];// 第i列皇后数
int d[MAXN << 1];// 对角线皇后数
int ad[MAXN << 1];// 反对角线皇后数

// 初始化棋盘
void initTheChess();

int con(int x, int y);// 计算(x,y)出皇后的冲突数
void take(int x, int y);// 从(x,y)拿走一个皇后
void put(int x, int y);// 在(x,y)放置一个皇后
int best(int x);// 找到当前皇后的最佳位置
void printChess();// 输出一个结果
void solve();

int main() {
    while (scanf("%d", &N) != EOF && N) solve();
    system("pause");
    return 0;
}

void init() {}

// 初始化棋盘
void initTheChess() {
    memset(v, 0, sizeof(v));
    memset(d, 0, sizeof(d));
    memset(ad, 0, sizeof(ad));
    conflict = 0;
    // 随机放置
    for (int i = 0; i < N; ++i) put(i, rand() % N);
}

// 计算(x,y)出皇后的冲突数
int con(int x, int y) {
    return v[y] + d[x + N - y] + ad[x + y];
}

// 从(x,y)拿走一个皇后
void take(int x, int y) {
    if (--v[y] > 0) --conflict;
    if (--d[x + N - y] > 0) --conflict;
    if (--ad[x + y] > 0) --conflict;
}

// 在(x,y)放置一个皇后
void put(int x, int y) {
    a[x] = y;
    if (++v[y] > 1) ++conflict;
    if (++d[x + N - y] > 1) ++conflict;
    if (++ad[x + y] > 1) ++conflict;
}

// 找到当前皇后的最佳位置
int best(int x) {
    // 记录冲突数目的最小值
    int m = INT_MAX;
    for (int y = 0; y < N; ++y) {
        int t = con(x, y);
        if (t < m) m = t;
    }
    vector<int> loc;
    loc.clear();
    for (int y = 0; y < N; ++y) 
        if (con(x, y) == m)
            loc.push_back(y);
    return loc[rand() % loc.size()];
}

// 输出一个结果
void printChess() {
    printf("%d", a[0] + 1);
    for (int i = 1; i < N; ++i)
        printf(" %d", a[i] + 1);
    printf("\n");
}

void solve() {
    initTheChess();
    while (true) {
        bool change = false;
        for (int i = 0; i < N; ++i) {
            // 没有冲突
            if (con(i, a[i]) == 0) continue;
            // 有冲突,拿走皇后,放在最好的行上
            int before = a[i];
            take(i, a[i]);
            int next = best(i);
            put(i, next);
            if (next != before) change = true;
            // 全局没有冲突
            if (!conflict) {
                printChess();
                return;
            }
        }
        // 陷入局部极值时候重启
        if (!change) {
            initTheChess();
        }
    }
}

/*

Solution to the n Queens Puzzle
Time Limit: 1000MS		Memory Limit: 131072K
Total Submissions: 4304		Accepted: 1544		Special Judge
Description

The eight queens puzzle is the problem of putting eight chess queens
 on an 8 × 8 chessboard such that none of them is able to capture 
 any other. The puzzle has been generalized to arbitrary n × n boards.
 Given n, you are to find a solution to the n queens puzzle.


Input

The input contains multiple test cases. Each test case consists of 
a single integer n between 8 and 300 (inclusive).
 A zero indicates the end of input.

Output

For each test case, output your solution on one line. The solution 
is a permutation of {1, 2, …, n}. The number in the ith place means
 the ith-column queen in placed in the row with that number.

Sample Input

8
0

Sample Output

5 3 1 6 8 2 4 7

Source

POJ Monthly--2007.06.03, Yao, Jinyu

*/


