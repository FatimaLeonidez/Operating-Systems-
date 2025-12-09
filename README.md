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
- FCFS.h
- Page.h

The necessary cpp files are:
- Auth.cpp
- Process.cpp
- FCFS.h
- Page.cpp

The main cpp file that must be run is:
- Main.cpp


All files can be found on the main branch of the GitHub repository. Once all files are open on a compiler such as Visual Studio, the program can be executed. The user must make sure to add the header files to the Header file folder and the cpp files to the Source folder of their Visual Studio compiler; otherwise, the program will not run. For the best results, at the top of the Visual Studio compiler, go to Project and select Add Class. From there, both the header and its corresponding cpp file can be created simultaneously. </p>

![WhatsApp Image 2025-12-06 at 21 32 30_03ee338b](https://github.com/user-attachments/assets/3a271ec2-3922-4db8-87da-35711c016dbd)

<h3>Upon Execution: </h3>

<p>This OS is mainly text-based. Upon execution, the booting process begins. The user will then be prompted to log in, sign up, or terminate the program. To properly proceed, the user must first sign up and make an account. They will then log in using those same credentials to unlock the following processes: Process, CPU Scheduling, and Virtual Memory. Finally, the program will log out the user and terminate.</p>

<h2>Project-Part 1:</h2>
<p>In the earliest stages of the project, three files were created to simulate the functionality of turning on a computer and logging in. The files created for this task were: Auth.h, Auth.cpp, and Main.cpp. These files were created to provide structure to the starting process. Branches were created to allow the user to choose whether to sign up, log in, or terminate the program. Based on their choices, the text would prompt them on how to proceed. The user has to adhere to the rules of how to enter their chosen password for simulated security purposes. By the end of this first portion of the project, the user is properly welcomed into the Operating System.<br><br>

Relevant submission details:
- Auth.h
- Auth.cpp
- Main.cpp
</p>


<h2> Process: </h2>
<p> The project was expanded from the first part to include the two additional files: Process.h and Process.cpp. The process header file (Process.h) contains the attributes that define a process, getters and setters to obtain some of its attributes, and functions for process behaviors. Additionally, the implementation of the class was stored in its designated C++ file (process.cpp), where the functions were designed to provide the proper functionalities of a Process instance along with its state representation. Lastly, the main cpp file (Main.cpp) was edited and designed to simulate and display a Process instance with its set PID, current state, remaining time, waiting time, and its turnaround time.<br><br>

Relevant submission details:
- Process.h
- Process.cpp
- Main.cpp (edited)

</p>

<h2>Scheduling:</h2>
<p>Three scheduling algorithms were added to the main portion of the project to simulate the process lifecycle. The chosen three are First Come First Serve (FCFS), Shortest Job First (SJF), and Priority Scheduling. <br> Two additional files were created to implement the FCFS Scheduling algorithm into the main file. These files were FCFS.h and FCFS.cpp. Meanwhile, the other two scheduling algorithms were directly implemented into the main. Each scheduling algorithm was designed by a member of the team. FCFS was designed and implemented by Fatima Leonidez, SJF was designed and implemented by Cecilia Duran, and Priority-based scheduling was designed and implemented by Alejandra Rodriguez. This lead to a unique outcome where each scheduling algorithm is presented with its very own design and manner, all while still displaying relevant information. <br><br>

Relevant submission details:
- FCFS.h
- FCFS.cpp
- Main.cpp (edited)
</p>

<h2>Virtual Memory:</h2>
<p> Two additional files were added to implement the functionality of virtual memory: Page.h and Page.cpp. The virtual memory implementation is a simplified version of what an actual one can do. Our virtual memory system loads page requests from the pre-made .txt file, checks if each page is already stored in memory, records hits and faults, updates the page table, and then displays the results at the end. 

Relevant submission details:
- Page.h
- Page.cpp
- Main.cpp (final edit)

<br><br>

At this point in time, the individual functionalities can only be observed by setting up and running the complete program. This is due to the extensive editing that was done as the project timeline progressed. <br> Thank you, and enjoy this simplified Operating System experience.

</p>


