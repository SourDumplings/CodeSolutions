/*
 @Date    : 2018-01-04 16:35:54
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p544
 */

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <algorithm>
#include <utility>
#include <memory>
#include <cstring>

using namespace std;

class String
{
public:
    String(): String("") {}
    String(const char *);
    ~String() { free(); };
    size_t size() { return eos - data; }
    size_t size() const { return eos - data; }
    void getStr(ostream&);
    String(const String&);
    String(String&&);
    String& operator=(const String&);
    String& operator=(String&&);
    String& operator=(const char*);
    char*& begin() { return data; }
    char*& end() { return eos; }
    char* begin() const { return data; }
    char* end() const { return eos; }
private:
    char *data;
    char *eos;
    static allocator<char> alloc;
    void free();
};

allocator<char> String::alloc;

String::String(String &&s): data(s.begin()), eos(s.end())
{
    s.begin() = s.end() = nullptr;
}

String& String::operator=(String &&rhs)
{
    if (&rhs != this)
    {
        free();
        data = rhs.begin();
        eos = rhs.end();
        rhs.begin() = rhs.end() = nullptr;
    }
    return *this;
}

String::String(const String &s)
{
    size_t l = s.size();
    data = alloc.allocate(l);
    eos = data + l;
    uninitialized_copy(s.begin(), s.end(), data);
}

String& String::operator=(const String &s)
{
    size_t l = s.size();
    auto newdata = alloc.allocate(l);
    free();
    data = newdata;
    eos = newdata + l;
    uninitialized_copy(s.begin(), s.end(), data);
    return *this;
}

String& String::operator=(const char *s)
{
    size_t l = strlen(s);
    auto newdata = alloc.allocate(l);
    free();
    data = newdata;
    eos = newdata + l;
    auto p = data;
    for (size_t i = 0; s[i] != '\0'; ++i)
    {
        alloc.construct(p++, s[i]);
    }
    return *this;
}

void String::getStr(ostream &os)
{
    for (auto p = data; p != eos; ++p)
        os << *p;
    return;
}

String::String(const char *s)
{
    size_t l = strlen(s);
    // printf("%u\n", l);
    char* ucs = const_cast<char*>(s);
    data = alloc.allocate(l);
    eos = data + l;
    for_each(data, eos, [ucs] (char &c) mutable { alloc.construct(&c, *ucs++); });
}

void String::free()
{
    for_each(data, eos, [] (char c) {alloc.destroy(&c); });
    alloc.deallocate(data, eos - data);
    return;
}

#endif
