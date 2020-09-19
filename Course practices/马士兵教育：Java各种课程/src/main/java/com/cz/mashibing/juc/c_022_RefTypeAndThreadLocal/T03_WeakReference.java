/**
 * 弱引用遭到gc就会回收
 */
package com.cz.mashibing.juc.c_022_RefTypeAndThreadLocal;

import java.lang.ref.WeakReference;

public class T03_WeakReference
{
    public static void main(String[] args)
    {
        WeakReference<M> m = new WeakReference<>(new M());

        System.out.println(m.get());
        System.gc();
        System.out.println(m.get());

        /*
        * 输出结果：
        com.cz.mashibing.juc.c_022_RefTypeAndThreadLocal.M@2acf57e3
        null
        finalize

        弱引用的作用在于：
        如果弱引用指向的对象被强引用指向，
        强引用消失后，该对象就该被回收了
        常用于容器，
        典型的应用是 ThreadLocal
        ThreadLocal 是把对象存在了 Thread 中的 ThreadLocalMap中
        这个 Map 的 key 是弱引用指向的 ThreadLocal 对象
        这样就保证这个 Map 的 key 不会影响 ThreadLocal 被回收
        这样就一定程度上防止了内存泄漏
        但是问题是此时 Map 中的 key 为 null 了其与值（引用着导致这个对象释放不掉）依然存于 Map 中访问不到
        依然会引起内存泄漏
        因此使用 ThreadLocal 里面对象不用了就一定要调用 remove 方法
        * */

        ThreadLocal<M> tl = new ThreadLocal<>();
        tl.set(new M());
        tl.remove();

    }
}

