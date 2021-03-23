#include <iostream>
using namespace std;

class Student{
    public : 
    int height;
    int width;
};

int main() {
    Student *s = new Student;
    s -> height = 1;
    cout << s -> height;
}