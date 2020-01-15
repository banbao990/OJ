/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2262                        *
 **********************************************************************/

/*
 * bbq: 哥德巴赫猜想, 偶数 = 质数1 + 质数2
*/

#include <stdio.h>
#include <math.h>

int judge(int a) {
    int i;
    int max = (int)sqrt((float)a) + 1;
    for (i = 2; i <= max; i++) {
        if (a%i) continue;
        break;
    }
    if (i == max + 1) return 1;
    else return 0;
}

int main() {
    int N;
    int i;
    int max;

    while (1) {
        scanf("%d", &N);
        if (!N) break;
        max = N / 2;
        for (i = 3; i < max; i++)
            if (judge(i) && judge(N - i))
                    break;
        printf("%d = %d + %d\n", N, i, N - i);
    }
    return 0;
}
