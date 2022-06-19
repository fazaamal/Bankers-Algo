<h1 align="center">Bankers Algorithm</h1>
  
   GROUP MEMBERS | MATRIC NO
------------ | -------------
HAFSA BINTE MAHBUB | 2024364
FAZA AMAL SOPHIAN | Content column 2
FAZA AMAL SOPHIAN | Content column 2
FAZA AMAL SOPHIAN | Content column 2

<h2 align="center">Introduction</h2>
Our Application implements a resource allocation and deadlock avoidance algorithm also reffered to as the "Bankers Algorithm". The program will read from an input .txt file that contains the maximum and allocation matrix of a six different threads then proced to run a Safety algorithm on the input and output the order in which the threads can execute in a safe state. The program will then output the result from the following requests: 

1. Request from Thread 1 arrives for (1, 0, 2)
2. Request from Thread 4 arrives for (3, 3, 0)
3. Request from Thread 0 arrives for (0, 2, 0)

<h2 align="center">How to Compile and Run the Code</h2>

* **Step 1 : Download The Source Code** : Download and save the source file and the input file as "inFile.cpp" and "inputFile.txt" respectively
* **Step 2 : Compile the Executable Code** : Compile and Link (aka Build) the source code "inFile.cpp" into executable code ("infile.exe" in Windows or "inFile" in UNIX/Linux/Mac
  - On IDE (such as CodeBlocks), push the "Build" button.
  - On Text editor with the GNU GCC compiler, start a CMD Shell (Windows) or Terminal (UNIX/Linux/Mac) and issue these commands: 
  
    ```
    // Windows (CMD shell) - Build "inFile.cpp" into "inFile.exe"
    > g++ -o hello.exe hello.cpp
 
    // UNIX/Linux/Mac (Bash shell) - Build "inFile.cpp" into "inFile"
    $ g++ -o hello hello.cpp
    }
    ```
* **Step 3 : Run the Executable Code** : Execute (Run) the program.
  - On IDE (such as CodeBlocks), push the "Run" button.
  - On Text Editor with GNU GCC compiler, issue these command from CMD Shell (Windows) or Terminal (UNIX/Linux/Mac):
  
    ```
    // Windows (CMD shell) - Run "inFile.exe" 
    > inFile
    Reading File and Assigning content to respective arrays...
    Process 0 is finished.
    Process 1 is finished.
    Process 2 is finished.
    Process 3 is finished.
    Process 4 is finished.
    
    System is in safe state
    Safe sequence is 0 1 2 3 4 
    Enter the process number and the new allocation values to check whether it will be successful: 
 
    // UNIX/Linux/Mac (Bash shell) - Run "inFile" 
    $ ./inFile
    hello, world
    }
    ```
