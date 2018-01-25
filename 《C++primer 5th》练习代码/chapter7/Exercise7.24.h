/*
 @Date    : 2017-12-20 19:28:26
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p275
 */


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
    Screen& move(pos r, pos c);
private:
    pos cursor = 0, height = 0, width = 0;
    string contents;
};

inline
Screen& Screen::move(pos r, pos c)
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

