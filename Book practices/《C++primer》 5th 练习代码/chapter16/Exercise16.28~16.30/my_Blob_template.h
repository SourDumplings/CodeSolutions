/*
 @Date    : 2018-01-12 16:38:48
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p678
 */

#ifndef MY_BLOB_TEMPLATE_H
#define MY_BLOB_TEMPLATE_H

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include "my_Smart_Pointer.h"

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
    template <typename It> Blob(It b, It e): data(make_SP<vector<T>>(b, e)) {}
    size_type size() const { return (*data).size(); }
    bool empty() const { return (*data).empty(); }
    void push_back(const T &t) { return (*data).push_back(t); }
    void push_back(T &&t) { return (*data).push_back(std::move(t)); }
    void pop_back();
    T& back();
    T& operator[](size_type i);
private:
    SP<vector<T>> data;
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
    if (i >= (*data).size())
        throw out_of_range(msg);
    return;
}

template <typename T> T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return (*data).back();
}

template <typename T> T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T> void Blob<T>::pop_back()
{
    check(0, "back on empty Blob");
    return (*data).back();
}

template <typename T> Blob<T>::Blob():
data(make_SP<vector<T>>()) {}

template <typename T> Blob<T>::Blob(initializer_list<T> il):
data(make_SP<vector<T>>(il)) {}

#endif
