/*
 @Date    : 2018-08-27 21:46:37
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805449625288704
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
const int MAXN = 10001;
vector<string> nums;

int main()
{
    scanf("%d", &N);
    nums.resize(N);
    for (int i = 0; i != N; ++i)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), [] (const string &s1, const string &s2)
         {
             return s1 + s2 < s2 + s1;
         });
    bool firstZero = true;
    for (auto &num : nums)
    {
        if (firstZero)
        {
            for (auto &d : num)
            {
                if (firstZero && d != '0')
                    firstZero = false;
                if (!firstZero)
                    cout << d;
            }
        }
        else
        {
            cout << num;
        }
    }
    if (firstZero)
        cout << 0;
    cout << endl;

    return 0;
}

