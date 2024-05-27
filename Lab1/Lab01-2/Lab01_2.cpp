//
//  Lab01_2.cpp
//  Lab01
//
//  Modified by Jeman Park on 2024/03/12.
//

#include <iostream>
using namespace std;

struct StudentRecord
{
    char department[20];
    char name[14];
    int student_id;
    float gpa;
    int totalCredits;
};

int main(int argc, const char * argv[]) {
    StudentRecord student;
    StudentRecord students[100];

    cout << "sizeof(student): "<< sizeof(student) << endl;
    cout << "sizeof(students): "<< sizeof(students) << endl;
    
    return 0;
}
