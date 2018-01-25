/*
 @Date    : 2017-12-20 19:28:26
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p278
 */

#include <iostream>
#include <string>

using namespace std;

class Screen
{
public:
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {}
    char get() const {return contents[cursor];}
    inline char get(pos ht, pos wd) const;
    Screen move(pos r, pos c);
    Screen set(char);
    Screen set(pos, pos, char);
    const Screen& display(ostream &os) const {os << contents; return *this;}
private:
    pos cursor = 0, height = 0, width = 0;
    string contents;
};

inline
Screen Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row+c];
}
Screen Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
Screen Screen::set(pos r, pos col, char c)
{
    contents[r*width + col] = c;
    return *this;
}

