/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2591                        *
 **********************************************************************/

/*
 * bbq:
*/

#include <stdio.h>
#define min(x,y) ((x)<(y))?(x):(y)

#define MAX 10000005

long ugly[MAX]={0,1};

int main() {
    int i;
    int ugly2 = 1, ugly3 = 1;
    long N;

    for (i = 2; i < MAX; i++) {
        ugly[i] = min(ugly[ugly2] * 2 + 1, ugly[ugly3] * 3 + 1);
        //重复舍去
        if (ugly[i] == ugly[ugly2] * 2 + 1)    ugly2++;
        if (ugly[i] == ugly[ugly3] * 3 + 1)    ugly3++;
    }
    while (scanf("%ld", &N) != EOF) printf("%ld\n", ugly[N]);
    return 0;
}

/*
Set Definition
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 9915     Accepted: 4654
Description

Set S is defined as follows: 
(1) 1 is in S; 
(2) If x is in S, then 2x + 1 and 3x + 1 are also in S; 
(3) No other element belongs to S. 

Find the N-th element of set S, if we sort the elements in S by increasing order.
Input

Input will contain several test cases; each contains a single positive integer N 
(1 <= N <= 10000000), which has been described above.
Output

For each test case, output the corresponding element in S.
Sample Input

100
254
Sample Output

418
1461
Source

POJ Monthly--2005.08.28,Static
*/
