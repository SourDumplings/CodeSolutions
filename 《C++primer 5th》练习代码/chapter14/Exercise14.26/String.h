/*
 @Date    : 2018-01-05 16:32:15
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p566
 */

#include <iostream>
#include <algorithm>
#include <utility>
#include <memory>
#include <cstring>

using namespace std;

class String
{
    friend ostream& operator<<(ostream&, const String&);
    friend bool operator==(const String&, const String&);
    friend bool operator<(const String&, const String&);
public:
    char& operator[](size_t n) { return data[n]; }
    const char& operator[](size_t n) const { return data[n]; }
    String(): String("") {}
    String(const char *);
    ~String() { free(); };
    size_t size() { return eos - data; }
    size_t size() const { return eos - data; }
    String(const String&);
    String& operator=(const String&);
    String& operator=(const char*);
    char* begin() { return data; }
    char* end() { return eos; }
    char* begin() const { return data; }
    char* end() const { return eos; }
private:
    char *data;
    char *eos;
    static allocator<char> alloc;
    void free();
};

allocator<char> String::alloc;

bool operator==(const String &lhs, const String &rhs)
{
    return equal(lhs.data, lhs.eos, rhs.data);
}

bool operator<(const String &lhs, const String &rhs)
{
    return strcmp(lhs.data, rhs.data) < 0;
}

bool operator<=(const String &lhs, const String &rhs)
{
    return lhs < rhs || lhs == rhs;
}

bool operator>(const String &lhs, const String &rhs)
{
    return !(lhs <= rhs);
}

bool operator>=(const String &lhs, const String &rhs)
{
    return !(lhs < rhs);
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

ostream& operator<<(ostream &os, const String &s)
{
    for (auto pc = s.data; pc != s.eos; ++pc)
        os << *pc;
    return os;
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
