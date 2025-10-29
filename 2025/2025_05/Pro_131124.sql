-- 코드를 입력하세요
SELECT m.MEMBER_NAME , r.REVIEW_TEXT, DATE_FORMAT(r.REVIEW_DATE,'%Y-%m-%d') as REVIEW_DATE  from REST_REVIEW r
join MEMBER_PROFILE m on r.MEMBER_ID = m.MEMBER_ID
where m.MEMBER_ID in (
select member_id from  (
select r.MEMBER_ID as member_id  from REST_REVIEW r group by r.MEMBER_ID order by count(*) desc limit 1) as sub)
order by REVIEW_DATE , r.REVIEW_TEXT;