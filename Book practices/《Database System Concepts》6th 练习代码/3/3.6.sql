SELECT
    dept_name
FROM
    department
WHERE
    LOWER(dept_name) LIKE '%sci%';