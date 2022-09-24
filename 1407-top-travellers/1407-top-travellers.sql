# Write your MySQL query statement below

select Users.name , ifnull(m.d,0) as travelled_distance from Users left join (select user_id,sum(distance) as d from Rides group by user_id ) m on m.user_id=Users.id order by travelled_distance desc,name; 