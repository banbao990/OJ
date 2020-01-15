/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1953                        *
 **********************************************************************/

/*
 * bbq: dp, 双函数
*/

#include <stdio.h>

long long a0[50] = {}, a1[50] = {};

long long cal0(int n);
long long cal1(int n);

int main() {
    int N;
    int i;
    int n;

    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &n);
        printf("Scenario #%d:\n%lld\n\n", i, cal0(n) + cal1(n));
    }
    return 0;
}

long long cal0(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    if (a0[n])
        return a0[n];
    else {
        a0[n - 1] = cal0(n - 1);
        a1[n - 1] = cal1(n - 1);
    }
    return a0[n - 1] + a1[n - 1];
}

long long cal1(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;

    if (a1[n])
        return a1[n];
    else {
        a0[n - 1] = cal0(n - 1);
    }
    return a0[n - 1];
}



/*
World Cup Noise
Time Limit: 1000MS      Memory Limit: 30000K
Total Submissions: 19004        Accepted: 9145
Description
Problem
Given a positive integer n, determine the number of different chanting
patterns of this length, i.e., determine the number of n-bit sequences
that contain no adjacent 1's. For example, for n = 3 the answer is 5
(sequences 000, 001, 010, 100, 101 are acceptable
while 011, 110, 111 are not).

Input

The first line contains the number of scenarios.
For each scenario, you are given a single positive integer
less than 45 on a line by itself.

Output

The output for every scenario begins with a line containing "Scenario #i:",
where i is the number of the scenario starting at 1. Then print a single line
containing the number of n-bit sequences which have no adjacent 1's.
Terminate the output for the scenario with a blank line.

Sample Input

2
3
1

Sample Output

Scenario #1:
5

Scenario #2:
2
Source

TUD Programming Contest 2002, Darmstadt, Germany
*/
