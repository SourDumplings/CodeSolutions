package com.itheima.domain;

import java.util.Date;

public class UserBean
{
	private String username;
	private String password;
	private String email;
	private String phone;
	private String address;
	private Date birthday;
	public Date getBirthday()
	{
		return birthday;
	}
	public void setBirthday(Date birthday)
	{
		this.birthday = birthday;
	}
	public String getUsername()
	{
		return username;
	}
	public void setUsername(String username)
	{
		this.username = username;
	}
	public String getPassword()
	{
		return password;
	}
	public void setPassword(String password)
	{
		this.password = password;
	}
	public String getEmail()
	{
		return email;
	}
	public void setEmail(String email)
	{
		this.email = email;
	}
	public String getPhone()
	{
		return phone;
	}
	public void setPhone(String phone)
	{
		this.phone = phone;
	}
	public String getAddress()
	{
		return address;
	}
	public void setAddress(String address)
	{
		this.address = address;
	}
	@Override
	public String toString()
	{
		return "UserBean [username=" + username + ", password=" + password + ", email=" + email + ", phone=" + phone
				+ ", address=" + address + ", birthday=" + birthday + "]";
	}
	
	
}
