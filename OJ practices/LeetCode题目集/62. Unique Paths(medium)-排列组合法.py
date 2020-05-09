'''
@Author: SourDumplings
@Date: 2020-05-09 15:22:53
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: https://leetcode-cn.com/problems/unique-paths/

向右走的步数与向下走的步数都是固定的，主要就是先后顺序问题
即向下 m -1 步，向右 n - 1 步进行排列
即对于总共 m + n - 2 步，选出 m - 1 步作为向下步骤
即 C(m-1, m+n-2)
'''
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return int(math.factorial(m+n-2)/math.factorial(m-1)/math.factorial(n-1))