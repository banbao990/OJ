/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2083                        *
 **********************************************************************/

/*
 * bbq: 递归画分形图
*/


#include <stdio.h>
#include <math.h> 

char map[740][740];

void fill(int n, int x, int y) {
    if (n == 1) {
        map[x][y] = 1;
        return;
    }
    int temp = pow(3.0, n - 2);
    fill(n - 1, x, y);
    fill(n - 1, x + 2 * temp, y);
    fill(n - 1, x + temp, y + temp);
    fill(n - 1, x, y + 2 * temp);
    fill(n - 1, x + 2 * temp, y + 2 * temp);
}

int main() {
    int i, j;
    int n;
    int temp;

    fill(7, 1, 1);
    while (scanf("%d", &n), n != -1) {
        temp = pow(3.0, n - 1);
        for (i = 1; i <= temp; i++) {
            for (j = 1; j <= temp; j++) {
                if (map[i][j])   printf("X");
                else    printf(" ");
            }
            printf("\n");
        }
        puts("-");
    }
    return 0;
}

/*
#include <stdio.h>
#include <math.h>
int main() {
    int i, j, n, ii, jj, k;
    while (scanf("%d", &n) && n-- != -1) {
        for (i = 0; i < pow(3, n); i++, printf("\n"))
            for (j = 0; j < pow(3, n); j++) {
            // for begin //
                for (ii = i, jj = j, k = 0;
                     k < n && (ii % 3 + jj % 3) % 2 == 0;
                     ii /= 3, jj /= 3, k++);
            // for end //
                printf("%c", 32 + 56 * (k == n));
            }
        printf("-\n");
    }
}
*/


/*
Fractal
Time Limit: 1000MS      Memory Limit: 30000K
Total Submissions: 11957        Accepted: 5297
Description

A fractal is an object or quantity that displays self-similarity,
in a somewhat technical sense, on all scales.
The object need not exhibit exactly the same structure at all scales,
but the same "type" of structures must appear on all scales.
A box fractal is defined as below :
A box fractal of degree 1 is simply
X
A box fractal of degree 2 is
X X
X
X X
If using B(n - 1) to represent the box fractal of degree n - 1,
then a box fractal of degree n is defined recursively as following
B(n - 1)        B(n - 1)

        B(n - 1)

B(n - 1)        B(n - 1)

Your task is to draw a box fractal of degree n.
Input

The input consists of several test cases.
Each line of the input contains a positive integer n
which is no greater than 7.
The last line of input is a negative integer -1
indicating the end of input.
Output

For each test case, output the box fractal using the 'X' notation.
Please notice that 'X' is an uppercase letter.
Print a line with only a single dash after each test case.
Sample Input

1
2
3
4
-1
Sample Output

X
-
X X
 X
X X
-
X X   X X
 X     X
X X   X X
   X X
    X
   X X
X X   X X
 X     X
X X   X X
-
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
   X X               X X
    X                 X
   X X               X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
         X X   X X
          X     X
         X X   X X
            X X
             X
            X X
         X X   X X
          X     X
         X X   X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
   X X               X X
    X                 X
   X X               X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
-
Source

Shanghai 2004 Preliminary
*/
