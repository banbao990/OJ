/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2663                        *
 **********************************************************************/

/*
 * bbq: 双函数, dp, 记忆化
*/

//  分类  最后两列   f1()  --  f2()  0|  0表示随意
//                        --        0|
//                        --        00

#include <stdio.h>

long long sum1[16] = { 0,1,3 };
long long sum2[16] = { 0,2,8 };

int cal1(int n);
int cal2(int n);

int main() {
    int i;
    int N;

    for (i = 1; i <= 15; i++) {
        sum1[i] = cal1(i);
        sum2[i] = cal2(i);
    }
    for (;;) {
        scanf("%d", &N);
        if (N == -1)   break;
        if (N == 0) {
            printf("1\n"); //搞不懂，题目也没说是 1 啊 
            continue;
        }
        if (N % 2) {
            printf("0\n");
            continue;
        }
        else {
            printf("%lld\n", sum1[N / 2] + sum2[N / 2]);
        }
    }
    return 0;
}

int cal1(int n) {
    if (sum1[n]) return sum1[n];
    return cal1(n - 1) + cal2(n - 1);
}

int cal2(int n) {
    if (sum2[n]) return sum2[n];
    return 2 * cal1(n - 1) + 3 * cal2(n - 1);
}

/*
Tri Tiling
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 11969        Accepted: 5994

Description

In how many ways can you tile a 3xn rectangle with 2x1 dominoes?
Here is a sample tiling of a 3x12 rectangle.

Input

Input consists of several test cases followed by a line containing -1.
Each test case is a line containing an integer 0 <= n <= 30.

Output

For each test case, output one integer number giving the number of
possible tilings.

Sample Input

2
8
12
-1

Sample Output

3
153
2131

Source
Waterloo local 2005.09.24
*/
