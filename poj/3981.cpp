/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=3981                        *
 **********************************************************************/

/*
 * bbq:
*/

#include <stdio.h>
#include <string.h>

int main() {
    char a[1000];
    int i;
    while (gets(a)) {
        int alength = strlen(a);
        alength -= 2;
        for (i = 0; i < alength; i++) {
            if (a[i] == 'y'&&a[i + 1] == 'o'&&a[i + 2] == 'u') {
                printf("we");
                if (i != alength - 1)
                    i += 2;
            }
            else printf("%c", a[i]);
        }
        if (a[i - 1] == 'y'&&a[i] == 'o'&&a[i + 1] == 'u') {
            printf("\n");
            continue;
        }
        else
            printf("%c%c\n", a[i], a[i + 1]);
    }
    return 0;
}

/*
字符串替换
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 12172        Accepted: 5687
Description

编写一个C程序实现将字符串中的所有"you"替换成"we"
Input

输入包含多行数据

每行数据是一个字符串，长度不超过1000
数据以EOF结束
Output

对于输入的每一行，输出替换后的字符串
Sample Input

you are what you do
Sample Output

we are what we do
Source
*/
