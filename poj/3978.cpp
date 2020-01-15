
/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=3978                        *
 **********************************************************************/

/*
 * bbq: 输入一个数n，求n以内的所有质数
 *      注意越界
*/



#include <stdio.h> 
#define N 100000
int main() {
    int zhishu[10000] = { 0 };
    int n, a, b;
    int i, j, k;
    zhishu[0] = 2;
    k = 1;
    for (i = 3; i <= N; i++) {
        for (j = 0; j < k; j++)
            if (i%zhishu[j] == 0)
                break;
        if (j == k) {
            zhishu[k] = i;
            k++;
        }
    }

    for (;;) {
        scanf("%d%d", &a, &b);
        if (a == -1 && b == -1)
            break;
        n = 0;
        for (i = 0;; i++) {
            if (zhishu[i] < a)
                continue;
            else if (zhishu[i] <= b)
                n++;
            else break;
        }
        printf("%d\n", n);
    }
//  for(i=0;i<k;i++)    printf("%d\n",zhishu[i]);
    return 0;
}
