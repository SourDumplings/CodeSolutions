package innnerClass.anonymousInnerClass;

import javax.swing.*;

/**
 * @author CHANG Zheng
 * @title: AnonymousInnerClassTest
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/210:02
 */
public class AnonymousInnerClassTest
{
    public static void main(String[] args)
    {
        TalkingClock clock = new TalkingClock();
        clock.start(1000, true);

        // keep program running until user select "OK"
        JOptionPane.showMessageDialog(null, "Quit program?");
        System.exit(0);

    }
}
