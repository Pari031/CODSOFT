#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    srand(time(0)); 
    int secretNumber = rand() % 100 + 1; 
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100..." << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        // Input validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }

        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again.\n\n";
        } else if (guess < secretNumber) {
            cout << "Too low! Try again.\n\n";
        } else {
            cout << "\nCONGRATULATIONS! You guessed the number in " << attempts << " attempts.\n";
            break;
        }
    }

    return 0;
}
