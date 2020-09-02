package com.cz.mashibing.juc.c_012_Volatile;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName 马士兵教育：Java各种课程
 * @date 2020/8/31 20:35
 */
public class TestNew
{
    public static void main(String[] args)
    {
        final Object o = new Object();
    }
}

/*
字节码：
可以看出 new 语句是四条指令，因此可能出现指令重排序

// class version 52.0 (52)
// access flags 0x21
public class com/cz/mashibing/juc/c_012_Volatile/TestNew {

  // compiled from: TestNew.java

  // access flags 0x1
  public <init>()V
   L0
    LINENUMBER 9 L0
    ALOAD 0
    INVOKESPECIAL java/lang/Object.<init> ()V
    RETURN
   L1
    LOCALVARIABLE this Lcom/cz/mashibing/juc/c_012_Volatile/TestNew; L0 L1 0
    MAXSTACK = 1
    MAXLOCALS = 1

  // access flags 0x9
  public static main([Ljava/lang/String;)V
   L0
    LINENUMBER 13 L0
    NEW java/lang/Object
    DUP
    INVOKESPECIAL java/lang/Object.<init> ()V
    ASTORE 1
   L1
    LINENUMBER 14 L1
    RETURN
   L2
    LOCALVARIABLE args [Ljava/lang/String; L0 L2 0
    LOCALVARIABLE o Ljava/lang/Object; L1 L2 1
    MAXSTACK = 2
    MAXLOCALS = 2
}
*/
