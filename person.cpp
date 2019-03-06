
#include "person.h"

Person::Person(){}

/*------GETTERS------*/
string Person::getFirstName(){
    return firstName;
}

string Person::getLastName(){
    return lastName;
}

int Person::getEmployeeId(){
    return employeeID;
}

string Person::getCompanyName(){
    return companyName;
}

float Person::getPayRate(){
    return payRate;
}

float Person::getHoursWorked(){
    return hoursWorked;
}

/*------SETTERS------*/
void Person::setFirstName(string fName){
    firstName = fName;
}

void Person::setLastName(string lName){
    lastName = lName;
}

void Person::setEmployeeId(int id){
    employeeID = id;
}

void Person::setCompanyName(string coName){
    companyName = coName;
}

void Person::setPayRate(float rate){
    payRate = rate;
}

void Person::setHoursWorked(float hours){
    hoursWorked = hours;
}

/*------FUNCTIONS------*/
float Person::totalPay(){
    return hoursWorked * payRate;
}

string Person::fullName(){
    string full = firstName + " " + lastName;
    return full;
};