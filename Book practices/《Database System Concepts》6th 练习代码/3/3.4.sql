# a
SELECT
    count(*)
FROM
    person,
    participated,
    accident
WHERE
    person.driver_id = participated.driver_id
    AND participated.report_number = accident.report_number
    AND accident.date BETWEEN date '1989-01-01'
    AND date '1989-12-31';

# b
INSERT INTO
    accident(`report_number`, `date`, `location`)
VALUES
    (4007, '2001-09-01', 'Hangzhou');

# c
DELETE FROM
    car
WHERE
    model = 'Mazda'
    AND license IN (
        SELECT
            license
        FROM
            owns NATURAL
            JOIN person
        WHERE
            `name` = 'John Smith'
    );

