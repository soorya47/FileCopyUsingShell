#include <jni.h>     
#include <fstream>
#include "FileCopy.h"
#include <cstdlib>
#include <iostream>
#include <filesystem>

using namespace std;
std::string toString(JNIEnv *env, jstring jStr);
std::string toString(JNIEnv *env, jstring jStr){
 if (!jStr)
        return "";

    const jclass stringClass = env->GetObjectClass(jStr);
    const jmethodID getBytes = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
    const jbyteArray stringJbytes = (jbyteArray) env->CallObjectMethod(jStr, getBytes, env->NewStringUTF("UTF-8"));

    size_t length = (size_t) env->GetArrayLength(stringJbytes);
    jbyte* pBytes = env->GetByteArrayElements(stringJbytes, NULL);

    std::string ret = std::string((char *)pBytes, length);
    env->ReleaseByteArrayElements(stringJbytes, pBytes, JNI_ABORT);

    env->DeleteLocalRef(stringJbytes);
    env->DeleteLocalRef(stringClass);
    return ret;
}

JNIEXPORT jboolean JNICALL Java_FileCopy_copyFile(JNIEnv *env, jobject thisObj, jstring jStr1, jstring jStr2) {

string ret1=toString(env,jStr1);

string ret2=toString(env,jStr2);
try {
	ofstream file;
    file.open("test.ps1");

    string newArg = "-auto";
    string powershell;
    powershell = "$task = Copy-Item "+ret1+" -Destination "+ret2+"\n" ;
    file << powershell << endl;
    file.close();

	cout << "executing power shell script"<< endl;
    system("powershell -ExecutionPolicy Bypass -F test.ps1");

    remove("test.ps1");
	
	return true;
} catch (...) {
    cout << "Inside c++: error occured"<< endl;
  }
	
   return false;
}