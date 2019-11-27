# a
UPDATE
    instructor
SET
    salary = salary * 1.1
WHERE
    dept_name = 'Comp. Sci.';

# b
# m1
DELETE FROM
    course
WHERE
    NOT EXISTS (
        SELECT
            *
        FROM
            section
        WHERE
            course.`course_id` = section.`course_id`
    );

# m2
DELETE FROM
    course
WHERE
    course_id NOT IN (
        SELECT
            course_id
        FROM
            section
    );

# c
INSERT INTO
    instructor
SELECT
    ID,
    `name`,
    dept_name,
    10000 AS salary
FROM
    student
WHERE
    tot_cred > 100;