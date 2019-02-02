-- insert
INSERT INTO t_stu (NAME, age) VALUES ("wangqiang", 28);
INSERT INTO t_stu VALUES (NULL, "wangqiang", 28);
-- delete
DELETE FROM t_stu WHERE id = 6;
-- update
UPDATE t_stu SET age = 38 WHERE NAME = "zhangsan";
-- query
SELECT * FROM t_stu;

