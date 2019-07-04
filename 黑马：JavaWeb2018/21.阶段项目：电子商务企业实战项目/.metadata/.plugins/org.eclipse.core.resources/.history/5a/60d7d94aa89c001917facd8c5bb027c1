package cn.itcast.store.service;

import java.sql.SQLException;

import cn.itcast.store.domain.Order;
import cn.itcast.store.domain.PageModel;
import cn.itcast.store.domain.User;

public interface OrderService
{

	void saveOrder(Order order) throws SQLException;

	PageModel findMyOrdersWithPage(User user, int curNum) throws Exception;

}
