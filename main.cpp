#include <iostream>
#include "Patient.hpp"
#include "Register.hpp"
#include <vector>
#include <queue>
using namespace std;

int  mainMenu() {
    int choice;
    cout << "Please enter one of the given choices: (press -1 to quit)" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cin >> choice;
    while(choice != 1 && choice != 2 && choice != -1){
        cout << "Invalid input please try again (press -1 to quit)" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cin >> choice;
    }
    return choice;
}

int userMenu()
{
    int choice;
    cout << "Please enter one of the given choices: (press -1 to go back to the main menu)" << endl;
    cout << "1. Show Record" << endl;
    cout << "2. Update personal info" << endl;
    cout << "3. delete personal account" << endl;
    cin >> choice;
    while(choice != 1 && choice != 2 && choice != 3 && choice != -1)
    {
        cout << "Invalid input please try again (press -1 to go back to the main menu)" << endl;
        cout << "1. Show Record" << endl;
        cout << "2. Update personal info" << endl;
        cout << "3. delete personal account" << endl;
        cin >> choice;
    }
    return choice;
}

int adminMenu()
{
    int choice;
    cout << "Please enter one of the given choices: (press -1 to go back to the main menu)" << endl;
    cout << "1. Show Record" << endl;
    cout << "2. Update personal info" << endl;
    cout << "3. delete personal account" << endl;
    cout << "4. delete a user account using national ID" << endl;
    cout << "5. View a user account using national ID" << endl;
    cout << "6. View Statistics" << endl;
    cin >> choice;
    while(choice != 1 && choice != 2 && choice != 3 && choice != -1 && choice != 4 && choice != 5 && choice != 6)
    {
        cout << "Invalid input please try again (press -1 to go back to the main menu)" << endl;
        cout << "1. Show Record" << endl;
        cout << "2. Update personal info" << endl;
        cout << "3. delete personal account" << endl;
        cout << "4. delete a user account using national ID" << endl;
        cout << "5. View a user account using national ID" << endl;
        cout << "6. View Statistics" << endl;
        cin >> choice;
    }
    return choice;
}


void updateInfo(Patient patient)
{
    int choice;
    do {
        cout << "What info do you want to change ? (press -1 to return to previous menu)" << endl;
        cout << "1. Country" << endl;
        cout << "2. Governorate" << endl;
        cout << "3. Doses Received" << endl;
        cout << "4. Password" << endl;
        cin >> choice;
        if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != -1)
            cout << "Invalid Input, please try again!";
        if(choice == -1)
            return;
    } while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != -1);

    switch (choice) {
        case 1:
            patient.setCountry();
            break;
        case 2:
            patient.setGovernorate();
            break;
        case 3:
            patient.setDosesReceived();
            break;
        case 4:
            patient.setPassword();
            break;
        default:
            cout << "Fatal error: updateInfo ( wrong choice chosen )" << endl;
    }
}


int Login(vector<Patient>& patients) {
    string inputNationalID, inputPassword;
    cout << "Enter patient National ID: " << endl;
    cin >> inputNationalID;
    cout << "Enter password" << endl;
    cin >> inputPassword;
    for(int i = 0; i < patients.size(); i++)
    {
        if(patients[i].getNationalID() == inputNationalID && patients[i].getPassword() == inputPassword)
            return i;
    }
    return -404;
}

void deletePatient(vector<Patient>& patients,int patientIndex)
{
    patients.erase( patients.begin() + patientIndex);
}

void deletePatientUsingNationalID(vector<Patient>& patients)
{
    string nationalID;
    int  patientIndex = -1;
    cout << "Enter national id of patient you want to delete " << endl;
    cin >> nationalID;

    for(int i = 0; i < patients.size(); i++)
    {
        if(patients[i].getNationalID() == nationalID)
            patientIndex = i;
    }
    if(patientIndex == -1)
    {
        cout << "No patient found with that national id " << endl;
        return;
    }

    patients.erase(patients.begin() + patientIndex);
    cout << "Patient deleted successfully" << endl;
}

void showPatientRecordUsingNationalID(vector<Patient>& patients)
{
    string nationalID;
    int  patientIndex = -1;
    cout << "Enter national id of patient you want to View " << endl;
    cin >> nationalID;

    for(int i = 0; i < patients.size(); i++)
    {
        if(patients[i].getNationalID() == nationalID)
            patientIndex = i;
    }
    if(patientIndex == -1)
    {
        cout << "No patient found with that national id " << endl;
        return;
    }

    patients[patientIndex].showRecord();
}

