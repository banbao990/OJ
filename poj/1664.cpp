/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1664                        *
 **********************************************************************/

/*
 * bbq: 
*/

#include <stdio.h>

int put(int M, int N) {
    if (N == 1)
        return 1;
    if (M < N)
        return put(M, N - 1);
    else
        return put(M - N, N) + put(M, N - 1);
}

int main() {
    int t;
    int M, N;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &M, &N);
        printf("%d\n", put(M, N));
    }
    return 0;
}



/*
放苹果
Time Limit: 1000MS      Memory Limit: 10000K
Total Submissions: 38242        Accepted: 23514
Description

把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，
问共有多少种不同的分法？（用K表示）
5，1，1和1，5，1 是同一种分法。
Input

第一行是测试数据的数目t（0 <= t <= 20）。
以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
Output

对输入的每组数据M和N，用一行输出相应的K。
Sample Input

1
7 3
Sample Output

8
Source

lwx@POJ
*/
