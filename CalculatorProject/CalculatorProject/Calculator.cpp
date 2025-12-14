/*
 * Calculator.cpp
 *
 * Date: 11/13/2025
 * Author: Daniel Gray
 */

#include <iostream>

using namespace std;

// main MUST return int
int main()
{
    // char statement[100]; // This variable was not used
    int op1, op2;
    char operation;
    char answer = 'Y'; // this is char, must have single quotes and semicolon.

    // Check for both lowercase 'y' and uppercase 'Y', bc could be lowercase.
    while (answer == 'y' || answer == 'Y')
    {
        cout << "Enter expression (e.g., 10 + 5)" << endl; // provide example prompt for user

        // Read in the correct, logical order
        cin >> op1 >> operation >> op2;

        // NO semicolon after the 'if'
		// Use { } to hold the code that runs, otherwise only first line runs conditionally
        if (operation == '+')
        {
            cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
        }

        // NO semicolon after the 'if'
        if (operation == '-')
        {
            cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
        }

        // NO semicolon after the 'if'
        if (operation == '*')
        {
            // Text " * " now matches the operation
            cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
        }

        // NO semicolon after the 'if'
        if (operation == '/')
        {
            // Text " / " now matches the operation
            cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
        }

        cout << "Do you wish to evaluate another expression? (Y/N) " << endl;
        cin >> answer;
    }

    // Add return 0 because main is int
    return 0;
}