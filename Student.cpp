#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Student structure
struct Student {
    int id;
    string name;
    int age;
    float grade;
};

// Function prototypes
void addStudent(vector<Student>& students);
void displayStudents(const vector<Student>& students);
void searchStudent(const vector<Student>& students, int id);

int main() {
    vector<Student> students;
    int choice, id;

    while (true) {
        cout << "\nStudent Management System";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                cout << "Enter Student ID to search: ";
                cin >> id;
                searchStudent(students, id);
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

// Function to add a student
void addStudent(vector<Student>& students) {
    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Student Age: ";
    cin >> s.age;
    cout << "Enter Student Grade: ";
    cin >> s.grade;
    students.push_back(s);
    cout << "Student added successfully!\n";
}

// Function to display all students
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }
    cout << "\nStudent List:\n";
    for (const auto& s : students) {
        cout << "ID: " << s.id << " | Name: " << s.name << " | Age: " << s.age << " | Grade: " << s.grade << "\n";
    }
}

// Function to search for a student by ID
void searchStudent(const vector<Student>& students, int id) {
    for (const auto& s : students) {
        if (s.id == id) {
            cout << "Student Found: " << "ID: " << s.id << " | Name: " << s.name << " | Age: " << s.age << " | Grade: " << s.grade << "\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}
