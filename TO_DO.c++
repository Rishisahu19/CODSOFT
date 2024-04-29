#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;
};

// Function to add a task to the to-do list
void addTask(vector<Task>& todoList, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    todoList.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks in the to-do list
void viewTasks(const vector<Task>& todoList) {
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << i + 1 << ". ";
        cout << (todoList[i].completed ? "[X] " : "[ ] ");
        cout << todoList[i].description << endl;
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task>& todoList, size_t index) {
    if (index >= 1 && index <= todoList.size()) {
        todoList[index - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

// Function to remove a task from the to-do list
void removeTask(vector<Task>& todoList, size_t index) {
    if (index >= 1 && index <= todoList.size()) {
        todoList.erase(todoList.begin() + index - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

int main() {
    vector<Task> todoList;

    while (true) {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                cin.ignore(); // Ignore newline character left in the buffer
                string description;
                getline(cin, description);
                addTask(todoList, description);
                break;
            }
            case 2:
                viewTasks(todoList);
                break;
            case 3: {
                cout << "Enter task index to mark as completed: ";
                size_t index;
                cin >> index;
                markCompleted(todoList, index);
                break;
            }
            case 4: {
                cout << "Enter task index to remove: ";
                size_t index;
                cin >> index;
                removeTask(todoList, index);
                break;
            }
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