void percentageOfDose(vector<Patient> & patients, bool dose)
{
    /*
     * if dose = true - return percentage of patients who received the first dose
     * * if dose = false - return percentage of patients who received both doses
     * */
    double counter = 0;
    for(int i = 0; i < patients.size(); i++)
    {
        if(dose && patients[i].getDosesReceived() == 1)
            counter++;
        if(!dose && patients[i].getDosesReceived() == 2)
            counter++;
    }
    cout << "Percentage of patients who received " << (dose ? " the first" : "both") << (dose ? "dose" : "doses") << " is " << (( counter / double(patients.size()) ) * 100.0) << "%"  << endl;
}

void percentageOfGender(vector<Patient>& patients, bool gender)
{
    /*
     * if gender = true - return percentage of patients who are males
     * * if gender = false - return percentage of patients who are females
     * */
    double counter = 0;
    for(int i = 0; i < patients.size(); i++)
    {
        if(gender && !patients[i].getGender())
            counter++;
        if(gender && patients[i].getGender())
            counter++;
    }
    cout << "Percentage of patients who are " << (gender ? "males" : "females") << " is " << (( counter / double(patients.size()) ) * 100 ) << "%" << endl;
}

void viewStatistics(vector<Patient> & patients) {
    int choice;
    do {
        cout << "Choose which percentage you want to view: ( -1 to go to previous menu )" << endl;
        cout << "1. patients who received the first dose" << endl;
        cout << "2. patients who received both doses" << endl;
        cout << "3. Males" << endl;
        cout << "4. Females" << endl;
        cin >> choice;
        if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != -1)
            cout << "Invalid choice, please try again" << endl;
    } while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != -1);

    switch(choice)
    {
        case 1:
            percentageOfDose(patients, true);
            break;
        case 2:
            percentageOfDose(patients, false);
            break;
        case 3:
            percentageOfGender(patients, true);
            break;
        case 4:
            percentageOfGender(patients, false);
            break;
        case -1:
            return;
        default:
            cout << "Fatal error: viewStatistics ( wrong choice )" << endl;
    }
}

int main() {
    vector<Patient> patients;
    queue<Patient> waitingList;
    int choice;
    do {
        choice = mainMenu();
        string fullName, nationalID, password, country, governorate;
        genderEnum gender;
        bool alreadyVaccinated, isAdmin;
        int age, doses, patientId, userChoice;
        switch (choice) {
            case 1:
                patientId = Login(patients);
                if(patientId == -404)
                {
                    cout << "Wrong credentials, please try again!" << endl;
                    break;
                }
                if(patients[patientId].getIsAdmin())
                    userChoice = adminMenu();
                else
                    userChoice = userMenu();
                while(userChoice != -1)
                {
                    switch (userChoice)
                    {
                        case 1:
                            patients[patientId].showRecord();
                            break;
                        case 2:
                            updateInfo(patients[patientId]);
                            break;
                        case 3:
                            deletePatient(patients, patientId);
                            userChoice = -1;
                            break;
                        case 4:
                            deletePatientUsingNationalID(patients);
                            break;
                        case 5:
                            showPatientRecordUsingNationalID(patients);
                            break;
                        case 6:
                            viewStatistics(patients);
                            break;
                        default:
                            cout << "Fatal error: user entered wrong number in user menu";
                    }
                    if(userChoice == -1) {
                        cout << "Thank you for using our app, we hope to see you again soon!" << endl;
                        break;
                    }
                    if(patients[patientId].getIsAdmin())
                        userChoice = adminMenu();
                    else
                        userChoice = userMenu();
                }
                break;
            case 2:
                isAdmin = enterIsAdmin();
                fullName = enterFullName();
                nationalID = enterNationalID(patients);
                password = enterPassword();
                gender = enterGender();
                age = enterAge();
                country = enterCountry();
                governorate = enterGovernorate();
                alreadyVaccinated = enterAlreadyVaccinated();
                if (alreadyVaccinated)
                    doses = enterDosesTaken();
                else {
                    doses = 0;
                }
                addNewPatient(patients,waitingList, fullName, nationalID, password, gender, age, country, governorate,
                              alreadyVaccinated, doses, isAdmin);
                break;
            case -1:
                cout << "Thank you for using our app, we hope to see you again soon!" << endl;
                break;
            default:
                cout << "Fatal error: user entered wrong number in main menu";
        }
    } while(choice != -1);
    return 0;
}
