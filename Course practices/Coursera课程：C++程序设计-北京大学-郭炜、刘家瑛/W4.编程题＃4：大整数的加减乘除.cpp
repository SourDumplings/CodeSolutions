/*
 @Date    : 2018-03-09 09:48:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/D/
 */

#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>

using namespace std;

static const int MAXN = 201;

class Num
{
private:
    int length, a[MAXN];
    bool neg;
public:
    Num();
    int& operator[](const int i);
    int operator[](const int i) const;
    bool operator<(const Num &b) const;
    Num operator+(const Num &b) const;
    Num operator-(const Num &b) const;
    Num operator*(const int &b) const;
    Num operator<<(const int &shift) const;
    Num operator*(const Num &b) const;
    Num operator/(const Num &b) const;
    void init();
    void print();
};

Num::Num()
{
    memset(a, 0, sizeof(a));
    length = 0;
    neg = false;
}

int& Num::operator[](const int i)
{
    assert(i >= 0 && i < MAXN);
    return a[i];
}

int Num::operator[](const int i) const
{
    assert(i >= 0 && i < MAXN);
    return a[i];
}

bool Num::operator<(const Num &b) const
{
    if (length == b.length)
    {
        for (int i = length - 1; i > -1; --i)
        {
            if (a[i] != b[i])
                return a[i] < b[i];
        }
        return false;
    }
    else
        return length < b.length;
}

Num Num::operator+(const Num &b) const
{
    Num c;
    int t = 0;
    for (int i = 0; i < length || i < b.length || t; ++i)
    {
        int s = a[i] + b[i] + t;
        c[i] = s % 10;
        t = s / 10;
        ++c.length;
    }
    return c;
}

Num Num::operator-(const Num &b) const
{
    Num c;
    if (*this < b)
    {
        c = b - *this;
        c.neg = true;
        return c;
    }
    int t = 0;
    for (int i = 0; i != length; ++i)
    {
        int s = a[i] - b[i] - t;
        if (s < 0)
        {
            t = 1;
            s += 10;
        }
        else
            t = 0;
        c[i] = s;
        ++c.length;
    }
    for (; c.length > 0 && c[c.length-1] == 0; --c.length);
    return c;
}

Num Num::operator*(const int &b) const
{
    Num c;
    int t = 0;
    for (int i = 0; i < length || t; ++i)
    {
        int s = a[i] * b + t;
        c[i] = s % 10;
        t = s / 10;
        ++c.length;
    }
    return c;
}

Num Num::operator<<(const int &shift) const
{
    Num c;
    for (int i = 0; i != length; ++i)
        c[i+shift] = a[i];
    c.length = length + shift;
    return c;
}

Num Num::operator*(const Num &b) const
{
    Num c;
    for (int i = 0; i != b.length; ++i)
        c = c + ((*this * b[i]) << i);
    return c;
}

Num Num::operator/(const Num &b) const
{
    assert(b.length > 0);
    Num c, tempA = *this;
    c.length = length - b.length + 1;
    for (int i = length - b.length; i > -1; --i)
    {
        Num d = b << i;
        for (; !(tempA < d); ++c[i], tempA = tempA - d);
    }
    for (; c.length > 0 && c[c.length-1] == 0; --c.length);
    return c;
}

void Num::init()
{
    char c[MAXN+1];
    scanf("%s", c);
    int l = strlen(c);
    length = l;
    for (int i = 0; c[i] != '\0'; ++i)
        a[length - i - 1] = c[i] - '0';
    return;
}

void Num::print()
{
    if (length == 0)
    {
        printf("0\n");
        return;
    }
    if (neg) putchar('-');
    for (int i = length - 1; i > -1; --i)
        printf("%d", a[i]);
    putchar('\n');
    return;
}

int main(int argc, char const *argv[])
{
    Num a, b;
    char c;
    a.init();
    getchar();
    scanf("%c", &c);
    b.init();
    Num res;
    switch (c)
    {
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a * b; break;
        case '/': res = a / b; break;
    }
    res.print();
    return 0;
}

