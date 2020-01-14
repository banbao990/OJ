/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1338                        *
 **********************************************************************/

/*
 * bbq: 数列问题
*/

#include <stdio.h>
#define min(x,y) ((x)<(y))?(x):(y)

int main() {
    long long ugly[1510] = { 0,1,2,3,4,5 };
    int i;
    int ugly2 = 1, ugly3 = 1, ugly5 = 1;
    int N;

    for (i = 2; i < 1508; i++) {
        ugly[i] = min(min(ugly[ugly2] * 2, ugly[ugly3] * 3), ugly[ugly5] * 5);
        //重复舍去
        if (ugly[i] == ugly[ugly2] * 2)  ugly2++;
        if (ugly[i] == ugly[ugly3] * 3)  ugly3++;
        if (ugly[i] == ugly[ugly5] * 5)  ugly5++;
    }

    while (scanf("%d", &N), N)
        printf("%lld\n", ugly[N]);
    return 0;
}
/*
Ugly Numbers
Time Limit: 1000MS      Memory Limit: 10000K
Total Submissions: 27009        Accepted: 11679

Description

Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, ...
shows the first 10 ugly numbers. By convention, 1 is included.
Given the integer n,write a program to find and print the n'th ugly number.

Input

Each line of the input contains a postisive integer n (n <= 1500).
Input is terminated by a line with n=0.

Output

For each line, output the n’th ugly number .:Don’t deal with the line with n=0.
Sample Input

1
2
9
0
Sample Output

1
2
10
Source

New Zealand 1990 Division I,UVA 136
*/
