# a
# m1 没成绩会为空
SELECT
    SUM(credits * points)
FROM
    (
        takes NATURAL
        JOIN course
    ) NATURAL
    JOIN grade_points
WHERE
    ID = '12345';

# m2 没成绩会为0
(
    SELECT
        SUM(credits * points)
    FROM
        (
            takes NATURAL
            JOIN course
        ) NATURAL
        JOIN grade_points
    WHERE
        ID = '12345'
)
UNION
(
    SELECT
        0
    FROM
        student
    WHERE
        ID = '12345'
        AND NOT EXISTS(
            SELECT
                *
            FROM
                takes
            WHERE
                takes.ID = '12345'
        )
);

# b
(
    SELECT
        SUM(credits * points) / SUM(credits) AS GPA
    FROM
        (
            takes NATURAL
            JOIN course
        ) NATURAL
        JOIN grade_points
    WHERE
        ID = '12345'
)
UNION
(
    SELECT
        NULL AS GPA
    FROM
        student
    WHERE
        ID = '12345'
        AND NOT EXISTS(
            SELECT
                *
            FROM
                takes
            WHERE
                takes.ID = '12345'
        )
);

# c
# m1 对于学生排除选了课但是都没成绩的情况，结果中不会出现
(
    SELECT
        ID,
        SUM(credits * points) / SUM(credits) AS GPA
    FROM
        (
            takes NATURAL
            JOIN course
        ) NATURAL
        JOIN grade_points
    GROUP BY
        ID
)
UNION
(
    SELECT
        ID,
        NULL AS GPA
    FROM
        student
    WHERE
        NOT EXISTS(
            SELECT
                *
            FROM
                takes
            WHERE
                takes.ID = student.ID
        )
);

# m2
# 对于学生排除选了课但是都没成绩的情况，GPA 为 0
    (
        SELECT
            ID,
            SUM(credits * points) / SUM(credits) AS GPA
        FROM
            (
                takes NATURAL
                JOIN course
            ) NATURAL
            JOIN grade_points
        GROUP BY
            ID
    )
    UNION
    (
        SELECT
            ID,
            0 AS GPA
        FROM
            student
        WHERE
            NOT EXISTS(
                SELECT
                    *
                FROM
                    takes
                WHERE
                    takes.ID = student.ID
            ) OR NOT EXISTS
            (
                            SELECT
                    *
                FROM
                    takes
                WHERE
                    takes.ID = student.ID AND takes.`grade` IS NOT NULL
            )
    );