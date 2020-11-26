/*
 * @Author: SourDumplings
 * @Date: 2020-11-26 16:20:52
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/reverse-words-in-a-string/
 * 
 * C++ 中的字符串 string 是可变类型，故可以使用 reverse 算法实现空间复杂度 O(1) 的解法
 */

class Solution
{
public:
    string reverseWords(string s)
    {
        // 反转整个字符串
        reverse(s.begin(), s.end());

        int n = s.size();
        int endOfWords = 0;
        for (int start = 0; start < n; ++start)
        {
            if (s[start] != ' ')
            {
                // 填一个空白字符然后将 endOfWords 移动到下一个单词的开头位置
                if (endOfWords != 0)
                { s[endOfWords++] = ' '; }

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ')
                { s[endOfWords++] = s[end++]; }

                // 反转整个单词
                reverse(s.begin() + endOfWords - (end - start),
                        s.begin() + endOfWords);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + endOfWords, s.end());
        return s;
    }
};