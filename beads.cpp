/*
ID: abhowmi1
PROG: beads 
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;

char oppColor(char color){
	if(color == 'r')	return 'b';
	else if(color == 'b')	return 'r';
	else			return 'w';
}

int leftAssignment(string doubleNecklace, int markerPos, int N){
	int collection=0;
	char leftColor;
	// determine left color
	int i = markerPos;
	while(i>0 && doubleNecklace.at(i-1)=='w')	i--;
	if(i>0)	leftColor = doubleNecklace.at(i-1);
	else	leftColor = 'w';
	//calculate beads of leftColor or white on left side
	if(leftColor == 'w')	collection = markerPos;
	else{
	while(doubleNecklace.at(markerPos-1)!=oppColor(leftColor)){
		markerPos--;
		collection++;
		if(markerPos<=1)	break;
	}
	}
	return collection;
}

int rightAssignment(string doubleNecklace, int markerPos, int N){
	int collection=0;
	char rightColor;
	// determine left color
	int i = markerPos;
	while((i<2*N) && doubleNecklace.at(i)=='w')	i++;
	if(i<2*N)	rightColor = doubleNecklace.at(i);
	else		rightColor = 'w';
	//calculate beads of leftColor or white on left side
	if(rightColor == 'w')	collection = (2*N) - markerPos;
	else{
	while(doubleNecklace.at(markerPos)!=oppColor(rightColor)){
		markerPos++;
		collection++;
		if(markerPos>=2*N)	break;
	}
	}
	return collection;
}

int moveMarkerLeft(string doubleNecklace, int markerPos){

 char currentLeftColor = oppColor(doubleNecklace.at(markerPos-1));
 markerPos--;
if(markerPos <= 1)	return markerPos;	

if(currentLeftColor != 'w'){
 while(doubleNecklace.at(markerPos -1) != currentLeftColor){
	markerPos--;		
	if(markerPos <= 1)	return markerPos;
 }
}

return markerPos;
}


int main(){

string necklace, doubleNecklace;
int N, collected, maxCollected;
int markerPos;
ifstream myFile;
myFile.open("beads.in");

myFile >> N;
assert((N>=3)&&(N<=350));
myFile >> necklace;
myFile.close();
doubleNecklace = necklace + necklace;

// marker position indicates the bead number after which cut is made
markerPos = N;
maxCollected = 0;
while(markerPos >= 1){

	collected = rightAssignment(doubleNecklace, markerPos, N) + leftAssignment(doubleNecklace, markerPos, N);
	if(collected > maxCollected)	maxCollected = collected;
	
	if(maxCollected >= N){
		maxCollected = N;
		break;
	}	
	markerPos = moveMarkerLeft(doubleNecklace, markerPos);
	
}

ofstream outFile;
outFile.open("beads.out");
outFile << maxCollected << endl;
outFile.close();
return 0;
}
