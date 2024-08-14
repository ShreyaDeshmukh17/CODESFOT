#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> todoList;
    int choice;
    string newTask;

    while (true) {
        cout << "\n!!TO-DO LIST MANAGER!!";
        cout <<endl<< "1. Add a New Task\n";
        cout << "2. Show All Tasks\n";
        cout << "3. Quit\n";
        cout << "Select an option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the task you want to add: ";
            cin.ignore();
            getline(cin, newTask);
            todoList.push_back(newTask);
            cout << "Task added to the list!\n";
        } 
        else if (choice == 2) {
            cout << "\nYour current tasks:\n";
            if (todoList.empty()) {
                cout << "No tasks in the list.\n";
            } else {
                for (size_t i = 0; i < todoList.size(); ++i) {
                    cout << i + 1 << ". " << todoList[i] << endl;
                }
            }
        } 
        else if (choice == 3) {
            cout << "Goodbye!\n";
            break;
        } 
        else {
            cout << "Please enter a valid option.\n";
        }
    }

    return 0;
}

