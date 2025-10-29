-- 코드를 입력하세요
SELECT user_id, nickname,sum(a.price) as total_sales
from USED_GOODS_BOARD as a 
left join USED_GOODS_USER as b on a.writer_id = b.user_id
where status ='DONE'
group by user_id,nickname
having sum(a.price)>=700000
order by sum(a.price) asc