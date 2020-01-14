
/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1010                        *
 **********************************************************************/

/*
 * bbq: 每组数据两行输入
 *      第一行表示有几种邮票(>25题目数据有误), 输入数据为邮票价格
 *      第二行表示有几个客户(总价为K)
 * 不同方案依次比较得出优劣性
 *  1. 输出邮票种类最多,每人最多4种邮票
 *  2. 邮票总数最少
 *  3. 单张邮票价值最大
 *
 * 如果没有达到要求的输出 none, 比不出优劣输出 tie
*/

#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct finals {
    int price, type;
}final[4];

int req;
int total;                          // 表示相同组合的数目 
int finaltypesum;                   // 表示最终有几张邮票 
int finalstampsum;                  // 表示最终有几种邮票  
int stamp[100];                     // 神坑!!!!!!!!!!!!!!!!!!!!!!!!!!!!!       25会爆炸 
int snum;                           // snum表示输入有几种邮票

//降序排列
bool compare(int aa, int bb) {
    return aa > bb;
}

/*
 * now 表示现在选择的邮票, pricenum表示总价, typesum表示选择的邮票种类数目
 * stampsum表示邮票总数, step表示选择了几种邮票
*/
void dfs(finals now[4], int pricesum, int typesum, int stampsum, int step) {
    int i;
    // 找到结果
    if (pricesum == req) {
        // 种类更多, 更新答案
        if (typesum > finaltypesum) {
            memset(final, 0, sizeof(final));
            for (i = 0; i < stampsum; i++) final[i] = now[i];
            finaltypesum = typesum;
            finalstampsum = stampsum;
            total = 1;
            return;
        }
        // 种类一样多
        else if (typesum == finaltypesum) {
            // 数量更少, 更新结果 
            if (stampsum < finalstampsum) {
                memset(final, 0, sizeof(final));
                for (i = 0; i < typesum; i++)  final[i] = now[i];
                finaltypesum = typesum;
                finalstampsum = stampsum;
                total = 1;
                return;
            }
            // 种类数量都一样多
            else if (stampsum == finalstampsum) {
                // 单价更大
                if (now[0].price > final[0].price) {
                    memset(final, 0, sizeof(final));
                    for (i = 0; i < typesum; i++)  final[i] = now[i];
                    finaltypesum = typesum;
                    finalstampsum = stampsum;
                    total = 1;
                    return;
                }
                // 比不出大小
                else if (now[0].price == final[0].price) {
                    total++;
                    return;
                }
            }
        }
    }

    // 剪枝, 总价溢出, 邮票数量 > 4 
    if (step == 4 || pricesum > req) return;         
    
    // normal
    for (i = 0; i < snum; i++) {
        if (step && (i < now[step - 1].type)) continue;
        if (pricesum + stamp[i] <= req) {
            now[step].price = stamp[i];
            now[step].type = i;
            int flag = 1;
            for (int j = 0; j < step; j++){
                if (now[j].type == i){
                    flag = 0;
                    break;
                }
            }
            dfs(now, pricesum + stamp[i], typesum + flag, stampsum + 1, step + 1);
        }
    }
    return;
}
int main() {
    int i;
    finals now[4];
    while (scanf("%d", &stamp[0]) != EOF) {
        for (i = 1;; i++) {
            scanf("%d", &stamp[i]);
            if (!stamp[i])   break;
        }
        snum = i;
        sort(stamp, stamp + i, compare);            //降序排列 

        for (;;) {
            scanf("%d", &req);                   // 要求的金额 
            if (!req) break;
            memset(now, 0, sizeof(now));
            total = 0;

            finaltypesum = 0;
            finalstampsum = 0;
            dfs(now, 0, 0, 0, 0);
            if (!total)  printf("%d ---- none\n", req);
            else if (total == 1) {
                printf("%d (%d):", req, finaltypesum);
                for (i = finalstampsum - 1; i >= 0; i--) printf(" %d", final[i].price);
                printf("\n");
            }
            else printf("%d (%d): tie\n", req, finaltypesum);
        }
    }
    return 0;
}
