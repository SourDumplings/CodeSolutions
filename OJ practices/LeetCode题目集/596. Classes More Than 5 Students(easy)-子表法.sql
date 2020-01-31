/*
 * @Author: SourDumplings
 * @Date: 2019-10-08 19:06:30
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/classes-more-than-5-students/
 */

select
    class
from
    (select
        class, count(distinct student) as num
    from
        courses
    group by class)
    as temp_table
where num >= 5;
