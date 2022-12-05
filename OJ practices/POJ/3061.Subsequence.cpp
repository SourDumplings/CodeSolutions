/*
 * @Author: SourDumplings
 * @Date: 2022-12-05 22:13:35
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: http://poj.org/problem?id=3061
 * 
 * 答案错误，不知为何
 *
Subsequence
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 48372		Accepted: 19123
Description

A sequence of N positive integers (10 < N < 100 000), each of them less than or equal 10000, and a positive integer S (S < 100 000 000) are given. Write a program to find the minimal length of the subsequence of consecutive elements of the sequence, the sum of which is greater than or equal to S.
Input

The first line is the number of test cases. For each test case the program has to read the numbers N and S, separated by an interval, from the first line. The numbers of the sequence are given in the second line of the test case, separated by intervals. The input will finish with the end of file.
Output

For each the case the program has to print the result on separate line of the output file.if no answer, print 0.
Sample Input

2
10 15
5 1 3 5 10 7 4 9 2 8
5 11
1 2 3 4 5
Sample Output

2
3
 */

#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int c, N, S;
    scanf("%d", &c);
    for (int i = 0; i < c; i++)
    {
        scanf("%d %d", &N, &S);
        
        int num[N];
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &num[j]);
        }
        int res = __INT_MAX__, b = 0, e = 0;
        int sum = 0;
        while (e < N)
        {
            while (sum < S)
            {
                sum += num[e++];
                if (e == N)
                {
                    break;
                }
            }

            while (S <= sum && b < e)
            {
                if (sum - num[b] < S)
                {
                    res = min(res, e - b);
                    break;
                }
                sum -= num[b++];
            }
            b = e;
            sum = 0;
        }

        if (res == __INT_MAX__)
        {
            res = 0;
        }
        printf("%d\n", res);
    }

    return 0;
}
