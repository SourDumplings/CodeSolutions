package cn.itcast.store.dao.daoImpl;

import java.sql.SQLException;
import java.util.List;
import java.util.Map;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.commons.beanutils.ConvertUtils;
import org.apache.commons.beanutils.converters.DateConverter;
import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanHandler;
import org.apache.commons.dbutils.handlers.BeanListHandler;
import org.apache.commons.dbutils.handlers.MapListHandler;
import org.apache.commons.dbutils.handlers.ScalarHandler;

import java.sql.Connection;

import cn.itcast.store.dao.OrderDao;
import cn.itcast.store.domain.Order;
import cn.itcast.store.domain.OrderItem;
import cn.itcast.store.domain.Product;
import cn.itcast.store.domain.User;
import cn.itcast.store.utils.JDBCUtils;

public class OrderDaoImpl implements OrderDao
{

	public void saveOrder(Connection conn, Order order) throws SQLException
	{
		// TODO Auto-generated method stub
		String sql = "insert into orders values(?, ?, ?, ?, ?, ?, ?, ?)";
		QueryRunner qr = new QueryRunner();
		Object[] params = {order.getOid(), order.getOrdertime(), order.getTotal(), order.getState(), order.getAddress(), order.getName(), order.getTelephone(), order.getUser().getUid()};
		qr.update(conn, sql, params);
	}

	public void saveOrderItem(Connection conn, OrderItem orderItem) throws SQLException
	{
		// TODO Auto-generated method stub
		String sql = "insert into orderitem values(?, ?, ?, ?, ?)";
		QueryRunner qr = new QueryRunner();
		Object[] params = {orderItem.getItemId(), orderItem.getQuantity(), orderItem.getTotal(), orderItem.getProduct().getPid(), orderItem.getOrder().getOid()};
		qr.update(conn, sql, params);
	}

	public int getTotalRecords(User user) throws SQLException
	{
		// TODO Auto-generated method stub
		String sql = "select count(*) from orders where uid=?";
		QueryRunner qr = new QueryRunner(JDBCUtils.getDataSource());
		Long num = (Long) qr.query(sql, new ScalarHandler(), user.getUid());
		return num.intValue();
	}

	public List<Order> findMyOrdersWithPage(User user, int startIndex, int pageSize) throws Exception
	{
		// TODO Auto-generated method stub
		String sql = "select * from orders where uid=? limit ?, ?";
		QueryRunner qr = new QueryRunner(JDBCUtils.getDataSource());
		List<Order> list = qr.query(sql, new BeanListHandler<Order>(Order.class), user.getUid(), startIndex, pageSize);
		
		// 遍历所有的订单
		for (Order order : list)
		{
			// 获取每笔订单的oid，查询每笔订单下的订单项以及订单项对应的商品信息
			String oid = order.getOid();
			String sql2 = "select * from orderitem o, product p where o.pid = p.pid and o.oid = ?";
			List<Map<String, Object>> list02 = qr.query(sql2, new MapListHandler(), oid);
			// 遍历list
			for (Map<String, Object> map : list02)
			{
				OrderItem orderItem = new OrderItem();
				Product product = new Product();
				
				
				// 由于BeanUtils将字符串"1992-3-3"向user对象的setBithday();方法传递参数有问题,手动向BeanUtils注册一个时间类型转换器
				// 1_创建时间类型的转换器
				DateConverter dt = new DateConverter();
				// 2_设置转换的格式
				dt.setPattern("yyyy-MM-dd");
				// 3_注册转换器
				ConvertUtils.register(dt, java.util.Date.class);
				
				// 将map中属于orderItem的数据自动填充到orderItem对象上
				BeanUtils.populate(orderItem, map);
				// 将map中属于product的数据自动填充到product对象上
				BeanUtils.populate(product, map);
				
				// 让orderItem和Product关联
				orderItem.setProduct(product);
				// 将订单项存入订单下的集合中
				order.getList().add(orderItem);
			}
		}
		return list;
	}

	public Order findOrderByOid(String oid) throws Exception
	{
		// TODO Auto-generated method stub
		String sql = "select * from orders where oid = ?";
		QueryRunner qr = new QueryRunner(JDBCUtils.getDataSource());
		Order order = (Order) qr.query(sql, new BeanHandler<Order>(Order.class), oid);
		
		// 根据订单id查询订单下的订单项对应的商品信息
		String sql2 = "select * from orderitem o, product p where o.pid= p.pid and o.oid = ?";
		List<Map<String, Object>> list = qr.query(sql2, new MapListHandler(), oid);
		// 遍历list
		for (Map<String, Object> map : list)
		{
			OrderItem orderItem = new OrderItem();
			Product product = new Product();
			
			
			// 由于BeanUtils将字符串"1992-3-3"向user对象的setBithday();方法传递参数有问题,手动向BeanUtils注册一个时间类型转换器
			// 1_创建时间类型的转换器
			DateConverter dt = new DateConverter();
			// 2_设置转换的格式
			dt.setPattern("yyyy-MM-dd");
			// 3_注册转换器
			ConvertUtils.register(dt, java.util.Date.class);
			
			// 将map中属于orderItem的数据自动填充到orderItem对象上
			BeanUtils.populate(orderItem, map);
			// 将map中属于product的数据自动填充到product对象上
			BeanUtils.populate(product, map);
			
			// 让orderItem和Product关联
			orderItem.setProduct(product);
			// 将订单项存入订单下的集合中
			order.getList().add(orderItem);
		}
		return order;
	}
	
	

}
