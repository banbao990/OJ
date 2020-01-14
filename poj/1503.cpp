/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1503                        *
 **********************************************************************/

/*
 * bbq: 大整数加法
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int add(char a[110], char b[110]) {
    //m表示较大的一个数，n较小的一个数 (后来并没有用到大小) 
    char n[110] = {};
    char m[110] = {};
    char temp[110] = {};
    int alength, blength, maxlength;
    int i;

    alength = strlen(a);
    blength = strlen(b);

    maxlength = (alength > blength) ? alength : blength;

    for (i = 0; i < alength; i++)
        m[i] = a[alength - 1 - i] - 48;
    for (i = 0; i < blength; i++)
        n[i] = b[blength - 1 - i] - 48;

    for (i = 0; i < maxlength; i++)
        temp[i] = m[i] + n[i];

    for (i = 0; i < maxlength; i++) {
        if (temp[i] > 9) {
            temp[i + 1] += (temp[i] / 10);
            temp[i] %= 10;
        }
    }
    if (temp[maxlength] != 0)
        maxlength++;

    for (i = 0; i < maxlength; i++)
        a[i] = temp[maxlength - 1 - i] + 48;
    return 0;
}


int main() {
    char a[110] = {};
    char addition[110] = {};
    int alength;
    int i;

    gets(addition);
    gets(a);

    while (1) {
        alength = strlen(a);
        //排除数据   00001  (类似有前导 0 的数据)
        for (i = 0; i < alength; i++)
            if (a[i] != '0')
                break;
        if (i == alength)
            break;
        add(addition, a);
        gets(a);
    }
    printf("%s", addition);
    return 0;
}
