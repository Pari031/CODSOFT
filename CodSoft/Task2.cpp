#include <iostream>
#include <limits> // For input validation

using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "Simple Calculator\n";

    // Input first number
    cout << "Enter the first number: ";
    while (!(cin >> num1)) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
        cout << "Invalid input. Please enter a valid number: ";
    }

    // Input second number
    cout << "Enter the second number: ";
    while (!(cin >> num2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number: ";
    }

    // Input operation
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform operation
    switch (operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Error: Division by zero is not allowed.\n";
            } else {
                cout << "Result: " << num1 / num2 << endl;
            }
            break;
        default:
            cout << "Invalid operation. Please enter +, -, *, or /.\n";
    }

    return 0;
}
