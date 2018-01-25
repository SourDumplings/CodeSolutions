/*
 @Date    : 2018-01-04 20:59:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p562
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
public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    string& deref() const;
    StrBlobPtr& incr();
    StrBlobPtr& decr();
private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};



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

inline string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference pas end");
    return (*p)[curr];
}

inline StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr& StrBlobPtr::decr()
{
    --curr;
    check(curr, "decrement past end of StrBlobPtr");
    return *this;
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
#endif
