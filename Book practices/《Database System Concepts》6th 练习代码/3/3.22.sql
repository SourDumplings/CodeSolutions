WHERE
    (
        SELECT
            count(title)
        FROM
            course
    ) = (
        SELECT
            count(DISTINCT title)
        FROM
            course
    );