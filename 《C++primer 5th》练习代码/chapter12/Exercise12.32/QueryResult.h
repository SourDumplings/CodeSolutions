/*
 @Date    : 2018-01-01 23:06:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p490
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
#include "StrBlob.h"

using namespace std;
using namespace std::placeholders;

class QueryResult
{
    friend ostream& print(ostream&, const QueryResult&);
public:
    using line_no = vector<string>::size_type;
    QueryResult(const string &s, const shared_ptr<set<line_no>> &p, const StrBlob &f):
    sought(s), lines(p), file(f) {}
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    StrBlob file;
};

ostream& print(ostream&, const QueryResult&);

#endif
