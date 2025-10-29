-- 코드를 입력하세요
SELECT  a.author_id as author_id , a.author_name as author_name,
b.category as category,sum(s.sales*b.price) as TOTAL_SALES
from AUTHOR as a
join BOOK as b on a.author_id = b.author_id
join BOOK_SALES as s on s.book_id = b.book_id
where s.sales_date between '2022-01-01' and '2022-01-31'
group by author_id,author_name,category
order by author_id asc, category desc