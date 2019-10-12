/*
 @Date    : 2018-01-14 12:19:16
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p706
 */

#include <iostream>

using namespace std;

#ifndef MY_SMART_POINTER_H
#define MY_SMART_POINTER_H

template <typename T> class SP
{
public:
    SP(): p(nullptr), use(nullptr) {}
    explicit SP(T *pt): p(pt), use(new size_t(1)) {}
    SP(const SP &sp): p(sp.p), use(sp.use) { if (use) ++*use; }
    SP& operator=(const SP&);
    ~SP();
    T& operator*() { return *p; }
    T& operator*() const { return *p; }
private:
    T *p;
    size_t *use;
};

template <typename T> SP<T>::~SP()
{
    if (use && --*use == 0)
    {
        delete p;
        delete use;
    }
}

template <typename T> SP<T>& SP<T>::operator=(const SP<T> &rhs)
{
    if (rhs.use)
        ++*rhs.use;
    if (use && --*use == 0)
    {
        delete p;
        delete use;
    }
    p = rhs.p;
    use = rhs.use;
    return *this;
}

template <typename T, class... Args> SP<T> make_SP(Args&&...args)
{
    return SP<T>(new T(forward<Args>(args)...));
}

template <typename T> class UP
{
private:
    T *p;
public:
    UP(): p(nullptr) {}
    UP(const UP&) = delete; // 禁止复制构造函数
    explicit UP(T *pt): p(pt) {}
    UP& operator=(const UP&) = delete; // 禁止拷贝赋值操作符
    ~UP();
    T* release();
    void reset(T* = nullptr);
    T& operator*() { return *p; }
    T& operator*() const { return *p; }
};

template<typename T> UP<T>::~UP()
{
    if (p)
        delete p;
}

template <typename T> void UP<T>::reset(T *new_p)
{
    if (p)
        delete p;
    p = new_p;
    return;
}

template <typename T> T* UP<T>::release()
{
    T *q = p;
    p = nullptr;
    return q;
}

#endif
