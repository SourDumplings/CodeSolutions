/*
 @Date    : 2018-01-01 22:55:45
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p720
 */

#include <iostream>
#include <string>
#include <fstream>
#include "TextQuery.h"

using namespace std;
using namespace std::placeholders;

ostream& print(ostream &os, const QueryResult &qr)
{
    os << get<0>(qr);
    if (get<1>(qr)->size() == 0)
    {
        os << " doesn't occur" << endl;
    }
    else
    {
        os << " occurs " << get<1>(qr)->size() << " "
        << (get<1>(qr)->size() > 1 ? "times" : "time") << endl;
        for (auto it = get<1>(qr)->begin(); it != get<1>(qr)->end(); ++it)
        {
            auto num = *it;
            os << "\t(line " << num + 1 << ") "
            << *(get<2>(qr)->begin() + num) << endl;
        }
    }
    return os;
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
        {
            break;
        }
        print(cout, tq.query(s));
    }
    return;
}

int main(int argc, char const *argv[])
{
    ifstream infile("storyDataFile");
    runQueries(infile);
    return 0;
}
