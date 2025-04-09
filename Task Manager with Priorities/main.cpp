#include <iostream>
#include <queue>
#include <string>
#include <fstream>
using namespace std;

struct Task {
    string description;
    int priority;

    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

priority_queue<Task> tasks;

void addTask() {
    string desc;
    int prio;
    cin.ignore(); 
    cout << "Enter task description: ";
    getline(cin, desc);
    cout << "Enter task priority (higher number = higher priority): ";
    cin >> prio;

    tasks.push({ desc, prio });
    cout << "Task added successfully!\n\n";
}

void executeTask() {
    if (!tasks.empty()) {
        cout << "Executed task: " << tasks.top().description << " (priority " << tasks.top().priority << ")\n";
        tasks.pop();
    }
    else {
        cout << "No tasks to execute!\n";
    }
    cout << endl;
}

void showTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n\n";
        return;
    }

    priority_queue<Task> copy = tasks;
    cout << "Current tasks:\n";
    while (!copy.empty()) {
        cout << " - " << copy.top().description << " (priority " << copy.top().priority << ")\n";
        copy.pop();
    }
    cout << endl;
}

void saveTasks() {
	ofstream file("tasks.txt");
	if (file.is_open()) {
		priority_queue<Task> copy = tasks;
		while (!copy.empty()) {
			file << copy.top().description << "," << copy.top().priority << "\n";
			copy.pop();
		}
		file.close();
	}
}

int main() {
    int choice;

    do {
        cout << "====== TASK MANAGER ======\n";
        cout << "1. Add Task\n";
        cout << "2. Execute Task\n";
        cout << "3. Show Tasks\n";
        cout << "4. Save Tasks\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1: addTask(); break;
        case 2: executeTask(); break;
        case 3: showTasks(); break;
        case 5: cout << "Goodbye!\n"; break;
		case 4: saveTasks(); break;
        default: cout << "Invalid option!\n\n";
        }

    } while (choice != 5);

    return 0;
}
