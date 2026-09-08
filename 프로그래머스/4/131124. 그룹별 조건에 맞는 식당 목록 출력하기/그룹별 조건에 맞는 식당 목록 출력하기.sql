-- 코드를 입력하세요

SELECT
    a.MEMBER_NAME AS MEMBER_NAME,
    b.REVIEW_TEXT AS REVIEW_TEXT,
    TO_CHAR(b.REVIEW_DATE, 'YYYY-MM-DD') AS REVIEW_DATE
FROM
    MEMBER_PROFILE a, REST_REVIEW b
WHERE a.MEMBER_ID = b.MEMBER_ID
    AND a.MEMBER_ID = (SELECT MEMBER_ID
                       FROM (SELECT MEMBER_ID
                             FROM REST_REVIEW
                             GROUP BY MEMBER_ID
                             ORDER BY COUNT(*) desc)
                       WHERE ROWNUM <= 1)
ORDER BY b.REVIEW_DATE, REVIEW_TEXT;
