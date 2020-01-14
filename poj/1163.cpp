/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1163                        *
 **********************************************************************/

/*
 * bbq: 简单动规dp
*/

#include <stdio.h>
#include <limits.h>

int main() {
    int i, j;
    int a[105][105], b[105][105];
    int sum = INT_MIN;
    int N;
    int temp;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        for (j = 0; j <= i; j++)
            scanf("%d", &a[i][j]);
/*
    for (i = 0; i < N; i++)
        b[N - 1][i] = a[N - 1][i];
    for (i = N - 2; i >= 0; i--)
        for (j = 0; j <= i; j++)
            b[i][j] = a[i][j] + (temp = (b[i + 1][j] > b[i + 1][j + 1]) ? b[i + 1][j] : b[i + 1][j + 1]);
    printf("%d\n", b[0][0]);
*/
    b[0][0] = a[0][0];
    for (i = 1; i < N; i++) {
        b[i][0] = b[i - 1][0] + a[i][0];
        b[i][i] = b[i - 1][i - 1] + a[i][i];
        for (j = 1; j < i; j++) {
            temp = (b[i - 1][j] > b[i - 1][j - 1]) ? b[i - 1][j] : b[i - 1][j - 1];
            b[i][j] = temp + a[i][j];
        }
    }
    for (i = 0; i < N; i++)
        if (b[N - 1][i] > sum)
            sum = b[N - 1][i];
    printf("%d\n", sum);

    return 0;
}





/*

        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5

Write a program that calculates the highest sum of numbers passed on a route that
starts at the top and ends somewhere on the base.
Each step can go either diagonally down to the left or diagonally down to the right.

Sample Input

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
Sample Output

30

*/
