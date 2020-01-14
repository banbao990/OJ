/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1099                        *
 **********************************************************************/

/*
 * bbq:
 */

#include <stdio.h>
#include <malloc.h>

int main() {
    int count = 0, N;
    int **number;
    char **image;
    int i, j;
    int r, c;

    while (++count) {
        scanf("%d", &N);
        if (!N)  break;

        number = (int**)malloc(sizeof(int*)*N);
        //申请动态数组 
        for (i = 0; i < N; i++)
            number[i] = (int*)malloc(sizeof(int)*N);

        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                scanf("%d", &number[i][j]);

        r = 4 * N - 1;
        c = 4 * N + 3;
        image = (char**)malloc(sizeof(char*)*r);
        //申请动态数组 
        for (i = 0; i < r; i++)
            image[i] = (char*)malloc(sizeof(char)*c);
        //画框框
        for (i = 0; i < r; i++) {
            image[i][0] = '*';
            image[i][c - 1] = '*';
        }
        for (i = 1; i < c - 1; i++) {
            image[0][i] = '*';
            image[r - 1][i] = '*';
        }
        //画  'H' , 'O' , ' '
        for (i = 1; i < r; i += 4) {
            for (j = 1; j < c - 1; j++) {
                if (j % 4 == 1) 
                    image[i][j] = 'H';
                else if (j % 4 == 2) 
                    image[i][j] = ' ';
                else if (j % 4 == 3) 
                    image[i][j] = 'O';
                else image[i][j] = ' ';
            }
        }
        for (i = 2; i < r - 1; i += 2) 
            for (j = 1; j < c - 1; j++) 
                image[i][j] = ' ';
        for (i = 3; i < r - 1; i += 4) {
            for (j = 1; j < c - 1; j++) {
                if (j % 4 == 3) 
                    image[i][j] = 'H';
                else
                    image[i][j] = ' ';
            }
        }
        //解决 1 / -1
        for (i = 0; i < N; i++) {
            //image[4*i+1][4*j+3] 
            for (j = 0; j < N; j++) {
                if (number[i][j] == 1)
                    image[4 * i + 1][4 * j + 2] = image[4 * i + 1][4 * j + 4] = '-';
                if (number[i][j] == -1) 
                    image[4 * i][4 * j + 3] = image[4 * i + 2][4 * j + 3] = '|';
            }
        }
        //解决 0 
        for (i = 0; i < N; i++) {
            //image[4*i+1][4*j+3] 
            for (j = 0; j < N; j++) {
                if (!number[i][j]) {
                    int flag = 0;
                    if (image[4 * i][4 * j + 3] == ' ') {
                        if (i != 0 && image[4 * i - 2][4 * j + 3] == ' ') {
                            image[4 * i][4 * j + 3] = '|';
                            flag++;
                        }
                    }
                    if (image[4 * i + 1][4 * j + 2] == ' ') {
                        if (j == 0 || image[4 * i + 1][4 * j] == ' ') {
                            image[4 * i + 1][4 * j + 2] = '-';
                            flag++;
                            if (flag == 2) continue;
                        }
                    }
                    if (image[4 * i + 1][4 * j + 4] == ' ') {
                        /* if begin*/
                        if ((j == N - 1 || image[4 * i + 1][4 * j + 6] == ' ') 
                            && (image[4 * i + 1][4 * j + 2] != '-')) {
                        /* if end */
                            image[4 * i + 1][4 * j + 4] = '-';
                            flag++;
                            if (flag == 2) continue;
                        }
                    }
                    if (image[4 * i + 2][4 * j + 3] == ' ') {
                        if (i != N - 1 || image[4 * i + 4][4 * j + 3] == ' ') {
                            image[4 * i + 2][4 * j + 3] = '|';
                            flag++;
                            if (flag == 2) continue;
                        }
                    }
                }
            }
        }

        printf("Case %d:\n\n", count);
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++)
                printf("%c", image[i][j]);
            printf("\n");
        }
        printf("\n");

        //释放动态数组
        for (i = 0; i < N; i++)
            free(number[i]);
        for (i = 0; i < r; i++)
            free(image[i]);
        free(number);
        free(image);
    }

    return 0;
}

/*
5
0 0 1 0 0
0 1 -1 1 0
1 -1 1 -1 1
0 1 -1 1 0
0 0 1 0 0
*/

/*
Sample Input

2
0 1
1 0
4
0 1 0 0
1 -1 0 1
0 0 1 0
0 1 0 0
0
Sample Output

Case 1:

***********
*H-O H-O-H*
*  |      *
*  H   H  *
*      |  *
*H-O-H O-H*
***********

Case 2:

*******************
*H-O H-O-H O-H O-H*
*  |       |   |  *
*  H   H   H   H  *
*      |          *
*H-O-H O H-O H-O-H*
*      |   |      *
*  H   H   H   H  *
*  |           |  *
*H-O H-O H-O-H O-H*
*      |          *
*  H   H   H   H  *
*  |       |   |  *
*H-O H-O-H O-H O-H*
*******************
*/
