package com.zju.se.nohair.fitness.web.admin.service.test;

import com.zju.se.nohair.fitness.web.admin.service.UserService;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName fitness
 * @date 2019/11/21 15:49
 */
@SpringBootTest
public class UserServiceTest {

  @Autowired
  private UserService userService;

  public void setUserService(UserService userService) {
    this.userService = userService;
  }
}
