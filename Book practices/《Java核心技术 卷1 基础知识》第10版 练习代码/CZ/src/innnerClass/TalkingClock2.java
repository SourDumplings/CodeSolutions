package innnerClass;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Date;

/**
 * 其包含有局部类TimePrinter的start方法，
 * 使用ReflectionTest，输入：
 * innnerClass.TalkingClock2$1TimePrinter
 * 输出：
 * class innnerClass.TalkingClock2$1TimePrinter
 * {
 * innnerClass.TalkingClock2$1TimePrinter(innnerClass.TalkingClock2, boolean);
 * <p>
 * public void actionPerformed(java.awt.event.ActionEvent);
 * <p>
 * final boolean val$beap;
 * final innnerClass.TalkingClock2 this$0;
 * }
 *
 * @author CHANG Zheng
 * @title: TalkingClock2
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/29:11
 */
public class TalkingClock2
{
    public void start(int interval, boolean beap)
    {
        class TimePrinter implements ActionListener
        {
            public void actionPerformed(ActionEvent event)
            {
                System.out.println("At the tone, the time is " + new Date());
                if (beap)
                {
                    Toolkit.getDefaultToolkit().beep();
                }
            }
        }
        ActionListener listener = new TimePrinter();
        Timer t = new Timer(interval, listener);
        t.start();
    }
}
