/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2545                        *
 **********************************************************************/

/*
 * bbq:
*/

#include <stdio.h>
#include <malloc.h>
#define min(x,y) ((x)<(y))?(x):(y)

int main() {
    long long* ugly;
    int i;
    long long u2, u3, u5, N;

    while (scanf("%lld%lld%lld%lld", &u2, &u3, &u5, &N) != EOF) {
        ugly = (long long*)malloc(sizeof(long long)*(1 + N));
        ugly[0] = 1;
        int ugly2 = 0, ugly3 = 0, ugly5 = 0;

        for (i = 1; i <= N; i++) {
            ugly[i] = min(min(ugly[ugly2] * u2, ugly[ugly3] * u3), ugly[ugly5] * u5);
            //重复舍去       
            if (ugly[i] == ugly[ugly2] * u2) ugly2++;
            if (ugly[i] == ugly[ugly3] * u3) ugly3++;
            if (ugly[i] == ugly[ugly5] * u5) ugly5++;
        }
        printf("%lld\n", ugly[N]);
        free(ugly);
    }
    return 0;
}

/*
Hamming Problem
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 6756     Accepted: 3113
Description

For each three prime numbers p1, p2 and p3, let's define Hamming sequence Hi(p1, p2, p3), 
i=1, ... as containing in increasing order all the natural numbers whose only prime divisors
are p1, p2 or p3.

For example, H(2, 3, 5) = 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25, 27, ...

So H5(2, 3, 5)=6.

Input

In the single line of input file there are space-separated integers p1 p2 p3 i.

Output

The output file must contain the single integer - Hi(p1, p2, p3). All numbers in input and 
output are less than 10^18.

Sample Input

7 13 19 100

Sample Output

26590291

Source
Northeastern Europe 2000, Far-Eastern Subregion
*/
