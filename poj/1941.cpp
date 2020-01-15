/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1941                        *
 **********************************************************************/

/*
 * bbq: 递归画分形图
*/

#include <stdio.h>
#include <memory.h>

char a[1025][2049];

void fractal(int n, int r, int c) {
    if (n == 1) {
        a[r][c] = '/';
        a[r][c + 1] = '_';
        a[r][c + 2] = '_';
        a[r][c + 3] = 92;
        a[r - 1][c + 1] = '/';
        a[r - 1][c + 2] = 92;
        return;
    }
    fractal(n - 1, r, c);
    fractal(n - 1, r - (1 << (n - 1)), c + (1 << (n - 1)));
    fractal(n - 1, r, c + (1 << n));
    return;
}

int main() {
    int r, c;
    int n;
    memset(a, 0, sizeof(a));
    fractal(10, 1 << 10, 1);
    for (;;) {
        scanf("%d", &n);
        if (!n)	break;
        int mark = (1 << n) + 2;
        for (r = (1024 - (1 << n) + 1); r <= 1024; r++) {
            int temp = 4 << (n - 1);
            for (c = 1; c <= temp; c++) {
                if (c == mark) {
                    mark++;
                    printf("\n");
                    break;
                }
                if (a[r][c])
                    printf("%c", a[r][c]);
                else
                    printf(" ");
            }
        }
        printf("\n\n");
    }

    return 0;
}

/* 每行都有多余空格
#include <stdio.h>
#include <memory.h>

char a[1025][2049];

void fractal(int n, int r, int c) {
    if (n == 1) {
        a[r][c] = '/';
        a[r][c + 1] = '_';
        a[r][c + 2] = '_';
        a[r][c + 3] = 92;
        a[r - 1][c + 1] = '/';
        a[r - 1][c + 2] = 92;
        return;
    }
    fractal(n - 1, r, c);
    fractal(n - 1, r - (1 << (n - 1)), c + (1 << (n - 1)));
    fractal(n - 1, r, c + (1 << n));
    return;
}

int main() {
    int r, c;
    int n;
    memset(a, 0, sizeof(a));
    fractal(10, 1 << 10, 1);
    for (;;) {
        scanf("%d", &n);
        if (!n)	break;
//      int mark = (1 << n) + 2;
        for (r = (1024 - (1 << n) + 1); r <= 1024; r++) {
            int temp = 4 << (n - 1);
            for (c = 1; c <= temp; c++) {
                //if (c == mark) {
                //    mark++;
                //    printf("\n");
                //    break;
                //}
                if (a[r][c])
                    printf("%c", a[r][c]);
                else
                    printf(" ");
            }
            printf("\n");
        }
        printf("\n");
//		printf("\n\n");
    }

    return 0;
}
*/

/*
The Sierpinski Fractal
Time Limit: 1000MS		Memory Limit: 30000K
Total Submissions: 4908		Accepted: 2027

Description

Consider a regular triangular area, divide it into four equal triangles of 
half height and remove the one in the middle. Apply the same operation 
recursively to each of the three remaining triangles. If we repeated this 
procedure infinite times, we'd obtain something with an area of zero.
The fractal that evolves this way is called the Sierpinski Triangle.
Although its topological dimension is 2, its Hausdorff-Besicovitch dimension 
is log(3)/log(2)~1.58, a fractional value (that's why it is called a fractal).
By the way, the Hausdorff-Besicovitch dimension of the Norwegian coast is 
approximately 1.52, its topological dimension being 1.

For this problem, you are to outline the Sierpinski Triangle up to a certain 
recursion depth, using just ASCII characters. Since the drawing resolution is 
thus fixed, you'll need to grow the picture appropriately. Draw the smallest 
triangle (that is not divided any further) with two slashes, to backslashes 
and two underscores like this:

 /\
/__\

To see how to draw larger triangles, take a look at the sample output.

Input

The input contains several testcases. Each is specified by an integer n.
Input is terminated by n=0. Otherwise 1<=n<=10 indicates the recursion depth.

Output

For each test case draw an outline of the Sierpinski Triangle with a side's 
total length of 2n characters. Align your output to the left, that is, 
print the bottom leftmost slash into the first column. The output must not 
contain any trailing blanks. Print an empty line after each test case.

Sample Input

3
2
1
0
Sample Output

       /\
      /__\
     /\  /\
    /__\/__\
   /\      /\
  /__\    /__\
 /\  /\  /\  /\
/__\/__\/__\/__\

   /\
  /__\
 /\  /\
/__\/__\

 /\
/__\
Hint


The Sierpinski-Triangle up to recursion depth 7
Source
*/
