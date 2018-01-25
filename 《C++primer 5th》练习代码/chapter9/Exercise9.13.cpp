/*
 @Date    : 2017-12-23 16:47:20
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p337
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    list<int> il = {1, 2, 3, 4, 5, 6, 7};
    vector<int> iv = {7, 6, 5, 4, 3, 2, 1};
    // vector <double> dv1(il);
    vector <double> dv2(il.begin(), il.end());
    vector <double> dv4(iv.begin()+2, iv.end()-1);
    // vector<double> dv3(iv);

    cout << dv2.size() << " " << dv2[0] << " " << dv2[dv2.size()-1] << endl;
    cout << dv4.size() << " " << dv4[0] << " " << dv4[dv4.size()-1] << endl;

    return 0;
}
