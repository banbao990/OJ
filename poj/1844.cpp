/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1844                        *
 **********************************************************************/

/*
 * bbq: trick, 不知直接枚举
*/

#include <stdio.h>

int main() {
    int N;
    int i;
    int sum = 0;
    scanf("%d", &N);
    for (i = 1;; i++) {
        sum += i;
        if (sum >= N && (sum - N) % 2 == 0)
            break;
    }
    printf("%d\n", i);
    return 0;
}

/*
Sum
Time Limit: 1000MS      Memory Limit: 30000K
Total Submissions: 11192        Accepted: 7318

Description

Consider the natural numbers from 1 to N. By associating to each number a 
sign (+ or -) and calculating the value of this expression we obtain a sum
S. The problem is to determine for a given sum S the minimum number N for 
which we can obtain S by associating signs for all numbers between 1 to N 

For a given S, find out the minimum value N in order to obtain S 
according to the conditions of the problem. 

Input

The only line contains in the first line a positive integer S
(0< S <= 100000) which represents the sum to be obtained.

Output

The output will contain the minimum number N for which the sum S 
can be obtained.

Sample Input

12

Sample Output

7

Hint

The sum 12 can be obtained from at least 7 terms in the following way:
12 = -1+2+3+4+5+6-7.

Source

Romania OI 2002
*/
