# a
# 注意不能写成 count(*)，对于没有教课的老师，count(*) 会得到1而不是0
# 要写成 count(teaches表里的属性)才能满足题意
SELECT
    instructor.ID,
    instructor.name,
    COUNT(course_id) AS sect_num_taught
FROM
    instructor
    LEFT JOIN teaches ON instructor.ID = teaches.`ID`
GROUP BY
    instructor.ID,
    instructor.name;

# b
SELECT
    ID,
    NAME,
    (
        SELECT
            COUNT(*)
        FROM
            teaches
        WHERE
            instructor.`ID` = teaches.`ID`
    ) AS sect_num_taught
FROM
    instructor;

# c
SELECT
    course_id,
    sec_id,
    ID,
    COALESCE(NAME, '-') AS instructor_name
FROM
    (
        section NATURAL
        LEFT JOIN teaches
    ) NATURAL
    LEFT JOIN instructor
WHERE
    semester = 'Spring'
    AND YEAR = 2010;

# d
SELECT
    dept_name,
    COUNT(ID) AS instructor_num
FROM
    department NATURAL
    LEFT JOIN instructor
GROUP BY
    dept_name;