/*
 @Date    : 2018-03-13 14:43:13
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/827
注意不要忘记考虑小数、多位数和正负号情况
正号要忽略，负号要输出
除了第一个元素就是正负号外，其他的正负号左边必有左括号
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <stack>
#include <cctype>

using namespace std;

static map<char, int> key
{
    {'+', 0},
    {'-', 1},
    {'*', 2},
    {'/', 3},
    {'(', 4},
};

// 记录优先级顺序，第i行第j列中的元素为true代表的是栈内为符号i比栈外符号j优先级高
// 注意小括号在栈外时，优先级最高，在栈内时，优先级最低
// 同级元素的话栈内元素优先级高，小括号除外
static bool priority[5][5] =
{
    {true, true, false, false, false},
    {true, true, false, false, false},
    {true, true, true, true, false},
    {true, true, true, true, false},
    {false, false, false, false, false}
};

int main(int argc, char const *argv[])
{
    int output = 0;
    stack<char> S;
    string line;
    getline(cin, line);
    int l = line.length();
    for (int i = 0; i != l; ++i)
    {
        if (isdigit(line[i]) ||
            ((i == 0 || line[i-1] == '(') &&
                (line[i] == '+' || line[i] == '-')))
        {
            if (output++) putchar(' ');
            if (line[i] != '+') putchar(line[i]);
            for (; isdigit(line[i+1]) || line[i+1] == '.';
                ++i)
                putchar(line[i+1]);
        }
        else if (line[i] == ')')
        {
            for (; !S.empty() && S.top() != '('; S.pop())
            {
                if (output++) putchar(' ');
                putchar(S.top());
            }
            if (S.top() == '(') S.pop();
        }
        else
        {
            for (; !S.empty() && priority[key[S.top()]][key[line[i]]]; S.pop())
            {
                if (output++) putchar(' ');
                putchar(S.top());
            }
            S.push(line[i]);
        }
    }
    while (!S.empty())
    {
        if (output++) putchar(' ');
        putchar(S.top()); S.pop();
    }
    putchar('\n');
    return 0;
}

