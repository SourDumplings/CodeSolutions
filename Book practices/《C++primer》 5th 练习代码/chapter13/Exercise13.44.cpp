/*
 @Date    : 2018-01-03 21:08:09
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p531
 */

#include <iostream>
#include <algorithm>
#include <utility>
#include <memory>
#include <cstring>

using namespace std;
using namespace std::placeholders;

class String
{
public:
    String(): String("") {}
    String(const char *);
    ~String();
    size_t size() { return end - begin; }
    void getStr() { for_each(begin, end, [] (const char &c) { cout << c; });}
private:
    char *begin;
    char *end;
    static allocator<char> alloc;
};

allocator<char> String::alloc;

String::String(const char *s)
{
    size_t l = strlen(s);
    // printf("%u\n", l);
    char* ucs = const_cast<char*>(s);
    begin = alloc.allocate(l);
    end = begin + l;
    for_each(begin, end, [ucs] (char &c) mutable { alloc.construct(&c, *ucs++); });
}

String::~String()
{
    for_each(begin, end, [] (char c) {alloc.destroy(&c); });
    alloc.deallocate(begin, end-begin);
}

int main(int argc, char const *argv[])
{
    String s2("abc");
    String s1;
    s1.getStr();
    cout << endl;
    s2.getStr();
    cout << endl;
    return 0;
}
