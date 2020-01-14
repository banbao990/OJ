/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1008                        *
 **********************************************************************/

/*
 * bbq: Haab历转化成Tzolkin历
*/

#include <stdio.h>

int month(char a[10]) {
    int b;
    /*
     * pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen,
     * yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu
    */
    switch (a[0]) {
    case 'p':
        if (a[1] == 'o')   b = 1;
        else    b = 16;
        break;
    case 'n':
        b = 2;
        break;
    case 'z':
        if (a[1] == 'i')   b = 3;
        if (a[1] == 'o')   b = 4;
        if (a[1] == 'a') b = 11;
        break;
    case 't':
        b = 5;
        break;
    case 'x':
        b = 6;
        break;
    case 'y':
        if (a[1] == 'o')   b = 7;
        else    b = 10;
        break;
    case 'm':
        if (a[1] == 'o')   b = 8;
        if (a[1] == 'a')   b = 13;
        if (a[1] == 'u')   b = 15;
        break;
    case 'c':
        if (a[1] == 'h')   b = 9;
        if (a[1] == 'e')   b = 12;
        if (a[1] == 'u')   b = 18;
        break;
    case 'k':
        if (a[1] == 'a')   b = 14;
        else    b = 17;
        break;
    case 'u':
        b = 19;
        break;
    }
    return b;
}


int main() {
    int number;
    int i, j;
    char a[10] = {};
    int b, d, e;
    char temp;
    long long DAY;
    int day, year;
    char zifu[20][10] = { "imix", "ik", "akbal", "kan", "chicchan",
        "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben",
        "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
    int k;

    scanf("%d", &number);
    printf("%d\n", number);
    for (i = 0; i < number; i++) {
        //输入日期 b
        scanf("%d", &b);
        while (1) {
            scanf("%c", &temp);
            if (temp == ' ')   break;
        }
        //输入月份 a
        for (j = 0;; j++) {
            scanf("%c", &a[j]);
            if (a[j] == ' ')
            {
                a[j] = 0;
                break;
            }
        }

        e = month(a);//月份 a 转化为数字月份 e                             
        scanf("%d", &d);//输入年份 d

        DAY = 365 * d + (e - 1) * 20 + b + 1;//一共多少天 DAY
        //开始转换 
        day = (int)DAY % 260;
        year = (int)DAY / 260;
        if (day == 0)  year--;

        k = day % 13;
        if (k == 0)    k = 13;
        j = day % 20;
        if (j == 0)    j = 20;
        printf("%d %s %d\n", k, zifu[j - 1], year);
    }
    return 0;
}



//  4. uayet 259            DAY=94520               13 ahau 364


/*
Description

Haab 历法:
    1-18月, 20天/月(0-19)
        pop, no, zip, zotz, tzec, xul,
        yoxkin, mol, chen, yax, zac, ceh,
        mac, kankin, muan, pax, koyab, cumhu
    19月, 5天(0-4)
        uayet

Tzolkin 历法:
    A + B(类似于甲子纪年法)
        A: 1-13
        B:  imix, ik, akbal, kan, chicchan,
            cimi, manik, lamat, muluk, ok,
            chuen, eb, ben, ix, mem,
            cib, caban, eznab, canac, ahau。

eg:     1 imix, 2 ik, 3 akbal, 4 kan, 5 chicchan, 6 cimi, 7 manik,
        8 lamat, 9 muluk, 10 ok, 11 chuen, 12 eb, 13 ben,
        1 ix, 2 mem, 3 cib, 4 caban, 5 eznab, 6 canac, 7 ahau,
        8 imix, 9 ik, 10 akbal ……

Haab历和Tzolkin历中的年都用数字0, 1, 2, ... 表示
数字0表示世界的开始。
    所以第一天被表示成：
        Haab: 0. pop 0
        Tzolkin: 1 imix 0
*/


/*
//检测月份转换是否正确
int main(){
    int i=18;
    char a[10]={};
    int b;
    while(i--){
        gets(a);
        b=month(a);
        printf("%d\n",b);
    }
    return 0;
}

pop
no
zip
zotz
tzec
xul
yoxkin
mol
chen
yax
zac
ceh
mac
kankin
muan
pax
koyab
cumhu

*/

/*

#include <stdio.h>
//测试字符串数组输入
int main(){
    int i;
    char a[20][10]={"imix", "ik", "akbal", "kan", "chicchan",
    "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb",
    "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

    for(i=0;i<20;i++)   puts(a[i]);
    return 0;
}
*/
