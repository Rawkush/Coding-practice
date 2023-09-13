# Write your MySQL query statement below

select name, bonus
from Employee as e
Left join Bonus as b
on e.empId = b.empId
where bonus <1000 or bonus is NULL
