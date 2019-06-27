#!/bin/bash
#The following commands will create an java executable file in the demo folder
#This tutorial can be used as a bash script

#Before trying to create the executables, you need to add the path for jni.h and jni_md.h to the enviromental variable C_INCLUDE_PATH
#Alternatively you can add the paths to the C compilation command
#e.g. -I/usr/lib/jvm/java-12-openjdk-12.0.1.12-1.rolling.fc30.x86_64/include -I/usr/lib/jvm/java-12-openjdk-12.0.1.12-1.rolling.fc30.x86_64/include/linux

#Go to the file that contains the demo program
cd src/main/demo

#Create the shared object that contains the helloworld() method implementation

gcc -shared -o libhelloworld.so -fPIC  HelloWorld.c

#Create the shared object that contains the implementation 
#of the native method sayHello(), which calls the helloworld() method

gcc -shared -o libhello.so -fPIC  HelloJNI.c libhelloworld.so

#Add the path of the demo(current) directory to LD_LIBRARY_PATH
#This is necessary in order for the program to find the "hello" library (libhello.so)
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:."

#Compile the java executable which calls the native sayHello() method
javac HelloJNI.java

#(Optional) Run the executable
java HelloJNI
