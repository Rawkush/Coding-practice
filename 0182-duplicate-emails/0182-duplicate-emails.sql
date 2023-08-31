# Write your MySQL query statement below



## create a tmp table with count and use that count as a filter
# select email from
# (select email, count(email) as count from Person group by email ) 
# as tmpTable  # a name is required for tmporary tables

# where count >1;


select email
from Person
group by email 
having count(email)>1