- 交叉连接查询 笛卡尔积

SELECT * FROM product;
SELECT * FROM category;

-- 笛卡尔积，查出来的是两张表的乘积，查出来的结果没有意义
SELECT * FROM product, category;

-- 过滤出有意义的数据
SELECT * FROM product, category WHERE cno=cid;
SELECT * FROM product AS p, category AS c WHERE p.cno=c.cid;

-- 数据准备
INSERT INTO product VALUES(NULL, "耐克帝", 10, NULL);

- 内连接查询
只有对应上的数据才会查询出来
-- 隐式内连接
SELECT * FROM product p, category c WHERE p.cno=c.cid;
-- 显式内连接
SELECT * FROM product p INNER JOIN category c ON p.cno=c.cid;
-- 区别
	隐式内连接在查询出结果的基础上去做的where条件过滤
	显式内连接是带着条件去查询结果的，执行效率高

- 左外连接
左外连接，会将左表中的所有数据都查询数来，如果右表中没有对应的数据，就用null代替
SELECT * FROM product p LEFT OUTER JOIN category c ON	p.cno=c.cid;

- 准备工作
INSERT INTO category VALUES(100, "电脑办公", "电脑插插插");

- 右外连接
会将右表所有数据都查询出来，对于左表没有对应数据的用null代替
SELECT * FROM product p RIGHT OUTER JOIN category c ON	p.cno=c.cid;