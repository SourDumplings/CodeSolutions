# a
SELECT
    employee_name
FROM
    employee NATURAL
    LEFT JOIN manager
WHERE
    manager_name IS NULL;

# b
SELECT
    employee_name
FROM
    employee
WHERE
    NOT EXISTS(
        SELECT
            *
        FROM
            manager
        WHERE
            employee.employee_name = manager.employee_name
            AND manager_name IS NOT NULL
    );