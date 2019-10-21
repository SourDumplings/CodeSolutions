package textFile;

import domain.Employee;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.time.LocalDate;
import java.util.Scanner;

/**
 * 展示以文本形式存取对象
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/2111:17
 */
public class TextFileTest
{
    public static void main(String[] args)
        throws FileNotFoundException, UnsupportedEncodingException
    {
        Employee[] staff = new Employee[3];

        staff[0] = new Employee("Carl Cracker", 75000, 1987, 12, 15);
        staff[1] = new Employee("Harry Hacker", 50000, 1989, 10, 1);
        staff[2] = new Employee("Tony Tester", 40000, 1990, 3, 15);

        // save all employee to the file employee.dat
        try (PrintWriter out = new PrintWriter("employee.dat", "UTF-8"))
        {
            writeData(staff, out);
        }

        // retrieve all records into a new array
        try (Scanner in = new Scanner(new FileInputStream("employee.dat"), "UTF-8"))
        {
            Employee[] newStaff = readData(in);

            // print the newly read employee records
            for (Employee e : newStaff)
            {
                System.out.println(e);
            }
        }
    }

    /**
     * Reads an array of employees from a scanner
     *
     * @param in
     * @return
     */
    private static Employee[] readData(Scanner in)
    {
        // retrieve the array size
        int n = in.nextInt();
        // consume newline
        in.nextLine();

        Employee[] employees = new Employee[n];
        for (int i = 0; i < n; i++)
        {
            employees[i] = readEmployee(in);
        }
        return employees;
    }

    /**
     * Reads employee data from a buffered reader
     *
     * @param in
     * @return
     */
    private static Employee readEmployee(Scanner in)
    {
        String line = in.nextLine();
        String[] tokens = line.split("\\|");
        String name = tokens[0];
        double salary = Double.parseDouble(tokens[1]);
        LocalDate hireDate = LocalDate.parse(tokens[2]);
        return new Employee(name, salary, hireDate.getYear(), hireDate.getMonthValue(),
            hireDate.getDayOfMonth());
    }

    /**
     * Writes all employees in an array to a print writer
     *
     * @param employees
     * @param out
     */
    private static void writeData(Employee[] employees, PrintWriter out)
    {
        // write number of employees
        out.println(employees.length);

        for (Employee e : employees)
        {
            writeEmployee(out, e);
        }
    }

    /**
     * Writes employee data to a print writer
     *
     * @param out
     * @param e
     */
    private static void writeEmployee(PrintWriter out, Employee e)
    {
        out.println(e.getName() + "|" + e.getSalary() + "|" + e.getHireDay());
    }
}
