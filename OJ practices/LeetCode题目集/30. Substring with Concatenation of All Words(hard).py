'''
@Author: SourDumplings
@Date: 2020-01-29 12:50:27
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
'''
from typing import List


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        res = []
        if len(words) == 0:
            return res

        lOfWord = len(words[0])
        lOfSubstring = 0
        l = len(s)

        d = dict()
        for word in words:
            d[word] = d.get(word, 0) + 1
            lOfSubstring += lOfWord

        for i in range(0, l - lOfSubstring + 1):
            flag = True
            temp = d.copy()
            subStr = s[i:i + lOfSubstring]
            for j in range(0, lOfSubstring - lOfWord + 1, lOfWord):
                word = subStr[j:j + lOfWord]
                num = temp.get(word)
                if num is None or num == 0:
                    flag = False
                    break
                else:
                    temp[word] -= 1
            if flag:
                res.append(i)

        return res
