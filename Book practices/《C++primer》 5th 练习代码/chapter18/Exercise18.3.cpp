/*
 @Date    : 2018-01-19 11:41:11
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p775
 */

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 方法一：
void exercise(int *b, int *e)
{
    vector<int> v(b, e);
    int *p = new int[v.size()];
    try
    {
        ifstream in("int");
        // 此处发生异常
    }
    catch ()
    {
        delete p;
    }
}

// 方法二：
class Resourse
{
private:
    int *r;
public:
    Resourse(size_t sz) : r(new int[sz]) {}
    ~Resourse() { if(r) delete r; }
};

void exercise2(int *b, int *e)
{
    vector<int> v(b, e);
    Resourse res(v.size());
    ifstream in("ints");
    // 异常发生在此
}
