
/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=3750                        *
 **********************************************************************/

/*
 * bbq: 约瑟夫问题, 模拟
*/

#include <stdio.h>
#include <string.h> 
#include <malloc.h>

int main() {
    int N, S, W;
    int i, j, k = 0, flag = 0;
    int *a;
    char name[70][20];
    bool judge = true;

    scanf("%d", &N);
    getchar();

    a = (int*)malloc(sizeof(int)*N);
    for (i = 0; i < N; i++) {
        a[i] = 1;
        gets(name[i]);
    }

    scanf("%d,%d", &W, &S);
    while (flag < N) {
        for (j = 0; j < N; j++) {
            if (judge) {
                judge = false;
                j = W - 1;
            }
            if (a[j] == 1) {
                k++;
                if (k == S) {
                    a[j] = 0;
                    puts(name[j]);
                    k = 0;
                    flag++;
                }
            }

        }
    }
    return 0;
}

/*
小孩报数问题
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 16791        Accepted: 7530
Description

有N个小孩围成一圈，给他们从1开始依次编号，现指定从第W个开始报数，
报到第S个时，该小孩出列，然后从下一个小孩开始报数，仍是报到S个出列，
如此重复下去，直到所有的小孩都出列（总人数不足S个时将循环报数），求小孩出列的顺序。
Input

第一行输入小孩的人数N（N<=64）
接下来每行输入一个小孩的名字(人名不超过15个字符)
最后一行输入W,S (W < N)，用逗号","间隔
Output

按人名输出小孩按顺序出列的顺序，每行输出一个人名
Sample Input

5
Xiaoming
Xiaohua
Xiaowang
Zhangsan
Lisi
2,3
Sample Output

Zhangsan
Xiaohua
Xiaoming
Xiaowang
Lisi
Source
*/
