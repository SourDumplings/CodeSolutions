package concurrency.blockingQueue;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

/**
 * 在一个目录及其子目录下搜索所有文件，打印出包含关键字的每一行。
 *
 * @author CHANG Zheng
 * @title: BlockingQueueTest
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/1321:24
 */
public class BlockingQueueTest
{
    private static final int FILE_QUEUE_SIZE = 10;
    private static final int SEARCH_THREADS = 100;
    private static final File DUMMY = new File("");
    private static BlockingQueue<File> queue = new ArrayBlockingQueue<>(FILE_QUEUE_SIZE);

    public static void main(String[] args)
    {
        try (Scanner sc = new Scanner(System.in))
        {
            System.out.println("Enter base directory (eg. /opt/jdk1.8.0/src): ");
            String directory = sc.nextLine();
            System.out.println("Enter keyword (eg. volatile): ");
            String keyword = sc.nextLine();

            Runnable enumerator = () ->
            {
                try
                {
                    enumerate(new File(directory));
                    queue.put(DUMMY);
                }
                catch (InterruptedException e)
                {
                }
            };

            new Thread(enumerator).start();
            for (int i = 0; i < SEARCH_THREADS; ++i)
            {
                Runnable searcher = () ->
                {
                    try
                    {
                        boolean done = false;
                        while (!done)
                        {
                            File file = queue.take();
                            if (file == DUMMY)
                            {
                                queue.put(file); // 防止从阻塞队列中拿文件的别的线程阻塞在take处，故放空文件标志DUMMY
                                done = true;
                            }
                            else
                            {
                                search(file, keyword);
                            }
                        }
                    }
                    catch (InterruptedException e)
                    {
                    }
                    catch (FileNotFoundException e)
                    {
                        e.printStackTrace();
                    }
                };
                new Thread(searcher).start();
            }
        }
    }

    /**
     * Searches a file for a given keyword and prints all matching lines.
     *
     * @param
     * @return void
     * @throws
     * @description: TODO
     * @author CHANG Zheng
     * @date 2019/10/13 21:35
     */
    private static void search(File file, String keyword) throws FileNotFoundException
    {
        try (Scanner sc = new Scanner(file, "UTF-8"))
        {
            int lineNumber = 0;
            while (sc.hasNext())
            {
                ++lineNumber;
                String line = sc.nextLine();
                if (line.contains(keyword))
                {
                    System.out.printf("%s:%d:%s%n", file.getPath(), lineNumber, line);
                }
            }
        }
    }

    /**
     * Recursively enumerates all files in a given directory and its subdirectories
     *
     * @param
     * @return void
     * @throws
     * @description: TODO
     * @author CHANG Zheng
     * @date 2019/10/13 21:29
     */
    private static void enumerate(File directory) throws InterruptedException
    {
        File[] files = directory.listFiles();
        for (File file : files)
        {
            if (file.isDirectory())
            {
                enumerate(file);
            }
            else
            {
                queue.put(file);
            }
        }
    }
}
