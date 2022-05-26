# File-Movement-JNI

## This class file is used to move files using c++ through java JNI.

## Prerequisites:

- g++ compiler and JDk

- Below Commands are needed:
  - to create .h file 
    ```diff
    javac -h FileMovement.java
    ```
  
  - to create dll library file and link your .cpp file.
    ```diff
    x86_64-w64-mingw32-g++ -I "%JAVA_HOME%\include" -I "%JAVA_HOME%\include\win32" -shared -o fileCopy.dll FileCopy.cpp
    ```
    
  - to run the class - java FileMovement
  
- For running the class, steps 2 and 3 are enough.

