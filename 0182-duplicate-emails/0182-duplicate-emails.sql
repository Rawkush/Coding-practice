# Write your MySQL query statement below


select email from
(select email, count(email) as count from Person group by email ) 
as tmpTable  # a name is required for tmporary tables

where count >1;