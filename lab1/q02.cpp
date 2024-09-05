#include <iostream>
#include <string>

using namespace std;

class Assessment {
private:
    string* studentName;
    int* marks;
    int* examDate;
public:
    Assessment() : studentName(nullptr), marks(nullptr), examDate(nullptr) {}

    Assessment(const Assessment& other) {
        studentName = other.studentName ? new string(*other.studentName) : nullptr;
        marks = other.marks ? new int(*other.marks) : nullptr;
        examDate = other.examDate ? new int(*other.examDate) : nullptr;
    }

    void setStudentName(const string& name) {
        delete studentName;
        studentName = new string(name);
    }

    void setMarks(int score) {
        delete marks;
        marks = new int(score);
    }

    void setExamDate(int date) {
        delete examDate;
        examDate = new int(date);
    }

    void showDetails() const {
        cout << "Student Name: " << (studentName ? *studentName : "N/A") 
             << "\nMarks       : " << (marks ? *marks : 0)
             << "\nExam Date   : " << (examDate ? *examDate : 0)
             << endl;
    }

    ~Assessment() {
        delete studentName;
        delete marks;
        delete examDate;
    }
};

int main() {
    Assessment test1;
    test1.setStudentName("Fasih");
    test1.setMarks(70);
    test1.setExamDate(1);

    Assessment test2(test1);

    cout << "Before changing any values in test2:" << endl;
    test1.showDetails();
    test2.showDetails();

    test2.setStudentName("Ali");

    cout << "\nAfter changing the student's name in test2:" << endl;
    test1.showDetails();
    test2.showDetails();

    return 0;
}
