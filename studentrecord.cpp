#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Student {
    int roll;
    string name;
    float marks;
};

Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        cout << "Cannot add more students.\n";
        return;
    }

    cout << "\nEnter Roll Number: ";
    cin >> students[count].roll;
    cin.ignore(); // to clear buffer
    cout << "Enter Name: ";
    getline(cin, students[count].name);
    cout << "Enter Marks: ";
    cin >> students[count].marks;

    count++;
    cout << "Student added successfully!\n";
}

void displayAll() {
    if (count == 0) {
        cout << "\nNo records found.\n";
        return;
    }

    cout << "\n=== Student Records ===\n";
    for (int i = 0; i < count; i++) {
        cout << "Roll: " << students[i].roll
             << ", Name: " << students[i].name
             << ", Marks: " << students[i].marks << endl;
    }
}

void searchStudent() {
    int roll;
    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            cout << "Record Found!\n";
            cout << "Roll: " << students[i].roll
                 << ", Name: " << students[i].name
                 << ", Marks: " << students[i].marks << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Student not found.\n";
}

void deleteStudent() {
    int roll;
    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            found = true;
            cout << "Student deleted successfully!\n";
            break;
        }
    }
    if (!found)
        cout << "Student not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n====== Student Record System ======\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            displayAll();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
