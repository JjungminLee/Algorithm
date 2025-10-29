# Write your MySQL query statement below
select p.product_id , COALESCE(MAX(sub.new_price), 10) as price 
from Products as p 
left join (select * from Products where change_date <= '2019-08-16' ) as sub  
on sub.product_id = p.product_id and p.change_date = sub.change_date
group by p.product_id
