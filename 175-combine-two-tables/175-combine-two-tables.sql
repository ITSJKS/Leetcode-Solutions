# Write your MySQL query statement below
select firstName,lastName,a.city,a.state from Person as p left join Address as a on  a.personId = p.personId;
