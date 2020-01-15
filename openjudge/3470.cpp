/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://bailian.openjudge.cn/practice/3470             *
 **********************************************************************/

/*
 * bbq: 二分
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)


int a[54];
int special;

bool bisearch(int now) {
    int flag = 0;
    for (int i = 0; i < 54; i++) {
        if (a[i] < flag)
            return false;
        if (a[i] < now)
            flag += (now - a[i]);
        if (flag > special)
            return false;
    }
    return true;
}

int main() {
    int max = INT_MIN;
    int i;
    int low, high;

    while (scanf("%d", &special) != EOF) {
        for (i = 0; i < 54; i++) {
            scanf("%d", &a[i]);
            if (a[i] > max) max = a[i];
        }
        // +1 保证最右端肯定不行 
        max += (special / 54) + 1;
        sort(a, a + 54);
        low = 0;
        high = max;
        // 每次都保证最左端可以，最右端不行
        while (low < high - 1) {
            int mid = (low + high) >> 1;
            if (bisearch(mid))
                low = mid;
            else
                high = mid;
        }
        printf("%d\n", low);
    }
    return 0;
}

/*
3470:整理扑克牌
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
一副扑克牌有4种花色的牌各13张，再加上大小王2张，总共有54张牌。
一般你买的一副新扑克牌里除了这54张牌外还会有一两张特殊的牌，
如果你不小心弄丢了54张牌中的某一张，就可以用特殊牌来代替，
但是如果你弄丢两张的话就没有办法了，因为特殊牌上的图案是一样的。


现在你得到了很多扑克牌，准确来说，54种牌你各有a1、a2、……、a53、a54张，
同时你还有b张特殊牌，现在你需要从这些牌中整理出若干副牌供大家使用。
整理出的一副牌可以由54种普通牌各一张组成，
也可以由53种普通牌各一张再加一张特殊牌组成。


请你设计出一种方案，整理出尽可能多的牌。

输入
输入包含多组数据，每组数据包含55个整数（不超过1000000），
第一个数是b即特殊牌的数目，接下来分别是a1、a2、……、a53、a54。
输出
输出最多能整理出的牌的副数。
样例输入
11
5 4 10 10 10 10 10 10 10 10
10 10 10 10 10 10 10 10 10 10
10 10 10 10 10 10 10 10 10 10
10 10 10 10 10 10 10 10 10 10
10 10 10 10 10 10 10 10 10 10
10 10 10 10

54
54 54 54 54 54 54 54 54 54 54
54 54 54 54 54 54 54 54 54 54
54 54 54 54 54 54 54 54 54 54
54 54 54 54 54 54 54 54 54 54
54 54 54 54 54 54 54 54 54 54
54 54 54 54
样例输出
9
55
*/
