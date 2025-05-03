# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary
from Employee as e 
join Department as d on e.departmentId=d.id
join(
    select departmentId, max(salary) as salary from Employee group by departmentId
) as sub on sub.departmentId = e.departmentId and e.salary = sub.salary