# Write your MySQL query statement below
select   c.customer_id as customer_id
from Customer as c
group by customer_id
having count(distinct product_key) = (select  distinct count(*) from Product) 