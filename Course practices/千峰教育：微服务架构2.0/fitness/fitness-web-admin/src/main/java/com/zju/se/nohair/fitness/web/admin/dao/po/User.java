package com.zju.se.nohair.po;

import com.zju.se.nohair.fitness.commons.persistence.BaseEntity;
import java.io.Serializable;

/**
 * 用户实体类.
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName fitness
 * @date 2019/11/21 14:46
 */
public class User extends BaseEntity implements Serializable {
  private String name;
  private String phone;
  private String email;

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public String getPhone() {
    return phone;
  }

  public void setPhone(String phone) {
    this.phone = phone;
  }

  public String getEmail() {
    return email;
  }

  public void setEmail(String email) {
    this.email = email;
  }

  @Override
  public String toString() {
    final StringBuilder sb = new StringBuilder("User{");
    sb.append("name='").append(name).append('\'');
    sb.append(", phone='").append(phone).append('\'');
    sb.append(", email='").append(email).append('\'');
    sb.append('}');
    return sb.toString();
  }
}
