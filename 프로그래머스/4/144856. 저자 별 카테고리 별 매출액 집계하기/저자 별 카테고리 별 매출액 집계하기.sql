-- 코드를 입력하세요
SELECT
    b.AUTHOR_ID AS AUTHOR_ID,
    a.AUTHOR_NAME AS AUTHOR_NAME,
    b.CATEGORY AS CATEGORY,
    SUM(b.TOTAL_SALES) AS TOTAL_SALES
FROM
    AUTHOR AS a
JOIN
    (
        SELECT
            b.BOOK_ID AS BOOK_ID,
            b.CATEGORY AS CATEGORY,
            b.AUTHOR_ID AS AUTHOR_ID,
            SUM(bs.sales) * b.price AS TOTAL_SALES
        FROM BOOK b, BOOK_SALES bs
        WHERE
            b.BOOK_ID = bs.BOOK_ID
            AND (YEAR(bs.SALES_DATE) = 2022 AND MONTH(bs.SALES_DATE) = 1)
        GROUP BY b.BOOK_ID
    ) AS b
ON
    a.AUTHOR_ID = b.AUTHOR_ID
GROUP BY b.CATEGORY, b.AUTHOR_ID
ORDER BY AUTHOR_ID, CATEGORY desc;

