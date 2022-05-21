#include <string>
#include <iostream>
using namespace std;
#include "Patient.hpp"
#include "Register.hpp"
#include <queue>
#include <vector>

bool checkNationalIDConsistsOfDigits(string nationalID) {
    bool allNumbersError = false;

    for(char i : nationalID)
    {
        if(isalpha(i))
        {
            allNumbersError = true;
            break;
        }
    }

    return allNumbersError;
}

bool checkNationalIDLength(string nationalID)
{
    return nationalID.length() != 13;
}

string enterNationalID(vector<Patient> patients) {
    bool correctLengthError, duplicateError = false, allNumbersError;

    string nationalID;
    cout << "Please enter your national ID consisting of 13 digits" << endl;
    cin >> nationalID;

    allNumbersError = checkNationalIDConsistsOfDigits(nationalID);
    correctLengthError = checkNationalIDLength(nationalID);

    for(int i = 0; i < patients.size(); i++)
    {
        if(nationalID == patients[i].getNationalID()) {
            duplicateError = true;
            break;
        }
    }

    while(correctLengthError || duplicateError || allNumbersError)
    {
        if(allNumbersError)
            cout << "National ID cant's contain characters, please enter only numbers" << endl;

        if(correctLengthError)
            cout << "National ID should be exactly 13 digits long, please try again" << endl;

        if(duplicateError)
            cout << "there is already a patient with this national ID, please login" << endl;

        cout << "Please enter your national ID consisting of 13 digits" << endl;
        cin >> nationalID;

        allNumbersError = checkNationalIDConsistsOfDigits(nationalID);
        correctLengthError = checkNationalIDLength(nationalID);

        for(int i = 0; i < patients.size(); i++)
        {
            if(nationalID == patients[i].getNationalID()) {
                duplicateError = true;
                break;
            }
        }


    }

    return nationalID;
}

string enterFullName() {
    string fullName;
    cout << "please enter your full name";
    cin.clear();
    cin.ignore();
    getline(cin, fullName);
    return fullName;
}

string enterPassword() {
    int MAX_PASSWORD_LENGTH = 16;
    int MIN_PASSWORD_LENGTH = 8;
    string password;
    cout << "Please enter your password: ";
    cin >> password;
    while(password.length() > MAX_PASSWORD_LENGTH || password.length() < MIN_PASSWORD_LENGTH )
    {
        cout << "password length must be between 8 and 16" << endl;
        cout << "Please enter your password: ";
        cin >> password;
    }
    return password;
}

genderEnum enterGender() {
    int genderChoice;
    cout << "Please enter your gender: " << endl;
    cout << "1. Male" << endl;
    cout << "2. Female" << endl;
    cin >> genderChoice;
    while(genderChoice != 1 && genderChoice != 2)
    {
        cout << "Please enter either 1 or 2" << endl;
        cout << "Please enter your gender: " << endl;
        cout << "1. Male" << endl;
        cout << "2. Female" << endl;
        cin >> genderChoice;
    }

    if(genderChoice == 1)
        return Male;
    else
        return Female;
}

int enterAge() {
    int MIN_AGE = 16;
    int MAX_AGE = 200;
    int age;
    cout << "Please enter your age:";
    cin >> age;
    while(age < MIN_AGE || age > MAX_AGE)
    {
        cout << "Please enter a valid age:";
        cin >> age;
    }
    return age;
}

string enterCountry()
{
    string country;
    cout << "please enter the country of residence";
    cin.clear();
    cin.ignore();
    getline(cin, country);
    return country;
}

string enterGovernorate()
{
    string governorate;
    cout << "please enter the governorate";
    cin.clear();
    getline(cin, governorate);
    return governorate;
}

bool enterAlreadyVaccinated()
{
    int choice;
    cout << "did you already take the vaccination ?" << endl;
    cout << "1. yes" << endl;
    cout << "2. no" << endl;
    cin >> choice;
    while(choice != 1 && choice != 2)
    {
        cout << "Please enter a valid choice" << endl;
        cout << "1. yes" << endl;
        cout << "2. no" << endl;
        cin >> choice;
    }

    if(choice == 1)
        return true;
    else
        return false;
}

int enterDosesTaken() {
    int doses;
    cout << "How many doses did you receive? (1 or 2)";
    cin >> doses;
    while(doses != 1 && doses != 2)
    {
        cout << "Please enter 1 or 2";
        cin >> doses;
    }
    return doses;
}

void addNewPatient(vector<Patient>& patients,queue<Patient>& waitingList,string fullName, string nationalID, string password, genderEnum gender, int age
        , string country, string governorate, bool alreadyVaccinated, int dosesReceived, bool admin)
{

    Patient newPatient(fullName, nationalID, password, gender, age, country, governorate, alreadyVaccinated, dosesReceived, admin);
    patients.push_back(newPatient);
    if(!alreadyVaccinated)
    {
        waitingList.push(newPatient);
        cout << "You have been added to the waiting list for the vaccine" << endl;
    }

    cout << "You registered successfully!" << endl;
}

bool enterIsAdmin()
{
    int choice;
    cout << "Is this user an admin ?" << endl;
    cout << "1. yes" << endl;
    cout << "2. no" << endl;
    cin >> choice;
    while(choice != 1 && choice != 2)
    {
        cout << "Wrong input, please try again! " << endl;
        cout << "Is this user an admin ?" << endl;
        cout << "1. yes" << endl;
        cout << "2. no" << endl;
        cin >> choice;
    }
    return choice == 1;
}
