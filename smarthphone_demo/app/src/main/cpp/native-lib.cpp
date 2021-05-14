#include <jni.h>

#include "smartphone.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_hello_1cmake_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    string hello = "Welcome to AirController";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_hello_1cmake_MainActivity_listEvents(JNIEnv* env, jobject /* this */) {
    DataLog dado;
    dado.addEvent();
    string info = dado.listEvents();
    return env->NewStringUTF(info.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_hello_1cmake_MainActivity_totalTime(JNIEnv* env,jobject /* this */) {
    DataLog dado;
    dado.addEvent();
    string info = dado.totalTime();
    return env->NewStringUTF(info.c_str());
}