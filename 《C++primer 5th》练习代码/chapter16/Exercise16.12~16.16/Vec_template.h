/*
 @Date    : 2018-01-11 21:25:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p668
 */

#ifndef VEC_TEMPLATE_H
#define VEC_TEMPLATE_H

#include <memory>
#include <utility>
#include <initializer_list>

using namespace std;

template <typename T> class Vec
{
public:
    using size_type = unsigned;
    Vec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(const Vec<T>&);
    Vec(const initializer_list<T>&);
    Vec& operator=(const Vec<T>&);
    ~Vec() { free(); };
    void push_back(const T&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T* begin() const { return elements; }
    T* end() const { return first_free; }
    void reserve(size_t n) { if (n > capacity()) reallocate(n); }
    void resize(size_t);
    void resize(size_t, T&);
private:
    static allocator<T> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();
    void reallocate(size_t&);
    T *elements;
    T *first_free;
    T *cap;
};

template <typename T> allocator<T> Vec<T>::alloc;

template <typename T> inline void Vec<T>::resize(size_t n)
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

template <typename T> inline void Vec<T>::resize(size_t n, T &s)
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


template <typename T> inline void Vec<T>::reallocate(size_t &n)
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

template <typename T> inline Vec<T>::Vec(const initializer_list<T> &il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = newdata.second;
}

template <typename T> inline void Vec<T>::push_back(const T& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
    return;
}

template <typename T> inline pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
    auto data = alloc.allocate(e-b);
    return {data, uninitialized_copy(b, e, data)};
}

template <typename T> inline void Vec<T>::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap-elements);
    }
    return;
}

template <typename T> inline Vec<T>::Vec(const Vec& s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = newdata.second;
}

template <typename T> inline Vec<T>& Vec<T>::operator=(const Vec<T> &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T> inline void Vec<T>::reallocate()
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
