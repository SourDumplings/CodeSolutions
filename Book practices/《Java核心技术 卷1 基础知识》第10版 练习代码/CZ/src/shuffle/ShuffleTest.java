package shuffle;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * @author CHANG Zheng
 * @title: ShuffleTest
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/1114:43
 */
public class ShuffleTest
{
    public static void main(String[] args)
    {
        List<Integer> numbers = new ArrayList<>();
        for (int i = 0; i <= 49; i++)
        {
            numbers.add(i);
        }
        Collections.shuffle(numbers);
        List<Integer> winningCombination = numbers.subList(0, 6);
        Collections.sort(winningCombination);
        System.out.println(winningCombination);
    }
}
