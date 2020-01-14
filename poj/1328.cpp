/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1003                        *
 **********************************************************************/

/*
 * bbq: 排序, 贪心
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct radars {
    double left, right;
}radar[1005];

struct islands {
    double x, y;
}island[1005];

bool cmp(radars a, radars b) {
    if (a.left < b.left) return true;
    if ((a.left == b.left) && (a.right < b.right))
        return true;
    return false;
}

int main() {
    int N, R;
    int flag;
    double temp;
    int sum;
    int i;
    int num = 0;
    radars mark;

    for (;;) {
        scanf("%d%d", &N, &R);
        num++;
        if (!N && !R)  break;

        flag = 0;
        for (i = 0; i < N; i++) {
            scanf("%lf%lf", &island[i].x, &island[i].y);
            if (island[i].y > R)   flag = 1;
        }

        if (flag) {
            printf("Case %d: -1\n", num);
            continue;
        }

        for (i = 0; i < N; i++) {
            temp = sqrt(R*R - island[i].y*island[i].y);
            radar[i].left = island[i].x - temp;
            radar[i].right = island[i].x + temp;
        }
        sort(radar, radar + N, cmp);
        sum = 1;
        mark = radar[0];
/*
        for (i = 1; i < N; i++) {
            //不重叠
            if (radar[i].left > mark.right) {
                sum++;
                mark = radar[i];
            }
            //重叠取里面的端点
            else if (radar[i].right < mark.right) {
                mark = radar[i];
            }
        }
*/

        for (i = 1; i < N; i++) {
            //排序保证了 radar[i].left>=mark.left 
            if (radar[i].left <= mark.right) {
                //不用考虑左端点   排序保证 
                if (radar[i].right <= mark.right)
                    mark = radar[i];
            }
            else {
                mark = radar[i];
                sum++;
            }
        }

        printf("Case %d: %d\n", num, sum);
    }

    return 0;
}
/***************************************version 20190103
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct node {
    double left, right;
}a[1005];

bool cmp(node x, node y) {
    if (x.left != y.left)  return x.left < y.left;
    else    return x.right <= y.right;
}

int main() {
    int N;
    int R;
    double x, y;
    int k;
    int i;
    double r;
    int num;
    double left, right;

    for (k = 1;; ++k) {
        scanf("%d %d", &N, &R);
        if (!N && !R)  break;
        int flag = 0;

        for (i = 0; i < N; i++) {
            scanf("%lf %lf", &x, &y);
            if (y > R) flag = 1;
            r = sqrt(R*R - y * y);
            a[i].left = x - r;
            a[i].right = x + r;
        }
        if (flag) {
            printf("Case %d: -1\n", k);
            continue;
        }
        sort(a, a + N, cmp);
        num = 1;
        left = a[0].left;
        right = a[0].right;
        for (i = 1; i < N; i++) {
            if (a[i].right < right)    right = a[i].right;
            else if (a[i].left > right) {
                num++;
                left = a[i].left;
                right = a[i].right;
            }
        }
        printf("Case %d: %d\n", k, num);
    }
    return 0;
}
***************************************/

/*
Radar Installation
Time Limit: 1000MS      Memory Limit: 10000K
Total Submissions: 112630       Accepted: 24842
Description

Assume the coasting is an infinite straight line. Land is in one side of coasting,
sea in the other. Each small island is a point locating in the sea side.
And any radar installation, locating on the coasting, can only cover d distance,
so an island in the sea can be covered by a radius installation, if the distance
between them is at most d.

We use Cartesian coordinate system, defining the coasting is the x-axis. The sea
side is above x-axis, and the land side below. Given the position of each island
in the sea, and given the distance of the coverage of the radar installation,
your task is to write a program to find the minimal number of radar installations
to cover all the islands. Note that the position of an island is represented by
its x-y coordinates.

Figure A Sample Input of Radar Installations


Input

The input consists of several test cases. The first line of each case contains two
integers n (1<=n<=1000) and d, where n is the number of islands in the sea and d is
the distance of coverage of the radar installation. This is followed by n lines
each containing two integers representing the coordinate of the position of each
island. Then a blank line follows to separate the cases.

The input is terminated by a line containing pair of zeros
Output

For each test case output one line consisting of the test case number followed by
the minimal number of radar installations needed. "-1" installation means no
solution for that case.
Sample Input

3 2
1 2
-3 1
2 1

1 2
0 2

0 0
Sample Output

Case 1: 2
Case 2: 1
Source

Beijing 2002
*/
