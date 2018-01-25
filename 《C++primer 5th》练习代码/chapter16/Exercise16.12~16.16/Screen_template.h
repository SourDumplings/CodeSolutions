/*
 @Date    : 2018-01-11 20:17:36
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p668
 */

#ifndef SCREEN_TEMPLATE_H
#define SCREEN_TEMPLATE_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <int H, int W> class Screen;
template <int H, int W> istream& operator>>(istream&, Screen<H, W>&);
template <int H, int W> ostream& operator<<(ostream&, const Screen<H, W>&);

template <int H, int W> class Screen
{
    friend class Window_mgr;
    friend istream& operator>> <H, W>(istream&, Screen<H, W>&);
    friend ostream& operator<< <H, W>(ostream&, const Screen<H, W>&);
private:
    static const char bkground;
    void do_display(ostream &) const;
    int cursor = 0;
    string contents;
public:
    Screen(): contents(H*W, ' ') {}
    Screen(char c): contents(H*W, c) {}
    char get() const { return contents[cursor]; }
    char get(int, int) const;
    Screen& clear(char = bkground);
    Screen& move(int, int);
    Screen& set(char);
    Screen& set(int, int, char);
    Screen& display(ostream &os) { do_display(os); return *this; }
    const Screen& display(ostream &os) const { do_display(os); return *this; }
};

template <int H, int W> const char Screen<H, W>::bkground = ' ';

template <int H, int W> istream& operator>>(istream &is, Screen<H, W> &s)
{
    string t;
    is >> t;
    if (t.size() > H * W)
        // s.contents = t.substr(0, H*W);
        copy_n(t.begin(), H*W, s.contents.begin());
    else
        copy(t.begin(), t.end(), s.contents.begin());
        fill(s.contents.begin()+t.size(), s.contents.end(), Screen<H, W>::bkground);
    return is;
}

template <int H, int W> ostream& operator<<(ostream &os, const Screen<H, W> &s)
{
    os << s.contents;
    return os;
}

template <int H, int W> void Screen<H, W>::do_display(ostream &os) const
{
    for (int r = 0; r != H; ++r)
    {
        for (int c = 0; c != W; ++c)
            cout << contents[r*W+c] << " ";
        cout << endl;
    }
    return;
}

template <int H, int W> Screen<H, W>& Screen<H, W>::clear(char c)
{
    contents = string(H*W, c);
    return *this;
}

template <int H, int W> inline Screen<H, W>& Screen<H, W>::move(int r, int c)
{
    int row = r * W;
    cursor = row + c;
    return *this;
}

template <int H, int W> inline Screen<H, W>& Screen<H, W>::set(char c)
{
    contents[cursor] = c;
    return *this;
}

template <int H, int W> inline Screen<H, W>& Screen<H, W>::set(int r, int col, char c)
{
    contents[r*W + col] = c;
    return *this;
}

#endif
