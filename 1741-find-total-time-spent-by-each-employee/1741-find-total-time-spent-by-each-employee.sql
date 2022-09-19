# Write your MySQL query statement below
select event_day as day,emp_id,(sum(Employees.out_time)-sum(Employees.in_time)) as total_time from Employees group by day,emp_id order by event_day;