    
/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1753                        *
 **********************************************************************/
/*
 * bbq: 熄灯问题, 枚举
*/
#include <stdio.h>
#include <limits.h>
#include <memory.h>

int chess[5][6] = {};
int flip[5][6] = {};
int ans = INT_MAX;

bool guess() {
    int r, c;
    int temp = 0;
    for (r = 1; r <= 3; r++)
        for (c = 1; c <= 4; c++)
            flip[r + 1][c]
            = (chess[r][c] + flip[r][c] + flip[r][c - 1]
                + flip[r][c + 1] + flip[r - 1][c])
            & 1;
    for (c = 1; c <= 4; c++) {
        if (chess[4][c] != 
            ((flip[4][c] + flip[4][c - 1] + flip[4][c + 1] + flip[3][c]) & 1))
            return false;
    }
    for (r = 1; r <= 4; r++)
        for (c = 1; c <= 4; c++)
            temp += flip[r][c];
    if (temp < ans)
        ans = temp;
    return true;
}

void enumerate() {
    int i;

    memset(flip, 0, sizeof(flip));
    guess();
//  if(guess())
//      return;
    for (i = 0; i < 15; i++) {
        flip[1][1]++;
        int c = 1;
        while (flip[1][c] > 1) {
            flip[1][c] = 0;
            flip[1][++c]++;
        }
        guess();
    //      if(guess())
    //          return;
    }
}

int main() {
    char a;
    int c, r;

    for (r = 1; r <= 4; r++) {
        for (c = 1; c <= 4; c++) {
            scanf("%c", &a);
            if (a == 'b')
                chess[r][c] = 0;
            else chess[r][c] = 1;
        }
        getchar();
    }
    enumerate();
    for (r = 1; r <= 4; r++)
        for (c = 1; c <= 4; c++)
            chess[r][c] ^= 1;
    enumerate();
    if (ans != INT_MAX)
        printf("%d", ans);
    else printf("Impossible");
    return 0;
}

/*
Flip Game
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 53632        Accepted: 22497
Description

Flip game is played on a rectangular 4x4 field with two-sided pieces placed on each of
its 16 squares. One side of each piece is white and the other one is black and each
piece is lying either it's black or white side up. Each round you flip 3 to 5 pieces,
thus changing the color of their upper side from black to white and vice versa.
The pieces to be flipped are chosen every round according to the following rules:
Choose any one of the 16 pieces.
Flip the chosen piece and also all adjacent pieces to the left, to the right, to the
top, and to the bottom of the chosen piece (if there are any).

Consider the following position as an example:

bwbw
wwww
bbwb
bwwb
Here "b" denotes pieces lying their black side up and "w" denotes pieces lying their
white side up. If we choose to flip the 1st piece from the 3rd row
(this choice is shown at the picture), then the field will become:

bwbw
bwww
wwwb
wwwb
The goal of the game is to flip either all pieces white side up or all pieces black
side up. You are to write a program that will search for the minimum number of rounds
needed to achieve this goal.
Input

The input consists of 4 lines with 4 characters "w" or "b" each that denote game field
position.
Output

Write to the output file a single integer number - the minimum number of rounds needed
to achieve the goal of the game from the given position. If the goal is initially
achieved, then write 0. If it's impossible to achieve the goal, then write the word
"Impossible" (without quotes).
Sample Input

bwwb
bbwb
bwwb
bwww
Sample Output

4
Source

Northeastern Europe 2000
*/
