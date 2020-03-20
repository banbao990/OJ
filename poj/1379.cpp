/***********************
 * author:      banbao *
 * language:    c++/c  *
 ***********************/

// link : http://poj.org/problem?id=1379
/*
 * bbq: 模拟退火(隐含条件:全局最优值比局部最优值底盘大)
 *      (想象成山峰山脚占地面积)
 * description: 
 *      在矩形(x*y)内有M个点,找到一个里最近距离最远的点
 *      精确到一位小数
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
void solve();

/* pragmas */
#pragma warning(disable:4996)

/* const variables */
const int INF_INT = 1 << 29;
const double PI = acos((double)-1);
const double INF = 1e20;
const double EPS = 1e-6;

/* code start here */
#define MAXN 1200
// 1 <= X, Y <= 10000, 1 <= M <= 1000
int X, Y, M;
int recX[MAXN], recY[MAXN];// 记录输入的矩形

inline bool outbound(double x, double y) {
    return !(x >= 0 && x <= X && y >= 0 && y <= Y);
}

int main() {
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d %d", &X, &Y, &M);
        for (int i = 0; i < M; ++i) scanf("%d %d", &recX[i], &recY[i]);
        solve();
    }
    system("pause");
    return 0;
}

void init() {}

double calc(double x, double y) {
    double dis = 1e20;
    for (int i = 0; i < M; ++i) {
        double tempDis = sqrt((x-recX[i])*(x - recX[i])+(y - recY[i])*(y - recY[i]));
        if (tempDis < dis) dis = tempDis;
    }
    return dis;
}

void solve() {
    double nowX, nowY;
    double nowAns = 0;
    int dx[8] = { -1,-1,-1,0,0,1,1,1 };
    int dy[8] = { -1,0,1,-1,1,-1,0,1 };
    // 初始值也可以随机给定
    nowX = X >> 1; nowY = Y >> 1;
    // t表示走的步伐, 刚开始大, 后来小
    // 调参
    for (double t = 1000; t > 1e-6; t *= 0.9) {
        // 向 8 个方向扩展
        for (int i = 0; i < 8; ++i) {
            double tempX = nowX + dx[i] * t;
            double tempY = nowY + dy[i] * t;
            if (outbound(tempX, tempY)) continue;
            double tempAns = calc(tempX, tempY);
            if (tempAns > nowAns) {
                nowAns = tempAns;
                nowX = tempX;
                nowY = tempY;
            }
        }
    }
    printf("The safest point is (%.1lf, %.1lf).\n", nowX, nowY);
}


/*
Run Away
Time Limit: 3000MS		Memory Limit: 65536K
Total Submissions: 11371		Accepted: 3324
Description

One of the traps we will encounter in the Pyramid is located 
in the Large Room. A lot of small holes are drilled into the 
floor. They look completely harmless at the first sight.
But when activated, they start to throw out very hot java,
uh ... pardon, lava. Unfortunately, all known paths to the
Center Room (where the Sarcophagus is) contain a trigger 
that activates the trap. The ACM were not able to avoid that. 
But they have carefully monitored the positions of all the holes.
So it is important to find the place in the Large Room that 
has the maximal distance from all the holes. This place is 
the safest in the entire room and the archaeologist has to 
hide there.

Input

The input consists of T test cases. The number of them (T)
is given on the first line of the input file. Each test 
case begins with a line containing three integers X, Y, M 
separated by space. The numbers satisfy conditions: 1 <= X,
Y <=10000, 1 <= M <= 1000. The numbers X and Yindicate the 
dimensions of the Large Room which has a rectangular shape.
The number M stands for the number of holes. Then exactly M
lines follow, each containing two integer numbers Ui and Vi 
(0 <= Ui <= X, 0 <= Vi <= Y) indicating the coordinates of 
one hole. There may be several holes at the same position.

Output

Print exactly one line for each test case. The line should
contain the sentence "The safest point is (P, Q)." where P
and Qare the coordinates of the point in the room that has
the maximum distance from the nearest hole, rounded to the 
nearest number with exactly one digit after the decimal 
point (0.05 rounds up to 0.1).

Sample Input

3
1000 50 1
10 10
100 100 4
10 10
10 90
90 10
90 90
3000 3000 4
1200 85
63 2500
2700 2650
2990 100

Sample Output

The safest point is (1000.0, 50.0).
The safest point is (50.0, 50.0).
The safest point is (1433.0, 1669.8).

Source

Central Europe 1999
*/