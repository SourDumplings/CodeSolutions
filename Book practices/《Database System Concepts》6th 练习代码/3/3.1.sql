# 3.1
# a
SELECT
    title
FROM
    course
WHERE
    credits = 3
    AND dept_name = 'Comp. Sci.';

# b
SELECT
    DISTINCT student.ID
FROM
    (
        student
        JOIN takes USING (ID)
    )
    JOIN (
        instructor
        JOIN teaches USING (ID)
    ) USING (course_id)
WHERE
    instructor.name = 'Einstein';

# c
SELECT
    MAX(salary)
FROM
    instructor;

# d
SELECT
    ID,
    NAME
FROM
    instructor
WHERE
    salary = (
        SELECT
            MAX(salary)
        FROM
            instructor
    );

# e
SELECT
    course_id,
    sec_id,
    COUNT(ID) AS enrolled_num
FROM
    takes NATURAL
    JOIN section
WHERE
    YEAR = 2009
    AND semester = 'Fall'
GROUP BY
    course_id,
    sec_id;

# f
# m1
SELECT
    MAX(enrolled_num)
FROM
    (
        SELECT
            course_id,
            sec_id,
            COUNT(ID) AS enrolled_num
        FROM
            takes NATURAL
            JOIN section
        WHERE
            `year` = 2009
            AND semester = 'Fall'
        GROUP BY
            course_id,
            sec_id
    ) AS temp;

# m2
WITH enrollment AS (
    SELECT
        course_id,
        sec_id,
        COUNT(ID) AS enrolled_num
    FROM
        takes NATURAL
        JOIN section
    WHERE
        `year` = 2009
        AND semester = 'Fall'
    GROUP BY
        course_id,
        sec_id
)
SELECT
    MAX(enrolled_num)
FROM
    enrollment;

# g
WITH enrollment AS (
    SELECT
        course_id,
        sec_id,
        COUNT(ID) AS enrolled_num
    FROM
        takes NATURAL
        JOIN section
    WHERE
        `year` = 2009
        AND semester = 'Fall'
    GROUP BY
        course_id,
        sec_id
)
SELECT
    course_id,
    sec_id
FROM
    enrollment
WHERE
    enrolled_num =(
        SELECT
            MAX(enrolled_num)
        FROM
            enrollment
    );