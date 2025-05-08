-- 코드를 입력하세요
select month(c.start_date) as MONTH, c.car_id as car_id, count(*) as records
from CAR_RENTAL_COMPANY_RENTAL_HISTORY as c 
join(
SELECT car_id
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where start_date between '2022-08-01' and '2022-10-31'
group by car_id
having count(*)>=5
    ) as c2 on c.car_id=c2.car_id
where c.start_date between '2022-08-01' and '2022-10-31'
GROUP BY MONTH(c.start_date), c.car_id
order by month asc , car_id desc