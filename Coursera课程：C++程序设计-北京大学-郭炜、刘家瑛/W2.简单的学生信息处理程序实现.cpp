/*
 @Date    : 2017-12-13 20:48:46
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://cxsjsxmooc.openjudge.cn/test/C/
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Student
{
    char sname[100];
    int sage, sid, sg1, sg2, sg3, sg4;
public:
    void ReadData(char *name, int age, int id, int g1, int g2, int g3, int g4);
    void PrintData(void);
};

void Student :: ReadData(char *name, int age, int id, int g1, int g2, int g3, int g4)
{
    strcpy(sname, name);
    sage = age;
    sid = id;
    sg1 = g1;
    sg2 = g2;
    sg3 = g3;
    sg4 = g4;
    return;
}

void Student :: PrintData(void)
{
    int avg = (sg1 + sg2 + sg3 + sg4) / 4;
    cout << sname << "," << sage << "," << sid << "," << avg << endl;
    return;
}

int main()
{
    Student S;
    char name[100];
    int age, id, g1, g2, g3, g4;
    cin.getline(name, 100, ',');
    scanf("%d,%d,%d,%d,%d,%d", &age, &id, &g1, &g2, &g3, &g4);
    S.ReadData(name, age, id, g1, g2, g3, g4);
    S.PrintData();
    return 0;
}

