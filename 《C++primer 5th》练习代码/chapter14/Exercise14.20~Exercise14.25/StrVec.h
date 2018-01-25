/*
 @Date    : 2018-01-04 16:26:03
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p544
 */

#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
#include <algorithm>

using namespace std;

class StrVec
{
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
public:
    using size_type = unsigned;
    StrVec& operator=(const initializer_list<string>&);
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec(const initializer_list<string>&);
    StrVec(StrVec &&s) noexcept;
    StrVec& operator=(const StrVec&);
    StrVec& operator=(StrVec&&) noexcept;
    ~StrVec() { free(); };
    void push_back(const string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }
    void reserve(size_t n) { if (n > capacity()) reallocate(n); }
    void resize(size_t);
    void resize(size_t, string&);
private:
    static allocator<string> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    void reallocate(size_t&);
    string *elements;
    string *first_free;
    string *cap;
};

allocator<string> StrVec::alloc;

inline StrVec& StrVec::operator=(const initializer_list<string> &il)
{
    free();
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = newdata.second;
    return *this;
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
    string *p1, *p2;
    for (p1 = lhs.begin(), p2 = rhs.begin(); p1 != lhs.end() && p2 != rhs.end();
        ++p1, ++p2)
    {
        if (*p1 < *p2)
            return true;
        else if (*p1 > *p2)
            return false;
    }
    if (p1 == lhs.end() && p2 != rhs.end())
        return true;
    return false;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
    return equal(lhs.elements, lhs.first_free, rhs.elements);
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs == rhs);
}

StrVec::StrVec(StrVec &&s) noexcept:
elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

inline void StrVec::resize(size_t n)
{
    if (n > size())
    {
        while (size() < n)
            push_back("");
    }
    else if (n < size())
    {
        for (auto p = elements + n; p != first_free; ++p)
        {
            alloc.destroy(p);
        }
        alloc.deallocate(elements+n, first_free-elements-n);
        first_free = elements + n;
    }
    return;
}

inline void StrVec::resize(size_t n, string &s)
{
    if (n > size())
    {
        while (size() < n)
            push_back(s);
    }
    else if (n < size())
    {
        for (auto p = elements + n; p != first_free; ++p)
        {
            alloc.destroy(p);
        }
        alloc.deallocate(elements+n, first_free-elements-n);
        first_free = elements + n;
    }
    return;
}


inline void StrVec::reallocate(size_t &n)
{
    auto newdata = alloc.allocate(n);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + n;
    return;
}

inline StrVec::StrVec(const initializer_list<string> &il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = newdata.second;
}

inline void StrVec::push_back(const string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
    return;
}

inline pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e-b);
    return {data, uninitialized_copy(b, e, data)};
}

inline void StrVec::free()
{
    if (elements)
    {
        for_each(elements, first_free, [] (string &s) { alloc.destroy(&s); });
        alloc.deallocate(elements, cap-elements);
    }
    return;
}

inline StrVec::StrVec(const StrVec& s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = newdata.second;
}

inline StrVec& StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

inline void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
    return;
}

#endif
