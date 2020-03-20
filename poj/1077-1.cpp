/***********************
 * author:      banbao *
 * language:    c++/c  *
 ***********************/

// link : http://poj.org/problem?id=1077
/*
 * bbq: TBFS(双向广搜)
 * description : 八数码问题
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
// 9! = 362880
#define MAXN 365000
// cantor
int cantor[Nine];
// begin, end
char en[Nine], be[Nine];
// 0表示尚未搜索到, 1表示正向搜索到了, 2表示反向搜索到了
char vis[MAXN];
// 判断是否找到答案
bool found;
// 记录TBFS相遇的点
int record;
// 移动位置
char dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
char move1[MAXN], move2[MAXN];
int father1[MAXN], father2[MAXN];
char pos1[5] = "urdl";
char pos2[5] = "dlur";

// cantor 哈希,一个全排列到自然数集的双射
void initAll() {
    // cantor
    cantor[Eight] = 1;
    for (int i = Eight - 1; i >= 0; --i) {
        cantor[i] = cantor[i + 1] * (Eight - i);
    }
    // 终点目标
    for (int i = 0; i < Eight; ++i) {
        en[i] = i + 1;
    }
    en[Eight] = 0;
}

// 求出给定的这个排列从小到大排在第几个(0开始)
// 对于每一位,找出后面有几个数字比他小
// 譬如第 x 位后面有 n 为比他小的数字
// 则 index += n*cantor[x]
int getHash(char *state) {
    int code = 0;
    for (int i = 0; i < Nine; ++i) {
        int cnt = 0;
        for (int j = i + 1; j < Nine; ++j) {
            if (state[i] > state[j]) {
                ++cnt;
            }
        }
        code += cantor[i] * cnt;
    }
    return code;
}


// BFS
void BFS(queue<char*> &Q, int from) {
    int to = (from == 1) ? 2 : 1;
    char* temp = Q.front();
    Q.pop();
    // 找到 0 的位置
    int zeroPos = 0;
    while (temp[zeroPos] != 0) ++zeroPos;
    // 确定坐标
    int x = zeroPos / 3, y = zeroPos % 3;
    int hash = getHash(temp);
    for (int i = 0; i < 4; ++i) {
        // 递归栈,不能使用局部变量
        char *t = new char[Nine];
        memcpy(t, temp, sizeof(char)*Nine);
        int xNow = x + dx[i], yNow = y + dy[i];
        if (xNow >= 0 && xNow < 3 && yNow >= 0 && yNow < 3) {
            int zeroPosNow = 3 * xNow + yNow;
            MYSWAP(t[zeroPos], t[zeroPosNow]);
            int hashNow = getHash(t);
            if (vis[hashNow] == to) {
                record = hashNow;
                if (to == 2) {
                    move1[hashNow] = i;
                    father1[hashNow] = hash;
                }
                else {
                    move2[hashNow] = i;
                    father2[hashNow] = hash;
                }
                found = true;
                return;
            }
            if (vis[hashNow] != from) {
                if (to == 2) {
                    move1[hashNow] = i;
                    father1[hashNow] = hash;
                }
                else {
                    move2[hashNow] = i;
                    father2[hashNow] = hash;
                }
                Q.push(t);
                vis[hashNow] = from;
            }
        }
    }
}

// TBFS
void TBFS() {
    queue<char*> Q1, Q2;
    while (!Q1.empty()) Q1.pop();
    while (!Q2.empty()) Q2.pop();
    vis[getHash(be)] = 1;
    vis[getHash(en)] = 2;
    Q1.push(be);
    Q2.push(en);
    while (!Q1.empty() || !Q2.empty()) {
        if (!Q1.empty()) BFS(Q1, 1);
        if (found) return;
        if (!Q2.empty()) BFS(Q2, 2);
        if (found) return;
    }
}

// 找到步骤
void findPath(int begin, int end) {
    stack<char> S;
    // 向前追溯
    int now = record;
    while (!S.empty()) S.pop();
    S.push(pos1[move1[now]]);
    while (father1[now] != begin) {
        now = father1[now];
        S.push(pos1[move1[now]]);
    }
    while (!S.empty()) {
        printf("%c", S.top());
        S.pop();
    }
    // 向后追溯
    now = record;
    if (now != end) {
        printf("%c", pos2[move2[now]]);
        while (father2[now] != end) {
            now = father2[now];
            printf("%c", pos2[move2[now]]);
        }
    }
    printf("\n");
}

int main() {
    initAll();
    char temp[Two];
    while (scanf("%s", temp) != EOF) {
        init();
        // input
        if (*temp == 'x') be[0] = 0;
        else be[0] = *temp - '0';
        for (int i = 1; i < Nine; ++i) {
            scanf("%s", temp);
            if (*temp == 'x') be[i] = 0;
            else be[i] = *temp - '0';
        }
        // 求逆序对, 如果逆序对为奇数则无解(交换不影响逆序对奇偶性)
        // 不算0
        int rev = 0;
        for (int i = 1; i < Nine; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!be[i] || !be[j]) continue;
                if (be[i] < be[j]) ++rev;
            }
        }
        if (rev & 1) printf("unsolvable\n");
        else {
            TBFS();
            findPath(getHash(be), getHash(en));
        }
    }
    system("pause");
    return 0;
}

void init() {
    record = 0;
    found = false;
    memset(vis, 0, sizeof(vis));
}


/*
Eight
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 40749		Accepted: 16822		Special Judge
Description

The 15-puzzle has been around for over 100 years;
even if you don't know it by that name, you've seen it.
It is constructed with 15 sliding tiles, each with a number
from 1 to 15 on it, and all packed into a 4 by 4 frame with
one tile missing. Let's call the missing tile 'x';
the object of the puzzle is to arrange the tiles so that
they are ordered as:

 1  2  3  4

 5  6  7  8

 9 10 11 12

13 14 15  x

where the only legal operation is to exchange 'x' with one
of the tiles with which it shares an edge. As an example,
the following sequence of moves solves a slightly scrambled puzzle:

 1  2  3  4    1  2  3  4    1  2  3  4    1  2  3  4

 5  6  7  8    5  6  7  8    5  6  7  8    5  6  7  8

 9  x 10 12    9 10  x 12    9 10 11 12    9 10 11 12

13 14 11 15   13 14 11 15   13 14  x 15   13 14 15  x

           r->           d->           r->

The letters in the previous row indicate which neighbor of
the 'x' tile is swapped with the 'x' tile at each step;
legal values are 'r','l','u' and 'd', for right, left, up,
and down, respectively.

Not all puzzles can be solved; in 1870, a man named Sam Loyd
was famous for distributing an unsolvable version of the puzzle,and
frustrating many people. In fact, all you have to do to make a
regular puzzle into an unsolvable one is to swap two tiles
(not counting the missing 'x' tile, of course).

In this problem, you will write a program for solving the
less well-known 8-puzzle, composed of tiles on a three by three
arrangement.

Input

You will receive a description of a configuration of the 8 puzzle.
The description is just a list of the tiles in their initial positions,
with the rows listed from top to bottom, and the tiles listed
from left to right within a row, where the tiles are represented
by numbers 1 to 8, plus 'x'. For example, this puzzle

 1  2  3

 x  4  6

 7  5  8

is described by this list:

 1 2 3 x 4 6 7 5 8

Output

You will print to standard output either the word ``unsolvable'',
if the puzzle has no solution, or a string consisting entirely of
the letters 'r', 'l', 'u' and 'd' that describes a series of moves
that produce a solution. The string should include no spaces and
start at the beginning of the line.

Sample Input

 2  3  4  1  5  x  7  6  8

Sample Output

ullddrurdllurdruldr

Source

South Central USA 1998
*/
/*
1 2 3 4 5 6 7 x 8
r
1 2 3 4 5 6 x 7 8
rr
1 2 3 4 x 6 7 5 8

*/