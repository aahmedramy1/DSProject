//
//  Register.hpp
//  ProjectTest
//
//  Created by Ahmed Ramy on 21/05/2022.
//

#ifndef Register_hpp
#define Register_hpp
#include <stdio.h>
#include "Patient.hpp"
#include <string>
#include <vector>
#include <queue>

bool checkNationalIDConsistsOfDigits(string nationalID);
bool checkNationalIDLength(string nationalID);
string enterNationalID(vector<Patient> patients);
string enterFullName();
string enterPassword();
genderEnum enterGender();
int enterAge();
string enterCountry();
string enterGovernorate();
bool enterAlreadyVaccinated();
int enterDosesTaken();
bool enterIsAdmin();
void addNewPatient(vector<Patient>& patients, queue<Patient>& waitingList, string fullName, string nationalID, string password, genderEnum gender, int age
        , string country, string governorate, bool alreadyVaccinated, int dosesReceived, bool admin);

#endif /* Register_hpp */
