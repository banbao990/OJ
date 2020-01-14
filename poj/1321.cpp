/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1321                        *
 **********************************************************************/
/*
 * bbq : 八皇后问题拓展, dfs
*/
#include <stdio.h> //解决了 max = N 的情况                       
#include <stdlib.h>

int queen[8];
int sum, max;
char flag[10][10];

int conflict(int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (queen[i] == queen[n]) return 1;
    }
    return 0;
}

void put(int n) {
    int i;
    for (i = 0; i < max; i++) {
        if (flag[n][i] == '.') continue;
        queen[n] = i;
        if (!conflict(n)) {
            if (n == max - 1) {
                sum++;
                for (int j = 0; j < max; j++)
                    printf("%d", queen[j]);
                printf("\n");
            }

            else
                put(n + 1);
        }
    }
}

int main() {
    while (1) {
        int i;
        int N;
        sum = 0;
        scanf("%d %d", &max, &N);
        getchar();
        if (max == -1 && N == -1)  break;
        for (i = 0; i < max; i++)  gets(flag[i]);
        put(0);
        printf("%d\n", sum);
    }

    return 0;
}


/*
棋盘问题
Time Limit: 1000MS      Memory Limit: 10000K
Total Submissions: 70753        Accepted: 33482
Description

在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。
要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，
请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
Input

输入含有多组测试数据。
每组数据的第一行是两个正整数，n k，用一个空格隔开，
表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。
n <= 8 , k <= n
当为-1 -1时表示输入结束。
随后的n行描述了棋盘的形状：每行有n个字符，
其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。
Output

对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。
Sample Input

2 1
#.
.#
4 4
...#
..#.
.#..
#...
-1 -1
Sample Output

2
1
Source

蔡错@pku
*/


