
/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://bailian.openjudge.cn/practice/2748             *
 **********************************************************************/

/*
 * bbq: 递归求全排列
*/

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <malloc.h>

int length;

void print(char a[10], char b[10], int count) {
    int i, j;

/*
    //顺序不对
    if(count==length) {
        for(i=0;i<length;i++)
            printf("%c",a[b[i]-1]);
        printf("\n");
    }
*/

    if (count == length) {
        for (i = 1; i <= length; i++) {
            for (j = 0; j < length; j++) {
                if (b[j] == i)
                    printf("%c", a[j]);
            }
        }
        printf("\n");
    }
    else {
        for (i = 0; i < length; i++) {
            if (b[i])
                continue;
            count++;
            b[i] = count;
            print(a, b, count);
            b[i] = 0;
            count--;
        }
    }
}


int main() {
    char a[10];
    char b[10];
    int count;

    gets(a);
    length = strlen(a);
    count = 0;
    memset(b, 0, length);

    print(a, b, count);

    return 0;
}




/*
2748:全排列
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。
 我们假设对于小写字母有'a' < 'b' < ... < 'y' < 'z'，
 而且给定的字符串中的字母已经按照从小到大的顺序排列。

输入
输入只有一行，是一个由 //不同的小写字母// 组成的字符串，已知字符串的长度在1到6之间。
输出
输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义：

已知S = s1s2...sk , T = t1t2...tk，则S < T 等价于，存在p (1 <= p <= k)，使得
s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp成立。
样例输入
abc
样例输出
abc
acb
bac
bca
cab
cba
*/
