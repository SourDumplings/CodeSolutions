/*
 @Date    : 2018-01-25 12:09:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
P852
 */

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

class Token
{
private:
    enum {INT, CHAR, DBL, STR} tok;
    union {
        char c;
        int i;
        double d;
        string s;
    };
    void copyUnion(const Token&);
public:
    Token(): tok(INT), i(0) {}
    Token(const Token &t): tok(t.tok) { copyUnion(t); }
    ~Token() { if (tok == STR) s.~string(); }
    Token& operator=(const Token&);
    Token& operator=(char);
    Token& operator=(int);
    Token& operator=(double);
    Token& operator=(const string&);

    Token(Token &&other);
    Token& operator=(Token &&other);
};

Token::Token(Token &&other): tok(INT), i(0)
{
    tok = other.tok;
    i = other.i;
    other.tok = INT;
}

Token& Token::operator=(Token &&other)
{
    if (this != &other)
    {
        tok = other.tok;
        i = other.i;
        other.tok = INT;
        other.i = 0;
    }
    return *this;
}

Token& Token::operator=(int ia)
{
    if (tok == STR) s.~string();
    i = ia;
    tok = INT;
    return *this;
}

Token& Token::operator=(char ca)
{
    if (tok == STR) s.~string();
    c = ca;
    tok = CHAR;
    return *this;
}

Token& Token::operator=(double da)
{
    if (tok == STR) s.~string();
    d = da;
    tok = DBL;
    return *this;
}

Token& Token::operator=(const string &sa)
{
    if (tok == STR) s = sa;
    else new(&s) string(sa);
    tok = STR;
    return *this;
}

void Token::copyUnion(const Token &t)
{
    switch (t.tok)
    {
        case Token::INT: i = t.i; break;
        case Token::CHAR: c = t.c; break;
        case Token::DBL: d = t.d; break;
        case Token::STR: new(&s) string(t.s); break;
    }
    return;
}

Token& Token::operator=(const Token &t)
{
    if (tok == STR && t.tok != STR) s.~string();
    if (tok == STR && t.tok == STR) s = t.s;
    else copyUnion(t);
    tok = t.tok;
    return *this;
}

#endif

