/*
 @Date    : 2018-01-07 15:15:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/4w5
 */

#include <iostream>
#include <cstring>
using namespace std;

class Array2
{
public:
    Array2() {}
    Array2(int row, int col): r(row), c(col) { p = new int[r*c]; }
    ~Array2() { if (p) delete [] p; }
    Array2& operator=(const Array2 &t)
    {
        if (p) delete [] p;
        r = t.r;
        c = t.c;
        p = new int[r*c];
        memcpy(p, t.p, r*c*sizeof(int));
        return *this;
    }
    int& operator()(int i, int j) { return p[i*c + j]; }
    int* operator[] (int i) { return p + i*c; }
private:
    int *p = nullptr;
    int r, c;
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
