/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://bailian.openjudge.cn/practice/2754             *
 **********************************************************************/

/*
 * bbq: 八皇后问题
*/

#include <stdio.h>
#include <stdlib.h>

#define max 8

int a[92][8] = {};
int queen[8] = {};
int sum = 0;

int conflict(int n) {
    int i;
    for (i = 0; i < n; i++) {
        if ((queen[i] == queen[n]) || (abs(queen[n] - queen[i]) == n - i))
            return 1;
    }
    return 0;
}

void put(int n) {
    int i, j;
    for (i = 0; i < max; i++) {
        queen[n] = i;
        if (!conflict(n)) {
            if (n == max - 1) {
                for (j = 0; j < max; j++)  a[sum][j] = queen[j];
                sum++;
            }
            else
                put(n + 1);
        }
    }
}

int main() {
    put(0);

    int N, b;
    int i;

    scanf("%d", &N);
    while (N--) {
        scanf("%d", &b);
        b--;
        for (i = 0; i < max; i++)
            printf("%d", a[b][i] + 1);
        printf("\n");
    }
    return 0;
}

/*
2754:八皇后
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
会下国际象棋的人都很清楚：皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。
如何将8个皇后放在棋盘上（有8 * 8个方格），使它们谁也不能被吃掉！这就是著名的八皇后问题。
对于某个满足要求的8皇后的摆放方法，定义一个皇后串a与之对应，即a=b1b2...b8，
其中bi为相应摆法中第i行皇后所处的列数。已经知道8皇后问题一共有92组解（即92个不同的皇后串）。
给出一个数b，要求输出第b个串。串的比较是这样的：皇后串x置于皇后串y之前，当且仅当将x视为整数时比y小。
输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数b(1 <= b <= 92)
输出
输出有n行，每行输出对应一个输入。输出应是一个正整数，是对应于b的皇后串。
样例输入
2
1
92
样例输出
15863724
84136275
*/
