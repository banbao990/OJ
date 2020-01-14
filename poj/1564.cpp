/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1564                        *
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int save[100][15] = {};//用 save 数组记录已经输出的数组 
int c[15];//存储输进来的数 
int now[15];//存储正在操作中的这组数 
int num, sum;//sum--和, num--输入几个数 
int total;//记录 save 中的组数(输出组数) 

// a 表示当前的和 , i 表示在输入排序之后的第几个， j 表示已经在 now 中存到第几个 
void select(int i, int a, int j) {
    if (i == num)  return;
    int k, y, x;
    for (k = i; k < num; k++) {
        int flag = a + c[k];
        if (flag < sum) {
            a = flag;
            now[j] = c[k];
            select(k + 1, a, j + 1);
            a -= c[k];
            now[j] = 0;
            continue;
        }

        if (flag > sum)
            continue;

        if (flag == sum) {
            now[j] = c[k];
            //判断是否和已经输出的相同 
            for (y = 0; y < total; y++) {
                for (x = 0; x <= j; x++)
                    if (save[y][x] != now[x])
                        break;
                if (x == j + 1)
                    break;
            }

            if (x == j + 1)
                continue;
            else {
                //输出 
                for (y = 0; y < j; y++)
                    printf("%d+", now[y]);
                printf("%d\n", now[y]);
                //存到save数组里 
                for (x = 0; x <= j; x++)
                    save[total][x] = now[x];
                total++;
            }
        }
    }
    now[j] = 0;
}
int main() {
    int i;

    while (1) {
        scanf("%d%d", &sum, &num);
        if (!sum && !num)  break;
        for (i = 0; i < num; i++)  scanf("%d", &c[i]);
        total = 0;
        printf("Sums of %d:\n", sum);
        select(0, 0, 0);
        if (!total)  printf("NONE\n");
    }
}


/*
Sum It Up
Time Limit: 1000MS      Memory Limit: 10000K
Total Submissions: 8721     Accepted: 4470
Description

Given a specified total t and a list of n integers, find all distinct sums using numbers
from the list that add up to t. For example, if t = 4, n = 6, and the list is [4, 3, 2,
2, 1, 1], then there are four different sums that equal 4: 4, 3+1, 2+2, and 2+1+1.
(A number can be used within a sum as many times as it appears in the list,
and a single number counts as a sum.) Your job is to solve this problem in general.

Input

The input will contain one or more test cases, one per line. Each test case contains t,
the total, followed by n, the number of integers in the list, followed by n integers
x1 , . . . , xn . If n = 0 it signals the end of the input; otherwise, t will be a
positive integer less than 1000, n will be an integer between 1 and 12 (inclusive),
and x 1 , . . . , x n will be positive integers less than 100. All numbers will be
separated by exactly one space. The numbers in each list appear in nonincreasing order,
and there may be repetitions.
Output

For each test case, first output a line containing `Sums of', the total, and a colon.
Then output each sum, one per line; if there are no sums, output the line `NONE'.
The numbers within each sum must appear in nonincreasing order.
A number may be repeated in the sum as many times as it was repeated in the original
list. The sums themselves must be sorted in decreasing order based on the numbers
appearing in the sum. In other words, the sums must be sorted by their first number;
sums with the same first number must be sorted by their second number; sums with the
same first two numbers must be sorted by their third number; and so on.
Within each test case, all sums must be distinct; the same sum cannot appear twice.

Sample Input

4 6 4 3 2 2 1 1
5 3 2 1 1
400 12 50 50 50 50 50 50 25 25 25 25 25 25
0 0
Sample Output

Sums of 4:
4
3+1
2+2
2+1+1
Sums of 5:
NONE
Sums of 400:
50+50+50+50+50+50+25+25+25+25
50+50+50+50+50+25+25+25+25+25+25
Source

Mid-Central USA 1997
*/
