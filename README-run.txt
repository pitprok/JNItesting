
#!/bin/bash
#The following commands will create an java executable file in the /src/main/java  folder
#This tutorial can be used as a bash script

#Before trying to create the executables, you need to add the paths for jni.h and jni_md.h to the enviromental variable C_INCLUDE_PATH
#Alternatively you can add the paths to the C compilation command
#e.g. -I/usr/lib/jvm/java-12-openjdk-12.0.1.12-1.rolling.fc30.x86_64/include -I/usr/lib/jvm/java-12-openjdk-12.0.1.12-1.rolling.fc30.x86_64/include/linux

#Go to the C directory

cd src/main/c/

#Create the shared object that contains the helloworld() method implementation

gcc -shared -o sharedobjects/libhelloworld.so -fPIC $(pwd)/app/HelloWorld.c

#Create the shared object that contains the implementation 
#of the native method sayHello(), which calls the aforementioned helloworld() method

gcc -shared -o sharedobjects/libhello.so -fPIC  $(pwd)/app/HelloJNI.c $(pwd)/sharedobjects/libhelloworld.so

#Add the path of the directory that contains the shared objects to LD_LIBRARY_PATH
#This is necessary in order for the Java program to find the "hello" library (libhello.so)
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:$(pwd)/sharedobjects"

#Navigate to the file that contains your java project

cd ../java

#Compile the java executable which calls the native sayHello() method

javac -h native app/HelloJNI.java

#(Optional) Run the executable

java app.HelloJNI
