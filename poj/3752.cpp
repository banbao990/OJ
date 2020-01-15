
/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=3752                        *
 **********************************************************************/

/*
 * bbq: 蛇形填充数组
*/

#include <stdio.h>
#include <malloc.h> 

int main() {
    char **matrix;
    int ROW, COL;
    int i, j;

    scanf("%d %d", &ROW, &COL);
    matrix = (char**)malloc(sizeof(char*)*ROW);
    for (i = 0; i < ROW; i++)
        matrix[i] = (char*)malloc(sizeof(char)*COL);

    int minr = 0, minc = 0, maxr = ROW - 1, maxc = COL - 1;
    char flag = 'A';
    for (;;) {
        for (i = minc; i <= maxc; i++) {
            matrix[minr][i] = flag;
            if (flag < 'Z')
                flag++;
            else
                flag = 'A';
        }
        if (minr == maxr)
            break;
        minr++;
        for (i = minr; i <= maxr; i++) {
            matrix[i][maxc] = flag;
            if (flag < 'Z')
                flag++;
            else
                flag = 'A';
        }
        if (maxc == minc)
            break;
        maxc--;

        for (i = maxc; i >= minc; i--) {
            matrix[maxr][i] = flag;
            if (flag < 'Z')    flag++;
            else    flag = 'A';
        }
        if (maxr == minr)
            break;
        maxr--;

        for (i = maxr; i >= minr; i--) {
            matrix[i][minc] = flag;
            if (flag < 'Z')
                flag++;
            else
                flag = 'A';
        }
        if (minc == maxc)
            break;
        minc++;
    }
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++)
            printf("   %c", matrix[i][j]);
        printf("\n");
    }

    for (i = 0; i < ROW; i++)
        free(matrix[i]);
    free(matrix);
    return 0;
}
/*
字母旋转游戏
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 8876     Accepted: 3308
Description

给定两个整数M，N，生成一个M*N的矩阵，矩阵中元素取值为A至Z的26个字母中的一个，A在左上角，
其余各数按顺时针方向旋转前进，依次递增放置，当超过26时又从A开始填充。
例如，当M=5，N=8时，矩阵中的内容如下：

   A   B   C   D   E   F   G   H

   V   W   X   Y   Z   A   B   I

   U   J   K   L   M   N   C   J

   T   I   H   G   F   E   D   K

   S   R   Q   P   O   N   M   L

Input

M为行数，N为列数，其中M，N都为大于0的整数。

Output

分行输出相应的结果

Sample Input

4 9

Sample Output

   A   B   C   D   E   F   G   H   I
   V   W   X   Y   Z   A   B   C   J
   U   J   I   H   G   F   E   D   K
   T   S   R   Q   P   O   N   M   L
*/
