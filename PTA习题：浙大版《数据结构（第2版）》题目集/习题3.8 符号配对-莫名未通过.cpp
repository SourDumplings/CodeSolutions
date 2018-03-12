/*
 @Date    : 2018-03-11 15:58:24
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5869
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

static const int INF = 999999;

void pre_process(string &text)
{
    string::size_type i = 0;
    int left = -1;
    while (true)
    {
        i = text.find("/*/", i);
        if (i == string::npos) break;
        if (left == -1)
            text.replace(i, 3, "/*");
        else
            text.replace(i, 3, "*/");
        left = -left;
    }
    return;
}

int main(int argc, char const *argv[])
{
    string text;
    string eachLine;
    while (getline(cin, eachLine))
    {
        if (eachLine == ".")
            break;
        text += eachLine;
    }
    pre_process(text); // 去掉/*/这种情况

    int l = text.length();
    unordered_map<string, int> s;

    int firstLeftProblemIndex = INF;
    string firstLeftProblem;
    for (int i = l - 1; i != -1; --i)
    {
        switch (text[i])
        {
        case ')': ++s[string(")")]; break;
        case ']': ++s[string("]")]; break;
        case '}': ++s[string("}")]; break;
        case '/':
        {
            if (i != 0 && text[i - 1] == '*' && !(i > 1 && text[i - 2] == '/'))
            {
                ++s[string("*/")];
                --i;
            }
            break;
        }
        case '(':
        {
            if (s[string(")")] > 0) --s[string(")")];
            else
            {
                firstLeftProblem = "(";
                firstLeftProblemIndex = i;
                goto END_LEFT_JUDGE;
            }
            break;
        }
        case '[':
        {
            if (s[string("]")] > 0) --s[string("]")];
            else
            {
                firstLeftProblem = "[";
                firstLeftProblemIndex = i;
                goto END_LEFT_JUDGE;
            }
            break;
        }
        case '{':
        {
            if (s[string("}")] > 0) --s[string("}")];
            else
            {
                firstLeftProblem = "{";
                firstLeftProblemIndex = i;
                goto END_LEFT_JUDGE;
            }
            break;
        }
        case '*':
        {
            if (i != 0 && text[i - 1] == '/')
            {
                if (s[string("*/")] > 0) --s[string("*/")];
                else
                {
                    firstLeftProblem = "/*";
                    firstLeftProblemIndex = i;
                    goto END_LEFT_JUDGE;
                }
                --i;
            }
            break;
        }
        }
    }
END_LEFT_JUDGE:
    int firstRightProblemIndex = INF;
    string firstRightProblem;
    for (int i = 0; i != l; ++i)
    {
        switch (text[i])
        {
        case '(': ++s[string("(")]; break;
        case '[': ++s[string("[")]; break;
        case '{': ++s[string("{")]; break;
        case '/':
        {
            if (i != l - 1 && text[i + 1] == '*' && !(i < l - 1 && text[i + 2] == '/'))
            {
                ++s[string("/*")];
                ++i;
            }
            break;
        }
        case ')':
        {
            if (s[string("(")] > 0) --s[string("(")];
            else
            {
                firstRightProblem = ")";
                firstRightProblemIndex = i;
                goto END_RIGHT_JUDGE;
            }
            break;
        }
        case ']':
        {
            if (s[string("[")] > 0) --s[string("[")];
            else
            {
                firstRightProblem = "]";
                firstRightProblemIndex = i;
                goto END_RIGHT_JUDGE;
            }
            break;
        }
        case '}':
        {
            if (s[string("{")] > 0) --s[string("{")];
            else
            {
                firstRightProblem = "}";
                firstRightProblemIndex = i;
                goto END_RIGHT_JUDGE;
            }
            break;
        }
        case '*':
        {
            if (i != l - 1 && text[i + 1] == '/')
            {
                if (s[string("/*")] > 0) --s[string("/*")];
                else
                {
                    firstRightProblem = "*/";
                    firstRightProblemIndex = i;
                    goto END_RIGHT_JUDGE;
                }
                ++i;
            }
            break;
        }
        }
    }
END_RIGHT_JUDGE:
    if (firstRightProblemIndex == INF && firstLeftProblemIndex == INF)
        printf("YES\n");
    else
    {
        printf("NO\n");
        if (firstLeftProblemIndex < firstRightProblemIndex)
            printf("%s-?\n", firstLeftProblem.c_str());
        else
            printf("?-%s\n", firstRightProblem.c_str());
    }
    return 0;
}

