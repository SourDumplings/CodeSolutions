package concurrency.future;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.concurrent.FutureTask;

/**
 * This task counts the files in a directory and its subdirectories that
 * contain a given keyword.
 *
 * @author CHANG Zheng
 * @title: MatchCounter
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/1414:56
 */
public class MatchCounter implements Callable<Integer>
{
    private File directory;
    private String keyword;

    /**
     * Constructs a MatchCounter.
     *
     * @param
     * @return
     * @throws
     * @description: TODO
     * @author CHANG Zheng
     * @date 2019/10/14 14:57
     */
    public MatchCounter(File directory, String keyword)
    {
        this.directory = directory;
        this.keyword = keyword;
    }

    @Override
    public Integer call()
    {
        int count = 0;
        try
        {
            File[] files = directory.listFiles();
            List<Future<Integer>> results = new ArrayList<>();

            for (File file : files)
            {
                if (file.isDirectory())
                {
                    MatchCounter counter = new MatchCounter(file, keyword);
                    FutureTask<Integer> task = new FutureTask<>(counter);
                    results.add(task);
                    Thread t = new Thread(task);
                    t.start();
                }
                else
                {
                    if (search(file))
                    {
                        ++count;
                    }
                }
            }
            for (Future<Integer> result : results)
            {
                try
                {
                    count += result.get();
                }
                catch (ExecutionException e)
                {
                    e.printStackTrace();
                }
            }
        }
        catch (InterruptedException e)
        {
        }
        return count;
    }

    /**
     * Searches a file for a given keyword.
     *
     * @param
     * @return boolean
     * @throws
     * @description: TODO
     * @author CHANG Zheng
     * @date 2019/10/14 15:03
     */
    private boolean search(File file)
    {
        try
        {
            try (Scanner sc = new Scanner(file, "UTF-8"))
            {
                boolean found = false;
                while (!found && sc.hasNextLine())
                {
                    String line = sc.nextLine();
                    if (line.contains(keyword))
                    {
                        found = true;
                    }
                }
                return found;
            }
        }
        catch (IOException e)
        {
            return false;
        }
    }
}
