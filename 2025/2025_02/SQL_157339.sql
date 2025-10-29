select c.car_id,c.car_type,floor(c.daily_fee*30*(1-d.DISCOUNT_RATE/100)) as fee
from CAR_RENTAL_COMPANY_CAR c
left join CAR_RENTAL_COMPANY_DISCOUNT_PLAN d on c.car_type=d.car_type and d.duration_type = '30일 이상'
where c.car_type in ('세단','SUV')
and c.car_id not in (select distinct h.car_id from CAR_RENTAL_COMPANY_RENTAL_HISTORY h where h.start_date <= '2022-11-30' and h.end_date >='2022-11-01'  )
and floor(c.daily_fee*30*(1-d.discount_rate/100) between 500000 AND 1999999 )
order by fee desc, c.car_type asc, c.car_id desc