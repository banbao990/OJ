/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1011                        *
 **********************************************************************/

/*
 * bbq: 少林神棍, 剪枝
*/

#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <memory.h>
using namespace std;

int s;// 现在尝试的长度
int flag;// 成功标记
int n;
int a[65];
bool vis[65];

//sort函数， 降序排列 
bool compare(int i, int j) {
    return i > j;
}

//now 表示现在有多长， left 表示还剩下几根小棒， start 表示下一根将要进行操作的小棒
void dfs(int now, int left, int start) {
    if (flag) return;
    int i;
    // 成功凑成一根 s 长度
    if (now == s) {
        // 成功凑完, 结束
        if (!left) {
            flag = 1;
            return;
        }
        dfs(0, left, 0);
        if (flag) return;
    }
    
    // 接下来尝试下一根 
    if (!start) {
        while (vis[start]) start++;
        vis[start] = true;
        dfs(a[start], left - 1, start + 1);
        vis[start] = false;
        return;
    }

    for (i = start; i < n; i++) {
        if (!vis[i] && now + a[i] <= s) {
            // 不重复操作, 剪枝 
            if (!vis[i - 1] && a[i] == a[i - 1]) continue;
            vis[i] = true;
            dfs(now + a[i], left - 1, i + 1);
            if (flag) return;
            vis[i] = false;
        }
    }
    return;
}

int main() {
    int i;
    int sum;
    for (;;) {
        scanf("%d", &n);
        if (!n)  break;
        sum = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        // 降序排列
        sort(a, a + n, compare);
        flag = 0;
        // 从最大值开始
        for (s = a[0]; s < sum; s++) {
            // 可行性剪枝
            if (sum%s) continue;
            memset(vis, 0, sizeof(vis));
            dfs(0, n, 0);
            if (flag) break;
        }
        printf("%d\n", s);
    }
    return 0;
}

/*
Description
    乔治拿来一组等长的木棒，将它们随机地砍断，使得每一节木棍的长度都不超过50个长度单位。
    然后他又想把这些木棍恢复到为裁截前的状态，但忘记了初始时有多少木棒以及木棒的初始长度。
    请你设计一个程序，帮助乔治计算木棒的可能最小长度。每一节木棍的长度都用大于零的整数表示。
Input
    输入包含多组数据，每组数据包括两行。
    第一行是一个不超过64的整数，表示砍断之后共有多少节木棍。第二行是截断以后，
    所得到的各节木棍的长度。在最后一组数据之后，是一个零。
Output
    为每组数据，分别输出原始木棒的可能最小长度，每组数据占一行。
Sample Input
    9
    5 2 1 5 2 1 5 2 1
    4
    1 2 3 4
    0
Sample Output
    6
    5
Source
    Central Europe 1995
Translator
    北京大学程序设计实习, Xie Di
*/
