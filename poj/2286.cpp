/***********************
 * author:      banbao *
 * language:    c++/c  *
 ***********************/

// link : http://poj.org/problem?id=2286
/*
 * bbq: ID 迭代加深算法
 * description : 输入顺序如下, 操作描述如下
 * output: 输出最少的移动方法 + 中间的数字(0 -> No moves needed)
*/

/*
 *           A     B
 *           01    02
 *           03    04
 *  H  05 06 07 08 09 10 11  C
 *           12    13
 *  G  14 15 16 17 18 19 20  D
 *           21    22
 *           23    24
 *           F     E
 */

/*
 * 具体实现下标从 0 开始而不是上面的 1 
*/

/*
 * 目标 : 中间 8 个数数字一致
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

// 数组大小
const int chessSize = 24;
// 07 08 09 
// 12    13
// 16 17 18 
// 中间 8 个数字在整个数组中的位置
const int centerEight[8] = { 6,7,8,11,12,15,16,17 };
#define Eight 8
#define Six 6
#define baseOperatorChar 'A'
const int moveOperate[Eight][Eight] = {
    {0,2,6,11,15,20,22},     //A
    {1,3,8,12,17,21,23},     //B
    {10,9,8,7,6,5,4},        //C
    {19,18,17,16,15,14,13},  //D
    {23,21,17,12,8,3,1},     //E
    {22,20,15,11,6,2,0},     //F
    {13,14,15,16,17,18,19},  //G
    {4,5,6,7,8,9,10}         //H
};
/*
 *           A     B
 *           01    02
 *           03    04
 *  H  05 06 07 08 09 10 11  C
 *           12    13
 *  G  14 15 16 17 18 19 20  D
 *           21    22
 *           23    24
 *           F     E
 */

// 函数声明

bool check(int *chess);// 检查现在中间八个数字是否相等
int countMinDiff(int *chess);// g:中间8个数字和众数的差距
bool dfs(int depth, int maxDepth, string &res, int *chess);// IDA
void move(int* chess, int n);// 移动操作

// ID 迭代加深算法
int main() {
    int chess[chessSize];
    while (scanf("%d", chess) && *chess != 0) {
        // input
        for (int i = 1; i < chessSize; ++i) {
            scanf("%d", &chess[i]);
        }
        // deal
        if (check(chess)) {
            printf("No moves needed\n%d\n", chess[centerEight[0]]);
        }
        else {
            int maxDepth = 1;
            string now = "";
            // ID
            while (!dfs(1, maxDepth, now, chess)) {
                now = "";
                ++maxDepth;
            }
            cout << now << endl;
            cout << chess[centerEight[0]] << endl;
        }
    }

    system("pause");
    return 0;
}

void init() {}

// 检查现在中间八个数字是否相等
bool check(int* chess) {
    for (int i = 1; i < Eight; ++i) {
        if (chess[centerEight[i]] != chess[centerEight[i - 1]]) {
            return false;
        }
    }
    return true;
}

// g:中间8个数字和众数的差距
// 这里尚未考虑:7个1,8个2,9个3,但是此时恰好7个1在中间
// 上述情况也满足 g 的要求
int countMinDiff(int* chess){
    int minDiff = 8;
    for (int i = 1;i <= 3; ++i) {
        int num = 0;
        for (int j = 0; j < Eight; ++j) {
            if (chess[centerEight[j]] != i) {
                ++num;
            }
        }
        if (num < minDiff) {
            minDiff = num;
        }
    }
    return minDiff;
}

// ID
bool dfs(int depth, int maxDepth, string &now, int* chess){
    // ID限制
    if (depth > maxDepth) {
        return false;
    }
    // 已经完成了搜索
    if (check(chess)) {
        return true;
    }
    // 剪枝
    if (depth + countMinDiff(chess) > maxDepth) {
        return false;
    }
    // 枚举 8 种移动方案
    for (int i = 0; i < Eight; ++i) {
        now.push_back(baseOperatorChar + i);
        move(chess, i);
        if (dfs(depth + 1, maxDepth, now, chess)) {
            return true;
        }
        else {
            // 逆操作,取消后效
            // CDGH(2,3,6,7)
            if (i & 2) {
                move(chess, 9 - i);
            }
            // ABEF(0,1,4,5)
            else {
                move(chess, 5 - i);
            }
            // now.pop_back();
            now.erase(now.end() - 1);
        }
    }
    return false;
}

// 移动操作
void move(int* chess, int op){
    // Six = Seven - 1(每次操作变化7个)
    int temp = chess[moveOperate[op][0]];
    for (int i = 0; i < Six; ++i) {
        chess[moveOperate[op][i]] = chess[moveOperate[op][i + 1]];
    }
    chess[moveOperate[op][Six]] = temp;
}


/*
The Rotation Game
Time Limit: 15000MS		Memory Limit: 150000K
Total Submissions: 7808		Accepted: 2692
Description

The rotation game uses a # shaped board, which can hold 24 pieces 
of square blocks (see Fig.1). The blocks are marked with symbols 
1, 2 and 3, with exactly 8 pieces of each kind.


Initially, the blocks are placed on the board randomly. Your task
is to move the blocks so that the eight blocks placed in the center
square have the same symbol marked. There is only one type of 
valid move, which is to rotate one of the four lines, each
consisting of seven blocks. That is, six blocks in the line
are moved towards the head by one block and the head block is 
moved to the end of the line. The eight possible moves are 
marked with capital letters A to H. Figure 1 illustrates two 
consecutive moves, move A and move C from some initial configuration.

Input

The input consists of no more than 30 test cases. Each test 
case has only one line that contains 24 numbers, which are
the symbols of the blocks in the initial configuration. 
The rows of blocks are listed from top to bottom. For each
row the blocks are listed from left to right. The numbers
are separated by spaces. For example, the first test case 
in the sample input corresponds to the initial configuration
in Fig.1. There are no blank lines between cases. There is a
line containing a single `0' after the last test case that 
ends the input.

Output

For each test case, you must output two lines. The first line 
contains all the moves needed to reach the final configuration.
Each move is a letter, ranging from `A' to `H', and there 
should not be any spaces between the letters in the line. 
If no moves are needed, output `No moves needed' instead. 
In the second line, you must output the symbol of the blocks
in the center square after these moves. If there are several 
possible solutions, you must output the one that uses the least
number of moves. If there is still more than one possible solution,
you must output the solution that is smallest in dictionary order 
for the letters of the moves. There is no need to output blank 
lines between cases.

Sample Input

1 1 1 1 3 2 3 2 3 1 3 2 2 3 1 2 2 2 3 1 2 1 3 3
1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3
0
Sample Output

AC
2
DDHH
2
Source

Shanghai 2004
*/