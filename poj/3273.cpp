/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=3273                        *
 **********************************************************************/

/*
 * bbq: 二分
*/

#include <stdio.h>

long long ans;
int day[100005];
int N;
int total;

void bi(long long a, long long b) {
    if (a > b) return;
    else if (a == b) {
        if (a < ans) ans = a;
        return;
    }
    long long mid = (a + b) >> 1;
    long long sum = 0;
    int num = 1;
    int i;
    for (i = 0; i < N; i++) {
        if (sum + day[i] <= mid) sum += day[i];
        else {
            sum = day[i];
            num++;
        }
    }
    if (num < total) bi(a, mid - 1);
    else if (num == total) {
        ans = mid;
        bi(a, mid - 1);
    }
    else bi(mid + 1, b);
    return;
}

int main() {
    int i;
    long long sum = 0;//表示所有数之和 
    long long max = 0;//表示所有数组里的最大值 
    scanf("%d%d", &N, &total);
    for (i = 0; i < N; i++) {
        scanf("%d", &day[i]);
        sum += day[i];
        if (day[i] > max) max = day[i];
    }
    ans = sum;
    bi(max, sum);
    printf("%lld\n", ans);
    return 0;
}

/*
Monthly Expense
Time Limit: 2000MS      Memory Limit: 65536K
Total Submissions: 36286        Accepted: 13492
Description

Farmer John is an astounding accounting wizard and has realized he might run out of money
to run the farm. He has already calculated and recorded the exact amount of money
(1 ≤ moneyi ≤ 10,000) that he will need to spend each day over the next N (1 ≤ N ≤ 100,000) days.

FJ wants to create a budget for a sequential set of exactly M (1 ≤ M ≤ N) fiscal periods
called "fajomonths". Each of these fajomonths contains a set of 1 or more consecutive days.
Every day is contained in exactly one fajomonth.

FJ's goal is to arrange the fajomonths so as to minimize the expenses of the fajomonth with
the highest spending and thus determine his monthly spending limit.

Input

Line 1: Two space-separated integers: N and M
Lines 2..N+1: Line i+1 contains the number of dollars Farmer John spends on the ith day
Output

Line 1: The smallest possible monthly limit Farmer John can afford to live with.
Sample Input

7 5
100
400
300
100
500
101
400
Sample Output

500
Hint

If Farmer John schedules the months so that the first two days are a month, the third and fourth are a month, and the last three are their own months, he spends at most $500 in any month. Any other method of scheduling gives a larger minimum monthly limit.
Source

USACO 2007 March Silver
*/
