/*
 @Date    : 2018-01-10 15:15:58
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p645
 */

#ifndef COMPLEX_QUERY_H
#define COMPLEX_QUERY_H

#include <iostream>
#include <string>
#include <memory>
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

class Query_base
{
    friend class Query;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
protected:
    using line_no = TextQuery::line_no;
    ~Query_base() = default;
};

class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const string&);
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    string rep() const { return q->rep(); }
private:
    Query(shared_ptr<Query_base> query): q(query)
    {
        cout << "Query constructor on Query_base" << endl;
    }
    shared_ptr<Query_base> q;
};

inline ostream& operator<<(ostream &os, const Query &query)
{
    return os << query.rep();
}

class WordQuery: public Query_base
{
    friend class Query;
private:
    string query_word;
    WordQuery(const string &s): query_word(s)
    {
        cout << "WordQuery constructor" << endl;
    }
    QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
    string rep() const { return query_word; }
};

inline Query::Query(const string &s): q(new WordQuery(s))
{
    cout << "Query constructor on string" << endl;
}

class NotQuery: public Query_base
{
    friend Query operator~(const Query&);
private:
    Query query;
    QueryResult eval(const TextQuery&) const { QueryResult tempQr; return tempQr; };
    string rep() const { return "~(" + query.rep() + ")"; }
    NotQuery(const Query &q) : query(q)
    {
        cout << "NotQuery constructor" << endl;
    }
};

inline Query operator~(const Query &operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery: public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query &r, const string &s): lhs(l), rhs(r), opSym(s)
    {
        cout << "BinaryQuery constructor" << endl;
    }
    string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
    Query lhs, rhs;
    string opSym;
};

class AndQuery: public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
private:
    AndQuery(const Query &l, const Query &r): BinaryQuery(l, r, "&")
    {
        cout << "AndQuery constructor" << endl;
    }
    QueryResult eval(const TextQuery&) const { QueryResult tempQr; return tempQr; };
};

Query operator&(const Query &l, const Query &r)
{
    return shared_ptr<Query_base>(new AndQuery(l, r));
}

class OrQuery: public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
private:
    OrQuery(const Query &l, const Query &r): BinaryQuery(l, r, "|")
    {
        cout << "OrQuery constructor" << endl;
    }
    QueryResult eval(const TextQuery&) const { QueryResult tempQr; return tempQr; };
};

Query operator|(const Query &l, const Query &r)
{
    return shared_ptr<Query_base>(new OrQuery(l, r));
}

#endif
