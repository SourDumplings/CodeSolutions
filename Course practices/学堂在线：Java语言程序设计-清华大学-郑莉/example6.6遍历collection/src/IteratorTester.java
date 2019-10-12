import java.util.Vector;
import java.util.Iterator;

public class IteratorTester
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		String[] num = {"one", "two", "three", "four",
				"five", "six", "seven", "eight", "nine",
				"ten"};
		Vector<String> aVector = new Vector<String>(
				java.util.Arrays.asList(num));
		System.out.println("Before Vector: " + aVector);
		Iterator<String> nums = aVector.iterator();
		while (nums.hasNext())
		{
			String aString = (String)nums.next();
			System.out.println(aString);
			if (aString.length() > 4)
				nums.remove();
		}
		System.out.println("After Vector: " + aVector);
	}

}
