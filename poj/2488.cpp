
/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2488                        *
 **********************************************************************/

/*
 * bbq: 马走日, dfs
*/

#include <stdio.h>
#include <memory.h>
#include <limits.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

#define max 40

int end;
bool flag = false;
int p, q;
int a[max][max];

struct road {
    int x;
    int y;
}roads[max];

struct direction {
    int x;
    int y;
}directions[8] = { -1,-2,1,-2,-2,-1,2,-1,-2,1,2,1,-1,2,1,2 };

void dfs(int x, int y, int step) {
    if (flag) return;
    else {
        if (step == end) {
            flag = true;
            return;
        }

        else {
            for (int i = 0; i < 8; i++) {
                int xx, yy;
                xx = x + directions[i].x;
                yy = y + directions[i].y;
                if (xx >= 0 && xx < p && yy >= 0 && yy < q && a[xx][yy] == 0) {
                    a[xx][yy] = 1;
                    roads[step].x = xx;
                    roads[step].y = yy;
                    dfs(xx, yy, step + 1);
                    if (flag)   return;
                    a[xx][yy] = 0;
                }
            }
        }
    }
}

int main() {
    int N;
    int i, j, k;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d%d", &p, &q);
        for (j = 0; j < p; j++) for (k = 0; k < q; k++) a[j][k] = 0;
        int pmin = p / 2 + p % 2, qmin = q / 2 + q % 2;
        end = p * q;
        flag = false;
        for (j = 0; j < pmin; j++) {
            for (k = 0; k < qmin; k++) {
                a[j][k] = 1;
                roads[0].x = j;
                roads[0].y = k;
                dfs(j, k, 1);
                if (flag) break;
                a[j][k] = 0;
            }
            if (flag) break;
        }

        printf("Scenario #%d:\n", i);
        if (flag) {
            for (j = 0; j < end; j++)
                printf("%c%d", roads[j].y + 'A', roads[j].x + 1);
            printf("\n");
        }
        else
            printf("impossible\n");
        printf("\n");
    }

    return 0;
}



/*
A Knight's Journey
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 52687        Accepted: 17879
Description

Background
The knight is getting bored of seeing the same black and white squares again and 
again and has decided to make a journey
around the world. Whenever a knight moves, it is two squares in one direction and
one square perpendicular to this. The world of a knight is the chessboard he is 
living on. Our knight lives on a chessboard that has a smaller area than a 
regular 8 * 8 board, but it is still rectangular. Can you help this adventurous 
knight to make travel plans?

Problem

Find a path such that the knight visits every square once. The knight can start 
and end on any square of the board.

Input

The input begins with a positive integer n in the first line. The following lines
contain n test cases. Each test case consists of a single line with two positive 
integers p and q, such that 1 <= p * q <= 26. This represents a p * q chessboard,
where p describes how many different square numbers 1, . . . , p exist, q 
describes how many different square letters exist. These are the first q letters 
of the Latin alphabet: A, . . .

Output

The output for every scenario begins with a line containing "Scenario #i:", where
i is the number of the scenario starting at 1. Then print a single line 
containing the lexicographically first path that visits all squares of the 
chessboard with knight moves followed by an empty line. The path should be given 
on a single line by concatenating the names of the visited squares. Each square 
name consists of a capital letter followed by a number.

If no such path exist, you should output impossible on a single line.

Sample Input

3
1 1
2 3
4 3

Sample Output

Scenario #1:
A1

Scenario #2:
impossible

Scenario #3:
A1B3C1A2B4C2A3B1C3A4B2C4

Source
TUD Programming Contest 2005, Darmstadt, Germany

*/
