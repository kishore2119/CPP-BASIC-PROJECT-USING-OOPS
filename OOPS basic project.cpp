#include <bits/stdc++.h>
using namespace std;

// ------------------- Base Class / Person class -------------------
class Person {
protected:
    string name;                 // basic detaild of person
    int age;
public:
    void inputPerson() {                              // input for details of person
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
class Student : public Person {                 // Every student is person , so student class inherits the person class
private:
    string rollNo;
    int n_sub;
    string subjects[20];  // max 20 subjects
    float marks[20];      // marks of each subject
public:
    void inputStudent() {
        inputPerson();                          // details of student
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

    float getTotalMarks() {               // total marks of each student
        float total=0;
        for(int i=0;i<n_sub;i++) total += marks[i];
        return total;
    }

    float getAverage(){                   // average marks of each student
         return getTotalMarks() / n_sub; 
    }
 
    float getPercentage() {               // percentage of each student
        return (getTotalMarks()/(n_sub * 100 )) * 100; 
    }

    float getCGPA() {                     // cgpa of each student
        return getAverage()/9.5;
    }

    char getGrade(){                       // grade of each student
        float avg = getAverage();
        if(avg>=90) return 'A';
        else if(avg>=75) return 'B';
        else if(avg>=60) return 'C';
        else if(avg>=50) return 'D';
        else return 'F';
    }

    void displayStudent() {                  // display the student marks and information
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
class ClassRoom {                    // Class of Classroom which holds students
private:
    vector<Student> students;        // creating a vector of students with Student class
public:
    void addStudents() {             // add students into classroom
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

    void displayAllStudents() {          // display all the students in classroom
        if(students.empty()) {
            cout << "No students in this class.\n"; 
            return; 
        }
        for(int i=0;i<students.size();i++){
            cout << "\n--- Student " << i+1 << " ---\n";
            students[i].displayStudent();
        }
    }

    void sortByTotalMarks() {           // Sort the students based on total marks
        sort(students.begin(), students.end(), [](Student &a, Student &b){
            return a.getTotalMarks() > b.getTotalMarks();
        });
        cout << "Students sorted by total marks (highest to lowest).\n";
    }

    void displayTopper() {               // Get the details of topper based on total marks
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
class School {                        // Class school consists of classrooms
private:
    ClassRoom classes[10]; // assuming school having standards of 1 to 10
public:
    void addStudentsToClass(int standard) {   // adding student to class based on standard
        if(standard<1 || standard>10){
            cout << "Invalid standard.\n";
            return;
        }
        classes[standard-1].addStudents();
    }

    void displayClass(int standard) {         //display stuents on class room
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
        cout << "\n--- SCHOOL MANAGEMENT SYSTEM ---\n";   //Options for School Management System
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

