-- 코드를 입력하세요
SELECT car_id , '대여중' as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where '2022-10-16' between start_date and end_date

union

SELECT car_id , '대여 가능' as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where car_id not in (
SELECT car_id 
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where '2022-10-16' between start_date and end_date)

order by car_id desc