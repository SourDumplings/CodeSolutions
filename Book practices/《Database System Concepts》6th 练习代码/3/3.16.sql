# a
SELECT
    employee_name
FROM
    works
WHERE
    employee_name = 'First Bank Corporation';

# b
# m1
SELECT
    employee_name
FROM
    employee NATURAL
    JOIN works NATURAL
    JOIN company
WHERE
    employee.city = company.city;

# m2
SELECT
    e.employee_name
FROM
    employee AS e,
    works AS w,
    company AS c
WHERE
    e.city = c.city
    AND e.employee_name = w.emloyee_name
    AND w.company_name = c.company_name;

# c
SELECT
    e1.employee_name
FROM
    employee AS e1,
    employee AS e2,
    manages AS m
WHERE
    e1.employee_name = m.employee_name
    AND m.manager_name = e2.employee_name
    AND e1.city = e2.city
    AND e1.street = e2.street;

# d
SELECT
    w1.employee_name
FROM
    works AS w1
WHERE
    w1.salary > (
        SELECT
            AVG(salary)
        FROM
            works AS w2
        WHERE
            w1.company_name = w2.company_name
    );

# e
SELECT
    company_name
FROM
    works AS w1
GROUP BY
    company_name
HAVING
    SUM(w1.salary) <= ALL(
        SELECT
            SUM(w2.salary)
        FROM
            works AS w2
        GROUP BY
            w2.company_name
    );