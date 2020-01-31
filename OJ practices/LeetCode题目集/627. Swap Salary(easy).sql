/*
 * @Author: SourDumplings
 * @Date: 2019-10-11 10:12:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/swap-salary/
 */

# Write your MySQL query statement below
update salary
set
    sex = case sex
        when 'm' then 'f'
        else 'm'
    end;