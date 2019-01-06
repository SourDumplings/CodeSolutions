
public class Main
{

	public static void main(String[] args)
	{
		// ≤‚ ‘¥˙¬Î
		Driver a = new FemaleDriver();
		Driver b = new MaleDriver();
		Vehicle x = new Car();
		Vehicle y = new Bus();
		a.drives(x);
		b.drives(y);

	}

}


abstract class Vehicle
{
	private String type;
	public Vehicle() {}
	public Vehicle(String s) { type = s; }
	public abstract void drivedByFemaleDriver();
	public abstract void drivedByMaleDriver();
}

class Bus extends Vehicle
{
	public Bus() {}
	public void drivedByFemaleDriver()
	{
		System.out.println("A female driver drives a bus.");
	}
	public void drivedByMaleDriver()
	{
		System.out.println("A male driver drives a bus.");
	}
}

class Car extends Vehicle
{
	public Car() {}
	public void drivedByFemaleDriver()
	{
		System.out.println("A female driver drives a car.");
	}
	public void drivedByMaleDriver()
	{
		System.out.println("A male driver drives a car.");
	}
}

abstract class Driver
{
	public Driver() {}
	public abstract void drives(Vehicle v);
}

class FemaleDriver extends Driver
{
	public FemaleDriver() {}
	public void drives(Vehicle v)
	{
		v.drivedByFemaleDriver();
	}
}

class MaleDriver extends Driver
{
	public MaleDriver() {}
	public void drives(Vehicle v)
	{
		v.drivedByMaleDriver();
	}
}


