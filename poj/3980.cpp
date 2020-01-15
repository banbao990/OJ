/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=3980                        *
 **********************************************************************/

/*
 * bbq:
*/

#include <stdio.h>

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) printf("%d\n", a%b);
    return 0;
}

/*
取模运算
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 13048        Accepted: 7674
Description

编写一个C函数mod(int n, int m),实现取模运算%
Input

输入包含多行数据

每行数据是两个整数a, b (1 <= a, b <= 32767)
数据以EOF结束
Output

于输入的每一行输出a%b
Sample Input

5 3
100 2
Sample Output

2
0
Source
*/
