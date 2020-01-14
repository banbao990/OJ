/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1250                        *
 **********************************************************************/
 
#include <stdio.h>

int main() {
    int bednumber;
    char bed[25] = {}, wait[100] = {};
    int bedpeople, waitpeople, tanpeople, leave;
    // 注意此处 waitpeople不是指等待的人，
    // waitpeople 大于等于实际上等待的人(because of "no waitpeople--")
    char people;
    int i;
    int flag;

    while (1) {
        scanf("%d", &bednumber);
        if (!bednumber)  break;
        getchar();//去' '(空格)

        bedpeople = 0;
        waitpeople = 0;
        tanpeople = 0;
        leave = 0;

        while (1) {
            scanf("%c", &people);
            flag = 0;//flag=0    输入一个人 
            if (people == '\n')    break;

            if (bedpeople <= bednumber) {
                for (i = 0; i < bednumber; i++) {
                    if (bed[i] == people) {
                        bed[i] = 0;
                        tanpeople++;
                        flag = 3;//flag=3   享受完离开 
                        break;
                    }
                }

                if (flag != 3) {
                    for (i = 0; i < bednumber; i++) {
                        if (bed[i] == 0) {
                            bed[i] = people;
                            flag = 2;//flag=2    进入 bed 
                            break;
                        }
                    }

                    if (flag != 2) {
                        for (i = 0; i <= waitpeople; i++) {
                            if (wait[i] == people) {
                                wait[i] = 0;
                                //waitpeople--;
                                //不能减，因为不能确定他是否为最后一个                                
                                flag = 4;//flag=4    直接离开
                                leave++;
                                break;
                            }
                        }

                        if (flag != 4) {
                            for (i = 0; i <= waitpeople; i++) {
                                if (wait[i] == 0) {
                                    wait[i] = people;
                                    waitpeople++;
                                    flag = 1;//flag=1    进入 wait
                                    break;
                                }
                            }
                        }
                    }

                    if (flag == 2) {
                        for (i = 0; i <= waitpeople; i++) {
                            if (wait[i] == people) {
                                wait[i] = 0;
                                // waitpeople--;
                                //不能减，因为不能确定他是否为最后一个 
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (leave == 0)
            printf("All customers tanned successfully.\n");
        if (leave != 0)
            printf("%d customer(s) walked away.\n", leave);
    }

    return 0;
}


/*
Tanning Salon
Time Limit: 1000MS      Memory Limit: 10000K
Total Submissions: 8780     Accepted: 4693

Description

Tan Your Hide, Inc., owns several coin-operated tanning salons.
Research has shown that if a customer arrives and there are no beds available,
the customer will turn around and leave, thus costing the company a sale.
Your task is to write a program that tells the company how many customers left
without tanning.

Input

The input consists of data for one or more salons, followed by a line containing
the number 0 that signals the end of the input.
Data for each salon is a single line containing a positive integer, representing
the number of tanning beds in the salon, followed by a space, followed by
a sequence of uppercase letters.
Letters in the sequence occur in pairs.
The first occurrence indicates the arrival of a customer, the second indicates
the departure of that same customer.
No letter will occur in more than one pair.
Customers who leave without tanning always depart before customers who are currently tanning.
There are at most 20 beds per salon.

Output

For each salon, output a sentence telling how many customers, if any, walked away.
Use the exact format shown below.

Sample Input

2 ABBAJJKZKZ
3 GACCBDDBAGEE
3 GACCBGDDBAEE
1 ABCBCA
0
Sample Output

All customers tanned successfully.
1 customer(s) walked away.
All customers tanned successfully.
2 customer(s) walked away.
Source

Mid-Central USA 2002
*/
