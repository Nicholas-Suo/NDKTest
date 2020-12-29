
package com.example.ndktest;

public class Jni{
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native int intFromJNI();
    public native void init(String config);
}