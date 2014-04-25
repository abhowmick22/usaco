/*
ID: abhowmi1
PROG: friday 
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;

#define START 1
#define DAYS_IN_WEEK 7

struct cyclicCounter{

int month;

// constructor
cyclicCounter(int initialMonth){
	month = initialMonth;
}

bool LessThanEqualTo(int compareAgainst){
	if(month <= compareAgainst)	return true;
	else return false;
}

int get(){
	return month;
}

void increment(){
	if(month == 11)	month = 0;
	else month++;
}

};

bool isLeapYear(int year){
	// Century year
	if(year%100 == 0){
		if(year%400 == 0)	return true;
		else 			return false;
	}
	else{
		if(year%4 == 0)		return true;
		else			return false;
	}
}


int main(){

int day,year,N,yearBegin;
struct cyclicCounter month(0);

int frequency[] = {0, 0, 0, 0, 0, 0, 0};

ifstream myFile;
myFile.open("friday.in");
myFile >> N;
assert((N>0) && (N<=400));
myFile.close();
	// Start counting from 13 Jan, 1900 which is a Saturday
	day = 13;
	year = 1900;
	//Initialize beginning of year to day 1
	yearBegin = 1;
while(year <= 1900+N-1){

	// Update frequency bin
	frequency[(day - START) % DAYS_IN_WEEK]++;	
	
	// Update day for next month according to rules
	switch(int i = month.get()){
	// Case 1 : if month is Sept, Nov, Apr, Jun
	case 3 :
	case 5 :
	case 8 :
	case 10 :
		day += 30;
		break;
	// Case 2 : if month is Feb
	case 1 :
		if(isLeapYear(year))	day += 29;
		else day += 28;
		break;
	// Case 3 : all other months
	case 0 :
	case 2 :
	case 4 :
	case 6 :
	case 7 :
	case 9 :
	case 11 :
		day += 31;
		break;
	default :
		break;	
	}	

	// Update month
	month.increment();

	// Update year
	if(day - yearBegin > 365){
		if(isLeapYear(year))	yearBegin += 366;
		else yearBegin += 365;
		year++;
	}
}

ofstream outFile;
outFile.open("friday.out");
for(int j=0;j<6;j++)	outFile << frequency[(j+5)%DAYS_IN_WEEK] << " " ;
outFile << frequency[4] << endl;
outFile.close();

return 0;
}
