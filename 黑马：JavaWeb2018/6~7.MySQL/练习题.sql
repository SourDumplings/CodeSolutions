-- 员工信息表
CREATE TABLE emp(
	empno INT,
	ename VARCHAR(50),
	job VARCHAR(50),
	mgr	INT,
	hiredate DATE,
	sal	DECIMAL(7,2),
	comm DECIMAL(7,2),
	deptno INT
);

INSERT INTO emp VALUES(7369,'SMITH','CLERK',7902,'1980-12-17',800,NULL,20);
INSERT INTO emp VALUES(7499,'ALLEN','SALESMAN',7698,'1981-02-20',1600,300,30);
INSERT INTO emp VALUES(7521,'WARD','SALESMAN',7698,'1981-02-22',1250,500,30);
INSERT INTO emp VALUES(7566,'JONES','MANAGER',7839,'1981-04-02',2975,NULL,20);
INSERT INTO emp VALUES(7654,'MARTIN','SALESMAN',7698,'1981-09-28',1250,1400,30);
INSERT INTO emp VALUES(7698,'BLAKE','MANAGER',7839,'1981-05-01',2850,NULL,30);
INSERT INTO emp VALUES(7782,'CLARK','MANAGER',7839,'1981-06-09',2450,NULL,10);
INSERT INTO emp VALUES(7788,'SCOTT','ANALYST',7566,'1987-04-19',3000,NULL,20);
INSERT INTO emp VALUES(7839,'KING','PRESIDENT',NULL,'1981-11-17',5000,NULL,10);
INSERT INTO emp VALUES(7844,'TURNER','SALESMAN',7698,'1981-09-08',1500,0,30);
INSERT INTO emp VALUES(7876,'ADAMS','CLERK',7788,'1987-05-23',1100,NULL,20);
INSERT INTO emp VALUES(7900,'JAMES','CLERK',7698,'1981-12-03',950,NULL,30);
INSERT INTO emp VALUES(7902,'FORD','ANALYST',7566,'1981-12-03',3000,NULL,20);
INSERT INTO emp VALUES(7934,'MILLER','CLERK',7782,'1982-01-23',1300,NULL,10);
INSERT INTO emp VALUES(7981,'MILLER','CLERK',7788,'1992-01-23',2600,500,20);

-- 部门信息表
CREATE TABLE dept(
	deptno		INT,
	dname		VARCHAR(14),
	loc		VARCHAR(13)
);

INSERT INTO dept VALUES(10, 'ACCOUNTING', 'NEW YORK');
INSERT INTO dept VALUES(20, 'RESEARCH', 'DALLAS');
INSERT INTO dept VALUES(30, 'SALES', 'CHICAGO');
INSERT INTO dept VALUES(40, 'OPERATIONS', 'BOSTON');

- 基本查询
-- 所有员工的信息
SELECT * FROM emp;
-- 薪资大于等于1000并且小于等于2000的员工信息
SELECT * FROM emp WHERE sal > 1000 AND sal <= 2000;
-- 从员工表中查询出所有的部门编号
SELECT deptno FROM emp;
-- 查询出名字以A开头的员工的信息
SELECT * FROM emp WHERE ename LIKE "A%";
-- 查询出名字第二个字母是L的员工信息
SELECT * FROM emp WHERE ename LIKE "_L%";
-- 查询出没有奖金的员工信息
SELECT * FROM emp WHERE comm IS NULL;
-- 所有员工的平均工资
SELECT AVG(sal) FROM emp;	
-- 所有员工的工资总和
SELECT SUM(sal) FROM emp;
-- 所有员工的数量
SELECT COUNT(*) FROM emp;
-- 最高工资
SELECT MAX(sal) FROM emp;
-- 最少工资
SELECT MIN(sal) FROM emp;

- 分组查询


- 子查询
-- 最高工资的员工信息
SELECT * FROM emp WHERE sal = (SELECT MAX(sal) FROM emp);
-- 最低工资的员工信息
SELECT * FROM emp WHERE sal = (SELECT MIN(sal) FROM emp);
-- 单行子查询(> < >= <= = <>)
	-- 查询出高于10号部门的平均工资的员工信息
-- SELECT AVG(sal) FROM emp WHERE deptno = 10; 10号部门平均工资：2916.67
SELECT * FROM emp WHERE sal > (SELECT AVG(sal) FROM emp WHERE deptno = 10);
	
-- 多行子查询(in  not in any all)    >any  >all
	-- 查询出比10号部门任何员工薪资高的员工信息
-- select * from emp where deptno = 10;
SELECT * FROM emp WHERE sal > ALL(SELECT sal FROM emp WHERE deptno = 10);

-- 多列子查询(实际使用较少)   in
	-- 和10号部门同名同工作的员工信息
