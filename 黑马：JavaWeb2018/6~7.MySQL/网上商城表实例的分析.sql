-- 用户表 (用户的ID,用户名,密码,手机)
CREATE TABLE USER(
	uid INT PRIMARY KEY AUTO_INCREMENT,
  	username VARCHAR(31),
  	PASSWORD VARCHAR(31),
  	phone  VARCHAR(11)
);

INSERT INTO USER VALUES(1,'zhangsan','123','13811118888');

-- 订单表 (订单编号,总价,订单时间 ,地址,外键用户的ID)
CREATE TABLE orders(
  	oid INT PRIMARY KEY AUTO_INCREMENT,
    	SUM INT NOT NULL,
      otime TIMESTAMP,
    	address VARCHAR(100),
    	uno INT,
    	FOREIGN KEY(uno) REFERENCES USER(uid)
  );
  INSERT INTO orders VALUES(1,200,NULL,'黑马前台旁边小黑屋',1);
  INSERT INTO orders VALUES(2,250,NULL,'黑马后台旁边1702',1);
  
  -- 商品表 (商品ID, 商品名称,商品价格,外键cno)
  CREATE TABLE product(
	pid INT PRIMARY KEY AUTO_INCREMENT,
  	pname VARCHAR(10),
  	price DOUBLE,
  	cno INT,
  	FOREIGN KEY(cno) REFERENCES category(cid)
);

INSERT INTO product VALUES(NULL,'小米mix4',998,1);
INSERT INTO product VALUES(NULL,'锤子',2888,1);
INSERT INTO product VALUES(NULL,'阿迪王',99,2);
INSERT INTO product VALUES(NULL,'老村长',88,3);
INSERT INTO product VALUES(NULL,'劲酒',35,3);
INSERT INTO product VALUES(NULL,'小熊饼干',1,4);
INSERT INTO product VALUES(NULL,'卫龙辣条',1,5);
INSERT INTO product VALUES(NULL,'旺旺大饼',1,5);

-- 订单项: 中间表(订单ID,商品ID,商品数量,订单项总价)
CREATE TABLE orderitem(
	ono INT,
  	pno INT,
  	FOREIGN KEY(ono) REFERENCES orders(oid),
  	FOREIGN KEY(pno) REFERENCES product(pid),
  	ocount INT,
  	subsum DOUBLE
);
-- 给1号订单添加商品 200块钱的商品
INSERT INTO orderitem VALUES(1,7,100,100);
INSERT INTO orderitem VALUES(1,8,101,100);

-- 给2号订单添加商品 250块钱的商品 ()
INSERT INTO orderitem VALUES(2,5,1,35);
INSERT INTO orderitem VALUES(2,3,3,99);

-- 商品分类表(分类ID,分类名称,分类描述)
CREATE TABLE category(
	cid INT PRIMARY KEY AUTO_INCREMENT,
  	cname VARCHAR(15),
  	cdesc VARCHAR(100)
);

INSERT INTO category VALUES(NULL,'手机数码','电子产品,黑马生产');
INSERT INTO category VALUES(NULL,'鞋靴箱包','江南皮鞋厂倾情打造');
INSERT INTO category VALUES(NULL,'香烟酒水','黄鹤楼,茅台,二锅头');
INSERT INTO category VALUES(NULL,'酸奶饼干','娃哈哈,蒙牛酸酸乳');
INSERT INTO category VALUES(NULL,'馋嘴零食','瓜子花生,八宝粥,辣条');
