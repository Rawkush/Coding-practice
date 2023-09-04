# Write your MySQL query statement below

select w.id 
from Weather as w
Inner Join Weather as w2
on DATEDIFF( w.recordDate, w2.recordDate)  = 1
And w.temperature > w2.temperature