/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1013                        *
 **********************************************************************/

/*
 * bbq: 称硬币  枚举法 
*/


#include <stdio.h>
#include <string.h>

char left[3][10] = {}, right[3][10] = {}, result[3][10] = {};     //全局变量  

int judge(char letter, int flag) {
    int leftweight, rightweight;
    int leftlength, rightlength;
    int i, j;

    for (i = 0; i < 3; i++) {
        leftweight = 0;
        rightweight = 0;

        leftlength = strlen(left[i]);
        rightlength = strlen(right[i]);
        for (j = 0; j < leftlength; j++) 
            if (left[i][j] == letter)  
                leftweight += flag;
        for (j = 0; j < rightlength; j++) 
            if (right[i][j] == letter)
                rightweight += flag;
        if (((leftweight < rightweight) && (result[i][0] == 'd'))
            || ((leftweight == rightweight) && (result[i][0] == 'e'))
            || ((leftweight > rightweight) && (result[i][0] == 'u')))
            continue;
        else return 0;
    }

    if (i == 3) return 1;
}

int main()
{
    int num;//表示有几组数据
    int i, j;
    char letter[15] = "ABCDEFGHIJKL";

    scanf("%d", &num);
    getchar();

    while (num--) {
        for (i = 0; i < 3; i++) {
            for (j = 0;; j++) {
                scanf("%c", &left[i][j]);
                if (left[i][j] == ' ') {
                    left[i][j] = 0;
                    break;
                }
            }

            for (j = 0;; j++) {
                scanf("%c", &right[i][j]);
                if (right[i][j] == ' ')
                {
                    right[i][j] = 0;
                    break;
                }
            }
            gets(result[i]);
        }

        for (i = 0; i < 12; i++)   if (judge(letter[i], 1)) {
            printf("%c is the counterfeit coin and it is heavy.\n", letter[i]);
            break;
        }
        if (i == 12) {
            for (i = 0; i < 12; i++)   if (judge(letter[i], -1)) {
                printf("%c is the counterfeit coin and it is light.\n", letter[i]);
                break;
            }
        }
    }

    return 0;
}

/*
1
ABCD EFGH even
ABCI EFJK up
ABIJ EFGH even
*/
