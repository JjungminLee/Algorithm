-- 코드를 입력하세요
SELECT distinct a.PRODUCT_ID , b.PRODUCT_NAME, SUM(b.price * a.amount) as TOTAL_SALES
from food_order a
join food_product b on a.product_id = b.product_id
where a.produce_date between '2022-05-01' and '2022-05-31'
group by a.PRODUCT_ID , b.PRODUCT_NAME
order by total_sales desc, a.product_id asc ;