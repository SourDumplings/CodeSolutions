package generic.exception;

/**
 * 正常情况下是必须捕获线程run方法的所有受查异常把其包装到非受查异常中
 * 但是run方法却声明为不抛出任何受查异常，这就利用泛型异常类和SuppressWarning注解把编译器给哄了。
 *
 * @author CHANG Zheng
 * @title: Block
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/718:53
 */
public abstract class Block
{
    public abstract void body() throws Exception;

    public Thread toThread()
    {
        return new Thread()
        {
            public void run()
            {
                try
                {
                    body();
                }
                catch (Throwable t)
                {
                    Block.<RuntimeException>throwAs(t);
                }
            }
        };
    }

    @SuppressWarnings("unchecked")
    public static <T extends Throwable> void throwAs(Throwable e) throws T
    {
        throw (T) e;
    }
}
