package objectStream;

import domain.Employee;
import domain.Manager;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

/**
 * 保存和重新加载Employee和Manager对象网络的代码
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @date 2019/10/23 14:28
 */
public class ObjectStreamTest
{
    public static void main(String[] args) throws IOException, ClassNotFoundException
    {
        Employee harry = new Employee("Harry Hacker", 50000, 1989, 10, 1);
        Manager carl = new Manager("Carl Cracker", 80000, 1987, 12, 15);
        carl.setSecretary(harry);
        Manager tony = new Manager("Tony Tester", 40000, 1990, 3, 15);
        tony.setSecretary(harry);

        Employee[] staff = new Employee[3];

        staff[0] = harry;
        staff[1] = carl;
        staff[2] = tony;

        String path = "./CZ/resources/employee.dat";
        // save all employee records to the file employee.dat
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(path)))
        {
            out.writeObject(staff);
        }

        // read all employee records from the file
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(path)))
        {
            // retrieve all records into a new array
            Employee[] newStaff = (Employee[]) in.readObject();

            // raise secretary's salary
            newStaff[1].raiseSalary(10);

            // print the newly read Employee records
            for (Employee e : newStaff)
            {
                System.out.println(e);
            }
        }
    }
}
