/*
ID: abhowmi1
PROG: transform 
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <cstdlib>
using namespace std;

string reflect (string input, int N){
	char temp;
	int opp;
	for(int i=0; i<input.size(); i++){
		if(i%N < N/2){
		temp = input.at(i);
		opp = (i/N)*N + N -1-(i%N);
		input.at(i) = input.at(opp);
		input.at(opp) = temp;
		}
	}
	return input;
}

string transpose (string input, int N){
	char temp;
	int opp;
	for(int i=0; i < input.size(); i++){
		if(i%N < i/N){	// lower triangular elements
			temp = input.at(i);
			opp = (i%N)*N + (i/N)%N;
			input.at(i) = input.at(opp);
			input.at(opp) = temp;	
		}
	}
	return input;
}

string rotate (string input, int N){
	input = reflect(transpose(input, N), N);
	return input;
}

bool checkString(string a, string b){
	if(a.compare(b) != 0)	return false;
	return true;
}

int main(){

string inputM, transformedM, s, t;
int N, transform;
bool valid = false;

ifstream iFile;
iFile.open("transform.in");

iFile >> N;
inputM = "";

// read input square
for (int i=0;i<N;i++){
	iFile >> s;
 	inputM += s;
	}

transformedM = "";
// read transformed square
for (int i=0;i<N;i++){
	iFile >> s;
 	transformedM += s;
	}

iFile.close();

// T 1
if(!valid){
	t = rotate(inputM, N);
	if(checkString(t, transformedM))	valid = true;
	transform = 1;
}

// T 2
if(!valid){
	t = rotate(t, N);
	if(checkString(t, transformedM))	valid = true;
	transform = 2;
}

// T 3
if(!valid){
	t = rotate(t, N);
	if(checkString(t, transformedM))	valid = true;
	transform = 3;
}

// T 4
if(!valid){
	t = reflect(inputM, N);
	if(checkString(t, transformedM))	valid = true;
	transform = 4;
}

// T 5
if(!valid){
	t = rotate(t, N);
	if(checkString(t, transformedM))	valid = true;
	t = rotate(t, N);
	if(checkString(t, transformedM))	valid = true;
	t = rotate(t, N);
	if(checkString(t, transformedM))	valid = true;
	transform = 5;
}

// T 6
if(!valid){
	if(checkString(inputM, transformedM))	valid = true;
	transform = 6;
}

ofstream oFile;
oFile.open("transform.out");
if(valid)	oFile << transform << endl;
else		oFile << "7" << endl;
oFile.close();

return 0;
}
