# Water_Management_System
A project for managing water distribution among consumers.

**1-GIT**

Git is a version control system that tracks changes in files over time. It allows multiple developers to collaborate on projects by managing revisions and merging changes seamlessly. Git operates locally, enabling offline work, and integrates with remote repositories like GitHub for centralized collaboration. Its features include branching, tagging, and efficient handling of large projects.

**Commands used** 

git status,
git add . ,
git commit -m,
git push,
git clone,
git checkout,
git switch,
git branch,
git branch -r


**2-UML**

UML (Unified Modeling Language) diagrams are visual representations used in software engineering to illustrate system structures, behaviors, and interactions. They provide a standardized way to communicate complex systems, processes, and architectures among stakeholders. UML diagrams include various types such as class diagrams, sequence diagrams, activity diagrams, and use case diagrams, each serving different purposes. These diagrams aid in understanding, designing, documenting, and analyzing software systems, facilitating clearer communication and effective development processes.

There are several types of UML diagrams, each serving a specific purpose in software development and system modeling. Here are some common types:

**[Class Diagrams](https://github.com/Aribah97/Water_Management_System/blob/main/UML_Diagrams/UML_Class_Diagram.pdf)**: Represent the static structure of a system by showing classes, their attributes, methods, and relationships between classes.

**[Sequence Diagrams](https://github.com/Aribah97/Water_Management_System/blob/main/UML_Diagrams/UML_Sequence_Diagram.pdf)**: Illustrate the interactions between objects or components in a system over time, focusing on the order of messages exchanged.

**[Use Case Diagrams](https://github.com/Aribah97/Water_Management_System/blob/main/UML_Diagrams/UML_Use_Case_Diagram.pdf)**: Depict the interactions between actors (users or external systems) and a system to describe its functionality from a user's perspective.

**[Activity Diagrams](https://github.com/Aribah97/Water_Management_System/blob/main/UML_Diagrams/UML_Activity_Diagram.pdf)**: Visualize the flow of control or workflow within a system, detailing the steps or actions involved in a process.


**3-DDD Domain Driven Design**

[Domain-Driven Design (DDD)](https://github.com/Aribah97/Water_Management_System/blob/main/DDD.pdf) is a software development approach focused on creating software that closely aligns with business domains through collaboration between technical and domain experts. 


**4-Metrics**

I have used [SonarCloud](https://sonarcloud.io/summary/new_code?id=Aribah97_Water_Management_System) for the metrics of my project as SonarCloud is a cloud-based service for continuous code quality inspection, detecting bugs, vulnerabilities, and code smells. It provides key metrics such as bugs, vulnerabilities, code smells, test coverage, code duplications, complexity, and documentation quality. Additionally, it offers ratings for reliability, security, and maintainability, alongside measuring technical debt and codebase size. The goal is to achieve zero bugs and vulnerabilities, high test coverage, low code duplications and complexity, and maintain high reliability, security, and maintainability ratings, all while minimizing technical debt. SonarCloud integrates with CI/CD pipelines to provide real-time feedback and maintain high code quality standards.


**5-Clean Code Development**

**[Clean code development](https://github.com/Aribah97/Water_Management_System/blob/main/Clean%20Code%20Development.pdf)** involves writing code that is easy to understand, modify, and maintain. This approach emphasizes the importance of readability, simplicity, and clarity in code, enabling developers to collaborate effectively and produce high-quality software. Key principles include using meaningful names for variables, functions, and classes, breaking down code into small, cohesive modules, avoiding unnecessary complexity, and following consistent formatting and commenting practices. By adhering to these principles, developers can create code that is easy to read, test, and refactor, leading to improved productivity, reduced bugs, and enhanced maintainability throughout the software development lifecycle.



**8-IDE**

I have used [Arduino IDE](https://www.arduino.cc/en/software) because I had to proogram the controller to detect and provide the signals from actuator it uses c++ language I like it because it has alot of libraries, its free to use and you can acheive alot form it.

**Arduino Shortcuts that I Like.**

**New Sketch** Ctrl + N,
**Open Sketch** Ctrl + O,
**Save Sketch** Ctrl + S,
**Verify/Compile** Ctrl + R,
**Upload** Ctrl + U,
**New Tab** Ctrl + Shift + N,
**Close Tab** Ctrl + W,
**Cut** Ctrl + X,
**Copy** Ctrl + C,
**Paste** Ctrl + V,
**Select All** Ctrl + A,
**Comment/Uncomment** Ctrl + /,
**Go to Line** Ctrl + L,
**Toggle Serial Monitor** Ctrl + Shift + M



**11-Functional Programming**

[Functional Programming](https://github.com/Aribah97/Water_Management_System/blob/main/Functional_Programming.pdf)
Pulse Counting for Flow Measurement:

Function: pulseCounter
Description: This interrupt service routine increments the pulseCount variable each time a pulse from the flow sensor is detected.
System Initialization:

Function: setup
Description: Initializes serial communication, sets up pin modes, initializes the LCD, and attaches the interrupt for the flow sensor.
Main Loop:

Function: loop
Description: Continuously calls other functions to update system state: Turbidity for turbidity measurement, lcdScr for updating the LCD screen, flow for calculating flow rate and water usage, leakage for detecting leaks, and sendData for sending data.
Leak Detection and Valve Control:

Function: leakage
Description: Checks for leaks every 60 seconds and controls the valve state based on water usage, turbidity, and leak detection.
Flow Rate and Water Usage Calculation:

Function: flow
Description: Calculates flow rate from pulse counts, updates total water usage, and prints the values to the serial monitor.
Turbidity Measurement:

Function: Turbidity
Description: Reads turbidity sensor values, averages them, and calculates turbidity in NTU (Nephelometric Turbidity Units).
LCD Screen Update:

Function: lcdScr
Description: Updates the LCD display every 3 seconds, cycling through screens showing turbidity, leak and valve status, and water usage limits.
Data Transmission Placeholder:

Function: sendData
Description: Placeholder for implementing data transmission logic, allowing for future expansion to send data to a remote server or other systems.
Key Functional Programming Aspects:
Modularity: Each function performs a specific task, enhancing readability and maintainability.
Encapsulation: Functions encapsulate specific behaviors, isolating them from other parts of the program.
Reusability: Functions like Turbidity and flow can be reused in other contexts or projects requiring similar functionality.
Event-Driven: The pulseCounter function is an interrupt service routine that responds to hardware events, demonstrating event-driven programming.
By organizing the code into these distinct functions, the system is easier to understand, debug, and extend with additional features.







