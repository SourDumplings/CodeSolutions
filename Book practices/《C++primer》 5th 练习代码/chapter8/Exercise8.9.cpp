/*
 @Date    : 2017-12-22 19:28:47
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p322
 */

#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

istream& f(istream &in)
{
    char c;
    while (in >> c, !in.eof())
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
        cout << c << endl;
    }
    in.clear();
    return in;
}

int main(int argc, char const *argv[])
{
    cout << "Please input some ints until pressing ctrl+z:" << endl;
    string s;
    cin >> s;
    istringstream in(s);
    f(in);
    return 0;
}
