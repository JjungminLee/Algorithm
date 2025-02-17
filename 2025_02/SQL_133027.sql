-- 코드를 입력하세요
-- 상반기랑 7월 flavor기준으로 조인해서 더한 서브쿼리 테이블을 정렬해서 맨위 3개만
select flavor
from(
SELECT j.total+h.total as total_order , j.flavor
from (select sum(total_order) as total,flavor from july group by flavor) as j
join (select sum(total_order) as total,flavor from FIRST_HALF group by flavor) as h on j.flavor=h.flavor) as sub
order by sub.total_order desc limit 3