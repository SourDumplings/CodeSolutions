/*
 @Date    : 2018-01-11 17:06:41
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p668
 */

#ifndef MY_BLOB_TEMPLATE_H
#define MY_BLOB_TEMPLATE_H

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>

using namespace std;

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T> bool operator<(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator!=(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob
{
    friend class BlobPtr<T>;
    friend bool operator< <T>(const Blob<T>&, const Blob<T>&);
    friend bool operator<= <T>(const Blob<T>&, const Blob<T>&);
    friend bool operator> <T>(const Blob<T>&, const Blob<T>&);
    friend bool operator>= <T>(const Blob<T>&, const Blob<T>&);
    friend bool operator== <T>(const Blob<T>&, const Blob<T>&);
    friend bool operator!= <T>(const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename vector<T>::size_type size_type;
    Blob();
    Blob(initializer_list<T>);
    template <typename It> Blob(It b, It e): data(make_shared<vector<T>>(b, e)) {}
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { return data->push_back(t); }
    void push_back(T &&t) { return data->push_back(std::move(t)); }
    void pop_back();
    T& back();
    T& operator[](size_type i);
private:
    shared_ptr<vector<T>> data;
    void check(size_type, const string&) const;
};

template <typename T> bool operator<(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return *lhs.data < *rhs.data;
}

template <typename T> bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return *lhs.data <= *rhs.data;
}

template <typename T> bool operator>(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return *lhs.data > *rhs.data;
}

template <typename T> bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return *lhs.data >= *rhs.data;
}

template <typename T> bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return lhs.data == rhs.data;
}

template <typename T> bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return lhs.data != rhs.data;
}

template <typename T> void Blob<T>::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
    return;
}

template <typename T> T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T> void Blob<T>::pop_back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> Blob<T>::Blob():
data(make_shared<vector<T>>()) {}

template <typename T> Blob<T>::Blob(initializer_list<T> il):
data(make_shared<vector<T>>(il)) {}

template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>=(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> class BlobPtr
{
    friend bool operator== <T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator<= <T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator> <T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator>= <T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
    BlobPtr(): curr(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    T& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    BlobPtr& operator++();
    BlobPtr<T>& operator++(int);
    BlobPtr& operator--();
    BlobPtr& operator--(int);
private:
    shared_ptr<vector<T>> check(size_t, const string&) const;
    weak_ptr<vector<T>> wptr;
    size_t curr;
};

template <typename T> inline bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
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

template <typename T> inline bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
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

template <typename T> inline bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
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

template <typename T> inline bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
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

template <typename T> inline bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
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

template <typename T> inline bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs == rhs);
}

template<typename T> shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
    {
        throw runtime_error("unbound BlobPtr");
    }
    if (i >= ret->size())
    {
        throw out_of_range(msg);
    }
    return ret;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator++()
{
    ++curr;
    check(curr, "incremenet out of range");
    return *this;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator--()
{
    --curr;
    check(curr, "decremenet out of range");
    return *this;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}

#endif


