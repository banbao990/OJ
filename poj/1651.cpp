/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1651                        *
 **********************************************************************/

/*
 * bbq: 递归选卡
*/

#include <stdio.h> 
#include <limits.h>

int N;
int a[110];
int judge[110][110] = {};

int dfs(int start, int end) {
    if (start + 1 == end)
        return 0;
    if (judge[start][end])
        return judge[start][end];
    int temp, i;
    judge[start][end] = a[start] * a[start + 1] * a[end] + dfs(start + 1, end);
    for (i = start + 2; i < end; i++) {
        //考虑最后一个抽的 
        temp = dfs(start, i) + a[start] * a[i] * a[end] + dfs(i, end);
        if (temp < judge[start][end])
            judge[start][end] = temp;
    }
    return judge[start][end];
}

int main() {
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    printf("%d", dfs(0, N - 1));
    return 0;
}

/*
Multiplication Puzzle
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 14124        Accepted: 8667

Description

The multiplication puzzle is played with a row of cards,
each containing a single positive integer. 
During the move player takes one card out of the row 
and scores the number of points equal to the product 
of the number on the card taken and the numbers on the cards
on the left and on the right of it. 
It is not allowed to take out the first and the last card in the row.
After the final move, only two cards are left in the row.

The goal is to take cards in such order as to minimize 
the total number of scored points.

For example, if cards in the row contain numbers 
10 1 50 20 5, player might take a card with 1,
then 20 and 50, scoring
 10*1*50 + 50*20*5 + 10*50*5 = 500+5000+2500 = 8000

If he would take the cards in the opposite order, 
i.e. 50, then 20, then 1, the score would be
1*50*20 + 1*20*5 + 10*1*5 = 1000+100+50 = 1150.

Input

The first line of the input contains the number of cards N (3 <= N <= 100). 
The second line contains N integers in the range from 1 to 100, 
separated by spaces.

Output

Output must contain a single integer - the minimal score.

Sample Input

6
10 1 50 50 20 5

Sample Output

3650

Source
Northeastern Europe 2001, Far-Eastern Subregion

*/
