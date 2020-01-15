/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=3984                        *
 **********************************************************************/

/*
 * bbq: dfs/bfs
*/

#include <stdio.h>          //dfs
#include <limits.h>

int maze[5][5];
int pass[5][5] = { 0 };
int minlength = INT_MAX;

struct direction {
    int x, y;
}directions[4] = { 1,0,0,1,0,-1,-1,0 };

struct node {
    int x, y;
}path[25], way[25];

void dfs(int a, int b, int length) {
    int i;
    int xx, yy;

    if (a == 4 && b == 4) {
        if (length < minlength) {
            minlength = length;
            for (i = 0; i < length; i++) {
                way[i].x = path[i].x;
                way[i].y = path[i].y;
            }
        }
        else return;
    }
    else {
        for (i = 0; i < 4; i++) {
            xx = a + directions[i].x;
            yy = b + directions[i].y;
            if (!maze[xx][yy] && xx < 5 && xx >= 0 
                && yy >= 0 && yy < 5 && pass[xx][yy] == false) {
                pass[xx][yy] = true;
                path[length].x = xx;
                path[length].y = yy;
                dfs(xx, yy, length + 1);
                pass[xx][yy] = false;
            }
        }
    }
    return;
}


int main()
{
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            scanf("%d", &maze[i][j]);

    pass[0][0] = true;
    path[0].x = 0;
    path[0].y = 0;
    dfs(0, 0, 1);

    for (i = 0; i < minlength; i++)
        printf("(%d, %d)\n", way[i].x, way[i].y);
    return 0;
}



/*
迷宫问题
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 36496        Accepted: 20602
Description

定义一个二维数组：

int maze[5][5] = {

    0, 1, 0, 0, 0,

    0, 1, 0, 1, 0,

    0, 0, 0, 0, 0,

    0, 1, 1, 1, 0,

    0, 0, 0, 1, 0,

};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，
要求编程序找出从左上角到右下角的最短路线。
Input

一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
Output

左上角到右下角的最短路径，格式如样例所示。
Sample Input

0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
Sample Output

(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)
Source
*/
