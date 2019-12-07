# a
# select * from student natural left join takes
(
    SELECT
        *
    FROM
        student NATURAL
        JOIN takes
)
UNION
(
    SELECT
        ID,
        NAME,
        dept_name,
        tot_cred,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    FROM
        student
    WHERE
        NOT EXISTS (
            SELECT
                ID
            FROM
                takes
            WHERE
                student.`ID` = takes.`ID`
        )
);

# b
(
    SELECT
        *
    FROM
        student NATURAL
        JOIN takes
)
UNION
(
    SELECT
        ID,
        NAME,
        dept_name,
        tot_cred,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    FROM
        student
    WHERE
        NOT EXISTS (
            SELECT
                ID
            FROM
                takes
            WHERE
                student.`ID` = takes.`ID`
        )
)
UNION
(
    SELECT
        ID,
        NULL,
        NULL,
        NULL,
        course_id,
        sec_id,
        semester,
        YEAR,
        grade
    FROM
        takes
    WHERE
        NOT EXISTS (
            SELECT
                ID
            FROM
                student
            WHERE
                student.`ID` = takes.`ID`
        )
);