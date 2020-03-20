/***********************
 * author:      banbao *
 * language:    c++/c  *
 ***********************/

// link : http://poj.org/problem?id=1568
// link : http://aiintro.openjudge.cn/test2/1/
/*
 * bbq: min-max算法
 *      可以用一个int来保存当前状态(32=2*16)
*/

/*
 * Q: 井字棋(4*4)[0-3][0-3]
 *    胜利条件:4子一线(有平局)
 *    输入:残局(x先手,下一步为x,x/o都至少走过2步)
 *    输出:下一步要走的棋(x,y),要求这一步必胜(不一定下一步胜利,而是最终胜利)
 *         没有方案则输出"#####"
 *         搜索顺序(题目要求):l->r,u->d
*/
 /* library */
#include <stdio.h>
#include <limits.h>
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

// 返回值只有-1,0,1(胜1,输-1,平0)
int minValueSearch(int now);
// 返回值只有-1,0,1(胜1,输-1,平0)
int maxValueSearch(int now);
// 针对 "x" 而言的输赢, 不检查下满了和棋的情况
int check(int now);

// 针对 "x" 而言的输赢, 不检查下满了和棋的情况

int main() {
    char op;
    while (scanf("%c", &op) != EOF && op == '?') {
        getchar();
        int now = 0;
        for (int i = 0; i < Four; ++i) {
            for (int j = 0; j < Four; ++j) {
                scanf("%c", &op);
                // int pos = (i*Four + j);
                int pos = ((i << 2) + j);
                // 0:'.', 1:'x', 2'o'
                if (op == 'x') now |= (1 << (pos << 1));
                else if (op == 'o') now |= (1 << ((pos << 1) | 1));
            }
            getchar();
        }
        // 搜索顺序(题目要求):l->r,u->d
        int k = 0;
        while (k < 31) {
            int nowPut = (now >> k) & 0x3;
            if (!nowPut) {
                int nextAction = minValueSearch(now | (0x1 << k));
                if (nextAction == 1) {
                    printf("(%d,%d)\n", (k >> 1) / Four, (k >> 1) % Four);
                    break;
                }
            }
            k += 2;
        }
        if (k > 31) printf("#####\n");
    }
    // system("pause");
    return 0;
}

void init() {}
// void solve() {}
void solve() {}

int check(int now) {
    // 0:'.', 1:'x', 2'o'
    // win+lost
    int win = 0x55;// 0b01010101
    int mask = 0xff;// 0b11111111
    int cnt = 4;
    while (cnt--) {
        if (!((now & mask) ^ win)) return 1;
        win <<= One;
        if (!((now & mask) ^ win)) return -1;
        win <<= Seven;
        mask <<= Eight;
    }
    win = 0x01010101;
    mask = 0x03030303;
    cnt = 4;
    while (cnt--) {
        if (!((now & mask) ^ win)) return 1;
        win <<= One;
        if (!((now & mask) ^ win)) return -1;
        win <<= One;
        mask <<= Two;
    }
    win = 0x40100401;
    mask = 0xc0300c03;
    if (!((now & mask) ^ win)) return 1;
    win <<= One;
    if (!((now & mask) ^ win)) return -1;
    win = 0x01041040;
    mask = 0x030c30c0;
    if (!((now & mask) ^ win)) return 1;
    win <<= One;
    if (!((now & mask) ^ win)) return -1;
    // !win && ! lost
    return 0;
}


// 返回值只有-1,0,1(胜1,输-1,平0)
int maxValueSearch(int now) {
    int win = check(now);
    // 出结果了,只能是-1(lost)
    if (win) return win;
    int k = 0;
    bool OK = true;
    while (k < 31) {
        int nowPut = (now >> k) & 0x3;
        if (!nowPut) {
            OK = false;
            int nextAction = minValueSearch((now | ((0x1) << k)));
            // 只要能赢就算赢
            if (nextAction == 1) return 1;
        }
        k += 2;
    }
    // draw
    if (OK) return 0;
    return -1;
}

// 返回值只有-1,0,1(胜1,输-1,平0)
int minValueSearch(int now) {
    int win = check(now);
    // 出结果了,只能是1(win)
    if (win) return win;
    int k = 0;
    bool OK = true;
    while (k < 31) {
        int nowPut = (now >> k) & 0x3;
        if (!nowPut) {
            OK = false;
            int nextAction = maxValueSearch((now | ((0x2) << k)));
            // 只要没赢就算输
            if (!nextAction || nextAction == -1) return -1;
        }
        k += 2;
    }
    // draw
    if (OK) return 0;
    return 1;
}

/*
Find the Winning Move
Time Limit: 3000MS		Memory Limit: 32768K
Total Submissions: 1924		Accepted: 918
Description

4x4 tic-tac-toe is played on a board with four rows (numbered 0
to 3 from top to bottom) and four columns (numbered 0 to 3 from
left to right). There are two players, x and o, who move
alternately with x always going first. The game is won by the
first player to get four of his or her pieces on the same row,
column, or diagonal. If the board is full and neither player
has won then the game is a draw.

Assuming that it is x's turn to move, x is said to have a forced
win if x can make a move such that no matter what moves o makes
for the rest of the game, x can win. This does not necessarily
mean that x will win on the very next move, although that is a
possibility. It means that x has a winning strategy that will
guarantee an eventual victory regardless of what o does.

Your job is to write a program that, given a partially-completed
game with x to move next, will determine whether x has a forced win.
You can assume that each player has made at least two moves,
that the game has not already been won by either player,
and that the board is not full.

Input

The input contains one or more test cases, followed by a line
beginning with a dollar sign that signals the end of the file.
Each test case begins with a line containing a question mark
and is followed by four lines representing the board;
formatting is exactly as shown in the example. The characters
used in a board description are the period (representing an
empty space), lowercase x, and lowercase o. For each test case,
output a line containing the (row, column) position of the first
forced win for x, or '#####' if there is no forced win
. Format the output exactly as shown in the example.

Output

For this problem, the first forced win is determined by board
position, not the number of moves required for victory.
Search for a forced win by examining positions (0, 0), (0, 1)
, (0, 2), (0, 3), (1, 0), (1, 1), ..., (3, 2), (3, 3), in that
order, and output the first forced win you find. In the second
test case below, note that x could win immediately by playing
at (0, 3) or (2, 0), but playing at (0, 1) will still ensure
victory (although it unnecessarily delays it),
and position (0, 1) comes first.

Sample Input

?
....
.xo.
.ox.
....
?
o...
.ox.
.xxx
xooo
$

Sample Output

#####
(0,1)

Source

Mid-Central USA 1999
*/