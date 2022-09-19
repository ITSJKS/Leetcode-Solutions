# Write your MySQL query statement below
# select user_id,min(time_stamp) as last_stamp from Logins l group by user_id having substr(l.time_stamp,1,4) = 2020;
select distinct l.user_id,max(l.time_stamp) as last_stamp from Logins l where substr(l.time_stamp,1,4) = 2020 group by user_id;