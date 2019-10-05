package logging;

import javax.swing.*;
import java.awt.*;
import java.io.IOException;
import java.util.logging.FileHandler;
import java.util.logging.Handler;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * A modification of the image viewer program that logs various events
 * 日志会以文件形式记录在用户根目录下
 *
 * @author CHANG Zheng
 * @title: LoggingImageViewer
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/517:48
 */
public class LoggingImageViewer
{
    public static void main(String[] args)
    {
        if (System.getProperty("java.util.logging.config.class") == null
            && System.getProperty("java.util.logging.config.file") == null)
        {
            try
            {
                Logger.getLogger("logging").setLevel(Level.ALL);
                final int LOG_ROTATION_COUNT = 10;
                Handler handler = new FileHandler("%h/LoggingImageViewer", 0, LOG_ROTATION_COUNT);
                Logger.getLogger("logging").addHandler(handler);
            }
            catch (IOException e)
            {
                Logger.getLogger("logging").log(Level.SEVERE,
                        "Can't create log file handler", e);
            }
        }

        EventQueue.invokeLater(()->
        {
            Handler windowHandler = new WindowHandler();
            windowHandler.setLevel(Level.ALL);
            Logger.getLogger("logging").addHandler(windowHandler);

            JFrame frame = new ImageViewerFrame();
            frame.setTitle("LoggingImageViewer");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            Logger.getLogger("logging").fine("Showing frame");
            frame.setVisible(true);
        });
    }
}
