/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1017                        *
 **********************************************************************/

/*
 * bbq: 模拟, 先装大的再装小的
*/

#include <stdio.h>

int main() {
    int p1, p2, p3, p4, p5, p6;
    int sum;
    int blank1, blank2;
    int special[4] = { 0,5,3,1 };

    while (1) {
        scanf("%d %d %d %d %d %d", &p1, &p2, &p3, &p4, &p5, &p6);
        if (!(p1 + p2 + p3 + p4 + p5 + p6)) break;
        sum = p6 + p5 + p4 + (p3 + 3) / 4;
        blank2 = 5 * p4 + special[p3 % 4];
        if (p2 > blank2)   sum += (p2 - blank2 + 8) / 9;
        blank1 = 36 * sum - 36 * p6 - 25 * p5 - 16 * p4 - 9 * p3 - 4 * p2;
        if (p1 > blank1)   sum += (p1 - blank1 + 35) / 36;
        printf("%d\n", sum);
    }
    return 0;
}
/****************************************20190103 version
#include <stdio.h>
int main(){
    int a[7];
    int i;
    int flag;
    int num;
    int blank1, blank2;
    int b[4] = { 0,5,3,1 };
    int c[4] = { 0,7,6,5 };

    for (;;) {
        flag = 0;
        for (i = 1; i <= 6; i++) {
            scanf("%d", &a[i]);
            if (!a[i]) flag++;
        }
        if (flag == 6) break;
        //要求 a[3] != 0
        if (a[3]) num = a[6] + a[5] + a[4] + (a[3] - 1) / 4 + 1;
        else num = a[6] + a[5] + a[4];

        blank1 = 11 * a[5] + c[a[3] % 4];
        blank2 = a[4] * 5 + b[a[3] % 4];

        if (a[2] <= blank2)    blank1 += ((blank2 - a[2]) * 4);
        else {
            num += ((a[2] - blank2 - 1) / 9 + 1);
            int temp = (a[2] - blank2) % 9;
            if (temp)    blank1 += ((9 - temp) * 4);
        }

        if (a[1] > blank1) num += ((a[1] - blank1 - 1) / 36 + 1);
        printf("%d\n", num);
    }
    return 0;
}
*************************************************************/
