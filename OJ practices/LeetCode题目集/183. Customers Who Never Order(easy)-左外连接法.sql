# Write your MySQL query statement below
select Name as Customers from Customers left outer join Orders on Customers.Id=Orders.CustomerId where Orders.CustomerId is null