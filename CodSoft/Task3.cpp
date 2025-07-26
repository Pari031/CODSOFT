#include <iostream>
#include <vector>
#include <limits> // For numeric_limits

using namespace std;

struct Task {
    string name;
    bool completed;
};

void addTask(vector<Task> &tasks) {
    Task newTask;
    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, newTask.name);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added.\n";
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to show.\n";
        return;
    }
    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "Complete" : "Pending") << "] " << tasks[i].name << endl;
    }
}

void markCompleted(vector<Task> &tasks) {
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if (cin.fail()) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a valid number.\n";
        return;
    }

    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void deleteTask(vector<Task> &tasks) {
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
        return;
    }

    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n===== TO-DO LIST MENU =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "\nEnter your choice (1-5): ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // clear input error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            cout << "\nInvalid input. Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: markCompleted(tasks); break;
            case 4: deleteTask(tasks); break;
            case 5: cout << "\nExiting To-Do List.\n"; break;
            default: cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
