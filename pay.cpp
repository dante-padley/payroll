#include <iostream>
#include <vector>
#include <fstream>
#include "person.cpp"
using namespace std;

void readData(vector<Person> &employees /*, vector<string> &companyNames*/){
    ifstream rw;
    rw.open("input.txt");

    int i = 0;
    while(!rw.eof()){
        string first, last, company;
        int id;
        float hours, pay;
        Person dude;

        rw >> first >> last >> id >> company >> hours >> pay;

        dude.setFirstName(first);
        dude.setLastName(last);
        dude.setEmployeeId(id);
        dude.setCompanyName(company);
        dude.setHoursWorked(hours);
        dude.setPayRate(pay);

        employees.push_back(dude);
        //companyNames.push_back(company);
        
        i++;
    }
    rw.close();
}

void getCompanies(vector<Person> &employees, vector<string> &companyNames){
    
}

int main(){
    vector<Person> employees;
    vector<string> companyNames;
    readData(employees/*, companyNames*/);
    getCompanies(employees, companyNames);
}