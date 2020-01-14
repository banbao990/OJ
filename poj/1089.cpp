/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1089                        *
 **********************************************************************/

/*
 * bbq: 区间合并
 */

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct qujian {
    int x, y;
}a[50000];

//将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergearray(qujian a[], int first, int mid, int last, qujian temp[]) {
    int i = first, j = mid + 1;
    int m = mid, n = last;
    int k = 0;
    while (i <= m && j <= n) {
        if (a[i].x <= a[j].x)
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= m)
        temp[k++] = a[i++];
    while (j <= n)
        temp[k++] = a[j++];
    for (i = 0; i < k; i++)
        a[first + i] = temp[i];
}
void mergesort(qujian a[], int first, int last, qujian temp[]) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergesort(a, first, mid, temp);    //左边有序
        mergesort(a, mid + 1, last, temp); //右边有序
        mergearray(a, first, mid, last, temp); //再将二个有序数列合并
    }
}

bool MergeSort(qujian a[], int n) {
    qujian *p = new qujian[n];
    if (p == NULL)
        return false;
    mergesort(a, 0, n - 1, p);
    delete[] p;
    return true;
}

int main() {
    int n;
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
        scanf("%d%d", &a[i].x, &a[i].y);
    MergeSort(a, n);
    int x = a[0].x;
    int y = a[0].y;
    for (i = 1; i < n; i++) {
        if (a[i].x >= x && a[i].x <= y) {
            if (a[i].y <= y)
                continue;
            else 
                y = a[i].y;
        }
        else {
            printf("%d %d\n", x, y);
            x = a[i].x;
            y = a[i].y;
        }
    }
    printf("%d %d\n", x, y);
    return 0;
}

/*
10
1 6
8 10
9 14
5 9
16 19
13 17
20 22
16 21
21 25
24 30
*/



/*
Sample Input
5
5 6
1 4
10 10
6 9
8 10

Sample Output
1 4
5 10
*/
