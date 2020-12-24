/*
 * @Author: SourDumplings
 * @Date: 2020-12-24 09:27:20
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/course-schedule/
 */

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int degree[numCourses];
        fill(degree, degree + numCourses, 0);
        for (vector<int> &edge : prerequisites)
        {
            ++degree[edge[0]];
        }
        while (true)
        {
            int nextCourse;
            bool nowPossible = false;
            for (int course = 0; course < numCourses; ++course)
            {
                if (degree[course] == 0)
                {
                    nowPossible = true;
                    degree[course] = -1;
                    nextCourse = course;
                    break;
                }
            }
            if (nowPossible == false)
            {
                break;
            }
            for (vector<int> &edge : prerequisites)
            {
                if (edge[1] == nextCourse)
                {
                    --degree[edge[0]];
                }
            }
        }
        return count_if(degree, degree + numCourses,
                     [](int degree)
                     { return degree < 0; }) == numCourses;
    }
};