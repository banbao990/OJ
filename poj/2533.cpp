/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2533                        *
 **********************************************************************/

/*
 * bbq: 最长上升子序列
*/

#include <stdio.h>

#define max(x,y)    ((x)>(y))?(x):(y)

int main() {
    int a[1005];
    int dp[1005];
    int N;
    int i, j;

    scanf("%d", &N);
    for (i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    dp[1] = 1;
    for (i = 2; i <= N; i++) {
        dp[i] = 1;
        for (j = 1; j < i; j++)
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    int maxdp = 0;
    for (i = 1; i <= N; i++)
        maxdp = (maxdp > dp[i]) ? maxdp : dp[i];
    printf("%d", maxdp);
    return 0;
}



/*
Sample Input
7
1 7 3 5 9 4 8

Sample Output
4
*/
