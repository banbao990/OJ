/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1008                        *
 **********************************************************************/

/*
 * bbq: Haab历转化成Tzolkin历
 * 威佐夫博弈 
 * ak =[k（1+√5）/2]，bk= ak + k （k=0，1，2，...n 方括号表示取整函数)
 *  0   1   3   4   6   8   9   11  12  14  ......
 *  0   2   5   7   10  13  15  18  20  23  ......
*/
#include <stdio.h>      
#include <math.h>   

int main() {
    int x, y;
    int change;
    int cha;
    int real_x; //表示自己输的情况下对应的 x 

    while (scanf("%d %d", &x, &y) != EOF) {
        if (x > y) {
            change = x;
            x = y;
            y = change;
        }

        cha = y - x;
        real_x = ceil(cha*(sqrt(5.0) + 1) / 2) - 1;
        if (x == real_x)   printf("0\n");
        else printf("1\n");
    }
}


/*
取石子游戏
Time Limit: 1000MS      Memory Limit: 10000K
Total Submissions: 45849        Accepted: 15673
Description

有两堆石子，数量任意，可以不同。游戏开始由两个人轮流取石子。游戏规定，每次有两种不同的取法，一是可以在任意的一堆中取走任意多的石子；二是可以在两堆中同时取走相同数量的石子。最后把石子全部取完者为胜者。现在给出初始的两堆石子的数目，如果轮到你先取，假设双方都采取最好的策略，问最后你是胜者还是败者。
Input

输入包含若干行，表示若干种石子的初始情况，其中每一行包含两个非负整数a和b，表示两堆石子的数目，a和b都不大于1,000,000,000。
Output

输出对应也有若干行，每行包含一个数字1或0，如果最后你是胜者，则为1，反之，则为0。
Sample Input

2 1
8 4
4 7
Sample Output

0
1
0
Source

NOI
*/
