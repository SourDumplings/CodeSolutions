/*
 @Date    : 2018-04-13 09:59:52
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.cnblogs.com/codingmengmeng/p/5913068.html
 */

#include <iostream>
#include <windows.h>
using namespace std;

DWORD WINAPI Fun(LPVOID lpParamter)
{
    for (int i = 0; i < 10; i++)
        cout << "A Thread Fun Display!" << endl;
    return 0L;
}

int main()
{
    HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
    CloseHandle(hThread);
    for (int i = 0; i < 10; i++)
        cout << "Main Thread Display!" << endl;
    return 0;
}
