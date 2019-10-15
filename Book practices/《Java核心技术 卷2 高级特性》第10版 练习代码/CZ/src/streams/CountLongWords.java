package streams;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;

/**
 * @author CHANG Zheng
 * @title: CountLongWords
 * @projectName 《Java核心技术 卷2 高级特性》第10版 练习代码
 * @description: TODO
 * @date 2019/10/159:36
 */
public class CountLongWords
{
    public static void main(String[] args) throws IOException
    {
        String contents = new String(Files.readAllBytes(Paths.get("./CZ/resources/info.txt")), StandardCharsets.UTF_8);
        List<String> words = Arrays.asList(contents.split("\\PL+"));

        // 传统方法
        long count = 0;
        for (String w : words)
        {
            if (w.length() > 12)
            {
                ++count;
                System.out.print(" ");
                System.out.print(w);
            }
        }
        System.out.println();
        System.out.println(count);

        // 顺序流
        count = words.stream().filter(w -> w.length() > 12).count();
        System.out.println(count);

        // 并发流
        count = words.parallelStream().filter(w -> w.length() > 12).count();
        System.out.println(count);
    }
}
