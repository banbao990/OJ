/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1054                        *
 **********************************************************************/

/*
 * bbq: 排序枚举
*/

#include <stdio.h>
#include <malloc.h>
#include <algorithm>
using namespace std;

#define MAX 5010

int r, c;

struct node {
    int x, y;
};

bool field[MAX][MAX] = {};

bool cmp(node a, node b) {
    if (a.x != b.x)    return a.x < b.x;
    return a.y <= b.y;
}

bool judge(int x, int y) {
    if ((x > 0 && x <= r) && (y > 0 && y <= c))
        return true;
    return false;
}

int main() {
    int N;
    int i, j;
    node *p;
    int ans = 0;
    int dx, dy;
    bool mark;
    scanf("%d %d", &r, &c);
    scanf("%d", &N);
    p = (node*)malloc(sizeof(node)*N);
    //录入青蛙踩过的点
    for (i = 0; i < N; i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
        field[p[i].x][p[i].y] = true;
    }
    sort(p, p + N, cmp);
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            mark = true;
            dx = p[j].x - p[i].x;
            dy = p[j].y - p[i].y;
            //剪枝，第一步能不能跳进来 
            if (judge(p[i].x - dx, p[i].y - dy))
                continue;
            //剪枝，看答案能不能比ans大
            if (!judge(p[i].x + ans * dx, p[i].y + ans * dy))
                continue;
            int num = 1;
            while (judge(p[j].x + num * dx, p[j].y + num * dy)) {
                if (field[p[j].x + num * dx][p[j].y + num * dy])
                    num++;
                else {
                    mark = false;
                    break;
                }
            }
            if (mark && (++num > ans))   ans = num;
        }
    }
    if (ans < 3)
        printf("0");
    else
        printf("%d", ans);
    free(p);
    return 0;
}
