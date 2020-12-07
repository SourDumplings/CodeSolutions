/*
 * @Author: SourDumplings
 * @Date: 2020-12-07 17:38:57
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/nth-highest-salary/

 排名第N的薪水意味着该表中存在N-1个比其更高的薪水
注意这里的N-1个更高的薪水是指去重后的N-1个，实际对应人数可能不止N-1个
最后返回的薪水也应该去重，因为可能不止一个薪水排名第N
由于对于每个薪水的where条件都要执行一遍子查询，注定其效率低下

作者：luanhz
链接：https://leetcode-cn.com/problems/nth-highest-salary/solution/mysql-zi-ding-yi-bian-liang-by-luanz/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT 
          DISTINCT e.salary
      FROM 
          employee e
      WHERE 
          (SELECT count(DISTINCT salary) FROM employee WHERE salary>e.salary) = N-1
  );
END
