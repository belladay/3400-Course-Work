#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct student {

    string name;
    int studentID;
    float mathGrade;
    float litGrade;
    float geoGrade;
    float graphicsGrade;
    float avgGrade;
    double scholarship;

};

// calculates and stores the averages and scholarships(funds) of a student
void calculate(student &_student) {

    _student.avgGrade = ((_student.mathGrade)+(_student.litGrade)+(_student.geoGrade)+(_student.graphicsGrade))/4;
    
    if(_student.avgGrade > 85.00) {
        _student.scholarship = 17000.00;
    }

    else if (_student.avgGrade > 70.00) {
        _student.scholarship = 0.75*17000.00;
    }

    else if (_student.avgGrade > 65.00) {
        _student.scholarship = 0.55*17000.00;
    }

    else {_student.scholarship = 0.00;}

}

//initializes a vector containing all students and their information based on user input
//returns the vector
vector<student> makeVector() {
    vector<student> _studentList = {};
    cout << "How many students would you like to input: ";
    int n;
    cin >> n;

    for (int i = 0 ; i < n ; i++ ) {
        
        student newstudent;
        
        cout << "Student name: ";
        cin >> newstudent.name;

        cout << "Student ID: ";
        cin >> newstudent.studentID;

        cout << "Student's math grade: ";
        cin >> newstudent.mathGrade;

        cout << "Student's literature grade: ";
        cin >> newstudent.litGrade;

        cout << "Student's georgraphy grade: ";
        cin >> newstudent.geoGrade;

        cout << "Student's graphics grade: ";
        cin >> newstudent.graphicsGrade;

        calculate(newstudent);  

        _studentList.push_back(newstudent);
    }
    return _studentList;

}


//calculates average of averages or average of scholarships based on user input
float findAvg(vector<student> &studentList, string a) {



    float avgGradeSum;
    float fundSum;

    vector<student>::iterator pointer;

    for (pointer = studentList.begin() ; pointer != studentList.end() ; pointer++ )
    { 
        avgGradeSum += (*pointer).avgGrade;
        fundSum += (*pointer).scholarship;
    }

    if (a == "grade") {

        return ((avgGradeSum)/(studentList.size()));

    }

    else if (a == "fund") {

        return ((fundSum)/(studentList.size()));

    }

    else {cout << "invalid ";}

}

int main() {

    vector<student> studentList = makeVector();

    cout << setw(8) << "Name" << "|" << setw(8) << " ID" << "|" << setw(8) << "Math"<< "|" << setw(8) << "Lit"<< "|"<< setw(8) << "Geo" << "|" << setw(8) << "Graphics"<< "|" << setw(8) << "Average"<< "|" << setw(8) << "Scholarship" << endl;
    
    vector<student>::iterator pointy;
    
    for(pointy = studentList.begin(); pointy != studentList.end(); pointy++) {
        cout << setw(8) << (*pointy).name << "|"<< setw(8) << (*pointy).studentID << "|"<< setw(8) << (*pointy).mathGrade << "|"<< setw(8) << (*pointy).litGrade << "|" << setw(8)<< (*pointy).geoGrade << "|"<< setw(8) << (*pointy).graphicsGrade << "|"<< setw(8) << (*pointy).avgGrade << "|"<< setw(8) << (*pointy).scholarship << endl;
    }

     cout << "Would you like to know the average grade or average scholarship amount? Please answer either 'grade' or 'fund': ";
    string a;
    cin >> a;

    float average = findAvg(studentList, a);

    if (a == "fund") {
        cout << "The average scholarship amount is: ";
    }
    else if (a == "grade") {
        cout << "The mean of the averages is: ";
    }
    else {cout << "input";}

    cout << average;
}