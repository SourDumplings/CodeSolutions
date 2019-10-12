/*
 @Date    : 2018-01-31 09:34:41
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1057
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void popStack(vector<int> &stack)
{
    if (stack.empty())
        printf("Invalid\n");
    else
    {
        printf("%d\n", stack.back());
        stack.pop_back();
    }
    return;
}

void peekMedianStack(vector<int> &stack)
{
    int n = stack.size();
    vector<int> temp = stack;
    sort(temp.begin(), temp.end());
    if (n)
    {
        if (n & 1)
            printf("%d\n", temp[(n+1)/2-1]);
        else
            printf("%d\n", temp[n/2-1]);
    }
    else
        printf("Invalid\n");
    return;
}

void pushStack(vector<int> &stack, int item)
{
    stack.push_back(item);
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    getchar();
    string order;
    vector<int> stack;
    for (int i = 0; i != N; ++i)
    {
        getline(cin, order);
        if (order == "Pop")
            popStack(stack);
        else if (order == "PeekMedian")
            peekMedianStack(stack);
        else
            pushStack(stack, stoi(order.substr(5)));
    }
    return 0;
}
