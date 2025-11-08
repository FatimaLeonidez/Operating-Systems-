<h1> Project Title: Creating a Basic OS </h1>
<em>Created by: Cecilia Duran, Fatima Leonidez, and Alejandra Rodriguez</em>

<h2>Project description:</h2> 
The following project is meant to demonstrate a simplified operating system. The functionalities of this simplified operating system include booting up the computer, prompting the user to log in or sign up, allowing the user to create a new account, permitting the user to log in after that new account has been created, and exiting the program. All in all, the program is made to mimic how an actual computer starts and operates.

<h2>Instructions for setting up and running the initial program:</h2> 
<p>This project can be run in Visual Studio Code or Visual Studio with the correct programming languages installed and their respective compilers downloaded. Web compilers are not recommended as they may only allow one file at a time. <br />
  
There are three files needed to run this program: auth.h, auth.cpp, and OS project1_main.cpp. All three files can be found on the main branch of the GitHub repository. Once all three files are open on a compiler such as Visual Studio, the program can be executed. The user must make sure to add the auth.cpp file and the auth.h file into the Header file folder of their Visual Studio compiler, otherwise the program will not run. A series of lines of text will appear upon execution of the program, prompting the user to enter strings of characters. These strings will represent the options to "log in" or "sign up", the username, the password, or the program termination command. In this manner, we have created a basic operating system capable of authenticating a unique user. </p>

<h2>Scheduling:</h2>
Three scheduling algorithms were added to the main portion of the project to simulate the process lifecycle. The chosen three are First Come First Serve (FCFS), Shortest Job First (SJF), and Priority Scheduling.

<h2> Representing a Process in the OS: </h2>
<p> To run this pogram the following files are required: process_main.cpp, Process.h, and Process.cpp, which can be viewed in the main branch of the GitHub repository. The process header file (Process.h) contains the attributes that define a process, getters and setters to obtain some of its attributes, and functions for process behaviors. Additionally, the implementaiton of the class was stored in its designated cpp file (process.cpp), where the functions were designed to provide the proper functionalites of a Process instance along with its state representation. Lastly, the main process cpp file (main_process.cpp) was designed to simulate and display a Process instance with its set PID, current state, remaining time, waiting time, and its turnaround time.  </p>
