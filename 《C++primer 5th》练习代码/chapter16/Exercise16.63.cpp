/*
 @Date    : 2018-01-14 17:29:16
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p712
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
int occur(vector<T> &vec, const T &v)
{
    int ret = 0;
    for (auto a : vec)
    {
        if (a == v)
            ++ret;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    vector<double> vd{1.1, 3.14, 2.2, 3.14, 3.3, 4.4};
    cout << occur(vd, 3.14) << endl;

    vector<int> vi{0, 1, 2, 3, 4, 0, 5, 0};
    cout << occur(vi, 0) << endl;

    vector<string> vs{"Hello", "World", "!"};
    cout << occur(vs, string("end")) << endl;

    vector<char*> vp;
    vp.push_back(new char[6]);
    vp.push_back(new char[6]);
    vp.push_back(new char[6]);
    vp.push_back(new char[2]);
    strcpy(vp[0], "Hello");
    strcpy(vp[1], "World");
    strcpy(vp[2], "Hello");
    strcpy(vp[3], "!");
    char *h = new char[6];
    char *w = new char[6];
    strcpy(h, "Hello");
    strcpy(w, "World");
    cout << occur(vp, h) << endl;
    cout << occur(vp, w) << endl;

    delete h;
    delete w;
    delete vp[0];
    delete vp[1];
    delete vp[2];
    delete vp[3];

    return 0;
}
