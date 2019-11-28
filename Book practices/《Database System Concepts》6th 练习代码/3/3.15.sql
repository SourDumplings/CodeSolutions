# a
# MySQL 不支持 EXCEPT，需要用 LEFT JOIN 等方法替换
SELECT
    customer_name
FROM
    (
        depositor NATURAL
        JOIN account
    ) AS a1
WHERE
    NOT EXISTS (
        (
            SELECT
                branch_name
            FROM
                depositor NATURAL
                JOIN account NATURAL
                JOIN branch
            WHERE
                branch_city = 'Brooklyn'
        )
        EXCEPT
            branch_name (
                SELECT
                    branch_name
                FROM
                    (
                        depositor NATURAL
                        JOIN account
                    ) AS a2
                WHERE
                    a1.customer_name = a2.customer_name
            )
    );

# b
SELECT
    SUM(amount)
FROM
    loan;

# c
SELECT
    branch_name
FROM
    branch
WHERE
    assets > SOME(
        SELECT
            assets
        FROM
            branch
        WHERE
            branch_city = 'Brooklyn'
    );