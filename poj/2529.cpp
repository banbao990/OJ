/***********************
 * author:      banbao *
 * language:    c++/c  *
 ***********************/

// link : http://poj.org/problem?id=2559
/*
 * bbq:
 * description:单调递增栈
*/

 /* library */
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
/* micros */
/* functions */
/* pragmas */
#pragma warning(disable:4996)
/* const variables */
/* code start here */

// deal
// 1 <= n <= 100000. 0 <= hi <= 1000000000
#define N 100010
struct Node {
    long long height;
    int count;
};
Node node[N]; // ascending stack
int value[N];
void solve() {
    int n;
    while (true) {
        scanf("%d", &n);
        if (!n) { break; }
        int pos = 0;
        long long height;
        long long ans = 0;
        for (int i = 0; i < n; ++i) { scanf("%lld", &value[i]); }
        value[n] = 0;
        for (int i = 0; i <= n; ++i) {
            height = value[i];
            // stack is empty
            if (pos == 0) {
                if (height > ans) { ans = height; }
                node[pos].height = height;
                node[pos].count = i;
                ++pos;
            }
            else {
                // add to stack
                if (height >= node[pos - 1].height) {
                    node[pos].height = height;
                    node[pos].count = i;
                    ++pos;
                    if (height > ans) { ans = height; }
                }
                // pop element
                else {
                    // pop
                    while (pos > 0) {
                        if (node[pos - 1].height <= height) { break; }
                        // calc
                        int left = 0;
                        if (pos != 1) {
                            left = node[pos - 2].count + 1;
                        }
                        long long temp = (i - left)*node[pos - 1].height;
                        if (temp > ans) { ans = temp; }
                        --pos;
                    }
                    // add
                    // if (height > ans) { ans = height; }
                    node[pos].height = height;
                    node[pos].count = i;
                    ++pos;
                }
            }
        }
        printf("%lld\n", ans);
    }
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
/*

*/