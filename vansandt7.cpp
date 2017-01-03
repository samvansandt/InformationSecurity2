///////////////////////////////////////////////////////////////////
// Student name:   Sam Van Sandt
// Course: COSC 4553 - Information Security
// Assignment: Assignment #7 - Password Validity Checker
// File name:  vansandt7.cpp
// Purpose:  Implements a program to check if a candidate password
//           complies with a given set of format rules 
// Limitations: none known
// Development Computer:  
// Operating System:  Windows 7
// Integrated Development Environment (IDE): Notepad ++ 
// Compiler:  GNU g++
// Build Directions: 
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctype.h>

using namespace std;

// ##########################################################


int main(void)
{
string password;
bool longenough = false;
bool lowercase = false;
bool uppercase = false;
bool specialcharacter = false;
bool number = false;
bool valid = false;
int character = 0;
string search_str1 = "1234567890";
string search_str2 = "!@#$%^&*_+}/|{>=<,;:.";

while (valid == false){


cout << "please enter password" << endl;
cin >> password;

int length = password.length();

for (int i = 0; i < length; i++){
	if (islower(password[i])){
		//checking for lowercase character
		lowercase = true;}
	if (isupper(password[i])){
		//checking for uppercase character
		uppercase = true;}
character++;
}

//displaying messages if upper and lower aren't found while looping through string
if (lowercase == false){
cout << "your password doesn't contain a lowercase character" << endl;}
if (uppercase == false){
cout << "your password doesn't contain an uppercase character" << endl;}
//setting to true only if conditions met
if (character >= 9){
	longenough = true;}
else cout << "your password is not long enough" << endl;	
if (password.find_first_of(search_str1) != std::string::npos){
	number = true;}
else cout << "your password does not contain a number" << endl;
if (password.find_first_of(search_str2) != std::string::npos){
	specialcharacter = true;}
else cout << "your password does not contain a special character" << endl;

if ((longenough == true) & (lowercase == true) & (uppercase == true) & (specialcharacter == true) & (number == true)) {
	valid = true;
}
else cout << "password not valid"  << endl;

//resetting all to false each time a new password is entered	
longenough = false;
lowercase = false;
uppercase = false;
specialcharacter = false;
number = false;
}

cout << "password is valid";

return 0;
} // End main
