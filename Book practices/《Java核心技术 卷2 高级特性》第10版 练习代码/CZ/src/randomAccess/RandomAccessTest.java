package randomAccess;

import domain.Employee;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.time.LocalDate;

/**
 * 将三条记录写入到一个数据文件中，然后以逆序地将他们从文件中读回
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/2121:22
 */
public class RandomAccessTest
{
    public static void main(String[] args) throws IOException
    {
        Employee[] staff = new Employee[3];

        staff[0] = new Employee("Carl Cracker", 75000, 1987, 12, 15);
        staff[1] = new Employee("Harry Hacker", 50000, 1989, 10, 1);
        staff[2] = new Employee("Tony Tester", 40000, 1990, 3, 15);

        String path = "./CZ/resources/employee.dat";

        try (DataOutputStream out = new DataOutputStream(
            new FileOutputStream(path)))
        {
            // save all employee records to the file employee.dat
            for (Employee e : staff)
            {
                writeData(out, e);
            }
        }

        try (RandomAccessFile in = new RandomAccessFile(path, "r"))
        {
            // retrieve all records into a new array

            // compute the array size
            int n = (int) (in.length() / Employee.RECORD_SIZE);
            Employee[] newStaff = new Employee[n];

            // read employees in reverse order
            for (int i = n - 1; i >= 0; --i)
            {
                in.seek(i * Employee.RECORD_SIZE);
                newStaff[i] = readData(in);
            }

            // print the newly read employee records
            for (Employee e : newStaff)
            {
                System.out.println(e);
            }
        }
    }


    private static Employee readData(RandomAccessFile in) throws IOException
    {
        String name = DataIO.readFixedString(Employee.NAME_SIZE, in);
        double salary = in.readDouble();
        int y = in.readInt();
        int m = in.readInt();
        int d = in.readInt();
        return new Employee(name, salary, y, m - 1, d);
    }

    /**
     * Writes employee data to a data output
     *
     * @param out
     * @param e
     */
    private static void writeData(DataOutputStream out, Employee e) throws IOException
    {
        DataIO.writeFixedString(e.getName(), Employee.NAME_SIZE, out);
        out.writeDouble(e.getSalary());

        LocalDate hireDay = e.getHireDay();
        out.writeInt(hireDay.getYear());
        out.writeInt(hireDay.getMonthValue());
        out.writeInt(hireDay.getDayOfMonth());
    }
}
