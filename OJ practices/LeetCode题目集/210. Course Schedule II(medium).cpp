/*
 * @Author: SourDumplings
 * @Date: 2020-12-27 10:31:02
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/course-schedule-ii/
 */

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        int degree[numCourses];
        fill(degree, degree + numCourses, 0);
        for (vector<int> &p : prerequisites)
        {
            ++degree[p[0]];
        }
        vector<int> res;
        while (true)
        {
            int nextCourse = -1;
            for (int i = 0; i < numCourses; ++i)
            {
                if (degree[i] == 0)
                {
                    degree[i] = -1;
                    nextCourse = i;
                    break;
                }
            }
            if (nextCourse == -1)
            {
                break;
            }
            res.push_back(nextCourse);
            int n = prerequisites.size();
            for (int i = 0; i < n; ++i)
            {
                if (prerequisites[i][1] == nextCourse)
                {
                    --degree[prerequisites[i][0]];
                }
            }
        }
        if (res.size() < numCourses)
        {
            res.clear();
        }
        return res;
    }
};