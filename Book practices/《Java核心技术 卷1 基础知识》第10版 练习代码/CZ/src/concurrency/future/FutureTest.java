package concurrency.future;

import java.io.File;
import java.util.Scanner;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

/**
 * @author CHANG Zheng
 * @title: FutureTest
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/1415:13
 */
public class FutureTest
{
    public static void main(String[] args)
    {
        try (Scanner sc = new Scanner(System.in))
        {
            System.out.println("Enter base directory (e.g. /usr/local/jdk5.0/src): ");
            String directory = sc.nextLine();
            System.out.println("Enter keyword (e.g. volatile): ");
            String keyword = sc.nextLine();

            MatchCounter counter = new MatchCounter(new File(directory), keyword);
            FutureTask<Integer> task = new FutureTask<>(counter);
            Thread t = new Thread(task);
            t.start();
            try
            {
                System.out.println(task.get() + " matching files.");
            }
            catch (ExecutionException e)
            {
                e.printStackTrace();
            }
            catch (InterruptedException e)
            {
            }
        }
    }
}
