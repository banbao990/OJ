/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=3086                        *
 **********************************************************************/

/*
 * bbq:
*/

#include <stdio.h>

int main() {
    int N;
    int i, j;
    int n;
    int ans;

    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &n);
        ans = 0;
        for (j = 1; j <= n; j++) {
            ans += j * (1 + j + 1)*(j + 1) / 2;
        }
        printf("%d %d %d\n", i, n, ans);
    }
    return 0;
}

/*
Triangular Sums
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 7440     Accepted: 5245
Description

The nth Triangular number, T(n) = 1 + … + n, is the sum of the first n integers.
It is the number of points in a triangular array with n points on side.
For example T(4):

X
X X
X X X
X X X X
Write a program to compute the weighted sum of triangular numbers:

W(n) = SUM[k = 1…n; k * T(k + 1)]

Input

The first line of input contains a single integer N, (1 ≤ N ≤ 1000) which is the
number of datasets that follow.

Each dataset consists of a single line of input containing a single integer n,
(1 ≤ n ≤300), which is the number of points on a side of the triangle.

Output

For each dataset, output on a single line the dataset number (1 through N), a blank,
the value of n for the dataset, a blank, and the weighted sum ,W(n),
of triangular numbers for n.

Sample Input

4
3
4
5
10

Sample Output

1 3 45
2 4 105
3 5 210
4 10 2145
Source

Greater New York 2006
*/
