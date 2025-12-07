<h1> Project Title: Creating a Basic OS </h1>
<em>Created by: Cecilia Duran, Fatima Leonidez, and Alejandra Rodriguez</em>

<h2>Project description:</h2> 
The following project is meant to demonstrate a simplified operating system. The initial functionalities of this simplified operating system included booting up the computer, allowing the user to create a new account, permitting the user to log in after that new account has been created, and exiting the program. As the project expanded, the scheduling of processes and virtual memory functionalities were added. All in all, the program is made to mimic how an actual computer starts and operates.

<h2>Instructions for setting up and running the completed program:</h2> 
<p>This project can be run in Visual Studio Code or Visual Studio with the correct programming languages installed and their respective compilers downloaded. Web compilers are not recommended as they may only allow one file at a time. <br />
  
There are three types of files needed to run this program. They can be divided into three categories: the header files, the C++ files, and the main C++ file.
As the project progressed, new header and cpp files were added to expand the functionality of the Operating System.

The necessary header files are:
- Auth.h
- Process.h

The necessary cpp files are:
- Auth.cpp
- Process.cpp

The main cpp file that must be run is:


All files can be found on the main branch of the GitHub repository. Once all files are open on a compiler such as Visual Studio, the program can be executed. The user must make sure to add the header files to the Header file folder and the cpp files to the Source folder of their Visual Studio compiler; otherwise, the program will not run. </p>

<h2>Project-Part 1:</h2>
<p>In the earliest stages of the project, three files were created to simulate the functionality of turning on a computer and logging in. The files created for this task were: Auth.h, Auth.cpp, and main.cpp.</p>

<h2> Process: </h2>
<p> To run this program the following files are required: process_main.cpp, Process.h, and Process.cpp, which can be viewed in the main branch of the GitHub repository. The process header file (Process.h) contains the attributes that define a process, getters and setters to obtain some of its attributes, and functions for process behaviors. Additionally, the implementation of the class was stored in its designated C++ file (process.cpp), where the functions were designed to provide the proper functionalities of a Process instance along with its state representation. Lastly, the main process cpp file (main_process.cpp) was designed to simulate and display a Process instance with its set PID, current state, remaining time, waiting time, and its turnaround time.  </p>

<h2>Scheduling:</h2>
<p>Three scheduling algorithms were added to the main portion of the project to simulate the process lifecycle. The chosen three are First Come First Serve (FCFS), Shortest Job First (SJF), and Priority Scheduling. </p>

<h2>Virtual Memory:</h2>
<p> The virtual memory implemented is a simplified version of what an actual one can do. The virtual memory has a pre-made .txt file to store data instead of requiring user input. Our virtual memory system loads page requests from a pre-made .txt file, checks if each page is already stored in memory, records hits and faults, updates the page table, and then displays the results at the end. </p>


