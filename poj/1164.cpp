/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1164                        *
 **********************************************************************/

/*
 * bbq: 模拟 + dfs
*/

#include <stdio.h> 
#include <malloc.h>
#include <limits.h>

struct room {
    int x;
    bool left, right, up, down;
    //1表示西墙，2表示北墙，4表示东墙，8表示南墙
}b[100][100];

char a[300][300];
int sum;

void judge(int i, int j) {
    if (b[i][j].x >= 8) {
        b[i][j].down = true;
        b[i][j].x -= 8;
    }
    else
        b[i][j].down = false;
    if (b[i][j].x >= 4) {
        b[i][j].right = true;
        b[i][j].x -= 4;
    }
    else
        b[i][j].right = false;
    if (b[i][j].x >= 2) {
        b[i][j].up = true;
        b[i][j].x -= 2;
    }
    else
        b[i][j].up = false;
    if (b[i][j].x >= 1) {
        b[i][j].left = true;
        b[i][j].x -= 1;
    }
    else    b[i][j].left = false;
}

int cross(int i, int j){
    int flag = 0;
    if (a[i - 1][j] == '#') flag++;
    if (a[i][j - 1] == '#') flag++;
    if (a[i][j + 1] == '#') flag++;
    if (a[i + 1][j] == '#') flag++;
    return flag;
}

void cal(int i, int j){
    if (a[i][j] == ' ') sum++;
    a[i][j] = '#';
    if (a[i - 1][j] != '#') cal(i - 1, j);
    if (a[i][j - 1] != '#') cal(i, j - 1);
    if (a[i][j + 1] != '#') cal(i, j + 1);
    if (a[i + 1][j] != '#') cal(i + 1, j);
}

int main(){
    int R, C;
    int r, c;
//  char **a;
//  room **b;
    int i, j;
    int total = 0;
    int max = 0;

    scanf("%d %d", &R, &C);
    r = 2 * R + 1;
    c = 4 * C + 1;
/*
    a=(char**)malloc(sizeof(char*)*r);
    for (i = 0; i < r; i++)
    a[i] = (char*)malloc(sizeof(char)*c);
    b = (room**)malloc(sizeof(room*)*R);
    for (i = 0; i < r; i++)
        b[i] = (room*)malloc(sizeof(room)*C);
*/
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            scanf("%d", &b[i][j].x);
            judge(i, j);
        }
    }

    for (i = 0; i < c; i++) {
        a[0][i] = '#';
        a[r - 1][i] = '#';
    }
    for (i = 1; i < r - 1; i++) {
        a[i][0] = '#';
        a[i][c - 1] = '#';
    }

    for (i = 1; i < r - 1; i++)
        for (j = 1; j < c - 1; j++)
            a[i][j] = ' ';

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (b[i][j].left)
                a[2 * i + 1][4 * j] = '#';
            if (b[i][j].right)
                a[2 * i + 1][4 * j + 4] = '#';
            if (b[i][j].up)
                a[2 * i][4 * j + 1] 
                = a[2 * i][4 * j + 2] 
                = a[2 * i][4 * j + 3] 
                = '#';
            if (b[i][j].down)
                a[2 * i + 2][4 * j + 1] 
                = a[2 * i + 2][4 * j + 2] 
                = a[2 * i + 2][4 * j + 3] 
                = '#';
        }
    }

    for (i = 2; i < r; i += 2)
        for (j = 4; j < c; j += 4)
            if (cross(i, j))
                a[i][j] = '#';

    for (i = 1; i < r; i += 2)
        for (j = 4; j < c; j += 4)
            if (a[i][j] == ' ')
                a[i][j] = '|';

    for (i = 2; i < r - 1; i += 2)
        for (j = 1; j < c - 1; j++)
            if (a[i][j] == ' ')
                a[i][j] = '-';
/*
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
*/
    for (i = 1; i < r - 1; i++) {
        for (j = 0; j < c; j++) {
            if (a[i][j] != '#') {
                total++;
                sum = 0;
                cal(i, j);
                max = (sum > max) ? sum : max;
            }
        }
    }
/*
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
*/
    return 0;
    printf("%d\n%d", total, max / 3);

//  for(i=0;i<r;i++) free(a[i]);
//  free(a);
    return 0;
}


/*
4
7
11 6 11 6 3 10 6
7 9 6 5 5 15 5
1 10 11 0 12 7 5
13 11 10 8 10 12 13
*/

/*
4
7
11 6 11 6 3 2 6
7 9 6 1 0 0 4
1 10 11 0 0 6 5
13 11 10 8 8 12 13
*/

/*
5
7
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13
15 15 15 15 15 15 15

*/

/*
2815:城堡问题
查看 提交 统计 提示 提问
总时间限制: 1000ms 内存限制: 65536kB
描述

     1   2   3   4   5   6   7
   #############################
 1 #   |   #   |   #   |   |   #
   #####---#####---#---#####---#
 2 #   #   |   #   #   #   #   #
   #---#####---#####---#####---#
 3 #   |   |   #   #   #   #   #
   #---#########---#####---#---#
 4 #   #   |   |   |   |   #   #
   #############################
           (图 1)

   #  = Wall
   |  = No wall
   -  = No wall

图1是一个城堡的地形图。
请你编写一个程序，计算城堡一共有多少房间，最大的房间有多大。
城堡被分割成m?n(m≤50，n≤50)个方块，每个方块可以有0~4面墙。

输入
程序从标准输入设备读入数据。第一行是两个整数，分别是南北向、东西向的方块数。
在接下来的输入行里，每个方块用一个数字(0≤p≤50)描述。
用一个数字表示方块周围的墙，1表示西墙，2表示北墙，4表示东墙，8表示南墙。
每个方块用代表其周围墙的数字之和表示。
城堡的内墙被计算两次，方块(1,1)的南墙同时也是方块(2,1)的北墙。
输入的数据保证城堡至少有两个房间。

输出
城堡的房间数、城堡中最大房间所包括的方块数。结果显示在标准输出设备上。

样例输入
4
7
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13

样例输出
5
9

来源
1164
*/
