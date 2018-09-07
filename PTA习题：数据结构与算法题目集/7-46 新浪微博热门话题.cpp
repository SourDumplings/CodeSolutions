/*
 @Date    : 2018-03-16 10:00:28
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/893
此题有坑
每个话题要去掉首尾的分词
记录键值的时候要去掉首尾的分词，并且所有英文字母小写
40字符的限制可以忽略
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

static map<string, bool> shownInThisLine;
static map<string, int> fData;
static map<string, int>::iterator it;

int main() {
    int n; scanf("%d", &n); getchar();
    char line[1000];
    string originalKey;
    for (int i = 1; i <= n; i++)
    {
        gets(line);
        bool startRecordKey = false;
        shownInThisLine.clear();
        for (int i = 0; line[i]; i++)
        {
            if (line[i] == '#' && startRecordKey == false)
            {
                originalKey.clear(); startRecordKey = true;
            }
            else if (line[i] != '#' && startRecordKey == true)
            {
                if (!isalnum(line[i])) line[i] = ' ';
                line[i] = tolower(line[i]);
                int len = originalKey.length();
                if (len > 0 && line[i] == ' ' && originalKey[len - 1] == ' ') continue;
                originalKey.push_back(line[i]);
            }
            else if (line[i] == '#' && startRecordKey == true)
            {
                string alnumKey;
                if (originalKey[0] == ' ')
                {
                    for (int i = 1; i < originalKey.length(); i++)
                        alnumKey.push_back(originalKey[i]);
                }
                else if (originalKey[originalKey.length() - 1] == ' ')
                {
                    for (int i = 0; i < originalKey.length() - 1; i++)
                        alnumKey.push_back(originalKey[i]);
                }
                else alnumKey = originalKey;
                if (shownInThisLine.find(alnumKey) == shownInThisLine.end())
                {
                    shownInThisLine[alnumKey] = true;
                    fData[alnumKey]++;
                }
                startRecordKey = false;
            }
        }
    }
    int hotNum = 0;
    int maxF = 0;
    string hotS;
    for (it = fData.begin(); it != fData.end(); it++)
    {
        if (it->second > maxF)
        {
            hotNum = 0;
            maxF = it->second;
            hotS = it->first;
        }
        else if (it->second == maxF) hotNum++;
    }
    hotS[0] = toupper(hotS[0]);
    cout << hotS << endl << maxF << endl;
    if (hotNum) cout << "And " << hotNum << " more ..." << endl;
}
