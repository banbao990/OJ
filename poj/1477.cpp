/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1447                        *
 **********************************************************************/

/*
 * bbq: 输出这一列数中比平均数大的数超出平均数的部分之和
*/

#include <stdio.h>
#include <malloc.h>

int main() {
    int i, j;
    int N;
    int *p;
    int av;//average
    int bricks;
    int sum;

    for (i = 1;; i++) {
        scanf("%d", &N);
        if (!N)  break;

        sum = 0;
        bricks = 0;
        p = (int*)malloc(sizeof(int)*N);
        for (j = 0; j < N; j++) {
            scanf("%d", &p[j]);
            sum += p[j];
        }
        av = sum / N;
        for (j = 0; j < N; j++)
            if (p[j] > av)
                bricks += p[j] - av;
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", i, bricks);
    }

    return 0;
}
