/*
 @Date    : 2018-01-06 21:14:51
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p579
 */

#include <iostream>
#include <string>
#include <functional>
#include <map>

using namespace std;

int add(int i, int j) { return i + j; }
auto mod = [] (int i, int j) { return i % j; };
struct divide
{
    int operator()(int i, int j) { return i / j; }
};


int main(int argc, char const *argv[])
{
    map<string, function<int(int, int)>> binops =
    {
        {"+", add},
        {"-", std::minus<int>()},
        {"*", [] (int i, int j) { return i * j; }},
        {"/", mod},
        {"%", divide()}
    };
    int i = 3, j = 4;
    cout << binops["+"](i, j) << endl;
    cout << binops["-"](i, j) << endl;
    cout << binops["*"](i, j) << endl;
    cout << binops["/"](i, j) << endl;
    cout << binops["%"](i, j) << endl;
    return 0;
}
