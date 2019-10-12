/*
 @Date    : 2018-01-06 11:31:42
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
在此处添加文件说明
 */

#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H

#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <memory>

using namespace std;
using namespace std::placeholders;

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
    friend bool operator<(const StrBlob&, const StrBlob&);
    friend bool operator<=(const StrBlob&, const StrBlob&);
    friend bool operator>(const StrBlob&, const StrBlob&);
    friend bool operator>=(const StrBlob&, const StrBlob&);
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
public:
    string& operator[] (size_t n) { return (*data)[n]; }
    const string& operator[] (size_t n) const { return (*data)[n]; }
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &t) { data->push_back(t); }
    void push_back(const string &&t) { data->push_back(std::move(t)); }
    void pop_back();
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

    // 提供给StrBlobPtr的接口
    StrBlobPtr begin(); // 定义StrBlobPtr后才能定义这两个函数
    StrBlobPtr end();

    StrBlob(const StrBlob&);
    StrBlob& operator=(const StrBlob&);
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data < *rhs.data;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data <= *rhs.data;
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data > *rhs.data;
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data >= *rhs.data;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return lhs.data == rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return lhs.data != rhs.data;
}

inline StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
inline StrBlob::StrBlob(initializer_list<string>il): data(make_shared<vector<string>>(il)) {}

inline StrBlob::StrBlob(const StrBlob &s): data(make_shared<vector<string>>(*s.data)) {}

inline StrBlob& StrBlob::operator=(const StrBlob &rhs)
{
    data = make_shared<vector<string>>(*rhs.data);
    return *this;
}

inline void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
    {
        throw out_of_range(msg);
    }
    return;
}

inline string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline const string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
    friend StrBlobPtr& operator+(StrBlobPtr&, int);
    friend StrBlobPtr& operator-(StrBlobPtr&, int);
public:
    string& operator*() const;
    string* operator->() const;
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    string& operator[](size_t n);
    const string& operator[](size_t n) const;
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    string& deref() const;
private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

inline string& StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference pas end");
    return (*p)[curr];
}

inline string* StrBlobPtr::operator->() const
{
    return &this->operator*();
}

inline StrBlobPtr& operator+(StrBlobPtr &p, int n)
{
    p.curr += n;
    return p;
}

inline StrBlobPtr& operator-(StrBlobPtr &p, int n)
{
    p.curr -= n;
    return p;
}

inline StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr& StrBlobPtr::operator--()
{
    --curr;
    check(curr, "decrement past end of StrBlobPtr");
    return *this;
}

inline StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

inline StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

inline string& StrBlobPtr::operator[] (size_t n)
{
    auto p = check(n, "dereference pas end");
    return (*p)[n];
}

inline const string& StrBlobPtr::operator[] (size_t n) const
{
    auto p = check(n, "dereference pas end");
    return (*p)[n];
}

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
    {
        throw runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size())
    {
        throw out_of_range(msg);
    }
    return ret;
}

inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

// StrBlobPtr的比较操作
inline bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
    {
        // 若底层的vector是同一个
        // 则两个指针分空并且指向相同元素时，它们相等。
        return (!r || lhs.curr == rhs.curr);
    }
    else
    {
        return false;
    }
}

inline bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
    {
        // 若底层的vector是同一个
        return lhs.curr < rhs.curr;
    }
    else
    {
        return false;
    }
}

inline bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
    {
        // 若底层的vector是同一个
        return lhs.curr > rhs.curr;
    }
    else
    {
        return false;
    }
}

inline bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
    {
        // 若底层的vector是同一个
        return !r || lhs.curr <= rhs.curr;
    }
    else
    {
        return false;
    }
}

inline bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
    {
        // 若底层的vector是同一个
        return !r || lhs.curr >= rhs.curr;
    }
    else
    {
        return false;
    }
}

inline bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

class MyClass
{
public:
    string* operator->() const { return ptr->operator->(); }
private:
    StrBlobPtr *ptr;
};

#endif
