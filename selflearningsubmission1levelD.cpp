#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <limits>

class Student {
private:
    std::string name;
    std::string id;
    int age;
    double yeargroup;
    std::vector<double> grades;

public:
    Student(const std::string& name, const std::string& id, int age, double yeargroup)
        : name(name), id(id), age(age), yeargroup(yeargroup) {}

    const std::string& getName() const { return name; }
    const std::string& getId() const { return id; }
    int getAge() const { return age; }
    double getGrade() const { return yeargroup; }
    const std::vector<double>& getGrades() const { return grades; }

    void addStudentGrade(double yeargroup) {
        grades.push_back(yeargroup);
    }
};

struct RemovePredicate {
    const std::string& id;

    RemovePredicate(const std::string& id) : id(id) {}

    bool operator()(const Student& student) const {
        return student.getId() == id;
    }
};

bool StudentGradesComparison(const Student& student1, const Student& student2) {
    return student1.getGrade() < student2.getGrade();
}

class SchoolStudentAdminSystem {
private:
    std::vector<Student> students;

public:
    void addstudentdetails(const Student& student) {
        students.push_back(student);
        std::cout << "Student added successfully." << std::endl;
    }

    void removeStudent(const std::string& id) {
        std::vector<Student>::iterator it = std::find_if(students.begin(), students.end(), RemovePredicate(id));
        if (it != students.end()) {
            students.erase(it);
            std::cout << "Student removed successfully." << std::endl;
        }
        else {
            std::cout << "Student ID " << id << " not found." << std::endl;
        }
    }

    void displayStudents() const {
        if (students.empty()) {
            std::cout << "No students found." << std::endl;
        }
        else {
            for (std::vector<Student>::const_iterator it = students.begin(); it != students.end(); ++it) {
                const Student& student = *it;
                std::cout << "Name: " << student.getName() << std::endl;
                std::cout << "ID: " << student.getId() << std::endl;
                std::cout << "Age: " << student.getAge() << std::endl;
                std::cout << "Grade: " << student.getGrade() << std::endl;
                std::cout << "Grades: ";
                const std::vector<double>& grades = student.getGrades();
                for (std::vector<double>::const_iterator it = grades.begin(); it != grades.end(); ++it) {
                    std::cout << *it << " ";
                }
                std::cout << std::endl;
                std::cout << "-------------------------" << std::endl;
            }
        }
    }

    void saveToLocalFile(const std::string& filename) const {
        std::ofstream file(filename.c_str());

        if (file.is_open()) {
            for (std::vector<Student>::const_iterator it = students.begin(); it != students.end(); ++it) {
                const Student& student = *it;
                file << student.getName() << ","
                    << student.getId() << ","
                    << student.getAge() << ","
                    << student.getGrade();

                const std::vector<double>& grades = student.getGrades();
                for (std::vector<double>::const_iterator it = grades.begin(); it != grades.end(); ++it) {
                    file << "," << *it;
                }

                file << "\n";
            }

            file.close();
            std::cout << "Data saved to local file successfully." << std::endl;
        }
        else {
            std::cerr << "Failed to open local file for writing." << std::endl;
        }
    }

    void loadToLocalFile(const std::string& filename) {
        students.clear();  // Clear existing student data

        std::ifstream file(filename.c_str());
        std::string line;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string name, id;
                int age;
                double yeargroup;

                if (std::getline(iss, name, ',') &&
                    std::getline(iss, id, ',') &&
                    iss >> age &&
                    iss.ignore(std::numeric_limits<std::streamsize>::max(), ',') &&
                    iss >> yeargroup) {

                    students.push_back(Student(name, id, age, yeargroup));

                    double yeargroup;
                    while (iss >> yeargroup) {
                        students.back().addStudentGrade(yeargroup);
                        if (iss.peek() == ',')
                            iss.ignore();
                    }
                }
            }

            file.close();
            std::cout << "Data loaded from local file successfully." << std::endl;
        }
        else {
            std::cerr << "Failed to open local file for reading." << std::endl;
        }
    }

    void addStudentGrade(const std::string& id, double yeargroup) {
        std::vector<Student>::iterator it;
        for (it = students.begin(); it != students.end(); ++it) {
            if (it->getId() == id) {
                it->addStudentGrade(yeargroup);
                std::cout << "Grade added to student ID " << id << " successfully." << std::endl;
                break;
            }
        }

        if (it == students.end()) {
            std::cout << "Student ID " << id << " not found." << std::endl;
        }
    }

    void sortStudentsGrades() {
        std::sort(students.begin(), students.end(), StudentGradesComparison);
        std::cout << "Students sorted by grade." << std::endl;
    }
};

bool login() {
    std::string username, password;

    std::cout << std::endl;
    std::cout << "Teacher Username: ";
    std::cin >> username;
    std::cout << "Teacher Password: ";
    std::cin >> password;

    return (username == "teacher123" && password == "teacher123");
}

int main() {
    if (!login()) {
        std::cout << "Login Detials Incorrect. System Shutting Down..." << std::endl;
        return 0;
    }

    SchoolStudentAdminSystem sms;

    int choice = 0;
    std::string filename = "studentsdetails.txt";

    while (choice != 8) {
        std::cout << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "School Student Admin System" << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "1. Add Student Detials" << std::endl;
        std::cout << "2. Remove Student" << std::endl;
        std::cout << "3. Display Students" << std::endl;
        std::cout << "4. Save to Local File" << std::endl;
        std::cout << "5. Load from Local File" << std::endl;
        std::cout << "6. Add Student Grade" << std::endl;
        std::cout << "7. Sort Students by Grade" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Incorrect Option. Only type numbers for menu option." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            {
                std::string name, id;
                int age;
                double yeargroup;

                std::cout << "Enter Student Name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);

                std::cout << "Enter Student ID: ";
                std::cin >> id;

                std::cout << "Enter Student Age: ";
                std::cin >> age;

                std::cout << "Enter Student year group: ";
                std::cin >> yeargroup;

                Student student(name, id, age, yeargroup);
                sms.addstudentdetails(student);
            }
            break;
        case 2:
            {
                std::string id;
                std::cout << "Enter student ID: ";
                std::cin >> id;
                sms.removeStudent(id);
            }
            break;
        case 3:
            sms.displayStudents();
            break;
        case 4:
            sms.saveToLocalFile(filename);
            break;
        case 5:
            sms.loadToLocalFile(filename);
            break;
        case 6:
            {
                std::string id;
                double grade;

                std::cout << "Enter student ID: ";
                std::cin >> id;

                std::cout << "Enter grade: ";
                std::cin >> grade;

                sms.addStudentGrade(id, grade);
            }
            break;
        case 7:
            sms.sortStudentsGrades();
            break;
        case 8:
            std::cout << "See you later. Bye..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    return 0;
}
