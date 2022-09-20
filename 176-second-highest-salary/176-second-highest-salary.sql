# Write your MySQL query statement below
select 
IFNULL((select distinct salary  from Employee order by salary desc
LIMIT 1 offset 1),NULL) as SecondHighestSalary ;