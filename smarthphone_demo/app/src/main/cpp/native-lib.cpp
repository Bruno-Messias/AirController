#include <jni.h>

#include "smartphone.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_hello_1cmake_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    string hello = "Welcome to AirController";
    return env->NewStringUTF(hello.c_str());
}

