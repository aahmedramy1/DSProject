//
//  Patient.cpp
//  ProjectTest
//
//  Created by Ahmed Ramy on 21/05/2022.
//

#include "Patient.hpp"
#include <iostream>
#include <string>
using namespace std;                


Patient::Patient(string fullName, string nationalID, string password, genderEnum gender, int age, string country,
                 string governorate, bool alreadyVaccinated, int dosesReceived, bool admin) {
    this->fullName = fullName;
    this->nationalID = nationalID;
    this->password = password;
    this->gender = gender;
    this->age = age;
    this->country = country;
    this->governorate = governorate;
    this->alreadyVaccinated = alreadyVaccinated;
    this->dosesReceived = dosesReceived;
    this->admin = admin;
}

string Patient::getNationalID() {
    return this->nationalID;
}

string Patient::getPassword() {
    return this->password;
}

bool Patient::getIsAdmin() {
    return this->admin;
}

int Patient::getDosesReceived()
{
    return this->dosesReceived;
}

bool Patient::getGender() {
    return this->gender;
}

void Patient::showRecord() {
    string gender, alreadyVaccinated;
    if(this->gender == 0)
        gender = "Male";
    else
        gender = "Female";
    if(this->alreadyVaccinated)
        alreadyVaccinated = "Yes";
    else
        alreadyVaccinated = "No";


    cout << "Name: " << this->fullName << endl;
    cout << "National ID: " << this->nationalID << endl;
    cout << "Gender: " << gender << endl;
    cout << "Age: " << this->age << endl;
    cout << "Country: " << this->country << endl;
    cout << "Governorate: " << this->governorate << endl;
    cout << "Already vaccinated: " << alreadyVaccinated << endl;
    if(this->alreadyVaccinated)
        cout << "Doses Received: " << this->dosesReceived << endl;
}

void Patient::setPassword() {
    string oldPassword, newPassword, confirmNewPassword;
    cout << "Please enter your old password" << endl;
    cin >> oldPassword;

    if(this->password != oldPassword) {
        cout << "Wrong old password, please try again" << endl;
        return;
    }

    do{
        cout << "Please enter new password" << endl;
        cin >> newPassword;
        cout << "Please enter new password again" << endl;
        cin >> confirmNewPassword;
        if(newPassword != confirmNewPassword)
        {
            cout << "Passwords does not match, please try again !" << endl;
        }
    } while(newPassword != confirmNewPassword);

    this->password = newPassword;
    cout << "Password changed Successfully !" << endl;
}

void Patient::setCountry() {
    string newCountry;
    int choice;
    cout << "Please enter new country" << endl;
    cin.clear();
    getline(cin, newCountry);
    do {
        cout << "Are you sure you want to change your country to " << newCountry << " ?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> choice;
        if(choice != 1 && choice != 2)
            cout << "Invalid input, please try again !" << endl;
    } while(choice != 1 && choice != 2);

    if(choice == 1)
        this->country = newCountry;

}

void Patient::setGovernorate() {
    string newGovernorate;
    int choice;
    cout << "Please enter new governorate" << endl;
    cin.clear();
    getline(cin, newGovernorate);
    do {
        cout << "Are you sure you want to change your governorate to " << newGovernorate << " ?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> choice;
        if(choice != 1 && choice != 2)
            cout << "Invalid input, please try again !" << endl;
    } while(choice != 1 && choice != 2);

    if(choice == 1)
        this->governorate = newGovernorate;

}

void Patient::setDosesReceived() {
    int newDoses, choice;
    do {
        cout << "How many doses have you received ? (1 or 2)" << endl;
        cin >> newDoses;
        if(newDoses != 1 && newDoses != 2)
            cout << "Invalid choice, please enter either 1 or 2" << endl;
    } while(newDoses != 1 && newDoses != 2 );

    do {
        cout << "Are you sure you want to change doses taken to " << newDoses << " ?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> choice;
        if(choice != 1 && choice != 2)
            cout << "Invalid input, please try again !" << endl;
    } while(choice != 1 && choice != 2);

    if(choice == 1)
        this->dosesReceived = newDoses;

    if(!this->alreadyVaccinated)
        this->alreadyVaccinated = true;
}


