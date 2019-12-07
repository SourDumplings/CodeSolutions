CREATE VIEW tot_credits(YEAR, total_credits) AS (
    SELECT
        YEAR,
        SUM(credits)
    FROM
        takes NATURAL
        JOIN course
    GROUP BY
        YEAR
);

# select * from tot_credits;