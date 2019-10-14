package concurrency.threadPool;

import java.io.File;
import java.util.Scanner;
import java.util.concurrent.*;

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

            ExecutorService pool = Executors.newCachedThreadPool();

            MatchCounter counter = new MatchCounter(new File(directory), keyword, pool);
            Future<Integer> result = pool.submit(counter);

            try
            {
                System.out.println(result.get() + " matching files.");
            }
            catch (ExecutionException e)
            {
                e.printStackTrace();
            }
            catch (InterruptedException e)
            {
            }
            pool.shutdown();

            int largestPoolSize = ((ThreadPoolExecutor) pool).getLargestPoolSize();
            System.out.println("largest pool size = " + largestPoolSize);
        }
    }
}
