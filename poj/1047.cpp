/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1047                        *
 **********************************************************************/

/*
 * bbq: 输入一个数字m(大整数), 位数 k
 *      判断 m * i(1<=i<=k)是否为循环数
 *      拼接
 * eg:  
 *   142857  * 1  =   142857
 *   142857  * 2  =   285714
 *   142857  * 3  =   428571
 *   142857  * 4  =   571428
 *   142857  * 5  =   714285
 *   142857  * 6  =   857142
 * 
 * tip: 使用STL-string就很简单
*/


#include <string.h>
#include <stdio.h>

// a 中找 b
bool search(char *a, int *b, int length) {
    int i, j;
    for (i = 0; i <= length; i++) {
        for (j = 0; j < length; j++) {
            if (a[j + i] != b[j]) break;
        }
        if (j == length) return true;
    }
    return false;
}

int main() {
    char a[1000], c[1000];
    int d[1000];
    int length;
    int i, j, k;
    int flag;
    memset(a, 0, sizeof(a));

    while (gets(a)) {
        length = strlen(a);
        for (i = 0; i < length; i++) { 
            a[i] -= '0';
            c[i + length] = c[i] = a[i]; 
        }
        flag = 0;
        for (i = 0; i < length; i++) {
            for (j = 1; j <= length; j++) {
                memset(d, 0, sizeof(d));
                for (k = length - 1; k > 0; k--) {
                    d[k] += j * a[k];
                    if (d[k] > 9) {
                        d[k - 1] += (d[k] / 10);
                        d[k] %= 10;
                    }
                }
                d[0] += j * a[0];
                if (d[0] > 9) {
                    flag = 1;
                    break;
                }
                if (!search(c, d, length)) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }

        for (i = 0; i < length; i++)
            printf("%c", '0' + a[i]);
        if (flag) printf(" is not cyclic\n");
        else printf(" is cyclic\n");
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
    }
    return 0;
}
