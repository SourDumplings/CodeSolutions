/*
 @Date    : 2018-02-12 23:31:05
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
输入整数 n ( 0 <=n<= 2^30) , 以及整数i,j(0 <= i,j <31,i < j-1), 输出整数k(按十六进制输出结果 )，k的第i位和n相同，第j位和n不同，i,j之间的位是1, 其他位都是0。这里提到的所有的位，指的都是二进制位，最右边算第0位。
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, i, j;
        scanf("%d %d %d", &n, &i, &j);
        int ni = n & (1 << i); // 第i位和n相同，其他位全为0
        int nj = ~(n & (1 << j)) & (1 << j); // 第j位和n不同，其他位全为0
        int temp = ((1 << j) - 1) & (1 << (i + 1)); // (i, j)位是1，其余为0
        int res = temp | ni | nj;
        printf("%x\n", res);
    }
    return 0;
}
