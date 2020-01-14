/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2389                        *
 **********************************************************************/

/*
 * bbq: 大整数乘法
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[100] = {};
    char b[100] = {};//a,b用来记录输入的两个数
    int alength, blength;//a,b大数的长度 
    int m[100] = {};
    int n[100] = {}; //用来记录输入的两个数（倒序） 
    int temp1[100][1000] = {};//temp1数组用来记录乘法中间过程 
    int i, j, k = 0;//i,j,k用于各种循环 
    int temp[1000] = {};//一个缓存数组 
    int addlength;
    int result[1000] = {};//用于输出结果 

    gets(a);
    gets(b);

    alength = strlen(a);
    blength = strlen(b);
    addlength = alength + blength;

    for (i = 0; i < alength; i++)
        m[i] = a[alength - 1 - i] - 48;
    for (i = 0; i < blength; i++)
        n[i] = b[blength - 1 - i] - 48;

    for (j = 0; j < blength; j++) {
        for (i = 0; i < alength; i++)
            temp1[j][i + k] = n[j] * m[i];
        k++;
    }

    for (i = 0; i < addlength - 1; i++) {
        for (j = 0; j < blength; j++)
            temp[i] += temp1[j][i];
    }

    for (i = 0; i < addlength - 2; i++) {
        if (temp[i] > 9) {
            temp[i + 1] += (temp[i] / 10);
            temp[i] %= 10;
        }
    }

    if (temp[addlength - 2] > 9) {
        temp[addlength - 1] += temp[addlength - 2] / 10;
        temp[addlength - 2] %= 10;
        addlength++;
    }

    for (i = 0; i < addlength - 1; i++)
        result[i] = temp[addlength - 2 - i];

    for (i = 0; i < addlength - 1; i++)
        printf("%d", result[i]);

    return 0;
}

/*
Sample Input

11111111111111
1111111111
Sample Output

12345679011110987654321
Source

USACO 2004 November
*/
