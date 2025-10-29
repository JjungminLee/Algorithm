SELECT
YEAR(o.sales_date)
AS year,
    MONTH(o.sales_date) AS month,
    count(distinct o.user_id) as purchased_users,
    round(count(distinct o.user_id) / (SELECT count(*)
                                           FROM USER_INFO AS u
                                               WHERE YEAR(u.joined) = 2021),
          1) as PURCHASED_RATIO
    FROM online_sale AS o
    WHERE o.user_id IN(
        SELECT user_id
            FROM USER_INFO AS u
                WHERE YEAR(u.joined) = 2021)
        GROUP BY YEAR(o.sales_date),
    MONTH(o.sales_date)
        order by YEAR(o.sales_date) asc,
    MONTH(o.sales_date) asc;