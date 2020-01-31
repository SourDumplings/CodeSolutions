/*
 * @Author: SourDumplings
 * @Date: 2019-10-08 19:01:28
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/big-countries/
 */

select name, population, area from World
where population > 25000000 or area > 3000000;