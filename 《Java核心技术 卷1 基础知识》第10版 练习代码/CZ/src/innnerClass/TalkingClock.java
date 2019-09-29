package innnerClass;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.Timer;

/**
 * A clock that prints the time in regular intervals.
 *
 * @author Chang Zheng
 * @title: TalkingClock
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/9/2919:29
 */
public class TalkingClock
{
    private int interval;
    private boolean beap;

    public TalkingClock(int interval, boolean beap)
    {
        this.interval = interval;
        this.beap = beap;
    }

    /**
     * start the clock
     *
     * @param
     * @return void
     * @throws
     * @description: TODO
     * @author Chang Zheng
     * @date 2019/9/29 19:34
     */
    public void start()
    {
        ActionListener listener = new TimePrinter();
        Timer t = new Timer(interval, listener);
        t.start();
    }

    private class TimePrinter implements ActionListener
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
}
