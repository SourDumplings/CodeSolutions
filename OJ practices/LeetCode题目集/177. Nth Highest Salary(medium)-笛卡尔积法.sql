/*
 * @Author: SourDumplings
 * @Date: 2020-12-07 17:50:26
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/nth-highest-salary/

 当然，可以很容易将自连接法中的代码改为笛卡尔积连接形式，
 其执行过程实际上一致的，甚至MySQL执行时可能会优化成相同的查询语句。
 */

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT 
          e1.salary
      FROM 
          employee e1, employee e2 
      WHERE 
          e1.salary <= e2.salary
      GROUP BY 
          e1.salary
      HAVING 
          count(DISTINCT e2.salary) = N
  );
END
