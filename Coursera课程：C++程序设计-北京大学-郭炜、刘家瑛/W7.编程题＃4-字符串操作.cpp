/*
 @Date    : 2018-01-28 21:42:43
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/U/
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<string> strGiven; // 存储给的数据字符串
queue<string> strOrder; // 存储命令字符串

void strAnalyze(const string &orderLine)
{
    string order;
    for (char c : orderLine)
    {
        if (c != ' ')
            order.push_back(c);
        else
        {
            strOrder.push(order);
            order.clear();
        }
    }
    // 记录最后一个字符串
    strOrder.push(order);
    return;
}

string myCopy(int n, int x, int l)
{
    return strGiven[n-1].substr(x, l);
}

string myAdd(const string &s1, const string &s2)
{
    //判断字符串里是否全为数字
    //因为83s经过atoi后会变为83
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1.at(i) < '0' || s1.at(i) > '9')
        {
            return s1 + s2;
        }
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2.at(i) < '0' || s2.at(i) > '9')
        {
            return s1 + s2;
        }
    }
    //若全为数字，判断是否在0和99999之间
    long a = stol(s1);
    long b = stol(s2);
    if (a >= 0 && a <= 99999 && b >= 0 && b <= 99999)
    {
        return to_string(a+b);
    }
    else
    {
        return s1 + s2;
    }
}

int myFind(const string &s, int n)
{
    int result = strGiven[n-1].find(s);
    if (result == string::npos)
        result = s.length();
    return result;
}

int myRFind(const string &s, int n)
{
    int result = strGiven[n-1].rfind(s);
    if (result == string::npos)
        result = s.length();
    return result;
}

// 递归算法处理一行中的命令
string orderOp()
{
    string order = strOrder.front();
    strOrder.pop();
    string result;
    if (order == "copy")
    {
        int n = stoi(orderOp());
        int x = stoi(orderOp());
        int l = stoi(orderOp());
        result = myCopy(n, x, l);
    }
    else if (order == "add")
    {
        string s1 = orderOp();
        string s2 = orderOp();
        result = myAdd(s1, s2);
    }
    else if (order == "find")
    {
        string s = orderOp();
        int n = stoi(orderOp());
        result = to_string(myFind(s, n));
    }
    else if (order == "rfind")
    {
        string s = orderOp();
        int n = stoi(orderOp());
        result = to_string(myRFind(s, n));
    }
    else
    {
        // 参数
        result = order;
    }
    return result;
}

void myInsert(const string &s, int n, int x)
{
    strGiven[n-1].insert(x, s);
    return;
}

void myReset(const string &s, int n)
{
    strGiven[n-1] = s;
    return;
}

void myPrint(int n)
{
    cout << strGiven[n-1] << endl;
    return;
}

void myPrintAll()
{
    for (const auto &s : strGiven)
        cout << s << endl;
}

// 开始处理一行命令，注意开头的命令只可能是“insert”“reset”“print”“printall”和“over”
// 遇到"over"时返回false，程序结束
bool strProcess()
{
    string order = strOrder.front();
    strOrder.pop();
    if (order == "insert")
    {
        string s = orderOp();
        int n = stoi(orderOp());
        int x = stoi(orderOp());
        myInsert(s, n, x);
    }
    else if (order == "reset")
    {
        string s = orderOp();
        int n = stoi(orderOp());
        myReset(s, n);
    }
    else if (order == "print")
    {
        int n = stoi(orderOp());
        myPrint(n);
    }
    else if (order == "printall")
    {
        myPrintAll();
    }
    else if (order == "over")
    {
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    string s;
    for (int i = 0; i != n; ++i)
    {
        cin >> s;
        strGiven.push_back(s);
    }
    cin.get();

    string orderLine;
    while (getline(cin, orderLine))
    {
        // 将输入的一行数据分为若干个命令参数，并存入队列当中
        strAnalyze(orderLine);
        // 开始处理一行命令，注意开头的命令只可能是“insert”“reset”“print”“printall”和“over”
        // 遇到"over"时返回false，程序结束
        if (!strProcess())
            break;
    }
    return 0;
}

