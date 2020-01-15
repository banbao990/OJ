/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://bailian.openjudge.cn/practice/4123             *
 **********************************************************************/

/*
 * bbq: dfs + 回溯
*/

#include <stdio.h>
#include <memory.h> 

struct horse {
    int x, y;
};

horse route[8] = { 1,2,1,-2,-1,2,-1,-2,2,1,2,-1,-2,1,-2,-1 };
int sum = 0;
int count;
int n, m;

void total(int x, int y, int num, char a[10][10]) {
    int i;

    if (num == count)
        sum++;
    else {
        for (i = 0; i < 8; i++) {
            int xx = x + route[i].x;
            int yy = y + route[i].y;
            if (xx >= 0 && xx < n&&yy >= 0 && yy < m&&a[xx][yy] == 0) {
                a[xx][yy] = 1;
                num++;
                total(xx, yy, num, a);
                a[xx][yy] = 0;
                num--;
            }
        }
    }
}

int main() {
    int N;
    int x, y;
    char a[10][10] = {};

    scanf("%d", &N);
    while (N--) {
        //  0<=x<=n-1,  0<=y<=m-1,  m<10,   n<10
        scanf("%d %d %d %d", &n, &m, &x, &y);
        count = m * n;
        a[x][y] = 1;
        total(x, y, 1, a);
        printf("%d\n", sum);
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                a[i][j] = 0;
        sum = 0;
    }
}

/*
4123:马走日
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 1024kB
描述
马在中国象棋以日字形规则移动。

请编写一段程序，给定n*m大小的棋盘，以及马的初始位置(x，y)，
要求不能重复经过棋盘上的同一个点，计算马可以有多少途径遍历棋盘上的所有点。

输入
第一行为整数T(T < 10)，表示测试数据组数。
每一组测试数据包含一行，为四个整数，分别为棋盘的大小以及初始位置坐标n,m,x,y。
(0<=x<=n-1,0<=y<=m-1, m < 10, n < 10)
输出
每组测试数据包含一行，为一个整数，表示马能遍历棋盘的途径总数，0为无法遍历一次。
样例输入
1
5 4 0 0
样例输出
32
*/
