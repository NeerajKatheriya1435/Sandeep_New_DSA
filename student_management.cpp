#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const string DATA_FILE = "students.txt";

struct Student {
    int id;
    string name;
    int age;
    string course;
    double marks;
};

bool parseInt(const string& text, int& value) {
    stringstream input(text);
    char extra;
    return (input >> value) && !(input >> extra);
}

bool parseDouble(const string& text, double& value) {
    stringstream input(text);
    char extra;
    return (input >> value) && !(input >> extra);
}

bool loadStudents(vector<Student>& students) {
    ifstream input(DATA_FILE.c_str());
    if (!input.is_open()) {
        ofstream createFile(DATA_FILE.c_str());
        if (!createFile.is_open()) {
            cerr << "Error: Could not open or create " << DATA_FILE << ".\n";
            return false;
        }
        return true;
    }

    string line;
    int lineNumber = 0;
    while (getline(input, line)) {
        ++lineNumber;
        if (line.empty()) {
            continue;
        }

        string fields[5];
        stringstream row(line);
        bool valid = true;
        for (int i = 0; i < 5; ++i) {
            if (!getline(row, fields[i], '|')) {
                valid = false;
                break;
            }
        }
        string extra;
        if (getline(row, extra, '|')) {
            valid = false;
        }

        Student student;
        student.name = fields[1];
        student.course = fields[3];
        if (!valid ||
            !parseInt(fields[0], student.id) ||
            !parseInt(fields[2], student.age) ||
            !parseDouble(fields[4], student.marks) ||
            student.id <= 0 || student.name.empty() ||
            student.age <= 0 || student.course.empty() ||
            student.marks < 0 || student.marks > 100) {
            cerr << "Error: Invalid student record on line " << lineNumber
                 << " of " << DATA_FILE << ".\n";
            return false;
        }

        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i].id == student.id) {
                cerr << "Error: Duplicate student ID on line " << lineNumber
                     << " of " << DATA_FILE << ".\n";
                return false;
            }
        }
        students.push_back(student);
    }

    if (input.bad()) {
        cerr << "Error: Could not read " << DATA_FILE << ".\n";
        return false;
    }
    return true;
}

bool saveStudents(const vector<Student>& students) {
    ofstream output(DATA_FILE.c_str(), ios::trunc);
    if (!output.is_open()) {
        cerr << "Error: Could not save records to " << DATA_FILE << ".\n";
        return false;
    }

    output << setprecision(10);
    for (size_t i = 0; i < students.size(); ++i) {
        output << students[i].id << '|'
               << students[i].name << '|'
               << students[i].age << '|'
               << students[i].course << '|'
               << students[i].marks << '\n';
    }

    if (!output) {
        cerr << "Error: A problem occurred while writing " << DATA_FILE << ".\n";
        return false;
    }
    return true;
}

bool readText(const string& prompt, string& value) {
    while (true) {
        cout << prompt;
        if (!getline(cin, value)) {
            return false;
        }
        if (!value.empty() && value.find('|') == string::npos) {
            return true;
        }
        cout << "Please enter a non-empty value without the '|' character.\n";
    }
}

bool readInt(const string& prompt, int& value) {
    string text;
    while (true) {
        cout << prompt;
        if (!getline(cin, text)) {
            return false;
        }
        if (parseInt(text, value)) {
            return true;
        }
        cout << "Please enter a whole number.\n";
    }
}

bool readPositiveInt(const string& prompt, int& value) {
    while (true) {
        if (!readInt(prompt, value)) {
            return false;
        }
        if (value > 0) {
            return true;
        }
        cout << "Value must be greater than zero.\n";
    }
}

bool readMarks(double& marks) {
    string text;
    while (true) {
        cout << "Enter marks (0-100): ";
        if (!getline(cin, text)) {
            return false;
        }
        if (parseDouble(text, marks) && marks >= 0 && marks <= 100) {
            return true;
        }
        cout << "Please enter a number from 0 to 100.\n";
    }
}

