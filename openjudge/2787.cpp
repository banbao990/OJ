/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://bailian.openjudge.cn/practice/2787             *
 **********************************************************************/

/*
 * bbq: 递归求24点
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define eps 1e-6

double num[4];
int flag;

void dfs(int step) {
    int i;
    int j;

    if (step == 1) {
        if (fabs(num[0] - 24.0) < eps) {
            flag = 1;
            return;
        }
    }
    for (i = 0; i < step; i++) {
        for (j = i + 1; j < step; j++) {
            double a = num[i], b = num[j];
            num[j] = num[step - 1];
            num[i] = a + b;
            dfs(step - 1);
            num[i] = a - b;
            dfs(step - 1);
            num[i] = a * b;
            dfs(step - 1);
            num[i] = b - a;
            dfs(step - 1);
            if (fabs(b - 0.0) > eps) {
                num[i] = a / b;
                dfs(step - 1);
            }
            if (fabs(a - 0.0) > eps) {
                num[i] = b / a;
                dfs(step - 1);
            }
            num[i] = a;
            num[j] = b;
        }
    }
}

int main() {
    while (1) {
        scanf("%lf %lf %lf %lf", &num[0], &num[1], &num[2], &num[3]);
        if (num[0] + num[1] + num[2] + num[3] == 0)	break;

        flag = 0;
        dfs(4);
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

/*
2787:算24
查看 提交 统计 提示 提问
总时间限制: 3000ms 内存限制: 65536kB
描述
给出4个小于10个正整数，你可以使用加减乘除4种运算以及括号把这4个数连接起来得
到一个表达式。现在的问题是，是否存在一种方式使得得到的表达式的结果等于24。

这里加减乘除以及括号的运算结果和运算的优先级跟我们平常的定义一致
（这里的除法定义是实数除法）。

比如，对于5，5，5，1，我们知道5 * (5 – 1 / 5) = 24，因此可以得到24。
又比如，对于1，1，4，2，我们怎么都不能得到24。
输入
输入数据包括多行，每行给出一组测试数据，包括4个小于10个正整数。
最后一组测试数据中包括4个0，表示输入的结束，这组数据不用处理。
输出
对于每一组测试数据，输出一行，如果可以得到24，输出“YES”；否则，输出“NO”。
样例输入
5 5 5 1
1 1 4 2
0 0 0 0
样例输出
YES
NO
*/
