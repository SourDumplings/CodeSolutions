# a
INSERT INTO
    course(course_id, title, dept_name, credits)
VALUES
('CS-001', 'Weekly Seminar', NULL, 1);

# b
INSERT INTO
    section(
        course_id,
        sec_id,
        semester,
        YEAR,
        building,
        room_number,
        time_slot_id
    )
VALUES
('CS-001', 1, 'Fall', 2009, NULL, NULL, NULL);

# c
INSERT INTO
    takes
SELECT
    ID,
    'CS-001',
    1,
    'Fall',
    2009,
    NULL
FROM
    student
WHERE
    dept_name = 'Comp. Sci.';

# d
DELETE FROM
    takes
WHERE
    ID = (
        SELECT
            ID
        FROM
            student
        WHERE
            NAME = 'Chavez'
    )
    AND course_id = 'CS-001'
    AND sec_id = 1;

# e
# takes 对于 section 有外键，如果先删了 section 的，那么 takes 里对应的数据也就没了
# 同理，如果先删了 course 中的，那么 section 中没了，takes 中的也没了
# 因此最好是从 takes，即最根部的 referencing table 开始删
DELETE FROM
    takes
WHERE
    course_id = 'CS-001';

DELETE FROM
    section
WHERE
    course_id = 'CS-001';

DELETE FROM
    course
WHERE
    course_id = 'CS-001';

# f
# m1
DELETE FROM
    takes
WHERE
    LOWER(
        (
            SELECT
                title
            FROM
                course
            WHERE
                course.`course_id` = takes.`course_id`
        )
    ) LIKE '%database%';

# m2
DELETE FROM
    takes
WHERE
    course_id IN (
        SELECT
            course_id
        FROM
            course
        WHERE
            LOWER(title) LIKE '%database%'
    );