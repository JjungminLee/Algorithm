select distinct d.id, d.email,d.first_name,d.last_name
from DEVELOPERS d
left join SKILLCODES s on (s.code&d.skill_code)>0
where s.category = 'Front End'
order by d.id