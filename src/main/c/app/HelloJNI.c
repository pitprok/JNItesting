#include <jni.h>        // JNI header provided by JDK
#include <stdio.h>      // C Standard IO Header
#include "HelloJNI.h"   // Generated
#include "HelloWorld.h" // Original C code I want to use in Java 
// Implementation of the native method sayHello()
JNIEXPORT void JNICALL Java_app_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
   helloworld();
   return;
}
