/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1003                        *
 **********************************************************************/

/*
 * bbq: 输入a, 输出使得 1/2 + 1/3 + 1/4 + ... + 1/(n + 1) >= a 的最小 n
*/

#include <stdio.h>
#include <math.h>

int main() {
    double test;
    double sum = 0;
    double i = 2;
    while (1) {
        scanf("%lf", &test);
        if (fabs(test) > 1e-6) {
            sum = 0;
            i = 2;
            while (1) {
                sum += 1 / i;
                if (sum >= test) {
                    printf("%d card(s)\n", (int)(i - 1));
                    break;
                }
                ++i;
            }
        }
        else break;
    }
    return 0;
}
