-- 코드를 입력하세요
SELECT a.NAME AS NAME, a.DATETIME AS DATETIME
FROM (
    SELECT ROWNUM AS rn, NAME, DATETIME
    FROM (
        SELECT NAME, DATETIME
        FROM ANIMAL_INS i
        WHERE NOT EXISTS (SELECT 1
                          FROM ANIMAL_OUTS o
                          WHERE i.ANIMAL_ID = o.ANIMAL_ID)
        ORDER BY i.DATETIME)
) a
WHERE rn <= 3;