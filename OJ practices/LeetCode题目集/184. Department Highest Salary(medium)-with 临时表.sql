/*
 * @Author: SourDumplings
 * @Date: 2020-12-17 18:10:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/department-highest-salary/
 */

# Write your MySQL query statement below
WITH HighestS AS
(
    SELECT 
        DepartmentId, MAX(Salary) as HighestSalary
    FROM
        Employee
    GROUP BY
        DepartmentId
)
SELECT
    d.Name as Department, e.Name as Employee, Salary
FROM
    Employee e join Department d on e.DepartmentId = d.Id join HighestS on HighestS.DepartmentId = d.Id
WHERE
    Salary = HighestSalary