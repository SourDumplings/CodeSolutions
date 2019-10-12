/*
 @Date    : 2018-01-11 11:44:42
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p658
 */

#include <iostream>
#include <vector>
#include <array>

using namespace std;

template <typename T, size_t N> const T* my_begin(const T (&a)[N])
{
    return &a[0];
}

template <typename T, size_t N> const T* my_end(const T (&a)[N])
{
    return &a[0] + N;
}

int main(int argc, char const *argv[])
{
    int a1[10] = {1, 2, 3};
    array<int, 10> a2{{4, 5, 6}};
    vector<int> v1{7, 8, 9};

    for (auto it = my_begin(a1); it != my_end(a1); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // for (auto it = my_begin(a2); it != my_end(a2); ++it)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;
    for (auto it = begin(a2); it != end(a2); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    //
    //
    // for (auto it = my_begin(v1); it != my_end(v1); ++it)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;
    for (auto it = begin(v1); it != end(v1); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
