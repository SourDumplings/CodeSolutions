/*
 @Date    : 2018-03-13 18:31:22
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/837
说一下这道题的解题思路，用c++堆栈模拟队列，输入两个堆栈的长度，
长度短的作为输入栈，长的作为输出栈，如果输入栈满了但输出栈不空，
此时不能再输入了，为栈满，其他情况都可以输入，如果输入栈满了，输出栈为空，
就可以将输入栈的元素转移到输出栈，再向输入栈添加元素，如此就可以实现模拟队列的功能
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    stack<int> Si, So;
    int Ni, No;
    scanf("%d %d", &Ni, &No);
    if (Ni > No) swap(Ni, No);
    while (true)
    {
        char c;
        scanf("%c", &c);
        switch (c)
        {
            case 'A':
            {
                int item;
                scanf("%d", &item);
                // printf("A %d\n", item);
                if (Si.size() == Ni)
                {
                    if (So.empty())
                    {
                        while (!Si.empty())
                        {
                            So.push(Si.top()); Si.pop();
                        }
                        Si.push(item);
                    }
                    else
                        printf("ERROR:Full\n");
                }
                else
                    Si.push(item);
                break;
            }
            case 'D':
            {
                // printf("D\n");
                if (Si.empty() && So.empty())
                    printf("ERROR:Empty\n");
                else if (!So.empty())
                {
                    printf("%d\n", So.top()); So.pop();
                }
                else
                {
                    while (!Si.empty())
                    {
                        So.push(Si.top()); Si.pop();
                    }
                    printf("%d\n", So.top()); So.pop();
                }
                break;
            }
            case 'T': goto END;
        }
    }
END:
    return 0;
}

