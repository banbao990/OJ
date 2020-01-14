/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2247                        *
 **********************************************************************/

#include <stdio.h>
#define min(x,y) ((x)<(y))?(x):(y)

int main(){
    long long ugly[5844] = { 0,1,2,3,4,5 };
    int i;
    int ugly2 = 1, ugly3 = 1, ugly5 = 1, ugly7 = 1;
    int N;
    int temp;
    int temp2;

    for (i = 2; i < 5844; i++){
        ugly[i] = min(
            min(ugly[ugly2] * 2, ugly[ugly3] * 3), 
            min(ugly[ugly5] * 5, ugly[ugly7] * 7)
        );
        //重复舍去
        if (ugly[i] == ugly[ugly2] * 2) ugly2++;
        if (ugly[i] == ugly[ugly3] * 3) ugly3++;
        if (ugly[i] == ugly[ugly5] * 5) ugly5++;
        if (ugly[i] == ugly[ugly7] * 7) ugly7++;
    }

    while (scanf("%d", &N), N){
        temp = N % 10;
        temp2 = N % 100;
        if (temp == 1 && temp2 != 11)
            printf("The %dst humble number is %lld.\n", N, ugly[N]);
        else if (temp == 2 && temp2 != 12)
            printf("The %dnd humble number is %lld.\n", N, ugly[N]);
        else if (temp == 3 && temp2 != 13)
            printf("The %drd humble number is %lld.\n", N, ugly[N]);
        else
            printf("The %dth humble number is %lld.\n", N, ugly[N]);
    }
    return 0;
}
/*
Humble Numbers
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 11170        Accepted: 5190
Description

A number whose only prime factors are 2,3,5 or 7 is called a humble number. 
The sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 
24, 25, 27, ... shows the first 20 humble numbers.

Write a program to find and print the nth element in this sequence.
Input

The input consists of one or more test cases. Each test case consists of 
one integer n with 1 <= n <= 5842. Input is terminated by a value of zero (0) for n.
Output

For each test case, print one line saying "The nth humble number is number.".
Depending on the value of n, the correct suffix "st", "nd", "rd", or "th" 
for the ordinal number nth has to be used like it is shown in the sample output.
Sample Input

1
2
3
4
11
12
13
21
22
23
100
1000
5842
0
Sample Output

The 1st humble number is 1.
The 2nd humble number is 2.
The 3rd humble number is 3.
The 4th humble number is 4.
The 11th humble number is 12.
The 12th humble number is 14.
The 13th humble number is 15.
The 21st humble number is 28.
The 22nd humble number is 30.
The 23rd humble number is 32.
The 100th humble number is 450.
The 1000th humble number is 385875.
The 5842nd humble number is 2000000000.
Source

Ulm Local 1996
*/
