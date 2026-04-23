#include <iostream>
#include <vector>
using namespace std;

// Template Class
template <typename Temp>
class Student {
public:
    Temp studentId;
    string studentName;

    // Constructor
    Student(Temp id, string name) {
        studentId = id;
        studentName = name;
    }

    // Display method
    void showDetails() {
        cout << "ID: " << studentId << ", Name: " << studentName << endl;
    }
};

int main() {
    vector<Student<int>> studentList;
    int userChoice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> userChoice;

        if (userChoice == 1) {
            int idInput;
            string nameInput;

            cout << "Enter ID: ";
            cin >> idInput;
            cout << "Enter Name: ";
            cin >> nameInput;

            studentList.push_back(Student<int>(idInput, nameInput));
        }
        else if (userChoice == 2) {
            cout << "\nStudent List:\n";
            for (auto &studentObj : studentList) {
                studentObj.showDetails();
            }
        }
        else if (userChoice == 3) {
            int searchId;
            cout << "Enter ID to remove: ";
            cin >> searchId;

            bool isFound = false;
            for (auto iterator = studentList.begin(); iterator != studentList.end(); iterator++) {
                if (iterator->studentId == searchId) {
                    studentList.erase(iterator);
                    cout << "Student removed.\n";
                    isFound = true;
                    break;
                }
            }
            if (!isFound) cout << "Student not found.\n";
        }
        else if (userChoice == 4) {
            int searchId;
            cout << "Enter ID to search: ";
            cin >> searchId;

            bool isFound = false;
            for (auto &studentObj : studentList) {
                if (studentObj.studentId == searchId) {
                    studentObj.showDetails();
                    isFound = true;
                    break;
                }
            }
            if (!isFound) cout << "Student not found.\n";
        }

    } while (userChoice != 5);

    return 0;
}