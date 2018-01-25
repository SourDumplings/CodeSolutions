/*
 @Date    : 2018-01-08 20:39:12
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p616
 */

#include <iostream>

using namespace std;

class Base
{
private:
    char priv_mem;
protected:
    int prot_mem;
public:
    void pub_mem();
};

class Pub_Derive: public Base
{
public:
    int f() { return prot_mem; }
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Pub_Derive" << endl;
    }
};

class Priv_Derive: private Base
{
public:
    int f() { return prot_mem; }
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Priv_Derive" << endl;
    }
};

class Prot_Derive: protected Base
{
public:
    int f() { return prot_mem; }
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Prot_Derive" << endl;
    }
};

struct Derived_form_Public: public Pub_Derive
{
    int use_base() { return prot_mem; }
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Derived_form_Public" << endl;
    }
};

struct Derived_form_Protected: public Prot_Derive
{
    int use_base() { return prot_mem; }
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Derived_form_Protected" << endl;
    }
};

// struct Derived_form_Private: public Priv_Derive
// {
//     int use_base() { return prot_mem; }
//     void memfcn(Base &b)
//     {
//         b = *this;
//         cout << "Derived_form_Private" << endl;
//     }
// };

int main(int argc, char const *argv[])
{
    Pub_Derive d1;
    Priv_Derive d2;
    Prot_Derive d3;
    Derived_form_Public dd1;
    // Derived_form_Private dd2;
    Derived_form_Protected dd3;
    Base base;
    Base *p = new Base;
    p = &d1;
    // p = &d2;
    // p = &d3;

    d1.memfcn(base);
    d2.memfcn(base);
    d3.memfcn(base);
    dd1.memfcn(base);
    // dd2.memfcn(base);
    dd3.memfcn(base);

    delete p;

    return 0;
}
