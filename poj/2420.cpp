/***********************
 * author:      banbao *
 * language:    c++/c  *
 ***********************/

// link : http://poj.org/problem?id=2020
// link : http://aiintro.openjudge.cn/test2/2/
// link : http://aiintro.openjudge.cn/practice/5/

/*
 * bbq: 模拟退火(隐含条件:全局最优值比局部最优值底盘大)
 *      (想象成山峰山脚占地面积)
 * description: 
 *      找到离给定M个点距离之和最小的点(精确到整数)
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
    X = Y = 0;
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &recX[i], &recY[i]);
        // 边界设为最大值
        if (recX[i] > X) X = recX[i];
        if (recY[i] > Y) Y = recY[i];
    }
    solve();
    system("pause");
    return 0;
}

void init() {}

double calc(double x, double y) {
    double dis = 0;
    for (int i = 0; i < M; ++i) {
        double tempDis = sqrt((x-recX[i])*(x - recX[i])+(y - recY[i])*(y - recY[i]));
        dis += tempDis;
    }
    return dis;
}

void solve() {
    double nowX, nowY;
    double nowAns = 1e20;
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
            if (tempAns < nowAns) {
                nowAns = tempAns;
                nowX = tempX;
                nowY = tempY;
            }
        }
    }
    printf("%.0lf\n", nowAns);
}

/*
A Star not a Tree?
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 11414		Accepted: 4675
Description

Luke wants to upgrade his home computer network from 10mbs to 100mbs.
 His existing network uses 10base2 (coaxial) cables that allow you to
 connect any number of computers together in a linear arrangement. 
 Luke is particulary proud that he solved a nasty NP-complete problem
 in order to minimize the total cable length. 
 
Unfortunately, Luke cannot use his existing cabling. The 100mbs system
 uses 100baseT (twisted pair) cables. Each 100baseT cable connects only
 two devices: either two network cards or a network card and a hub. 
 (A hub is an electronic device that interconnects several cables.) 
 Luke has a choice: He can buy 2N-2 network cards and connect his N
 computers together by inserting one or more cards into each computer
 and connecting them all together. Or he can buy N network cards and
 a hub and connect each of his N computers to the hub. The first 
 approach would require that Luke configure his operating system to
 forward network traffic. However, with the installation of Winux
 2007.2, Luke discovered that network forwarding no longer worked. 
 He couldn't figure out how to re-enable forwarding, and he had never
 heard of Prim or Kruskal, so he settled on the second approach: 
 N network cards and a hub. 

Luke lives in a loft and so is prepared to run the cables and place 
the hub anywhere. But he won't move his computers. He wants to
 minimize the total length of cable he must buy.
 
Input

The first line of input contains a positive integer N <= 100, 
the number of computers. N lines follow; each gives the (x,y)
 coordinates (in mm.) of a computer within the room. 
 All coordinates are integers between 0 and 10,000.
 
Output

Output consists of one number, the total length of the cable segments,
 rounded to the nearest mm.
 
Sample Input

4
0 0
0 10000
10000 10000
10000 0
Sample Output

28284
Source

Waterloo Local 2002.01.26
*/

