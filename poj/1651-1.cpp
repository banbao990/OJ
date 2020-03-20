/***********************
 * author:      banbao *
 * language:    c++/c  *
 ***********************/

// link : http://poj.org/problem?id=1651

/*
 * bbq: 矩阵链相乘, dp, 递归实现
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

const int MAXN = 150;
int dp[MAXN][MAXN];
int matrix[MAXN];
int N; // 3 <= N <= 100

// dp, 矩阵链相乘最小次数
// f(i,j) = min{f(i,k) + f(k,j) + i*k*j} (i<k<j)
// 矩阵标号 1, 2, 3, ..., N-1
// 矩阵 i 为 matrix[i-1] 行 matrix[i]列
// dp[i][j] 表示矩阵链 i, i+1, ..., j 相乘的最小结果
// 记忆化
// 空间换时间

int f(int l, int r) {
    if (l == r) return 0;
    if (dp[l][r]) return dp[l][r];
    int ans = INT_MAX;
    for (int k = l; k < r; ++k) {
        int anslkr = f(l, k) + f(k + 1, r) + matrix[l - 1] * matrix[k] * matrix[r];
        if (anslkr < ans)
            ans = anslkr;
    }
    dp[l][r] = ans;
    return ans;
}

int main() {
    // input
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", matrix + i);
    // deal
    init();
    printf("%d\n", f(1, N - 1));
    system("pause");
    return 0;
}

void init() {
    memset(dp, 0, sizeof(dp));
    // dp 终点
    for (int i = 1; i < N - 1; ++i)
        dp[i][i + 1] = matrix[i - 1] * matrix[i] * matrix[i + 1];
}
/*

Multiplication Puzzle
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 16151        Accepted: 9914
Description

The multiplication puzzle is played with a row of cards, each containing 
a single positive integer. During the move player takes one card out of the row 
and scores the number of points equal to the product of the number on the card taken 
and the numbers on the cards on the left and on the right of it. 
It is not allowed to take out the first and the last card in the row. 
After the final move, only two cards are left in the row. 

The goal is to take cards in such order as to minimize 
the total number of scored points. 

For example, if cards in the row contain numbers 10 1 50 20 5, 
player might take a card with 1, then 20 and 50, scoring 
    10*1*50 + 50*20*5 + 10*50*5 = 500+5000+2500 = 8000

If he would take the cards in the opposite order,
 i.e. 50, then 20, then 1, the score would be 
    1*50*20 + 1*20*5 + 10*1*5 = 1000+100+50 = 1150.

Input

The first line of the input contains the number of cards N (3 <= N <= 100). 
The second line contains N integers in the range from 1 to 100, separated by spaces.

Output

Output must contain a single integer - the minimal score.

Sample Input

6
10 1 50 50 20 5

Sample Output

3650

Source

Northeastern Europe 2001, Far-Eastern Subregion

*/