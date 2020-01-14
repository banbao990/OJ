/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1012                        *
 **********************************************************************/
/*
 * bbq: 约瑟夫问题(Joseph)
 *      好人:1   ~   N
 *      坏人:N+1 ~   2*N
 *      坏人在前 N 个死亡
 *      求满足条件的最小报的数字 m
 * ans: int ans[]={0,2,7,5,30,169,441,1872,7632,1740,
 *                  93313,459901,1358657,2504881,13482720};
*/

#include <stdio.h>
#pragma warning(disable:4996)

int main() {
    // 记录已经处理过的输入, 避免重复计算
    int record[15] = {};
    int death[15] = {};          // 存储人(并不是原来的顺序),而是当前顺序 
    int i;
    int N;
    int m;
    int num;
    while (1) {
        scanf("%d", &N);
        if (!N) break;
        // 已经记录
        if (record[N]) {
            printf("%d\n", record[N]);
            continue;
        }
        // normal
        m = N + 1;
        num = 2 * N;
        death[0] = 1;
        for (i = 1; i <= N; i++) {
            death[i] = (death[i - 1] + m - 1) % (num - i + 1);
            if (death[i] && death[i] <= N) {
                i = 0;
                m++;
            }
            if (!death[i]) death[i] = 1;
        }
        record[N] = m;
        printf("%d\n", m);
    }
    return 0;
}
