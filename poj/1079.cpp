/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1079                        *
 **********************************************************************/

/*
 * bbq: 
*/

#include <stdio.h>

// 辗转相除法求最大公约数
int gcd(int m, int n) {
    int t = 1;
    while (t != 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}

int main() {
    int x, y, zdgys; //最大公约数 
    double standard;
    //cha1表示下一个分母中精确度比第一个小的第一个数，cha2表示下一个 (同分母)
    double cha1, cha2, cha;

    int i, j;

    while (scanf("%d %d", &x, &y) != EOF) {
        zdgys = gcd(x, y);
        x /= zdgys;
        y /= zdgys;
        standard = 1.0*x / y;
        cha = 1;

        for (i = 1; i <= y; i++) {
            for (j = 1; j <= x; j++) {
                cha1 = 1.0*j / i - standard;
                if (cha1 < 0)  cha1 = -cha1;
                if (cha1 < cha) {
                    cha2 = 1.0*(j + 1) / i - standard;
                    if (cha2 <= cha1) {
                        cha = cha2;//遇到大相同的取大的                    
                        j++;
                    }
                    else cha = cha1;
                    printf("%d/%d\n", j, i);
                    break;
                }

            }
        }
        printf("\n");
    }
    return 0;
}
