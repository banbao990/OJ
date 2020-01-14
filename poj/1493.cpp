/**********************************************************************
 * author:      banbao                                                *
 * language:    c++/c                                                 *
 * link:        http://poj.org/problem?id=1493                        *
 **********************************************************************/
 /*
  * bbq:
 */
#include <stdio.h>
#include <limits.h>

int main() {
    int N;
    char a[30];
    int blank, totalblank, minblank;
    int i;
    int temp;

    for (;;) {
        scanf("%d", &N);
        if (!N)  break;
        getchar();

        totalblank = 0;
        minblank = INT_MAX;
        temp = N;
        while (temp--) {
            blank = 0;
            gets(a);
            for (i = 0; i < 25; i++)   if (a[i] == ' ')   blank++;
            totalblank += blank;
            minblank = (minblank < blank) ? minblank : blank;
        }
        printf("%d\n", totalblank - minblank * N);
    }
    return 0;
}
/*
Machined Surfaces
Time Limit: 1000MS      Memory Limit: 10000K
Total Submissions: 3789     Accepted: 2325
Description

An imaging device furnishes digital images of two machined surfaces that
eventually will be assembled in contact with each other. The roughness
of this final contact is to be estimated.


A digital image is composed of the two characters, "X" and " " (space).
There are always 25 columns to an image, but the number of rows, N, is variable. 
Column one (1) will always have an "X" in it and will be part of the left surface.
The left surface can extend to the right from column one (1) as contiguous X's.


Similarly, column 25 will always have an "X" in it and will be part of the right 
surface. The right surface can extend to the left from column 25 as contiguous X's.

Digital-Image View of Surfaces

         Left                                      Right
         XXXX                                      XXXXX  ←1
         XXX                                     XXXXXXX
         XXXXX                                      XXXX
         XX                                       XXXXXX
         .                                             .
         .                                             .
         .                                             .
         XXXX                                       XXXX
         XXX                                       XXXXX  ←N
         ↑                                           ↑
         1                                          25


In each row of the image, there can be zero or more space characters separating 
the left surface from the right surface. There will never be more than a single 
blank region in any row.

For each image given, you are to determine the total ``void" that will exist after
the left surface has been brought into contact with the right surface. 
The ``void" is the total count of the spaces that remains between the left and right
surfaces after theyhave been brought into contact.

The two surfaces are brought into contact by displacing them strictly horizontally
towards each other until a rightmost "X" of the left surface of some row is 
immediately to the left of the leftmost "X" of the right surface of that row. 
There is no rotation or twisting of these two surfaces as they are brought into
contact; they remain rigid, and only move horizontally.

Note: The original image may show the two surfaces already in contact, in which 
case no displacement enters into the contact roughness estimation.
Input

The input consists of a series of digital images. Each image data set has the 
following format:

First line -
A single unsigned integer, N, with value greater than zero (0) and less than 13. 
The first digit of N will be the first character on a line.

Next N lines -
Each line has exactly 25 characters; one or more X's, then zero or more spaces,
then one or more X's.

The end of data is signaled by a null data set having a zero on the first line of
an image data set and no further data.
Output

For each image you receive as a data set, you are to reply with the total void
(count of spaces remaining after the surfaces are brought into contact).
Use the default output for a single integer on a line.
Sample Input

4
XXXX                XXXXX
XXX               XXXXXXX
XXXXX                XXXX
XX                 XXXXXX
2
XXXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
1
XXXXXXXXX              XX
0
Sample Output

4
0
0
Source

East Central North America 1995
*/
