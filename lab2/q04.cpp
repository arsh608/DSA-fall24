#include <iostream>
#include <cstdlib>
#include <ctime>

#define NUM_DEPARTMENTS 4

using namespace std;

int* department_students[NUM_DEPARTMENTS];
int student_counts[NUM_DEPARTMENTS] = {3, 4, 2, 1};

int main() {
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));

    for (int dept = 0; dept < NUM_DEPARTMENTS; ++dept) {
        department_students[dept] = new int[student_counts[dept]];
        for (int student = 0; student < student_counts[dept]; ++student)
            department_students[dept][student] = (rand() % 4) + (rand() % 2);
    }

    string department_names[NUM_DEPARTMENTS] = {"Software Engineering", "Artificial Intelligence", "Computer Science", "Data Science"};

    for (int dept = 0; dept < NUM_DEPARTMENTS; ++dept) {
        cout << department_names[dept] << ": ";
        for (int student = 0; student < student_counts[dept]; ++student) {
            cout << department_students[dept][student];
            if (student != student_counts[dept] - 1) cout << ", ";
        }
        cout << endl;
    }

    for (int dept = 0; dept < NUM_DEPARTMENTS; ++dept) {
        delete[] department_students[dept];
    }

    return 0;
}
