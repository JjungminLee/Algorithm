-- 코드를 입력하세요
SELECT ao.animal_id as ANIMAL_ID, ai.animal_type as ANIMAL_TYPE, ai.name as NAME from ANIMAL_OUTS as ao
left join ANIMAL_INS as ai on ao.ANIMAL_ID = ai.ANIMAL_ID
where ai.SEX_UPON_INTAKE like "%Intact%" and (ao.SEX_UPON_OUTCOME like "%Spayed%" or
                                             ao.SEX_UPON_OUTCOME like "%Neutered%")
order by ANIMAL_ID asc