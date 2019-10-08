/*
 * @Autor: SourDumplings
 * @Date: 2019-10-08 19:10:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/classes-more-than-5-students/
 */

select
    class
from
    courses
group by
    class
having
    count(distinct student) >= 5;