int findStudent(const vector<Student>& students, int id) {
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].id == id) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool readStudentDetails(Student& student) {
    if (!readText("Enter student name: ", student.name) ||
        !readPositiveInt("Enter age: ", student.age) ||
        !readText("Enter course: ", student.course) ||
        !readMarks(student.marks)) {
        return false;
    }
    return true;
}

void displayStudent(const Student& student) {
    cout << left << setw(8) << student.id
         << setw(24) << student.name
         << setw(8) << student.age
         << setw(20) << student.course
         << fixed << setprecision(2) << student.marks << '\n';
}

void listStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }

    cout << left << setw(8) << "ID"
         << setw(24) << "Name"
         << setw(8) << "Age"
         << setw(20) << "Course"
         << "Marks\n";
    cout << string(68, '-') << '\n';
    for (size_t i = 0; i < students.size(); ++i) {
        displayStudent(students[i]);
    }
}

bool addStudent(vector<Student>& students) {
    Student student;
    if (!readPositiveInt("Enter student ID: ", student.id)) {
        return false;
    }
    if (findStudent(students, student.id) != -1) {
        cout << "A student with that ID already exists.\n";
        return true;
    }
    if (!readStudentDetails(student)) {
        return false;
    }

    students.push_back(student);
    if (!saveStudents(students)) {
        students.pop_back();
        return true;
    }
    cout << "Student added successfully.\n";
    return true;
}

bool searchStudent(const vector<Student>& students) {
    int id;
    if (!readInt("Enter student ID to search: ", id)) {
        return false;
    }
    int index = findStudent(students, id);
    if (index == -1) {
        cout << "Student not found.\n";
    } else {
        cout << left << setw(8) << "ID"
             << setw(24) << "Name"
             << setw(8) << "Age"
             << setw(20) << "Course"
             << "Marks\n";
        displayStudent(students[index]);
    }
    return true;
}

bool updateStudent(vector<Student>& students) {
    int id;
    if (!readInt("Enter student ID to update: ", id)) {
        return false;
    }
    int index = findStudent(students, id);
    if (index == -1) {
        cout << "Student not found.\n";
        return true;
    }

    Student updated = students[index];
    cout << "Enter the updated details:\n";
    if (!readStudentDetails(updated)) {
        return false;
    }
    Student previous = students[index];
    students[index] = updated;
    if (!saveStudents(students)) {
        students[index] = previous;
        return true;
    }
    cout << "Student updated successfully.\n";
    return true;
}

bool deleteStudent(vector<Student>& students) {
    int id;
    if (!readInt("Enter student ID to delete: ", id)) {
        return false;
    }
    int index = findStudent(students, id);
    if (index == -1) {
        cout << "Student not found.\n";
        return true;
    }

    Student removed = students[index];
    students.erase(students.begin() + index);
    if (!saveStudents(students)) {
        students.insert(students.begin() + index, removed);
        return true;
    }
    cout << "Student deleted successfully.\n";
    return true;
}

int main() {
    vector<Student> students;
    if (!loadStudents(students)) {
        return 1;
    }

    while (true) {
        cout << "\n===== Student Management System =====\n"
             << "1. Add student\n"
             << "2. List students\n"
             << "3. Search student\n"
             << "4. Update student\n"
             << "5. Delete student\n"
             << "0. Exit\n";

        int choice;
        if (!readInt("Choose an option: ", choice)) {
            cout << "\nExiting Student Management System.\n";
            break;
        }

        switch (choice) {
            case 1:
                if (!addStudent(students)) {
                    cout << "\nExiting Student Management System.\n";
                    return 0;
                }
                break;
            case 2:
                listStudents(students);
                break;
            case 3:
                if (!searchStudent(students)) {
                    cout << "\nExiting Student Management System.\n";
                    return 0;
                }
                break;
            case 4:
                if (!updateStudent(students)) {
                    cout << "\nExiting Student Management System.\n";
                    return 0;
                }
                break;
            case 5:
                if (!deleteStudent(students)) {
                    cout << "\nExiting Student Management System.\n";
                    return 0;
                }
                break;
            case 0:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Please choose from the menu.\n";
        }
    }

    return 0;
}
