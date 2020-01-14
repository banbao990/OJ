/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1088                        *
 **********************************************************************/

/*
 * bbq: dfs
*/

#include <stdio.h>
#include <malloc.h>

#define MAX(x,y)((x)>(y)?(x):(y))

int**ski, **flag;
int R, C;

int length(int i, int j) {
    int a, b, c, d, temp;
    a = b = c = d = 0;
    // 记忆化搜索
    if (flag[i][j])
        return flag[i][j];
    if ((j > 0) && (ski[i][j] > ski[i][j - 1]))
        a = length(i, j - 1) + 1;
    if ((j < C - 1) && (ski[i][j] > ski[i][j + 1]))
        b = length(i, j + 1) + 1;
    if ((i > 0) && (ski[i][j] > ski[i - 1][j]))
        c = length(i - 1, j) + 1;
    if ((i < R - 1) && (ski[i][j] > ski[i + 1][j]))
        d = length(i + 1, j) + 1;
    temp = MAX(MAX(a, b), MAX(c, d));
    flag[i][j] = temp;
    if (!temp) return 1;
    else return temp;
}

int main() {
    int i, j;
    int max = 0;
    int temp;

    scanf("%d%d", &R, &C);
    ski = (int**)malloc(sizeof(int*)*R);
    flag = (int**)malloc(sizeof(int*)*R);
    for (i = 0; i < R; i++) {
        ski[i] = (int*)malloc(sizeof(int)*C);
        flag[i] = (int*)malloc(sizeof(int)*C);
    }

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            scanf("%d", &ski[i][j]);
            flag[i][j] = 0;
        }
    }
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            temp = length(i, j);
            max = (max > temp) ? max : temp;
        }
    }

    printf("%d", max);

    for (i = 0; i < R; i++) {
        free(ski[i]);
        free(flag[i]);
    }

    free(ski);
    free(flag);

    return 0;
}

/*
滑雪
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 108970       Accepted: 41481
Description

Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。
可是为了获得速度，滑的区域必须向下倾斜，
    而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。
Michael想知道载一个区域中最长底滑坡。
区域由一个二维数组给出。数组的每个数字代表点的高度。
下面是一个例子
 1  2  3  4 5

16 17 18 19 6

15 24 25 20 7

14 23 22 21 8

13 12 11 10 9

一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。
在上面的例子中，一条可滑行的滑坡为24-17-16-1。
当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
Input

输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。
下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
Output

输出最长区域的长度。
Sample Input

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
Sample Output

25
Source

SHTSC 2002
*/


/*
3 3 1 1 1 1 2 1 1 1 1
*/
