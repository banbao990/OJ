/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1005                       *
 **********************************************************************/

/*
 * bbq: 输出 ceil(pi * R * R / 2 / 50), 
 *      其中 R * R = x * x + y * y 
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14

int main() {
    int number;
    float x, y, area;
    int year;
    int i;

    scanf("%d", &number);

    for (i = 1; i <= number; i++) {
        scanf("%f %f", &x, &y);
        area = PI * (pow(x, 2) + pow(y, 2)) / 2;
        year = ceil(area / 50);/* ceil 函数向上取整 */
        printf("Property %d: This property will begin eroding in year %d.\n", i, year);
    }

    printf("END OF OUTPUT.\n");

    return 0;
}

