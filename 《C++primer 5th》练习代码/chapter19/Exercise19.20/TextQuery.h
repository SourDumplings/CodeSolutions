/*
 @Date    : 2018-01-01 22:59:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p847
 */

#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <memory>
#include <new>

using namespace std;
using namespace std::placeholders;

class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    class QueryResult;
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

class TextQuery::QueryResult
{
    friend ostream& print(ostream&, const QueryResult&);
public:
    using line_no = vector<string>::size_type;
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f):
    sought(s), lines(p), file(f) {}
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

ostream& print(ostream&, const TextQuery::QueryResult&);

TextQuery::TextQuery(ifstream &infile): file(new vector<string>)
{
    string text;
    while (getline(infile, text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word)
        {
            for (auto &c : word)
            {
                c = tolower(c);
            }
            auto &lines = wm[word];
            if (!lines)
            {
                lines.reset(new set<line_no>);
            }
            lines->insert(n);
        }
    }
}

TextQuery::QueryResult TextQuery::query(const string& sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
    {
        return QueryResult(sought, nodata, file);
    }
    else
    {
        return QueryResult(sought, loc->second, file);
    }
}

#endif
