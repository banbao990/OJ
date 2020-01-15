/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2676                        *
 **********************************************************************/

/*
 * bbq: 数独, dfs
*/

#include <stdio.h>
// 正搜会超时，用反搜
// 但是方法并没有改进 

char sudoku[9][10];
bool flag = false;

int conflict(int i, int j) {
    int k, y;
    int col, row;
    for (k = 0; k < 9; k++) {
        if (k == j)	continue;
        if (sudoku[i][k] == sudoku[i][j])
            return 1;
    }

    for (k = 0; k < 9; k++) {
        if (k == i)	continue;
        if (sudoku[k][j] == sudoku[i][j])
            return 1;
    }

    col = j / 3 * 3;
    row = i / 3 * 3;

    for (k = row; k < row + 3; k++) {
        for (y = col; y < col + 3; y++) {
            if (k == i && y == j)	continue;
            else	if (sudoku[k][y] == sudoku[i][j])	return 1;
        }
    }
    return 0;
}

void put(int i, int j) {
    int k;
    if (flag)	return;
    if (j == -1) {
        if (i == 0) {
            flag = true;
            return;
        }
        else {
            j = 8;
            i--;
        }
    }

    if (sudoku[i][j] != '0')	put(i, j - 1);
    else {
        for (k = 1; k <= 9; k++) {
            sudoku[i][j] = k + '0';
            if (conflict(i, j))	continue;
            else {
                put(i, j + 1);
            }

            if (flag)	return;
        }
        if (k == 10) {
            sudoku[i][j] = '0';
            return;
        }
    }

}

int main() {
    int N;
    int i;

    scanf("%d", &N);
    getchar();

    while (N--) {
        for (i = 0; i < 9; i++)	gets(sudoku[i]);
        flag = false;
        put(8, 8);
        for (i = 0; i < 9; i++)	puts(sudoku[i]);
    }

    return 0;
}




/*
2982:Sudoku
数独
样例输入
1
103000509
002109400
000704000
300502006
060000050
700803004
000401000
009205800
804000107
样例输出
143628579
572139468
986754231
391542786
468917352
725863914
237481695
619275843
854396127
来源
Southeastern Europe 2005
*/
