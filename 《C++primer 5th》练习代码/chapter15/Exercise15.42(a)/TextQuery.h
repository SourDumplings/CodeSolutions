/*
 @Date    : 2018-01-01 22:59:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p648
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
#include "QueryResult.h"

using namespace std;
using namespace std::placeholders;

class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &fin): file(new vector<string>)
{
    char ws[] = {'\t', '\r', '\v', '\f', '\n'};
    char eos[] = {'?', '.', '!'};
    set<char> whilteSpace(ws, ws+5); // 空白符（空格除外）
    set<char> endOfSentence(eos, eos+3); // 句子结束符
    string sentence;
    char ch;

    while (fin.get(ch)) // 读取单字符，遇到文件结束符终止
    {
        if (whilteSpace.find(ch) == whilteSpace.end())
            sentence += ch; // 读取到有效字符，加入到句子中
        if (endOfSentence.find(ch) != endOfSentence.end()) // 读完了一个句子
        {
            file->push_back(sentence);
            int n = file->size() - 1;
            istringstream sin(sentence);
            string word;
            while (sin >> word)
            {
                auto &lines = wm[word];
                if (!lines)
                    lines.reset(new set<line_no>);
                lines->insert(n);
            }
            sentence.assign(""); // 将sentence清空，准备读下一句
        }
    }
}

QueryResult TextQuery::query(const string& sought) const
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
