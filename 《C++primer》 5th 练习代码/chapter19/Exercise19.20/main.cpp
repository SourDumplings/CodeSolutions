/*
 @Date    : 2018-01-01 22:55:45
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p847
 */

#include <iostream>
#include <string>
#include <fstream>
#include "TextQuery.h"

using namespace std;
using namespace std::placeholders;

ostream& print(ostream  &os, const TextQuery::QueryResult &qr)
{
    os << qr.sought;
    if (qr.lines->size() == 0)
    {
        os << " doesn't occur" << endl;
    }
    else
    {
        os << " occurs " << qr.lines->size() << " "
        << (qr.lines->size() > 1 ? "times" : "time") << endl;
        for (auto num : *qr.lines)
        {
            os << "\t(line " << num + 1 << ") "
            << *(qr.file->begin() + num) << endl;
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
