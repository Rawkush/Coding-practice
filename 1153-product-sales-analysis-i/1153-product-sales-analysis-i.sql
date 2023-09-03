# Write your MySQL query statement below

select product_name,
       year, price

from Sales
Left Join Product on Sales.product_id = Product.product_id