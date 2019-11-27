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