
/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=3751                        *
 **********************************************************************/

/*
 * bbq: 注意提示
*/

#include <stdio.h>

int main() {
    char a[30];     //1970/01/01-00:01:01
    int N;
    char flag;
    int i;
    int h;

    scanf("%d", &N);
    getchar();
    while (N--) {
        gets(a);
        h = (a[11] - '0') * 10 + (a[12] - '0');

        if (h < 12) {
            flag = 'a';
//          if(h==0&&a[14]=='0'&&a[15]=='0'&&a[17]=='0'&&a[18]=='0')
            if (!h) {
                a[11] = '1';
                a[12] = '2';
            }
        }
        else {
            flag = 'p';
            if (h != 12) {
                h -= 12;
                a[11] = h / 10 + '0';
                a[12] = h % 10 + '0';
            }
        }

        printf("%c%c/%c%c/", a[5], a[6], a[8], a[9]);
        for (i = 0; i < 4; i++)
            printf("%c", a[i]);
        printf("-");
        for (i = 11; i < 19; i++)
            printf("%c", a[i]);
        printf("%cm\n", flag);
    }

    return 0;
}

/*
时间日期格式转换
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 9000     Accepted: 4097
Description

世界各地有多种格式来表示日期和时间。
对于日期的常用格式，在中国常采用格式的是“年年年年/月月/日日”或写为英语缩略表示的”yyyy/mm/dd”，
此次编程大赛的启动日期“2009/11/07”就是符合这种格式的一个日期，
而北美所用的日期格式则为“月月/日日/年年年年”或”mm/dd/yyyy”，如将“2009/11/07”改成这种格式，
对应的则是”11/07/2009”。对于时间的格式，则常有12小时制和24小时制的表示方法，
24小时制用0-24来表示一天中的24小时，而12小时制只采用1-12表示小时，再加上am/pm来表示上午或下午，
比如”17:30:00”是采用24小时制来表示时间，而对应的12小时制的表示方法是”05:30:00pm”。
注意12:00:00pm表示中午12点，而12:00:00am表示凌晨12点。

对于给定的采用”yyyy/mm/dd”加24小时制（用短横线”-”连接）来表示日期和时间的字符串，
请编程实现将其转换成”mm/dd/yyyy”加12小时制格式的字符串。
Input

第一行为一个整数T（T<=10），代表总共需要转换的时间日期字符串的数目。
接下来的总共T行，每行都是一个需要转换的时间日期字符串。
Output

分行输出转换之后的结果
Sample Input

2
2009/11/07-12:12:12
1970/01/01-00:01:01
Sample Output

11/07/2009-12:12:12pm
01/01/1970-12:01:01am
Hint

注意中午和凌晨时间的特殊表示
Source
*/