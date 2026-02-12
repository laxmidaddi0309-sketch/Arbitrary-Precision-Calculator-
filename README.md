# Arbitrary-Precision-Calculator-
📖 Description
APC (Arbitrary Precision Calculator) is a C program that performs arithmetic operations on very large numbers that cannot be stored in normal data types like int or long long.
The numbers are stored digit-by-digit using linked lists, which allows calculations on numbers of any size.
This project supports:
Addition
Subtraction
Multiplication
Division
Comparison of large numbers

🛠️ Technologies Used
Language: C
Data Structure: Linked List (Doubly / Singly as per implementation)
Compiler: GCC

⚙️ Features
Handles very large integers (no size limit)
Works on positive and negative numbers
Modular code for each operation
Menu-driven program
Efficient handling of carry and borrow

📂 Project Structure
APC/│├── main.c          // Main menu and input handling
├── add.c           // Addition logic
├── sub.c           // Subtraction logic
├── mul.c           // Multiplication logic
├── div.c           // Division logic
├── compare.c       // Compare two large numbers
├── apc.h           // Header file (structure + function declarations)
└── README.md       // Project documentation
(File names can change based on your project – update this if needed)

▶️ How to Compile and Run
gcc main.c add.c sub.c mul.c div.c compare.c -o apc./apc

🧪 Sample Input / Output
Input:
Enter number 1: 123456789123456789  Enter number 2: 987654321987654321  Choose operation: +
Output:
Result: 1111111111111111110

🧠 Working Principle (Short)
Each digit of the number is stored in a node of a linked list
Operations are done digit by digit (like manual calculation)
Carry and borrow are handled node by node
Division is implemented using repeated subtraction / long division logic

🎯 Use Cases
Handling very large integers
Learning data structures (Linked Lists)
Understanding how calculators work internally
College mini-project / DSA project

📌 Future Improvements
Add modulo operation
Support decimal numbers
Improve division performance
Add file input/output
Add GUI interface
✅ README for report submission
✅ Flowchart + explanation for APCIs this conversation helpful so far?
