select customer_number from (select customer_number, count(*) as cnt from Orders 
group by(customer_number)) as sub
order by sub.cnt desc limit 1