///////////////////////////////////////////////////////////////////
// Student name: 
// Course: COSC 4553 - Information Security
// Assignment: Assignment #5 - RSA Key Generation
// File name:   
// Purpose: Defines the functions that generate the RSA public and
//          private keys
// Limitations:  
// Development Computer:   
// Operating System: 
// Integrated Development Environment (IDE): 
// Compiler:  
// Build Directions: See the driver module
// Operational Status: 
///////////////////////////////////////////////////////////////////

#include <iostream>
#include "RSA_Keys.h"

using namespace std;



int relativelyPrime (int X);
int gcd(int numberV, int numberW);
int inverse(int numberX, int ModulusN);


// ##################################################################
void generateKeys(int primeA, int primeB, int &encryptionExponent, 
                  int &decryptionExponent)
{
int N = primeA * primeB;
int X = (primeA - 1) * (primeB - 1);
int rprime = 1;
int d = 1;
rprime = relativelyPrime(X);
d = inverse(rprime,X);

//cout << "do is going to be " << d;

//cout << "relatively prime is " << rprime;

//////////////////////////////
encryptionExponent = rprime; //rprime once it is working;
decryptionExponent = d ; //d is going to be when it is working;
/////////////////////////////

} // End generateKeys

int relativelyPrime(int number)
 {
	int x = 0;
	int GCD = 0;
	int divisorcount = 0;
	for (int e = 2; e < number; e++)
	{
		
		for (int i = 1; i <= e; i++)
		{
		if (e % i == 0)divisorcount++;
		}
		
		if (divisorcount == 2){
			cout << "e before gcd is " <<e << endl;
			GCD = gcd(e, number);
			
			if (GCD == 1)
			{
				cout << "yah it works";
				x = e;
				break;
			}
			else{ 
			cout << "nope";
			divisorcount = 0;}
		}
else divisorcount = 0;		
	}
	cout << "yo x is "<< x <<endl;
	return x;	
}

int gcd(int numberV, int numberW){

int A = numberV;
int B = numberW; 

while (B != 0)
{

int R = (A % B);
A = B;
B = R;
}

cout << "greatest common divisor is" << A;


return A;
	
}

int inverse(int numberX, int ModulusN){
	// e=3 and ModulusN = 20//
	int d = 0;
	int test= 0;
	
	//d = 1 / (numberX % ModulusN) ;
	for (int i = 0; i < ModulusN;i++){
		test = ((i * numberX) % ModulusN);
		if (test == 1){
			d = i;
			cout << "d equals" <<d;
			cout << "test equals"<<test;
			break;
		}
			
	}
		
	
	
	return d;
}




