/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=3094                        *
 **********************************************************************/


/*
 * bbq:  
*/
#include <stdio.h>
#include <string.h>

int main() {
    char a[260];
    int i;
    int length, sum;
    while (1) {
        gets(a);
        if (a[0] == '#') break;
        sum = 0;
        length = strlen(a);
        for (i = 0; i < length; i++) {
            if (a[i] == ' ') continue;
            sum += (a[i] - 'A' + 1)*(i + 1);
        }
        printf("%d\n", sum);
    }
    return 0;
}

/*


ACM: 
    1*1  + 2*3 + 3*13 = 46

MID CENTRAL:
    1*13 + 2*9 + 3*4 + 4*0 + 5*3 + 6*5 + 7*14 + 8*20 + 9*18 + 10*1 + 11*12 = 650

Sample Input

ACM
MID CENTRAL
REGIONAL PROGRAMMING CONTEST
ACN
A C M
ABC
BBC

#
Sample Output

46
650
4690
49
75
14
15

Source

Mid-Central USA 2006
*/
