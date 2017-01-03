///////////////////////////////////////////////////////////////////
// Student name:Samuel Van Sandt
// Course: COSC 4553 - Information Security
// Assignment: #1 - Simple Arithmetic Cipher
// File name: negative.cpp 
// Program Purpose: Encrypts and decrypts a text file using a simple arithmetic
// cipher and a nonnegative integer key
//
// Program Limitations: If the encryption is not redirected into an 
//outgoing file at the command line, then the encryption/decryption will print to screen. Also
//the program will take out whitespaces if they are there in the file. 
// 
// Development Computer: 
// Operating System:Windows 7
// Integrated Development Environment (IDE): notepad++/Cygwin
// Compiler: g++
// Build Directions: I've been testing with: g++ -Wall negative.cpp -o negative.exe
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>


using namespace std;

void cipher(int key);

int main(int argc, char* argv[]){
	
	int val;
	// first checking to see if there are three arguments (filename, -e/-d, and key)
		
	if( argc < 3) {
	std::cerr << "Usage: a.exe {-e | -d} integer-key";
		return 0;
	}
	
	//converting argv[2] to an int value in order to check to see if key is between 0 and 120
	istringstream iss (argv[2]);
	iss >> val;
	if (val < 0 || val > 120)
	{
	std::cerr <<"Usage: Integer key must range between 0 and 120 inclusive";
	return 0;
	}
	
	// checks to see if argv[1] is either -e or -d.
	if (strcmp(argv[1],"-e")==0){
	//cout << "encrypt \n";
	//cout << "val is " << val << "\n";
	cipher(val);
	std::cerr << "  Encryption is done";
	
	}
	else if(strcmp(argv[1],"-d")==0){
	//cout << "decrypt";
	val = -(val);
	//cout << "val is " << val << "\n";
	cipher(val);
	std::cerr << "  Decryption is done";
	}
	
	else std::cerr << "Usage: a.exe {-e | -d} integer-key";
	
}

void cipher (int key){
	//cout << "Cipher is working\n";
	//cout << "key is " << key;
	char x;
	while (cin >> x){
		x = x + key;
		//cout << "x is " << x << "\n";
		cout << x;
		}
	
}
