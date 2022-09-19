# Write your MySQL query statement below
UPDATE Salary 
set sex = char(ascii('m')^ascii('f')^ascii(sex));