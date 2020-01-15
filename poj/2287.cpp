/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2287                        *
 **********************************************************************/

/*
 * bbq: 田忌赛马, 贪心(最大+最小)
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int N;
int grade;
int a[1005], b[1005];// a 是田忌， b 是大王 

void race(int aleft, int aright, int bleft, int bright, int time) {
    if (time == N) return;
    else {
        // a 快马比 b 快马快， ++ 
        if (a[aleft] > b[bleft]) {
            grade++;
            race(aleft + 1, aright, bleft + 1, bright, time + 1);
        }
        // a 快马比 b 快马慢， -- ， 用最慢的马输 
        else if (a[aleft] < b[bleft]) {
            grade--;
            race(aleft, aright - 1, bleft + 1, bright, time + 1);
        }
        // a 快马和 b 快马一样快， 比较慢马 
        else {
            // a 慢马比 b 慢马快， ++  
            if (a[aright] > b[bright]) {
                grade++;
                race(aleft, aright - 1, bleft, bright - 1, time + 1);
            }
            // a 慢马比 b 慢马慢(一样快)， ++ ，用慢马输对方快马 
            else {
                if (a[aright] < b[bleft])  grade--;
                race(aleft, aright - 1, bleft + 1, bright, time + 1);
            }
        }
    }
    return;
}

int main() {
    int i;

    while (1) {
        scanf("%d", &N);
        if (!N)  break;

        grade = 0;
        for (i = 0; i < N; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < N; i++)
            scanf("%d", &b[i]);

        sort(a, a + N, cmp);
        sort(b, b + N, cmp);

        if (a[N - 1] > b[0])
            printf("%d\n", N * 200);
        else if (a[0] < b[N - 1])
            printf("-%d\n", N * 200);
        else {
            race(0, N - 1, 0, N - 1, 0);
            printf("%d\n", grade * 200);
        }
    }
    return 0;
}

/*
Tian Ji -- The Horse Racing

Input

The input consists of up to 50 test cases. Each case starts with a positive
integer n ( n<=1000) on the first line, which is the number of horses on each 
side. The next n integers on the second line are the speeds of Tian's horses. 
Then the next n integers on the third line are the speeds of the king's horses. 
The input ends with a line that has a single `0' after the last test case.

Output

For each input case, output a line containing a single number, which is the 
maximum money Tian Ji will get, in silver dollars.

Sample Input

3
92 83 71
95 87 74
2
20 20
20 20
2
20 19
22 18
0

Sample Output

200
0
0

Source
Shanghai 2004
*/
