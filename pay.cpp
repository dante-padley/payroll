#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "person.cpp"
using namespace std;

//----------
// Read data from input.txt into my vector
//----------
void readData(vector<Person> &employees){
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
        
        i++;
    }
    rw.close();
}

//----------
// Fill my companyNames vector with a list of each of the companies, no repeats
//----------
void getCompanies(vector<Person> &employees, vector<string> &companyNames){
    //for each item in employees
    for(int i = 0; i < employees.size(); i++){
        //item in employees
        string coName = employees[i].getCompanyName();
        //assume its unique
        bool isUnique = true;

        //for each item in companyNames
        for (int k = 0; k < companyNames.size(); k++){
            //cout << k << endl;
            //item in companyNames
            string uniqueName = companyNames[k];
            //if the current item in employees is the same as an item in companyNames
            if (uniqueName == coName){
                //it is not unique
                isUnique = false;
                //break loop
                break;
            }
        }
        //if bool not flipped, so item is unique
        if (isUnique == true){
            //add to companyNames vector
            companyNames.push_back(coName);
            //cout << coName << endl;
        }
    }
}
//----------
// Print the highest paid employee out to terminal
//----------
void printHighestPaid(vector<Person> &employees){
    Person highestPaidGuy = employees[0];

    for (int i = 1; i < employees.size(); i++){
        float highestPay = highestPaidGuy.totalPay();
        float nextGuysPay = employees[i].totalPay();
        if (highestPay < nextGuysPay){
            highestPaidGuy = employees[i];
        }
    }

    cout << "Highest paid: " << highestPaidGuy.fullName() << endl;
    cout << "Employee ID: " << highestPaidGuy.getEmployeeId() << endl;
    cout << "Employer: " << highestPaidGuy.getCompanyName() << endl;
    cout << "Total Pay: " << highestPaidGuy.totalPay() << endl;

}

//----------
// Save the employee data, sorted into files based on which company employs them
//----------
void separateAndSave(vector<Person> &employees, vector<string> &companyNames){
    //loop on each item in companyNames
        //open ostream to file with companyName as name
        //create total company pay var
        //loop on each item in employees
            //string employeeCo = employees[k].getCompanyName
            //if companyNames[i] == employeeCo
                //write to file
                //+= total company pay
        //write total company pay to file
        //close file
    for(int i = 0; i < companyNames.size(); i++){
        float companyTotal;
        string filename = companyNames[i] + ".txt";
        ofstream wo;
        wo.open(filename);
        for(int k = 0; k < employees.size(); k++){
            string employeeCo = employees[k].getCompanyName();
            if(companyNames[i] == employeeCo){
                string fname = employees[k].getFirstName();
                string lname = employees[k].getLastName();
                int id = employees[k].getEmployeeId();
                float pay = employees[k].totalPay();
                string strPay = "$" + to_string(pay);
                companyTotal += pay;
                
                wo << fixed << setprecision(2) << setw(10) << left << fname 
                << setw(10) << lname << setw(5) << id << setw(12) << employeeCo << "$" << pay << endl;
            }
            if(k == (employees.size() - 1)){
                    wo << "Total $" << companyTotal << endl;
                }
            
        }
        wo.close();
    }
}
//----------
// Main, create the 2 vectors and call each function
//----------
int main(){
    vector<Person> employees;
    vector<string> companyNames;
    readData(employees);
    getCompanies(employees, companyNames);
    printHighestPaid(employees);
    separateAndSave(employees, companyNames);
}