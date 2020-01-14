/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1004                        *
 **********************************************************************/
 
/*
 * bbq: 输出12个浮点数的平均值
 */

#include <stdio.h>

int main(){
    float month[12];                //表示每个月的 closing blance 
    int i;
    float sum = 0, average;
    for (i = 0; i < 12; i++){
        scanf("%f", &month[i]);
        sum += month[i];
    }
    average = sum / 12;
    printf("$%.2f", average);
    return 0;
}
