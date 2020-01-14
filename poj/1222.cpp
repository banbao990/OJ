/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1222                        *
 **********************************************************************/

/*
 * bbq: 熄灯问题, 枚举
*/


#include <stdio.h>
#include <memory.h>

int puzzle[6][8] = {}, press[6][8] = {};
bool flag;

bool guess() {
    int c, r;
//  memset(press,0,sizeof(press));
    for (r = 1; r <= 4; r++)
        for (c = 1; c <= 6; c++)
            press[r + 1][c] = (puzzle[r][c] + press[r][c] + press[r - 1][c] + press[r][c - 1] + press[r][c + 1]) & 1;
    for (c = 1; c <= 6; c++)
        if (((press[5][c - 1] + press[5][c] + press[5][c + 1] + press[4][c]) & 1) != puzzle[5][c])
            return false;
    return true;
}

void enumerate(int a) {
    if (a == 7) {
        if (guess())
            flag = true;
        return;
    }
    press[1][a] = 0;
    enumerate(a + 1);
    if (flag) return;
    press[1][a] = 1;
    enumerate(a + 1);
    return;
}

int main() {
    int cases;
    int i, c, r;
    scanf("%d", &cases);
    for (i = 1; i <= cases; i++) {
        flag = false;
//      memset(press, 0, sizeof(press));
//      memset(puzzle, 0, sizeof(puzzle));
        for (r = 1; r <= 5; r++)
            for (c = 1; c <= 6; c++)
                scanf("%d", &puzzle[r][c]);
        enumerate(1);
        printf("PUZZLE #%d\n", i);
        for (r = 1; r <= 5; r++) {
            for (c = 1; c <= 5; c++)
                printf("%d ", press[r][c]);
            printf("%d\n", press[r][6]);
        }
    }
    return 0;
}
/*
Sample Input

2
0 1 1 0 1 0
1 0 0 1 1 1
0 0 1 0 0 1
1 0 0 1 0 1
0 1 1 1 0 0

0 0 1 0 1 0
1 0 1 0 1 1
0 0 1 0 1 1
1 0 1 1 0 0
0 1 0 1 0 0
Sample Output

PUZZLE #1
1 0 1 0 0 1
1 1 0 1 0 1
0 0 1 0 1 1
1 0 0 1 0 0
0 1 0 0 0 0
PUZZLE #2
1 0 0 1 1 1
1 1 0 0 0 0
0 0 0 1 0 0
1 1 0 1 0 1
1 0 1 1 0 1
Source

Greater New York 2002
*/
