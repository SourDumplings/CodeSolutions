/*
 @Date    : 2018-01-25 11:40:47
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p852
 */

#ifndef TOKEN_H
#define TOKEN_H

#include "Sales_data.h"

using namespace std;

class Token
{
private:
    enum {INT, CHAR, DBL, SD} tok;
    union {
        char c;
        int i;
        double d;
        Sales_data sd;
    };
    void copyUnion(const Token&);
public:
    Token(): tok(INT), i(0) {}
    Token(const Token &t): tok(t.tok) { copyUnion(t); }
    ~Token() { if (tok == SD) sd.~Sales_data(); }
    Token& operator=(const Token&);
    Token& operator=(char);
    Token& operator=(int);
    Token& operator=(double);
    Token& operator=(const Sales_data&);
};

Token& Token::operator=(int ia)
{
    if (tok == SD) sd.~Sales_data();
    i = ia;
    tok = INT;
    return *this;
}

Token& Token::operator=(char ca)
{
    if (tok == SD) sd.~Sales_data();
    c = ca;
    tok = CHAR;
    return *this;
}

Token& Token::operator=(double da)
{
    if (tok == SD) sd.~Sales_data();
    d = da;
    tok = DBL;
    return *this;
}

Token& Token::operator=(const Sales_data &sa)
{
    if (tok == SD) sd = sa;
    else new(&sd) Sales_data(sa);
    tok = SD;
    return *this;
}

void Token::copyUnion(const Token &t)
{
    switch (t.tok)
    {
        case Token::INT: i = t.i; break;
        case Token::CHAR: c = t.c; break;
        case Token::DBL: d = t.d; break;
        case Token::SD: new(&sd) Sales_data(t.sd); break;
    }
    return;
}

Token& Token::operator=(const Token &t)
{
    if (tok == SD && t.tok != SD) sd.~Sales_data();
    if (tok == SD && t.tok == SD) sd = t.sd;
    else copyUnion(t);
    tok = t.tok;
    return *this;
}

#endif

