/*
 @Date    : 2017-12-21 16:33:14
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p300
 */

using namespace std;

class Debug
{
public:
    constexpr Debug(bool b = true) : Debug(b, b, b) {}
    constexpr Debug(bool b, bool i, bool o) : hw(b), io(i), other(o) {}
    constexpr bool any() { return hw || io || other;}
    void set_io(bool b) { io = b;}
    void set_hw(bool b) { hw = b;}
    void set_other(bool b) {other = b;}
private:
    bool hw, io, other;
};
