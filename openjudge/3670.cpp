/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://bailian.openjudge.cn/practice/3670             *
 **********************************************************************/

/*
 * bbq:
*/

#include <stdio.h>

int main() {
    int a[5][5];
    int i, j, k;
    int max, max_Subscript;
    bool flag = false;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < 5; i++) {
        max = a[i][0];
        max_Subscript = 0;
        for (j = 1; j < 5; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
                max_Subscript = j;
            }
        }
        for (k = 0; k < 5; k++) {
            if (k == i)
                continue;
            if (a[k][max_Subscript] < max)
                break;
        }
        if (k == 5) {
            printf("%d %d %d\n", i + 1, max_Subscript + 1, max);
            flag = true;
        }
    }
    if (!flag)
        printf("not found\n");
    return 0;
}
/*
 3670:计算鞍点
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个5*5的矩阵，每行只有一个最大值，每列只有一个最小值，寻找这个矩阵的鞍点。
鞍点指的是矩阵中的一个元素，它是所在行的最大值，并且是所在列的最小值。
例如：在下面的例子中（第4行第1列的元素就是鞍点，值为8 ）。
11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8 6 4 7 2
15 10 11 20 25

输入
输入包含一个5行5列的矩阵
输出
如果存在鞍点，输出鞍点所在的行、列及其值，如果不存在，输出"not found"
样例输入
11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8  6 4 7 2
15 10 11 20 25
样例输出
4 1 8
*/
