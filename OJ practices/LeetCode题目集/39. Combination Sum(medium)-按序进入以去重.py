'''
@Author: SourDumplings
@Date: 2020-02-14 16:30:53
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: https://leetcode-cn.com/problems/combination-sum/
'''
from typing import List


class Solution:
    __res = []
    __thisList = []
    __l = 0

    def combinationSum(self, candidates: List[int], target: int) -> List[
            List[int]]:
        self.__l = len(candidates)
        candidates.sort()
        for i in range(self.__l):
            thisNum = candidates[i]
            if target < thisNum:
                break
            self.__thisList.append(thisNum)
            self.__backtrack(candidates, target - thisNum, i)
            self.__thisList.pop()
        return self.__res

    def __backtrack(self, candidates: List[int], target: int, start: int):
        if target == 0:
            self.__res.append(self.__thisList.copy())
        elif target > 0:
            for i in range(start, self.__l):
                thisNum = candidates[i]
                if target < thisNum:
                    break
                self.__thisList.append(thisNum)
                self.__backtrack(candidates, target - thisNum, i)
                self.__thisList.pop()
