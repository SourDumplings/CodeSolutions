# a
# m1
SELECT
    customer_name
FROM
    customer
WHERE
    customer_name IN (
        SELECT
            customer_name
        FROM
            depositor
    )
    AND NOT IN (
        SELECT
            customer_name
        FROM
            borrower
    );

# m2 MySQL 不支持 EXCEPT 子句
(
    SELECT
        customer_name
    FROM
        depositor
)
EXCEPT
    (
        SELECT
            customer_name
        FROM
            borrower
    );

# b
SELECT
    c1.customer_name
FROM
    customer AS c1
    JOIN customer AS c2 USING(customer_street, customer_city)
WHERE
    c2.customer_name = 'Smith';

# c
SELECT
    DISTINCT branch_name
FROM
    account NATURAL
    JOIN depositor NATURAL
    JOIN customer
WHERE
    customer_city = 'Harrison';