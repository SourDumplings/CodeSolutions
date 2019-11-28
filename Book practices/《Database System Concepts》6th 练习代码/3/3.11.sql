# a
SELECT
    DISTINCT NAME
FROM
    student NATURAL
    JOIN takes
    JOIN course USING(course_id)
WHERE
    course.`dept_name` = 'Comp. Sci.';

# b
# m1
SELECT
    DISTINCT ID,
    NAME
FROM
    student NATURAL
    JOIN takes
WHERE
    YEAR >= 2009;

# m2 MySQL 不支持 EXCEPT 子句，需要使用 LEFT JOIN 等方法替换
(
    SELECT
        ID,
        NAME
    FROM
        student
)
EXCEPT
    (
        SELECT
            DISTINCT ID,
            NAME
        FROM
            student NATURAL
            JOIN takes
        WHERE
            YEAR < 2009
    );

# c
SELECT
    dept_name,
    MAX(salary)
FROM
    instructor
GROUP BY
    dept_name;

# d
# m1
SELECT
    salary
FROM
    instructor
GROUP BY
    dept_name
HAVING
    MAX(salary) <= ALL (
        SELECT
            MAX(salary)
        FROM
            instructor
        GROUP BY
            dept_name
    );

# m2
SELECT
    MIN(max_salary)
FROM
    (
        SELECT
            MAX(salary) AS max_salary
        FROM
            instructor
        GROUP BY
            dept_name
    ) AS max_salary_table;