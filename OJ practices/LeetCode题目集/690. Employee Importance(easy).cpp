/*
 * @Author: SourDumplings
 * @Date: 2019-10-17 21:52:07
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/employee-importance/
 */

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        int res = 0;
        unordered_map<int, Employee *> m;
        for (auto &&e : employees)
        {
            m[e->id] = e;
        }
        calcImportance(m, id, res);
        return res;
    }

    void calcImportance(unordered_map<int, Employee *> &m, int id, int &res)
    {
        Employee *e = m[id];
        res += e->importance;
        for (auto &&i : e->subordinates)
        {
            calcImportance(m, i, res);
        }
    }
};