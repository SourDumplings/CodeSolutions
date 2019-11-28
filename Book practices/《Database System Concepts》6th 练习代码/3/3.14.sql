# a
SELECT
    COUNT(*)
FROM
    accident NATURAL
    JOIN participated
WHERE
    license IN (
        SELECT
            license
        FROM
            person NATURAL
            JOIN owns
        WHERE
            NAME = 'John Smith'
    );

# b
# 这道题有 bug，report_num 是 int 的
UPDATE
    participated
SET
    damage_amount = 3000
WHERE
    license = 'AABB2000'
    AND report_number = 'AR2197';