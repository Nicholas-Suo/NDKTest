#include <jni.h>
#include <string>
#include <android/log.h>
#define LOG_TAG "jni_test"
#define LOGD(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ndktest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jint JNICALL  Java_com_example_ndktest_MainActivity_intFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    jint value = 88;
    return value;
}

/*
 * Class:     com_example_ndktest_MainActivity
 * Method:    init
 * Signature: (Ljava/lang/String;)V
 */
extern "C" JNIEXPORT void JNICALL Java_com_example_ndktest_MainActivity_init
        (JNIEnv * env, jobject, jstring jconfig){
         const char * config = env->GetStringUTFChars(jconfig,0);
         LOGD(" the config value is: %s" , config);
         env->ReleaseStringUTFChars(jconfig,config);
}
