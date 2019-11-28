# a
UPDATE
    works
SET
    salary = salary * 1.1
WHERE
    company_name = 'First Bank Corporation';

# b
UPDATE
    works
SET
    salary = salary * 1.1
WHERE
    company_name = 'First Bank Corporation'
    AND employee_name IN (
        SELECT
            manager_name
        FROM
            manages
    );

# c
DELETE FROM
    works
WHERE
    company_name = 'First Bank Corporation';