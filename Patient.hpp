//
//  Patient.hpp
//  ProjectTest
//
//  Created by Ahmed Ramy on 21/05/2022.
//

#ifndef Patient_hpp
#define Patient_hpp
#include <stdio.h>
#include <string>
using namespace std;

enum genderEnum {
    Male,
    Female
};

class Patient {
    string fullName;
    string nationalID;
    string password;
    genderEnum gender;
    int age;
    string country;
    string governorate;
    bool alreadyVaccinated;
    bool admin;
    int dosesReceived;

public:
    Patient(string fullName, string nationalID, string password, genderEnum gender, int age
            , string country, string governorate, bool alreadyVaccinated, int dosesReceived, bool admin);
    string getNationalID();
    string getPassword();
    bool getIsAdmin();
    bool getGender();
    int getDosesReceived();
    void showRecord();
    void setPassword();
    void setCountry();
    void setGovernorate();
    void setDosesReceived();

};


#endif /* Patient_hpp */
