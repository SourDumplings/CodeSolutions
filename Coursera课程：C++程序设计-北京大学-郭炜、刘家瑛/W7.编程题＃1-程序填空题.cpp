/*
 @Date    : 2018-01-28 19:50:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/7w6/
 */

#include <iostream>
using namespace std;
// 在此处补充你的代码


template<typename T>
class CArray3D
{
private:
    class CArray2D
    {
    private:
        T* data2;
        int c;
    public:
        CArray2D(int b, int c): c(c)
        {
            data2 = new T[b*c];
        }
        ~CArray2D() { delete [] data2; }
        T* operator[](int j) { return data2 + j * c; }
    };
    CArray2D **data3;
public:
    CArray3D(int a, int b, int c)
    {
        data3 = new CArray2D*[a];
        for (int i = 0; i != a; ++i)
            data3[i] = new CArray2D(b, c);
    }
    ~CArray3D() { delete [] data3; }
    CArray2D& operator[](int i) { return *data3[i]; }
};

int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}
