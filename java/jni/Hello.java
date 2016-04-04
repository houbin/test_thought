
package com.houbin.jni;

public class Hello
{
    static
    {
        try
        {
            System.loadLibrary("hello");
        }
        catch (UnsatisfiedLinkError e)
        {
            System.err.println("cannot load library: \n" + e.toString());
        }
    }

    public native static void native_say_hello(String strName);

    public static void SayHello(String name)
    {
        native_say_hello(name);
    }

    public static void main(String args[])
    {
        System.out.println(System.getProperty("java.library.path"));
        SayHello("123456");
    }
}

