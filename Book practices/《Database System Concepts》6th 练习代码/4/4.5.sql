CREATE VIEW student_grades(ID, GPA) AS (
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
            )
            OR NOT EXISTS (
                SELECT
                    *
                FROM
                    takes
                WHERE
                    takes.ID = student.ID
                    AND takes.`grade` IS NOT NULL
            )
    )
);

# select * from student_grades;