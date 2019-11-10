<!--
 * @Autor: SourDumplings
 * @Date: 2019-10-26 16:39:40
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: Java 多线程常用代码框架
 -->
# 创建线程并启动
## 方法一
```java
Runnable r = () ->
{
    // task
};
Thread thread = new Thread(r);
thread.start();
```
## 方法二（耦合高，不推荐）
```java
class MyThread extends Thread
{
    public void run()
    {
        // task
    }
}
MyThread myThread = new MyThread();
myThread.start();
```

# 检测中断
## 不使用sleep等不会被中断的操作时
```java
Runnable r = () ->
{
    try
    {
        // do something
        while (!Thread.currentThread().isInterrupted() && (more work to do))
        {
            // do more work
        }
    }
    catch (InterruptedException e)
    {
        // Thread was interrupted during sleep or wait.
    }
    finally
    {
        // clean, if required
    }
    // Exiting the run method terminates the thread.
};
```
## 使用sleep等不会被中断的操作时
```java
Runnable r = () ->
{
    try
    {
        // do something
        while (more work to do)
        {
            // do more work
            Thread.sleep(delayTime);
        }
    }
    catch (InterruptedException e)
    {
        // Thread was interrupted during sleep or wait.
    }
    finally
    {
        // clean, if required
    }
    // Exiting the run method terminates the thread.
};
```

# 条件同步
## 使用外部锁
```java
class A
{
    private Lock lock;
    private Condition condition;

    public A()
    {
        lock = new ReentrantLock();
        condition = lock.newCondition();
    }

    public void fun1()
    {
        lock.lock();
        try
        {
            while (!(ok to proceed))
            {
                condition.await();
            }
            // do something
            // ok to call fun2, cuz using ReentrantLock
            condition.signalAll();
        }
        finally
        {
            lock.unlock();
        }
    }

    public void fun2()
    {
        lock.lock();
        try
        {
            // do something
        }
        finally
        {
            lock.unlock();
        }
    } 
}
```
## 使用内部锁
```java
class A
{
    public synchronized void fun1()
    {
        while (!(ok to proceed))
        {
            wait(); // wait on intrinsic object's single condition
        }
        // do something
        notifyAll();
    }

    public synchronized void fun2()
    {
        // do something
    } 
}
```
这个类 A 可为监视器类，客户端可以使用其内部对象锁。

# 客户端加锁
使用对象内部锁还可以用`synchronized(obj)`方法来获得对象obj的内部锁（此为客户端加锁方式，不推荐使用，除非可以确定obj内部修改方法的加锁方式）：
```java
synchronized(obj)
{
    // do something
}
```

# volatile
`volatile`关键字保证线程每次都从主存中读取变量，而不是从线程的工作内存（寄存器、内存缓存等），保证每次取到的都是最新值。典型应用：
```java
private volatile boolean done;
public boolean isDone() { return done; }
public void setDone() { done = true; }
```
但是`volatile`不提供原子性，即不能用于如下情况：
```java
public void flipDone() { done = !done; }
```

# 原子操作
`java.util.concurrent.atomic`包中提供了许多机器级的原子操作，如对整数自增：
```java
public static AtomicLong nextNumber = new AtomicLong();
// In some thread...
long id = nextNumber.incrementAndGet(); 
```

# 线程局部变量
要为每个线程构造一个`SimpleDateFormat`实例，使用`ThreadLocal`辅助类：
```java
public static final ThreadLocal<SimpleDateFormat> dataFormat = ThreadLocal.withInitial(() -> new SimpleDateFormat("yyyy-MM-dd"));
// ...
// 访问具体的格式化方法如下
String dataStamp = dataFormat.get().format(new Date());
```
在一个给定的线程中首次调用ThreadLocal对象的get方法时会调用initialValue方法。之后调用get方法就会返回属于当前线程的那个实例。

# 锁测试
```java
if (myLock.tryLock())
{
    // now this thread owns the lock
    try
    {
        // do something
    }
    finally { myLock.unlock(); }
}
else
{
    // do other things
}
```

# 读写锁
```java
private ReentrantReadWriteLock rwl = new ReentrantReadWriteLock();
private Lock readLock = rwl.readLock();
private Lock writeLock = rwl.writeLock();

// read
public double getTotalBalance()
{
    readLock.lock();
    try { . . . }
    finally { readLock.unlock(); }
}

// write
public void transfer()
{
    writeLock.lock();
    try { . . . }
    finally { writeLock.unlock(); }
}
```

# 阻塞队列
`java.util.concurrent`包中提供的阻塞队列常用的有`ArrayBlockingQueue`、`LinkedBlockingQueue`、`PriorityBlockingQueue`、`TranSferQueUe`等。

常用方法为`put`和`take`，为向队列中存取，会导致阻塞。

# Future 和 Callable
```java
Callable<Integer> myComputation = . . .;
FutureTask<Integer> task = new FutureTask<Integer>(myComputation);
Thread t = new Thread(task);
t.start();
// do other things
Integer result = task.get();
```

# 线程池
使用`Executor`类的方法创建线程池，具体有`newCachedThreadPool`、`newFixedThreadPool`、`newSingleThreadExecutor`、`newScheduledThreadPool`和`newSingleThreadScheduledExecutor`。例子：
```java
ExecutorService pool = Executors.newCachedThreadPool();
Callable<Integer> myComputation = . . .;
Future<Integer> result = pool.submit(myComputation); // submit 提交 Callable 或 Runnable 对象
. . .
pool.shutdown();
```

# 控制任务组
```java
ExecutorCompletionService<T> service = new ExecutorCompletionService<>(executor);
for (Callable<T> task : tasks)
    service.submit(task);
for (int i = 0; i < tasks.size(); ++i)
    processFuther(service.take().get());
```

# Fork-Join 框架
其用于分而治之地处理任务，要继承`RecursiveTask`（有结果）或者`RecursiveAction`。例如统计数组中有多少元素满足特定条件：
```java
class Counter extends RecursiveTask<Integer>
{
    . . .
    protected Integer compute()
    {
        if (to - from < THRESHOLD)
        {
            // solve problem directly
        }
        else
        {
            int mid = (to + from) / 2;
            Counter first = new Counter(values, from, mid, filter);
            Counter second = new Counter(values, mid, to, filter);
            invokeAll(first, second);
            return first.join() + second.join();
        }
    }
}
```