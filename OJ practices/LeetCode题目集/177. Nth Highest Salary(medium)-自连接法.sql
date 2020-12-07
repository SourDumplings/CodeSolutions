/*
 * @Author: SourDumplings
 * @Date: 2020-12-07 17:44:01
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/nth-highest-salary/

 一般来说，能用子查询解决的问题也能用连接解决。具体到本题：

1.两表自连接，连接条件设定为表1的salary小于表2的salary
2.以表1的salary分组，统计表1中每个salary分组后对应表2中salary唯一值个数，即去重
3.限定步骤2中having 计数个数为N-1，即实现了该分组中表1salary排名为第N个
4.考虑N=1的特殊情形(特殊是因为N-1=0，计数要求为0)，此时不存在满足条件的记录数，但仍需返回结果，所以连接用left join
5.如果仅查询薪水这一项值，那么不用left join当然也是可以的，只需把连接条件放宽至小于等于、同时查询个数设置为N即可。因为连接条件含等号，所以一定不为空，用join即可。
注：个人认为无需考虑N<=0的情形，毕竟无实际意义。

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
          e1.salary
      FROM 
          employee e1 JOIN employee e2 ON e1.salary <= e2.salary
      GROUP BY 
          e1.salary
      HAVING 
          count(DISTINCT e2.salary) = N
  );
END