-- 1.查出10号部门员工信息
SELECT ename, job FROM emp WHERE deptno = 10;
-- 2.得到结果
SELECT * FROM emp WHERE (ename, job) IN(SELECT ename, job FROM emp WHERE deptno = 10) AND deptno <> 10;

-- Select接子查询
	-- 获取员工的名字和部门的名字
-- 1.获得员工名字和部门编号
SELECT ename, deptno FROM emp;
-- 2.得到结果
SELECT ename, (SELECT dname FROM dept WHERE dept.`deptno` = emp.`deptno`) FROM emp;

-- from后面接子查询
	-- 查询emp表中经理信息
-- 1.查询经理ID
SELECT DISTINCT mgr FROM emp; 
-- 2.得到结果
SELECT * FROM emp, (SELECT DISTINCT mgr FROM emp) AS mgrs WHERE emp.`empno` = mgrs.mgr;	
	
-- having后面接子查询
	-- 有哪些部门的平均工资高于30号部门的平均工资
-- 1.得到30号部门的平均工资
SELECT AVG(sal) FROM emp WHERE deptno = 30;
-- 2.统计所有部门的平均工资
SELECT deptno, AVG(sal) FROM emp GROUP BY deptno;
-- 3.得到结果
SELECT deptno, AVG(sal) FROM emp GROUP BY deptno HAVING AVG(sal) > (SELECT AVG(sal) FROM emp WHERE deptno = 30);

- 综合案例
-- 部门平均工资>JONES工资的部门
SELECT deptno, AVG(sal) FROM emp GROUP BY deptno HAVING AVG(sal) > (SELECT sal FROM emp WHERE ename = "JONES");
-- 查询与SCOTT同一个部门的员工
SELECT * FROM emp WHERE  deptno = (SELECT deptno FROM emp WHERE ename = "SCOTT");
-- 工资高于30号部门所有人的员工信息
SELECT * FROM emp WHERE sal > ALL(SELECT sal FROM emp WHERE deptno = 30);
-- 查询工作和工资与MARTIN完全相同的员工信息
SELECT * FROM emp WHERE (sal, job) IN (SELECT sal, job FROM emp WHERE ename = "MARTIN");

-- 有两个以上直接下属的员工信息
-- 1.查出mgr信息
SELECT mgr FROM emp;
-- 2.分组统计mgr信息;
SELECT mgr, COUNT(*) FROM emp GROUP BY mgr HAVING COUNT(*) > 2;
-- 3.得出结果
SELECT * FROM emp WHERE empno IN(SELECT mgr FROM emp GROUP BY mgr HAVING COUNT(*) > 2);

-- 查询员工编号为7788的员工名称,员工工资,部门名称,部门地址
SELECT ename, sal, (SELECT dname FROM dept WHERE dept.`deptno` = emp.`deptno`) AS 部门名称,
(SELECT loc FROM dept WHERE dept.`deptno` = emp.`deptno`) AS 部门地址 FROM emp WHERE empno = 7788;
-- 或者：
SELECT ename, sal, dname, loc FROM emp, dept WHERE emp.`deptno` = dept.`deptno` AND emp.`empno` = 7788;

-- 查询出高于本部门平均工资的员工信息
-- 1.分组统计每个部门的平均工资
SELECT deptno, AVG(sal) FROM emp GROUP BY deptno;
-- 2.得出结果
SELECT * FROM emp e1 WHERE e1.sal > (SELECT AVG(e2.sal) FROM emp e2 WHERE e1.`deptno` = e2.`deptno` GROUP BY deptno);

-- 列出达拉斯加工作的人中,比纽约平均工资高的人
-- 1.列出在DALLAS工作的人的ID和loc
SELECT empno, loc FROM emp, dept WHERE emp.deptno = dept.`deptno` AND dept.`loc` = "DALLAS";
-- 2.计算出纽约平均工资
SELECT AVG(sal), loc FROM emp, dept WHERE emp.`deptno` = dept.`deptno` AND dept.`loc` = "NEW YORK";
-- 3.得出结果
SELECT * FROM emp, dept WHERE emp.`deptno` = dept.`deptno` AND dept.`loc` = "DALLAS" AND emp.sal >
(SELECT AVG(sal) FROM emp, dept WHERE emp.`deptno` = dept.`deptno` AND dept.`loc` = "NEW YORK");

-- 查询员工编号,姓名,经理编号和经理姓名
SELECT e1.empno, e1.ename, e1.mgr, mgrs.ename FROM emp AS e1, emp AS mgrs WHERE e1.`mgr` = mgrs.`empno`;

-- 查询出各个部门薪水最高的员工所有信息
-- 1.统计各个部门的最高薪水
SELECT deptno, MAX(sal) FROM emp GROUP BY deptno;
-- 2.得到结果
SELECT * FROM emp e1 WHERE sal = (SELECT MAX(sal) FROM emp e2 WHERE e1.`deptno` = e2.`deptno` GROUP BY deptno);
