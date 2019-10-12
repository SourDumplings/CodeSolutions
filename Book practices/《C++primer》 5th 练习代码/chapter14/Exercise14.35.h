/*
 @Date    : 2018-01-06 14:15:30
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p572
 */

#include <iostream>
#include <string>

using namespace std;

class ReadString
{
public:
    ReadString(istream &in = cin): is(in) {}
    string operator()()
    {
        string line;
        if (!getline(is, line))
        {
            line = "";
        }
        return line;
    }
private:
    istream &is;
};
