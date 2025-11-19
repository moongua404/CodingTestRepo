-- 코드를 입력하세요

SELECT
    os.y YEAR,
    os.m MONTH,
    COUNT(DISTINCT(os.user_id)) PURCHASED_USERS,
    ROUND(COUNT(DISTINCT(os.user_id)) / (
        SELECT COUNT(*) FROM USER_INFO u WHERE YEAR(u.JOINED) = 2021
    ), 1) PUCHASED_RATIO
FROM 
    (
        SELECT user_id, DATE_FORMAT(sales_date, '%Y%m') AS ym,
        YEAR(sales_date) y, MONTH(sales_date) m
        FROM ONLINE_SALE o
        WHERE EXISTS(
            SELECT 1 FROM USER_INFO u
            WHERE YEAR(u.JOINED) = 2021 AND o.USER_ID = u.USER_ID
        )
    ) os
GROUP BY ym
ORDER BY ym;

