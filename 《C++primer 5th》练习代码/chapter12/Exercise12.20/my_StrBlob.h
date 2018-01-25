/*
 @Date    : 2017-12-31 15:14:59
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p476
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
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

    // 提供给StrBlobPtr的接口
    StrBlobPtr begin(); // 定义StrBlobPtr后才能定义这两个函数
    StrBlobPtr end();
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

inline StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string>il): data(make_shared<vector<string>>(il)) {}

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
    friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
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
inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
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

inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs, rhs);
}
#endif
