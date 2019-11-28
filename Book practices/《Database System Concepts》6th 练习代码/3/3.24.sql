SELECT
    dept_name
FROM
    instructor
GROUP BY
    dept_name
HAVING
    SUM(salary) >= (
        SELECT
            AVG(avg_sal)
        FROM
            (
                SELECT
                    SUM(salary)
                FROM
                    instructor
                GROUP BY
                    dept_name
            ) AS avg_sal_dept(avg_sal)
    );

# original
WITH dept_avg(dept_name, dept_sal) AS (
    SELECT
        dept_name,
        SUM(salary) AS dept_avg_sal
    FROM
        instructor
    GROUP BY
        dept_name
),
dept_total_avg(avg_sal) AS (
    SELECT
        AVG(dept_sal)
    FROM
        dept_avg
)
SELECT
    dept_name
FROM
    dept_avg,
    dept_total_avg
WHERE
    dept_sal >= avg_sal;