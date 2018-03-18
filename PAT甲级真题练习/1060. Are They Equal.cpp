/*
 @Date    : 2018-02-02 11:05:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1060
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string toChop(const string &num, const int prec)
{
    int valid = 0;
    int exp = 0;
    bool decimal = false;
    int n = num.length();
    string result("0.");
    int count = 0;
    for (; valid != n && (num[valid] == '0' || num[valid] == '.'); ++valid)
    {
        if (decimal)
            --exp;
        if (num[valid] == '.')
            // 说明这个数是个小于1的数，即纯小数
            decimal = true;
    }
    if (valid == n)
        // 说明这个数为0
        exp = 0;
    // printf("valid = %d, exp = %d\n", valid, exp);
    for (int i = valid; i != n; ++i)
    {
        if (num[i] != '.')
        {
            if (count != prec)
            {
                result += num[i];
                ++count;
            }
        }
        else if (!decimal)
        {
            // 这个数不是纯小数并且整数部分读取完毕
            exp = i - valid;
            decimal = true;
        }
    }
    if (exp == 0 && valid != n)
        // 说明是个非零正整数
        exp = n - valid;
    if (count != prec)
        result += string((prec - count), '0');
    string exp_s = to_string(exp);
    result += "*10^";
    result += exp_s;
    return result;
}

int main(int argc, char const *argv[])
{
    int N;
    string s1, s2;
    cin >> N >> s1 >> s2;
    string result1 = toChop(s1, N), result2 = toChop(s2, N);
    if (result1 == result2)
    {
        printf("YES ");
        cout << result1 << endl;
    }
    else
    {
        printf("NO ");
        cout << result1 << " " << result2 << endl;
    }
    return 0;
}
