-- 查询分类名称为手机数码的所有商品
1.查询出分类名称为手机数码的ID
SELECT cid FROM category WHERE cname = "手机数码";
2.得出id为1的结果
SELECT * FROM product WHERE cno = (SELECT cid FROM category WHERE cname = "手机数码");

-- 查询出商品名称，商品分类名称的信息
--- 左连接
SELECT p.pname, c.cname FROM product p LEFT OUTER JOIN category c ON p.cno = c.cid;
SELECT p.pname, c.cname FROM product p LEFT JOIN category c ON p.cno = c.cid;
--- 子查询
SELECT pname, (SELECT cname FROM category c WHERE p.cno = c.cid) AS 商品分类名称 FROM product p;