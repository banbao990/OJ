/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://bailian.openjudge.cn/practice/2698             *
 **********************************************************************/

/*
 * bbq: 八皇后问题, 经典递归回溯问题
*/

#include <stdio.h>

#define N 8 

void print(int a[N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N - 1; j++)
            printf(a[j] == i ? "1 " : "0 ");
        printf(a[j] == i ? "1" : "0");
        printf("\n");
    }
}

int step(int a[N], int n, int count) {
    int i, k;
    for (k = 0; k < N; k++) {
        for (i = 0; i < n; i++)
            if (a[i] == k || a[i] + i == k + n || a[i] - i == k - n)
                break;
        if (i == n) {
            a[n] = k;
            if (n == N - 1) {
                printf("No. %d\n", ++count);
                print(a);
            }
            else
                count = step(a, n + 1, count);
        }
    }
    return count;
}

int main(void) {
    int a[N] = {};              //棋盘向量 
    step(a, 0, 0);              //递归所有解 
    return 0;                   //退出主函数 
}

/*
2698:八皇后问题
总时间限制: 10000ms 内存限制: 65536kB
描述
在国际象棋棋盘上放置八个皇后，要求每两个皇后之间不能直接吃掉对方。
输入
无输入。
输出
按给定顺序和格式输出所有八皇后问题的解（见Sample Output）。
样例输入
样例输出
No. 1
1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1
0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0
0 0 1 0 0 0 0 0
No. 2
1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1
0 1 0 0 0 0 0 0
0 0 0 0 1 0 0 0
0 0 1 0 0 0 0 0
No. 3
1 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1
0 0 1 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 0 1 0 0 0 0
0 1 0 0 0 0 0 0
0 0 0 0 1 0 0 0
No. 4
1 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1
0 0 0 0 0 1 0 0
0 0 1 0 0 0 0 0
0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0
No. 5
0 0 0 0 0 1 0 0
1 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0
0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 1
0 0 1 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 0 1 0 0 0 0
No. 6
0 0 0 1 0 0 0 0
1 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1
0 1 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 1 0 0 0 0 0
0 0 0 0 0 1 0 0
No. 7
0 0 0 0 1 0 0 0
1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1
0 0 0 1 0 0 0 0
0 1 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 1 0 0 0 0 0
0 0 0 0 0 1 0 0
No. 8
0 0 1 0 0 0 0 0
1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1
0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0
No. 9
0 0 0 0 1 0 0 0
1 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1
0 1 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 1 0 0 0 0 0
...以下省略
提示
此题可使用函数递归调用的方法求解。
来源
计算概论05
*/
