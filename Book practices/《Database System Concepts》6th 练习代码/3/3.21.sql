# a
SELECT
    `name`
FROM
    member NATURAL
    JOIN borrowed NATURAL
    JOIN book
WHERE
    publisher = 'McGraw-Hill';

# b
# MySQL 不支持 EXCEPT，需要用 LEFT JOIN 等方法替代
SELECT
    DISTINCT m.`name`
FROM
    member AS m
WHERE
    NOT EXISTS (
        SELECT
            isbn
        FROM
            book
        WHERE
            publisher = 'McGraw-Hill'
    )
EXCEPT
    (
        SELECT
            isbn
        FROM
            borrowed AS b
        WHERE
            m.memb_no = b.memb_no
    );

# c
SELECT
    `name`,
    publisher
FROM
    (
        SELECT
            `name`,
            publisher,
            COUNT(isbn)
        FROM
            member NATURAL
            JOIN borrowed NATURAL
            JOIN book
        GROUP BY
            `name`,
            publisher
    ) AS mem_pub_count(`name`, publisher, bo_pub_count)
WHERE
    bo_pub_count > 5;

# d
WITH borrow_num(`name`, bo_num) AS (
    SELECT
        `name`,
        COUNT(isbn)
    FROM
        member NATURAL
        JOIN borrowed
    GROUP BY
        `name`
)
SELECT
    AVG(bo_num)
FROM
    borrow_num;