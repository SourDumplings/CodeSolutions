/*
 @Date    : 2017-12-18 09:25:32
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p198
如果没有catch，则无法编译：
Exercise5.25.cpp: In function 'int main()':
Exercise5.25.cpp:45:9: error: expected 'catch' before 'cout'
         cout << "The result is " << a / b << endl;
         ^
Exercise5.25.cpp:45:9: error: expected '(' before 'cout'
Exercise5.25.cpp:45:9: error: 'cout' does not name a type
Exercise5.25.cpp:45:14: error: expected ')' before '<<' token
         cout << "The result is " << a / b << endl;
              ^
Exercise5.25.cpp:45:14: error: expected '{' before '<<' token
Exercise5.25.cpp:45:14: error: expected primary-expression before '<<' token
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

int main()
{
    cout << "Please input a and b that are for a/b: " << endl;
    int a, b;
    while (cin >> a >> b)
    {
        try
        {
            if (b == 0)
            {
                throw runtime_error("b cannot be zero.");
            }
        }
        catch (runtime_error err)
        {
            cout << err.what() << endl;
            cout << "continue? (y/n)";
            char ch;
            cin >> ch;
            if (ch != 'y' && ch != 'Y')
            {
                break;
            }
        }
        cout << "The result is " << a / b << endl;
    }
    return 0;
}

