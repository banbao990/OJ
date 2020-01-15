/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=2159                        *
 **********************************************************************/

/*
 * bbq: 统计每个字符出现的次数, 
 *      次数降序排列得到序列相同则可以相互转换
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;  //升序排序
    //return *(int *)b - *(int *)a; //降序排序
}

int main() {
    char a[101], b[101];
    int anum[26] = {}, bnum[26] = {};
    int alength, blength;
    int aflag, bflag;
    int i;

    gets(a);
    gets(b);

    alength = strlen(a);
    blength = strlen(b);
    if (alength != blength) {
        printf("NO");
        return 0;
    }

    for (i = 0; i < alength; i++) {
        aflag = a[i] - 'A';
        bflag = b[i] - 'A';
        anum[aflag]++;
        bnum[bflag]++;
    }

    //快速排序 quick sort ,在头文件 stdlib 里 
    qsort(anum, 26, sizeof(int), comp);
    qsort(bnum, 26, sizeof(int), comp);

    for (i = 0; i < 26; i++) {
        if (anum[i] != bnum[i]) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}

/*
Ancient Cipher
Time Limit: 1000MS      Memory Limit: 65536K
Total Submissions: 37601        Accepted: 12227
Description

Ancient Roman empire had a strong government system with various departments,
including a secret service department. Important documents were sent between
provinces and the capital in encrypted form to prevent eavesdropping. The most
popular ciphers in those times were so called substitution cipher and
permutation cipher.

Substitution cipher changes all occurrences of each letter to some other
letter. Substitutes for all letters must be different. For some letters
substitute letter may coincide with the original letter. For example, applying
substitution cipher that changes all letters from 'A' to 'Y' to the next ones
in the alphabet, and changes 'Z' to 'A', to the message "VICTORIOUS" one gets
the message "WJDUPSJPVT".

Permutation cipher applies some permutation to the letters of the message. For
example, applying the permutation <2, 1, 5, 4, 3, 7, 6, 10, 9, 8> to the
message "VICTORIOUS" one gets the message "IVOTCIRSUO".

It was quickly noticed that being applied separately, both substitution cipher
and permutation cipher were rather weak. But when being combined, they were
strong enough for those times. Thus, the most important messages were first
encrypted using substitution cipher, and then the result was encrypted using
permutation cipher. Encrypting the message "VICTORIOUS" with the combination
of the ciphers described above one gets the message "JWPUDJSTVP".

Archeologists have recently found the message engraved on a stone plate. At
the first glance it seemed completely meaningless, so it was suggested that
the message was encrypted with some substitution and permutation ciphers. They
have conjectured the possible text of the original message that was encrypted,
and now they want to check their conjecture. They need a computer program to
do it, so you have to write one.

Input

Input contains two lines. The first line contains the message engraved on the
plate. Before encrypting, all spaces and punctuation marks were removed, so
the encrypted message contains only capital letters of the English alphabet.
The second line contains the original message that is conjectured to be
encrypted in the message on the first line. It also contains only capital
letters of the English alphabet.

The lengths of both lines of the input are equal and do not exceed 100.

Output

Output "YES" if the message on the first line of the input file could be the
result of encrypting the message on the second line, or "NO" in the other
case.

Sample Input

JWPUDJSTVP
VICTORIOUS

Sample Output

YES
Source

Northeastern Europe 2004
*/
