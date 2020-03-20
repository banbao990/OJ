/***********************
 * author:      banbao *
 * language:    c++/c  *
 ***********************/

// link : http://poj.org/problem?id=3239
/*
 * bbq: ��ɽ��
 * description: n�ʺ�����(�˻ʺ������ƹ�)
 * question: Ϊɶ���ⲻ����Ҳ�ܹ�
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
int conflict;// ��¼ȫ�ֵĳ�ͻ��Ŀ(0�ȼ�OK)
int v[MAXN];// ��i�лʺ���
int d[MAXN << 1];// �Խ��߻ʺ���
int ad[MAXN << 1];// ���Խ��߻ʺ���

// ��ʼ������
void initTheChess();

int con(int x, int y);// ����(x,y)���ʺ�ĳ�ͻ��
void take(int x, int y);// ��(x,y)����һ���ʺ�
void put(int x, int y);// ��(x,y)����һ���ʺ�
int best(int x);// �ҵ���ǰ�ʺ�����λ��
void printChess();// ���һ�����
void solve();

int main() {
    while (scanf("%d", &N) != EOF && N) solve();
    system("pause");
    return 0;
}

void init() {}

// ��ʼ������
void initTheChess() {
    memset(v, 0, sizeof(v));
    memset(d, 0, sizeof(d));
    memset(ad, 0, sizeof(ad));
    conflict = 0;
    // �������
    for (int i = 0; i < N; ++i) put(i, rand() % N);
}

// ����(x,y)���ʺ�ĳ�ͻ��
int con(int x, int y) {
    return v[y] + d[x + N - y] + ad[x + y];
}

// ��(x,y)����һ���ʺ�
void take(int x, int y) {
    if (--v[y] > 0) --conflict;
    if (--d[x + N - y] > 0) --conflict;
    if (--ad[x + y] > 0) --conflict;
}

// ��(x,y)����һ���ʺ�
void put(int x, int y) {
    a[x] = y;
    if (++v[y] > 1) ++conflict;
    if (++d[x + N - y] > 1) ++conflict;
    if (++ad[x + y] > 1) ++conflict;
}

// �ҵ���ǰ�ʺ�����λ��
int best(int x) {
    // ��¼��ͻ��Ŀ����Сֵ
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

// ���һ�����
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
            // û�г�ͻ
            if (con(i, a[i]) == 0) continue;
            // �г�ͻ,���߻ʺ�,������õ�����
            int before = a[i];
            take(i, a[i]);
            int next = best(i);
            put(i, next);
            if (next != before) change = true;
            // ȫ��û�г�ͻ
            if (!conflict) {
                printChess();
                return;
            }
        }
        // ����ֲ���ֵʱ������
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
 on an 8 �� 8 chessboard such that none of them is able to capture 
 any other. The puzzle has been generalized to arbitrary n �� n boards.
 Given n, you are to find a solution to the n queens puzzle.


Input

The input contains multiple test cases. Each test case consists of 
a single integer n between 8 and 300 (inclusive).
 A zero indicates the end of input.

Output

For each test case, output your solution on one line. The solution 
is a permutation of {1, 2, ��, n}. The number in the ith place means
 the ith-column queen in placed in the row with that number.

Sample Input

8
0

Sample Output

5 3 1 6 8 2 4 7

Source

POJ Monthly--2007.06.03, Yao, Jinyu

*/


