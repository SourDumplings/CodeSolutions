/*
 * @Autor: SourDumplings
 * @Date: 2019-10-11 08:06:36
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/not-boring-movies/
 */

select
    *
from
    cinema
where
    description != 'boring' and mod(id, 2) = 1
order by
    rating desc;