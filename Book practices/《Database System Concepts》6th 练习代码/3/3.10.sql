# a
UPDATE
    employee
SET
    city = 'Newton'
WHERE
    employee_name = 'Jones';

# b
# m1
UPDATE
    works
SET
    salary = CASE
        salary * 1.1 <= 100000 THEN salary * 1.1
        ELSE salary * 1.03
    END
WHERE
    employee_name IN (
        SELECT
            manager_name
        FROM
            manages
    )
    AND company_name = 'First Bank Corporation';

# m2
UPDATE
    works T
SET
    T.salary = T.salary * 1.03
WHERE
    T.employee_name IN (
        SELECT
            manager_name
        FROM
            manages
    )
    AND T.salary * 1.1 > 100000
    AND T.company name = 'First Bank Corporation';

UPDATE
    works T
SET
    T.salary = T.salary * 1.1
WHERE
    T.employee_name IN (
        SELECT
            manager_name
        FROM
            manages
    )
    AND T.salary * 1.1 <= 100000
    AND T.company name = 'First Bank Corporation';