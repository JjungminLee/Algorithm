select t1.category as category, count(t2.account_id) as accounts_count from
(
    select "Low Salary" as category
    union all 
    select "Average Salary"
    union all 
    select "High Salary"
) as t1
left join Accounts as t2 on t1.category= (
    case
        when t2.income < 20000 then "Low Salary"
        when t2.income between 20000 and 50000 then "Average Salary"
        when t2.income>50000 then "High Salary"
    end
)
group by t1.category
order by accounts_count desc