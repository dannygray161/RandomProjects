==================================================
PROJECT NAME: Online Shopping Cart (Part 1)
DATE: November 2025
==================================================

## 1. 🛒 Application Description

This program is the first step in building an Online Shopping Cart application using C++.

**What It Does:**
The program allows a user to input the name, price, and quantity for two different items. After the input is complete, it calculates the individual cost for each item and displays the final grand total for both items combined.

**Key Concept:**
The application uses **Object-Oriented Programming (OOP)** by creating a custom data type called a **Class** (`ItemToPurchase`). This class acts as a blueprint for the items, ensuring the data (name, price, quantity) is organized and reusable.

---

## 2. 🗂️ The C++ Three-File Template Structure

This project is built using the standard, professional C++ **Three-File Structure**. This organization is the core template you should follow for almost any future C++ application you write.

| File Name | Purpose (The Blueprint) | Action Item for Future Projects |
| :--- | :--- | :--- |
| **ItemToPurchase.h** | **Declaration File (The Contract)**: This file declares *what* the class is. It tells the compiler the name of the class, what data it holds (attributes), and what functions it has (methods). | **Create a new .h file** (e.g., Car.h, Customer.h) for every new real-world concept you want to model. |
| **ItemToPurchase.cpp** | **Implementation File (The Code)**: This file defines *how* the functions declared in the `.h` file actually work. It contains the C++ code for the Constructors, Getters, and Setters. | **Create a new .cpp file** (e.g., Car.cpp, Customer.cpp) to hold the working code for your new class. |
| **ShoppingCart.cpp** | **Driver File (The Control Center)**: This file contains the `main()` function, which is the starting point of the whole program. It creates objects and uses the functions from the other files. | **This file remains your main program.** It handles user interaction (input/output) and runs the application logic. |

---

## 3. 🛠️ Future Template Guide: Steps to Follow

Use the existing three files as a starting template for your next project (e.g., a "Dog" class instead of "ItemToPurchase").

### Step 1: Design the Blueprint (The .h File)

1.  **Rename/Copy `ItemToPurchase.h`** to your new class name (e.g., `Dog.h`).
2.  **Change the Header Guard:** Update the protection line at the top (e.g., `#ifndef DOG_H`).
3.  **Change the Class Name:** Update `class ItemToPurchase` to `class Dog`.
4.  **Update Private Data:** In the `private:` section, delete `itemName`, `itemPrice`, and `itemQuantity`. Replace them with the data your new class needs (e.g., `string dogName;`, `int dogAge;`).
5.  **Update Public Functions:** In the `public:` section, change the names and parameters of the Constructors, Getters, and Setters to match your new data (e.g., change `SetName(string name)` to `SetName(string name)` and `GetPrice()` to `GetAge()`).

### Step 2: Implement the Code (The .cpp File)

1.  **Rename/Copy `ItemToPurchase.cpp`** to your new class name (e.g., `Dog.cpp`).
2.  **Update the Include:** Change `#include "ItemToPurchase.h"` to `#include "Dog.h"`.
3.  **Update All Definitions:** For every function definition, replace `ItemToPurchase::` with `Dog::`. Update the variable names and logic to match your new class structure.

### Step 3: Use the New Class (The Main File)

1.  **Rename/Copy `ShoppingCart.cpp`** to your main project name (e.g., `MainDogApp.cpp`).
2.  **Update the Include:** Change `#include "ItemToPurchase.h"` to `#include "Dog.h"`.
3.  **Update `main()`:** Replace the code that creates and uses `item1` and `item2` with code that creates and uses your new objects (e.g., `Dog myDog;`).
4.  **Update Input/Output:** Change all prompts and display messages (`cout` statements) to match your new application's goal.

---

## 4. 🚀 How to Compile

To run your application, you must compile **all** source files (`.cpp`) together.

### Command Line Compilation (Using g++)

Open your terminal or command prompt in the project directory and run this command:

```bash
g++ ItemToPurchase.cpp ShoppingCart.cpp -o ShoppingCartApp