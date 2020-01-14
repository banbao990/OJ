/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1230                        *
 **********************************************************************/

/*
 * bbq: 从左往右遍历，遇到多的墙，就拆除向右延伸最长的墙
 *      贪心
*/

#include <stdio.h>
#include <memory.h>

int main() {
    int n;
    int row;
    int k;
    int a[105][105];
    int i, j;
    int lx, ly, rx, ry;
    int max;
    int time;
    int door;
    int maxw;
    int shu;
    int maxx;
    int r;
    int num;

    scanf("%d", &n);
    while (n--) {
        memset(a, 0, sizeof(a));
        max = 0;
        row = 0;
        num = 0;
        scanf("%d%d", &r, &k);
        //构建图形 
        for (i = 0; i < r; i++) {
            num++;
            // y 表示行 
            scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
            if (lx > rx) {
                int temp = lx;
                lx = rx;
                rx = temp;
            }
            if (rx > max) max = rx;
            if (ly > row) row = ly;
            for (j = lx; j <= rx; j++) a[ly][j] = num;
        }
        door = 0;
        for (i = 0; i <= max; i++) {
            time = 0;
            for (j = 0; j <= row; j++) {
                if (a[j][i])
                    time++;
            }
            //  printf("%d\n",time); 
            if (time <= k) continue;
            //一次不一定只删一堵墙        (time-k)可能大于一 
            while (time > k) {
                time--;
                maxw = 0;//墙最向右连着几块 
                maxx = 0;//maxx表示最向右的一行 
                door++;
                for (j = 0; j <= row; j++) {
                    if (a[j][i]) {
                        shu = 0;
                        for (int ii = i;; ii++) {
                            if (a[j][ii] != a[j][i] || ii > max)   break;
                            else    shu++;
                        }
                        if (shu > maxw) {
                            maxw = shu;
                            maxx = j;
                        }
                    }
                }
                for (j = i; j < i + maxw; j++)
                    a[maxx][j] = 0;
            }
        }
        printf("%d\n", door);
    }
}
