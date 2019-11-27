# a
SELECT
    ID,
    CASE
        WHEN score < 40 THEN 'F'
        WHEN score < 60 THEN 'C'
        WHEN score < 80 THEN 'B'
        ELSE 'A'
    END
FROM
    marks;

# b
WITH grades(ID, grade) AS (
    SELECT
        ID,
        CASE
            WHEN score < 40 THEN 'F'
            WHEN score < 60 THEN 'C'
            WHEN score < 80 THEN 'B'
            ELSE 'A'
        END AS grade
    FROM
        marks;

)
SELECT
    grade,
    count(ID)
FROM
    grades
GROUP BY
    grade;