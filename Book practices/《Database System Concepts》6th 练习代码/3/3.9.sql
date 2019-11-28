# a
SELECT
    `employee_name`,
    `city`
FROM
    employee NATURAL
    JOIN works
WHERE
    company_name = 'First Bank Corporation';

# b
SELECT
    `employee_name`,
    `street`,
    `city`
FROM
    employee NATURAL
    JOIN works
WHERE
    company_name = 'First Bank Corporation'
    AND salary > 10000;

# c
# 不存在无工作的人的情况
SELECT
    `employee_name`
FROM
    employee NATURAL
    JOIN works
WHERE
    company_name <> 'First Bank Corporation';

# 存在无工作的人的情况
SELECT
    `employee_name`
FROM
    employee
WHERE
    employee_name NOT IN (
        SELECT
            employee_name
        FROM
            works
        WHERE
            company_name = 'First Bank Corporation'
    );

# d
# 一个人只能在一家企业工作
SELECT
    `employee_name`
FROM
    works
WHERE
    salary > ALL(
        SELECT
            salary
        FROM
            works
        WHERE
            company_name = 'Small Bank Corporation'
    );

# 一个人可以为多家企业工作
WITH emp_total_salary(employee_name, total_salary) AS (
    SELECT
        employee_name,
        sum(salary)
    FROM
        works
    GROUP BY
        employee_name
)
SELECT
    `employee_name`
FROM
    emp_total_salary
WHERE
    total_salary > ALL(
        SELECT
            total_salary
        FROM
            emp_total_salary NATURAL
            JOIN works
        WHERE
            company_name = 'Small Bank Corporation'
    );

# e
# m1
SELECT
    c1.company_name
FROM
    company AS c1,
    company AS c2
WHERE
    c1.city = c2.city
    AND c2.company_name = 'Small Bank Corporation';

# m2
SELECT
    c1.company_name
FROM
    company AS c1
WHERE
    (
        SELECT
            c2.city
        FROM
            company AS c2
        WHERE
            c1.company_name = c2.company_name
    ) CONTAINS (
        SELECT
            c3.city
        FROM
            company AS c3
        WHERE
            c3.company_name = 'Small Bank Corporation'
    );

# m3 MySQL 不支持 EXCEPT
SELECT
    c1.company_name
FROM
    company AS c1
WHERE
    (
        SELECT
            c3.city
        FROM
            company AS c3
        WHERE
            c3.company_name = 'Small Bank Corporation'
    )
EXCEPT
    (
        SELECT
            c2.city
        FROM
            company AS c2
        WHERE
            c1.company_name = c2.company_name
    );

# f
# m1
WITH com_emp_num(company_name, employee_num) AS (
    SELECT
        company_name,
        count(employee_name) AS employee_num
    FROM
        works
    GROUP BY
        company_name
)
SELECT
    company_name
FROM
    com_emp_num
WHERE
    employee_num >= ALL (
        SELECT
            employee_num
        FROM
            com_emp_num
    );

# m2
SELECT
    company_name
FROM
    works
GROUP BY
    company_name
HAVING
    count(DISTINCT employee_name) >= ALL(
        SELECT
            count(DISTINCT employee_name)
        FROM
            works
        GROUP BY
            company_name
    );

# g
SELECT
    company_name
FROM
    works
GROUP BY
    company_name
HAVING
    avg(salary) > (
        SELECT
            avg(salary)
        FROM
            works
        WHERE
            company_name = 'First Bank Corporation'
    );