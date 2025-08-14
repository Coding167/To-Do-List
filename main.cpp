#include <iostream>
#include <limits> // for numeric_limits
#include "file.h"
using namespace std;

vector<string> split(const string& text, char c) {
    vector<string> result;
    string current;

    for (char ch : text) {
        if (ch == c) {
            result.push_back(current);
            current.clear();
        } else {
            current += ch;
        }
    }

    result.push_back(current);
    return result;
}

int validateChoice(int start, int end, const string& message) {
    int choice;
    do {
        cout<<message;
        cin>>choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between "<<start<<" and "<<end<<".\n";
            choice = start - 1;
        } 
        else if (choice < 1 || choice > 5) {
            cout << "Choice out of range! Please enter "<<start<<" to "<<end<<".\n";
        }
    }while(choice > end || choice < start);
    return choice;
}

int main() {
    cout<<"==== Welcome to our To-Do list app ====\n";

    while (true) {
        cout<<"1. Add new Task\n"
            <<"2. View all tasks\n"
            <<"3. Mark task as complete\n"
            <<"4. Delete task\n"
            <<"5. Exit\n";
        int choice = validateChoice(1,5,"Enter Your Choice: ");
        
        // Features
        File file("data.csv");
        if (choice == 1) {
            cout<<"Add new task Feature.\n";
        }else if (choice == 2) {
            cout<<"View all Tasks Feature.\n";
        }else if (choice == 3) {
            cout<<"Mark task as Complate Feature.\n";
        }else if (choice == 4) {
            vector<string> tasks = file.read();
            tasks.erase(tasks.begin());
            if (tasks.empty()) {
                cout<<"You haven't any task.\n";
            }else {
                for (int i = 0 ; i < tasks.size() ; i++) {
                    vector<string> parts = split(tasks.at(i),',');
                    cout<<i+1<<". "<<parts.at(0)<<" - "<<(parts.at(1) == "1" ? "Complated" : "Not Complated")<<endl;
                }
                int c = validateChoice(0,tasks.size(), "Enter the task to delete it [0 to exit]: ");
                if (c != 0) {
                    cout<<c<<endl;
                    file.removeLine(c+1);
                }
            }
        }else {
            break;
        }
        
    }

    return 0;
}
