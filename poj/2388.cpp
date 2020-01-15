/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2388                        *
 **********************************************************************/

/*
 * bbq: 求中位数
*/

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N;
    int i;
    int a[10000];
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    sort(a, a + N);
    printf("%d", a[N / 2]);
    return 0;
}

/*
Who's in the Middle

Input

* Line 1:
    A single odd integer N
* Lines 2..N+1:
    Each line contains a single integer that is the milk output of one cow.

Output

* Line 1:
    A single integer that is the median milk output.

Sample Input

5
2
4
1
3
5

Sample Output

3

Source
USACO 2004 November

*/
