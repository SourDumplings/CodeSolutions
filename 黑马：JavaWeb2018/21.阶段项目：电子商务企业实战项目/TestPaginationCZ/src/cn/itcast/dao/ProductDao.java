package cn.itcast.dao;

import java.sql.SQLException;
import java.util.List;

import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanListHandler;
import org.apache.commons.dbutils.handlers.ScalarHandler;

import cn.itcast.domain.Product;
import cn.itcast.utils.JDBCUtils;

public class ProductDao
{

	//统计表中有多少条数据
	public int findToralRecords() throws SQLException {
		QueryRunner qr = new QueryRunner(JDBCUtils.getDataSource());
		Long  num=(Long)qr.query("select count(*) from product",new ScalarHandler());
		return num.intValue();
	}

	public List findProducts(int startIndex, int pageSize) throws SQLException {
		String sql="select * from product limit ? ,? ";
		QueryRunner qr = new QueryRunner(JDBCUtils.getDataSource());
		return (List) qr.query(sql, new BeanListHandler<Product>(Product.class),startIndex,pageSize);
	}
}
