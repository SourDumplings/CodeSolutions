/*
 @Date    : 2018-02-12 22:25:19
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
输入

无

输出

1. abcd-efgh-abcd-

2. abcd-

3.

4. abcd-efgh-

5. efgh-

6. c

7. abcd-

8. ijAl-

9. ijAl-mnop

10. qrst-abcd-

11. abcd-qrst-abcd- uvw xyz

about

big

me

take

abcd

qrst-abcd-
 */

#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
// 在此处补充你的代码

class MyString
{
    friend MyString operator+(const MyString &lhs, const MyString &rhs);
    friend ostream& operator<<(ostream &os, const MyString &ms);
private:
    string data;
public:
    MyString() = default;
    MyString(const string &s): data(s) {}
    MyString(const char *s): data(s) {}
    MyString(const MyString &ms): data(ms.data) {}
    bool operator==(const MyString &ms) { return data == ms.data; }
    bool operator<(const MyString &ms) { return data < ms.data; }
    bool operator>(const MyString &ms) { return data > ms.data; }
    MyString& operator+=(const string &rhs)
    {
        data += rhs;
        return *this;
    }
    char& operator[](int i) { return data[i]; }
    MyString& operator=(const char *rhs) { data = rhs; return *this; }
    string operator()(int i, int j) { return data.substr(i, j); }
};

MyString operator+(const MyString &lhs, const MyString &rhs)
{ return lhs.data + rhs.data; }

ostream& operator<<(ostream &os, const MyString &ms)
{ os << ms.data; return os; }

int CompareString( const void * e1, const void * e2)
{
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if ( * s1 < *s2 )
        return -1;
    else if ( *s1 == *s2)
        return 0;
    else if ( *s1 > *s2 )
        return 1;
}
int main()
{
    MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
    MyString SArray[4] = {"big", "me", "about", "take"};
    cout << "1. " << s1 << s2 << s3 << s4 << endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray, 4, sizeof(MyString), CompareString);
    for ( int i = 0; i < 4; i ++ )
        cout << SArray[i] << endl;
    //s1的从下标0开始长度为4的子串
    cout << s1(0, 4) << endl;
    //s1的从下标5开始长度为10的子串
    cout << s1(5, 10) << endl;
    return 0;
}
