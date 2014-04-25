/*
ID: abhowmi1
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

#define ASCII_BASE 64 

using namespace std;

long getValue(string input);

int main() {

string line1, line2;
string output;
ifstream myfile;
myfile.open("ride.in");
myfile>>line1;
myfile>>line2;
myfile.close();

long cometValue = getValue(line1);
long groupValue = getValue(line2);

if((cometValue%47) == (groupValue%47))	output = "GO\n";
else	output = "STAY\n";

ofstream outFile;
outFile.open("ride.out");	

outFile << output;
outFile.close();

return 0;
}


long getValue(string input){
	long value=1;
	for(int i=0;i<input.size();i++){
	value *= ((int)input[i]-ASCII_BASE);
	}
	return value;
}
