#include <bits/stdc++.h>
using namespace std;

// ------------------- Base Class / Person class -------------------
class Person {
protected:
    string name;
    int age;
public:
    void inputPerson() {
        cout << "Enter Name : ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }
    void displayPerson() {
        cout << "Name: " << name << ", Age: " << age;
    }
};

// ------------------- Student class inheritad with person class-------------------
class Student : public Person {
private:
    string rollNo;
    int n_sub;
    string subjects[20];  // max 10 subjects
    float marks[20];
public:
    void inputStudent() {
        inputPerson();
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter number of subjects : ";
        cin >> n_sub;
        for(int i=0;i<n_sub;i++){
            cout << "Enter name of Subject " << i+1 << ": ";
            cin >> subjects[i];
            cout << "Enter marks for " << subjects[i] << ": ";
            cin >> marks[i];
        }
    }

    float getTotalMarks() {
        float total=0;
        for(int i=0;i<n_sub;i++) total += marks[i];
        return total;
    }

    float getAverage(){
         return getTotalMarks() / n_sub; 
    }

    float getPercentage() {
        return (getTotalMarks()/(n_sub * 100 )) * 100; 
    }

    float getCGPA() {
        return getAverage()/9.5;
    }

    char getGrade(){
        float avg = getAverage();
        if(avg>=90) return 'A';
        else if(avg>=75) return 'B';
        else if(avg>=60) return 'C';
        else if(avg>=50) return 'D';
        else return 'F';
    }

    void displayStudent() {
        displayPerson();
        cout << ", Roll No: " << rollNo << endl;
        cout << "Subjects and Marks:\n";
        for(int i=0;i<n_sub;i++)
            cout << subjects[i] << ": " << marks[i] << endl;
        cout << "Total: " << getTotalMarks() << ", Average: " << getAverage() 
             << ", Percentage: " << getPercentage() << "%, CGPA: " << getCGPA() 
             << ", Grade: " << getGrade() << endl;
    }
};

// ------------------- ClassRoom -------------------
class ClassRoom {
private:
    vector<Student> students;
public:
    void addStudents() {
        int n;
        cout << "Enter number of students in this class: ";
        cin >> n;
        for(int i=0;i<n;i++){
            cout << "\n--- Student " << i+1 << " ---\n";
            Student s;
            s.inputStudent();
            students.push_back(s);
        }
    }

    void displayAllStudents() {
        if(students.empty()) {
            cout << "No students in this class.\n"; 
            return; 
        }
        for(int i=0;i<students.size();i++){
            cout << "\n--- Student " << i+1 << " ---\n";
            students[i].displayStudent();
        }
    }

    void sortByTotalMarks() {
        sort(students.begin(), students.end(), [](Student &a, Student &b){
            return a.getTotalMarks() > b.getTotalMarks();
        });
        cout << "Students sorted by total marks (highest to lowest).\n";
    }

    void displayTopper() {
        if(students.empty()){
            cout << "No students.\n";
            return;
        }
        Student topper = *max_element(students.begin(), students.end(), [](Student &a, Student &b){
            return a.getTotalMarks() < b.getTotalMarks();
        });
        cout << "\n--- Topper of Class ---\n";
        topper.displayStudent();
    }
};

// ------------------- School -------------------
class School {
private:
    ClassRoom classes[10]; // Standards 1 to 10
public:
    void addStudentsToClass(int standard) {
        if(standard<1 || standard>10){
            cout << "Invalid standard.\n";
            return;
        }
        classes[standard-1].addStudents();
    }

    void displayClass(int standard) {
        if(standard<1 || standard>10){
            cout << "Invalid standard.\n";
            return;
        }
        classes[standard-1].displayAllStudents();
    }

    void sortClassByMarks(int standard) {
        if(standard<1 || standard>10){
            cout << "Invalid standard.\n";
            return;
        }
        classes[standard-1].sortByTotalMarks();
    }

    void displayTopper(int standard) {
        if(standard<1 || standard>10){
            cout << "Invalid standard.\n";
            return;
        }
        classes[standard-1].displayTopper();
    }
};

// ------------------- Main -------------------
int main() {
    School mySchool;
    int choice, num;

    while(true){
        cout << "\n--- SCHOOL MANAGEMENT SYSTEM ---\n";
        cout << "1. Add students to class\n";
        cout << "2. Display all students of a class\n";
        cout << "3. Sort class by highest total marks\n";
        cout << "4. Display topper of a class\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice==1){
            cout << "Enter standard (1-10): ";
            cin >> num;
            mySchool.addStudentsToClass(num);
        }
        else if(choice==2){
            cout << "Enter standard (1-10): ";
            cin >> num;
            mySchool.displayClass(num);
        }
        else if(choice==3){
            cout << "Enter standard (1-10): ";
            cin >> num;
            mySchool.sortClassByMarks(num);
        }
        else if(choice==4){
            cout << "Enter standard (1-10): ";
            cin >> num;
            mySchool.displayTopper(num);
        }
        else if(choice==5){
            cout << "Exiting program.\n";
            break;
        }
        else{
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
