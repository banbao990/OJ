/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1207                        *
 **********************************************************************/

/*
 * bbq: 可以加上保存计算过的值
 */

#include <stdio.h>
#include <limits.h> 
int main() {
    int min, max;
    int i;
    int k;
    int ans;
    int length;
    int xiao, da;

    while (scanf("%d %d", &min, &max) != EOF) {
        if (min > max) {
            xiao = max;
            da = min;
        }
        else {
            xiao = min;
            da = max;
        }
        ans = 0;
        for (i = xiao; i <= da; i++) {
            k = i;
            length = 1;
            while (k != 1) {
                length++;
                if (k % 2) k = 3 * k + 1;
                else k = k >> 1;
            }
            if (length > ans) ans = length;
        }
        printf("%d %d %d\n", min, max, ans);
    }
    return 0;
}


/*
The 3n + 1 problem
algorithm:
    1.  input n
    2.  print n
    3.  if n = 1 
            then STOP
    4.  if n is odd 
            then n <-- 3n+1
        else 
            n <-- n/2
    5.  GOTO 2

For each pair of input integers i and j ，
you should output i, j, and the maximum cycle length 
for integers between and including i and j.

Sample Input

1 10
100 200
201 210
900 1000
Sample Output

1 10 20
100 200 125
201 210 89
900 1000 174
Source

Duke Internet Programming Contest 1990,uva 100
*/
