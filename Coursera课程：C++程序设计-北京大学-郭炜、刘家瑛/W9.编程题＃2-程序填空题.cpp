/*
 @Date    : 2018-02-10 12:34:18
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/9w7
 */

#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码

template <typename T>
class CMyistream_iterator
{
private:
    T data;
    istream &is;
public:
    CMyistream_iterator(istream &is_): is(is_) { is >> data; }
    T& operator*() { return data; }
    void operator++(int) { is >> data; return; }
};

int main()
{
    CMyistream_iterator<int> inputInt(cin);
    int n1,n2,n3;
    n1 = * inputInt; //读入 n1
    int tmp = * inputInt;
    cout << tmp << endl;
    inputInt ++;
    n2 = * inputInt; //读入 n2
    inputInt ++;
    n3 = * inputInt; //读入 n3
    cout << n1 << "," << n2<< "," << n3 << endl;
    CMyistream_iterator<string> inputStr(cin);
    string s1,s2;
    s1 = * inputStr;
    inputStr ++;
    s2 = * inputStr;
    cout << s1 << "," << s2 << endl;
    return 0;
}
