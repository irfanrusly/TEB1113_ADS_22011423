/*
name : muhammad adam irfan bin rusli
id : 22011423
group : 1
lab : 1
*/

#include <iostream>
#include <string>
using namespace std;

const int NUM_STUDENTS = 5;

struct Student {
    int id;
    string name;
    string phone;
    string email;
};

void inputStudent(Student& s, int index) {
    cout << "\nStudent " << index + 1 << ":\n";
    cout << "Enter ID: ";
    cin >> s.id;
    cin.ignore(); // Flush newline after integer input
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Email: ";
    getline(cin, s.email);
    cout << "Enter Phone Number: ";
    getline(cin, s.phone);
}

void displayStudent(const Student& s, int index) {
    cout << "Student " << index + 1 << "\n";
    cout << "ID     : " << s.id << "\n";
    cout << "Name   : " << s.name << "\n";
    cout << "Email  : " << s.email << "\n";
    cout << "Contact: " << s.phone << "\n";
    cout << "----------------------------------------\n";
}

int main() {
    Student students[NUM_STUDENTS];

    cout << "Enter details for " << NUM_STUDENTS << " students:\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
        inputStudent(students[i], i);
    }

    cout << "\nStudent Database:\n";
    cout << "========================================\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
        displayStudent(students[i], i);
    }

    return 0;
}
