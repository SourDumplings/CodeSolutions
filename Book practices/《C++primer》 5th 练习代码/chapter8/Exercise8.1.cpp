/*
 @Date    : 2017-12-22 11:53:37
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p314
 */

#include <iostream>
#include <stdexcept>

using namespace std;

istream& f(istream &in)
{
    int v;
    while (in >> v, !in.eof())
    {
        if (in.bad())
        {
            throw runtime_error("IO stream error");
        }
        if (in.fail())
        {
            cerr << "data error, try agian: " << endl;
            in.clear();
            in.ignore(100, '\n'); // ignore()跳过输入流中n个字符，或在遇到指定的终止字符时提前结束
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main(int argc, char const *argv[])
{
    cout << "Please input some ints until pressing ctrl+z:" << endl;
    f(cin);
    return 0;
}
