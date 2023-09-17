# Write your MySQL query statement below
select 
  e.name
from 
  Employee as e
join 
  Employee as e1
on e.id = e1.managerId
group by e.Id
having count(e.Id) >= 5
