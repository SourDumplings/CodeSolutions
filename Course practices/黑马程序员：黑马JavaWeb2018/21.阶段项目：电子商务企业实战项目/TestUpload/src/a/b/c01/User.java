package a.b.c01;

public class User
{
	private String username;
	private String password;
	private String userhead;
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
	public String getUserhead()
	{
		return userhead;
	}
	public void setUserhead(String userhead)
	{
		this.userhead = userhead;
	}
	public User(String username, String password, String userhead)
	{
		super();
		this.username = username;
		this.password = password;
		this.userhead = userhead;
	}
	public User()
	{
		super();
		// TODO Auto-generated constructor stub
	}
	@Override
	public String toString()
	{
		return "User [username=" + username + ", password=" + password + ", userhead=" + userhead + "]";
	}
	
}
