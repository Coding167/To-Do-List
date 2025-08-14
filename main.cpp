#include <iostream>
#include <limits> // for numeric_limits
#include "file.h"
using namespace std;

int main() {
    cout<<"==== Welcome to our To-Do list app ====\n";

    while (true) {
        cout<<"1. Add new Task\n"
            <<"2. View all tasks\n"
            <<"3. Mark task as complete\n"
            <<"4. Delete task\n"
            <<"5. Exit\n";
        int choice;
        // Validate Choice
        do {
            cout<<"Enter your choice: ";
            cin>>choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number between 1 and 5.\n";
                choice = 0;
            } 
            else if (choice < 1 || choice > 5) {
                cout << "Choice out of range! Please enter 1 to 5.\n";
            }
        }while(choice > 5 || choice < 1);
        
        // Features
        if (choice == 1) {
            cout<<"Add new task Feature.\n";
        }else if (choice == 2) {
            cout<<"View all Tasks Feature.\n";
        }else if (choice == 3) {
            cout<<"Mark task as Complate Feature.\n";
        }else if (choice == 4) {
            cout<<"Delete task Feature.\n";
        }else {
            break;
        }
        
    }

    return 0;
}
