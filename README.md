# Water_Management_System
My roject aims to develop a comprehensive water management system that monitors and controls water usage, detects leaks, and ensures optimal operation of a water supply network. The system utilizes various sensors and actuators to gather real-time data on water turbidity, flow rate, and potential leaks, while also providing control over a valve to regulate water flow. By integrating hardware components with software logic, the project enables efficient water resource management and helps mitigate potential water wastage or damage caused by leaks.

**Key Features:**

**Turbidity Monitoring:** The system incorporates a turbidity sensor to measure the clarity of water, providing insights into its quality and potential contamination.

**Flow Rate Measurement:** A flow sensor accurately calculates the rate of water flow, allowing for precise monitoring of consumption and leakage detection.

**Leak Detection:** By analyzing flow data and sensor readings, the system can detect abnormal patterns indicative of leaks in the water supply network.

**Valve Control:** An actuator controls the opening and closing of a valve, enabling automated regulation of water flow based on predetermined conditions.

**Data Reporting:** Real-time data on turbidity, leakage status, valve operation, and water usage are transmitted to a central monitoring system via serial communication, facilitating 
remote monitoring and analysis.

With its ability to monitor water quality, detect leaks, and optimize water usage, this project contributes to the efficient management of water resources, promoting sustainability and minimizing environmental impact. Additionally, the system's modular design allows for scalability and customization to suit various applications, from residential water management to industrial-scale operations.


**1-GIT**


Git is a version control system that tracks changes in files over time. It allows multiple developers to collaborate on projects by managing revisions and merging changes seamlessly. Git operates locally, enabling offline work, and integrates with remote repositories like GitHub for centralized collaboration. Its features include branching, tagging, and efficient handling of large projects.

**Commands used** 

git status

git add . 

git commit -m

git push

git clone

git checkout

git switch

git branch

git branch -r


**2-UML(Unified Modeling Language)**


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

[Example 1](https://github.com/Aribah97/Water_Management_System/blob/main/WMS_Code_Arduino/WMS_Code_Arduino.ino#L143) Remove extra space.

[Example 2](https://github.com/Aribah97/Water_Management_System/blob/main/WMS_Code_Arduino/WMS_Code_Arduino.ino#L11) Remove not needed line.

[Example 3](https://github.com/Aribah97/Water_Management_System/blob/main/WMS_Code_Arduino/WMS_Code_Arduino.ino#L93-94) Remove unwanted delay of 10 sec to 5 sec.


**6-7 CI/CD and Build management using Git hub Actions**


GitHub Actions is a powerful tool for implementing CI/CD and build management directly within your GitHub repository. It allows you to automate workflows, including building, testing, and deploying your code, all within the GitHub ecosystem. Here's how you can use GitHub Actions for CI/CD and build management. The most difficult part was that I am integrating a software and hardware based project due to which I faced alot of problems in my build management.

Yaml file Link "[CI/CD](https://github.com/Aribah97/Water_Management_System/blob/main/.github/workflows/CICD/main.yml)"
Build management link "[Build Management](https://github.com/Aribah97/Water_Management_System/actions/runs/9142426230/job/25137958808)"


**8- Unit Test**
The unit test was not simple fr this project as I was testing the values of sensors, due to which I checked the results on actual data for verification the image is the test I did.

![Interpreter](https://github.com/Aribah97/Water_Management_System/assets/152000741/e2a33ee6-80c2-47d2-8ada-eea929102203)

This is the output of my Test.

![image](https://github.com/Aribah97/Water_Management_System/assets/152000741/93d9c654-0706-452c-99f0-e0dcf30f541e)


![image](https://github.com/Aribah97/Water_Management_System/assets/152000741/22e1713d-1a6a-412e-b81a-c3dd7960b39e)


**9-IDE**


I have used [Arduino IDE](https://www.arduino.cc/en/software) because I had to proogram the controller to detect and provide the signals from actuator it uses c++ language I like it because it has alot of libraries, its free to use and you can acheive alot form it.

**Arduino Shortcuts that I Like.**

**New Sketch** Ctrl + N

**Open Sketch** Ctrl + O

**Save Sketch** Ctrl + S

**Verify/Compile** Ctrl + R

**Upload** Ctrl + U

**New Tab** Ctrl + Shift + N

**Close Tab** Ctrl + W

**Cut** Ctrl + X

**Copy** Ctrl + C

**Paste** Ctrl + V

**Select All** Ctrl + A

**Comment/Uncomment** Ctrl + /

**Go to Line** Ctrl + L

**Toggle Serial Monitor** Ctrl + Shift + M


**10-DSL Domain Specific Language** 


A [Domain-Specific Language (DSL)](https://github.com/Aribah97/Water_Management_System/blob/main/DSL/DSL.ino) is a specialized programming language crafted to efficiently tackle particular tasks within a defined domain or context. Unlike general-purpose languages, DSLs offer a higher level of abstraction, enabling users to articulate complex concepts or operations succinctly and intuitively. This alignment with the problem domain enhances readability, productivity, and collaboration among domain experts and developers. DSLs manifest in two primary forms: external DSLs, which are autonomous languages with their own syntax and semantics, and internal DSLs, which are seamlessly integrated within a host programming language. Both types of DSLs deliver targeted solutions, leveraging domain expertise to streamline development and elevate code quality within their respective domains.

*I have explained the domains of my project below and what they do in the code also*

**Leakage**

•	void leakage()

•	Checks for leaks and controls the valve state based on water usage, turbidity, and leak detection.

•	Utilizes a timer to check and update the leak status and valve state periodically.

**Flow Rate**

•	void flow()

•	flowRate = ((1000.0 / (millis() - previousMillis)) * pulse1Sec) / 4.5;

•	previousMillis = millis();

•	Calculates the flow rate from pulse counts and updates the total water usage.

•	Log flow rate and water used via the serial monitor.

**Turbidity**

•	void Turbidity()

•	volt += (analogRead(turbidityPin) / 1023.0) * 5;

•	Measures the turbidity of water by averaging multiple analog readings.

•	Converts the voltage readings to a turbidity value using a polynomial formula.

**Update Flow Rate:**

          flowMilliLitres = (flowRate / 60) * 1000;
          
          float flowLitres = (flowRate / 60);
          
          totalMilliLitres += flowMilliLitres;
          
          totalLitres += flowLitres;
          
          waterUsed = totalLitres;


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
