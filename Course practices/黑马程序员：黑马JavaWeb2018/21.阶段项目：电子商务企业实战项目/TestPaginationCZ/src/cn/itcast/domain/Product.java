package cn.itcast.domain;

import java.util.Date;

public class Product
{
	private String pid; // 商品编号
	private String pname; // 商品名称
	private double market_price; // 商品市场价
	private double shop_price; // 商品商场价
	private String pimage; // 商品图片路径
	private Date pdate; // 商品上架日期
	private int is_hot; // 是否是热门商品
	private String pdesc; // 商品描述
	private int pflag; // 商品是否上架，0代表在货架上，1代表没货了
	private String cid; // 商品分类id
	
	
	public Product(String pid, String pname, double market_price, double shop_price, String pimage, Date pdate,
			int is_hot, String pdesc, int pflag, String cid)
	{
		super();
		this.pid = pid;
		this.pname = pname;
		this.market_price = market_price;
		this.shop_price = shop_price;
		this.pimage = pimage;
		this.pdate = pdate;
		this.is_hot = is_hot;
		this.pdesc = pdesc;
		this.pflag = pflag;
		this.cid = cid;
	}
	
	
	
	
	public Product()
	{
		super();
	}




	@Override
	public String toString()
	{
		return "Product [pid=" + pid + ", pname=" + pname + ", market_price=" + market_price + ", shop_price="
				+ shop_price + ", pimage=" + pimage + ", pdate=" + pdate + ", is_hot=" + is_hot + ", pdesc=" + pdesc
				+ ", pflag=" + pflag + ", cid=" + cid + "]";
	}


	public String getPid()
	{
		return pid;
	}
	public void setPid(String pid)
	{
		this.pid = pid;
	}
	public String getPname()
	{
		return pname;
	}
	public void setPname(String pname)
	{
		this.pname = pname;
	}
	public double getMarket_price()
	{
		return market_price;
	}
	public void setMarket_price(double market_price)
	{
		this.market_price = market_price;
	}
	public double getShop_price()
	{
		return shop_price;
	}
	public void setShop_price(double shop_price)
	{
		this.shop_price = shop_price;
	}
	public String getPimage()
	{
		return pimage;
	}
	public void setPimage(String pimage)
	{
		this.pimage = pimage;
	}
	public Date getPdate()
	{
		return pdate;
	}
	public void setPdate(Date pdate)
	{
		this.pdate = pdate;
	}
	public int getIs_hot()
	{
		return is_hot;
	}
	public void setIs_hot(int is_hot)
	{
		this.is_hot = is_hot;
	}
	public String getPdesc()
	{
		return pdesc;
	}
	public void setPdesc(String pdesc)
	{
		this.pdesc = pdesc;
	}
	public int getPflag()
	{
		return pflag;
	}
	public void setPflag(int pflag)
	{
		this.pflag = pflag;
	}
	public String getCid()
	{
		return cid;
	}
	public void setCid(String cid)
	{
		this.cid = cid;
	}
	
	
}
