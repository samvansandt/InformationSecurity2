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
#include <algorithm>
#include <cstring>



using namespace std;

void encrypt();
void decrypt();

const int rows = 6;
const int columns = 4;

int main(int argc, char* argv[]){

// first checking to see if there are two arguments (filename and -e/-d, )
		
	if( argc < 2) {
	std::cerr << "Usage: a.exe {-e | -d}";
		return 0;
	}
	
// checks to see if argv[1] is either -e or -d and calls either the encrypt or decrypt function
	if (strcmp(argv[1],"-e")==0){
	encrypt();
	std::cerr << "  Encryption is done";
	}
	else if(strcmp(argv[1],"-d")==0){
	decrypt();
	std::cerr << "  Decryption is done";
	}
	else std::cerr << "Usage: a.exe {-e | -d} integer-key";
}

void encrypt(){
char test[rows][columns];
// declaring input variable;
char input;
//nested for loop to populate the array;
while (!cin.eof()){
	for ( int i = 0; i <6; i++ ){
		for (int j = 0; j < 4; j++){
			cin >> input;
			if (cin.eof()){
				test[i][j] = 'X';
			}
			else {test[i][j] = input;}
		}
		
	}

//now we rearrange the array according to 3,5,0,2,1,4 for rows 
std::swap(test[0], test[2]);
std::swap(test[1], test[4]);
std::swap(test[3], test[0]);
std::swap(test[1], test[5]);

// rearranging 3,2,0,1 for columns
for (int i = 0; i < 6; i++){
std::swap(test[i][0], test[i][3]);
std::swap(test[i][1], test[i][3]);
std::swap(test[i][1], test[i][2]);
}
//read out to the file
for ( int i = 0; i <6; i++ ){
 for (int j = 0; j < 4; j++){
 
 cout << test[i][j];
   }
  }
 }
}

void decrypt(){

char test[rows][columns];
// declaring input variable;
char input;
//nested for loop to populate the array;
while (!cin.eof()){
	for ( int i = 0; i <6; i++ ){
	
		for (int j = 0; j < 4; j++){
			cin >> input;
			if (cin.eof()){
				test[i][j] = 'X';
			}
			else {test[i][j] = input;}
		}
	}

//now we rearrange the array according to 3,5,0,2,1,4 for rows 
std::swap(test[0], test[2]);
std::swap(test[1], test[4]);
std::swap(test[3], test[2]);
std::swap(test[4], test[5]);

// rearranging 3,2,0,1 for columns
for (int i = 0; i < 6; i++){
std::swap(test[i][0], test[i][2]);
std::swap(test[i][1], test[i][3]);
std::swap(test[i][2], test[i][3]);
}

for ( int i = 0; i <6; i++ ){
 for (int j = 0; j < 4; j++){
  //cout << "|" << test[i][j] << "|";
  cout << test[i][j];
   }
  }
 }
}
