/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2845                        *
 **********************************************************************/

/*
 * bbq: 二进制加法, 套用大整数加法即可
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    char a[100] = {};
    char b[100] = {};
    char n[100] = {};
    char m[100] = {};//m表示较大的一个数，n较小的一个数 (后来并没有用到大小) 
    char temp[100] = {};
    char addition[100] = {};
    int alength, blength, maxlength;
    int i;
    int N;

    scanf("%d", &N);
    getchar();

    for (int z = 1; z <= N; z++) {
        memset(temp, 0, 100 * sizeof(char));
        memset(m, 0, 100 * sizeof(char));
        memset(n, 0, 100 * sizeof(char));

        for (i = 0;; i++) {
            scanf("%c", &a[i]);
            //去前导 0 
            if (!i&&a[i] == '0')
                i--;
            if (a[i] == ' ') {
                if (!i) {
                    i++;
                    a[0] = '0';
                }
                a[i] = 0;
                break;
            }
        }

        for (i = 0;; i++) {
            scanf("%c", &b[i]);
            if (!i&&b[i] == '0')
                i--;
            if (b[i] == '\n') {
                if (!i) {
                    i++;
                    b[0] = '0';
                }
                b[i] = 0;
                break;
            }
        };

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
            if (temp[i] > 1) {
                temp[i + 1] += (temp[i] / 2);
                temp[i] %= 2;
            }
        }
        if (temp[maxlength] != 0)
            maxlength++;

        for (i = 0; i < maxlength; i++)
            addition[i] = temp[maxlength - 1 - i] + 48;

        printf("%d ", z);
        for (i = 0; i < maxlength; i++)
            printf("%c", addition[i]);
        printf("\n");
    }


    return 0;
}
/*

                       11  1 <-- Carry bits --> 1   11
  1001101             1001001                    1000111
+ 0010010           + 0011001                  + 1010110
 --------           ---------                  ---------
  1011111             1100010                   10011101

Sample Input

3
1001101 10010
1001001 11001
1000111 1010110
Sample Output

1 1011111
2 1100010
3 10011101
Source

Greater New York 2005
*/
