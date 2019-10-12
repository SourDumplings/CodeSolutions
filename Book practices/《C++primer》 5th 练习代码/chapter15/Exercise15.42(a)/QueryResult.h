/*
 @Date    : 2018-01-01 23:06:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p648
 */

#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <memory>
#include <new>

using namespace std;
using namespace std::placeholders;

class QueryResult
{
    friend ostream& print(ostream&, const QueryResult&);
public:
    using line_no = vector<string>::size_type;
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f):
        sought(s), lines(p), file(f) {}
    set<line_no>::iterator end() const { return lines->end(); }
    set<line_no>::iterator begin() const { return lines->begin(); }
    shared_ptr<vector<string>> get_file() const { return file; }
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

ostream& print(ostream &os, const QueryResult &qr)
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
            os << "\t(sentence " << num + 1 << ") "
            << (*qr.file)[num] << endl;
        }
    }
    return os;
}

#endif
