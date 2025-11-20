#Vehicle Management System
📖 Project Overview

This project is a console-based C++ application designed to manage vehicles (cars and motorbikes). It demonstrates the use of object-oriented programming (OOP) principles such as inheritance and polymorphism, as well as file handling and menu-driven program design.

🎯 Objectives
Apply OOP concepts in a practical program.

Implement inheritance and polymorphism in C++.

Practice dynamic memory allocation and cleanup.

Demonstrate file persistence by saving and reading vehicle data.

Design a user-friendly, menu-driven console interface.

✨ Features
Add Car – Enter brand, model, and number of seats.

Add Motorbike – Enter brand, model, and engine capacity.

Display All Vehicles – Shows all vehicles with indexes for easy reference.

Update Vehicle Model – Select a vehicle by index and update its model.

Save Vehicles to File – Saves all vehicles to vehicles.txt in CSV format.

Read Vehicles from File – Displays raw contents of vehicles.txt.

Delete Vehicle – Select a vehicle by index and remove it from the system.

Exit – Cleanly closes the program and frees memory.

🛠️ Concepts Demonstrated
Inheritance – Car and Motorbike classes inherit from the Vehicle base class.

Polymorphism – Overriding displayInfo() and getDetails() methods.

Dynamic Memory Management – Vehicles stored in a vector of pointers, with cleanup at program exit.

File Handling – Saving and reading vehicle data using fstream.

Menu-Driven CLI – Structured options for user interaction.

📖 Sample Interaction
Code
--- Vehicle Management Menu ---
1. Add Car
2. Add Motorbike
3. Display All Vehicles
4. Update Vehicle Model
5. Save Vehicles to File
6. Read Vehicles from File
7. Delete Vehicle
0. Exit
Enter choice: 1
Enter brand, model, seats: Toyota Corolla 5
Car added successfully!
Vehicles saved to vehicles.txt
Press Enter to return to the main menu...
📚 Learning Outcomes
Ability to design and implement an OOP-based system in C++.

Understanding of polymorphism and dynamic binding.

Skills in handling user input and managing program flow.

Experience with file persistence and data storage.

Improved ability to build structured, user-friendly console applications.

👨‍💻 Author
Berryl Gisemba BSc in Computer Security and Forensics (Kabarak University), Cybersecurity educator, ethical hacker, and a developer.
# VehicleManagementSystem
