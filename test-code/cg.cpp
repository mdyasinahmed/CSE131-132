// All Headers
#include <bits/stdc++.h>
using namespace std;

// Function to find Grade from marks
string marksToGrade(double marks) {
    if (marks >= 80) {
        return "Grade: A+";
    } else if (marks>=75 && marks<=79) {
        return "Grade: A";
    } else if (marks>=70 && marks<=74) {
        return "Grade: A-";
    } else if (marks>=65 && marks<=69) {
        return "Grade: B+";
    } else if (marks>=60 && marks<=64) {
        return "Grade: B";
    } else if (marks>=55 && marks<=59) {
        return "Grade: B-";
    } else if (marks>=50 && marks<=54) {
        return "Grade: C+";
    } else if (marks>=45 && marks<=49) {
        return "Grade: C";
    } else if (marks>=40 && marks<=44) {
        return "Grade: C-";
    } else {
        return "Grade: F";
    }
}

// Function to set Grade Points from Grade
double gradePoints(string grade) {
    if(grade == "Grade: A+") {
        return 4.00;
    } else if (grade == "Grade: A") {
        return 3.75;
    } else if (grade == "Grade: A-") {
        return 3.50;
    } else if (grade == "Grade: B+") {
        return 3.25;
    } else if (grade == "Grade: B") {
        return 3.00;
    } else if (grade == "Grade: B-") {
        return 2.75;
    } else if (grade == "Grade: C+") {
        return 2.50;
    } else if (grade == "Grade: C") {
        return 2.25;
    } else if (grade == "Grade: C-") {
        return 2.00;
    } else {
        return 0.00;
    }
}

// Function to get Credit Hours Attempts
double creditHourAttempts(double creditHour, double attempts) {
    double creditHourAttempts;

    return creditHourAttempts = creditHour*attempts;
}

// Function to Calculate Grade Points from Credit hour attempts and total grade points
double calculateGradePoints(double marks, double creditHour, double attempts) {
    double storeCreditHourAttempts = creditHourAttempts(creditHour, attempts);
    string storeGrades = marksToGrade(marks);
    double storeGradePoints = gradePoints(storeGrades);

    return storeCreditHourAttempts*storeGradePoints;
}

// Function to add Calculating CGPA
double calculate(double marks, double creditHour, double attempts) {
    double totalCreditsAttempts = 0;
    double totalGradePoints = 0;
    totalCreditsAttempts += calculateGradePoints(marks, creditHour, attempts);
    totalGradePoints += creditHourAttempts(creditHour, attempts);

    return totalGradePoints/totalCreditsAttempts;
}


// The main function 
int main() {
    system("cls");
	system("Color 07");

    cout << "\n\n";
    cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout << "\t\t\t~                                                                     ~"<<endl;
	cout << "\t\t\t~                   WELCOME! Calculate CGPA Here                      ~"<<endl;
	cout << "\t\t\t~                                                                     ~"<<endl;
    cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout << endl << endl << endl;

    cout << "\tEnter number of Semester: ";
    int totalSemester, totalCourses;
    cin >> totalSemester;
    cout << "\n";

    while(totalSemester--) {
        cout << "\t\tEnter number of Courses: ";
        cin >> totalCourses;
        cout << "\n";

        double marks, creditHour, attempts, gradesSum = 0, creditsSum = 0;

        for(int i=1; i<=totalCourses; i++) {
            cout << "\t\t\tFor course: " << i << "" << endl;
            cout << "\t\t\t\tEnter - Marks, Credit Hour and Credit Hour Attempt: "; 
            cin >> marks >> creditHour >> attempts;
            creditsSum += creditHourAttempts(creditHour, attempts);
            gradesSum += calculateGradePoints(marks, creditHour, attempts);
            cout << endl;
        }


        // printing output

        cout << "\t\t\t-----------------------------------------------------------------------"<<endl;
        cout << "\t\t\t|                             Your Result                             |"<<endl;
        cout << "\t\t\t-----------------------------------------------------------------------"<<endl;
        cout << endl;
        
        for(int i=1; i<=totalCourses; i++) {
            cout << "\t\t\t\t";
            cout << "Course " << i <<  "  Credit Hour: " ;
            cout << creditHour << "  Attempts: " ;
            cout << attempts << "  " ;
            //cout << marksToGrade(marks);
            cout << endl;
            cout << endl;
        }

        cout << "\t\t\t-----------------------------------------------------------------------"<<endl;
        cout << "\t\t\t\t\t\tYour total CGPA is " << gradesSum/creditsSum << endl;    
        cout << "\t\t\t-----------------------------------------------------------------------"<<endl;
    }

    return 0;
}