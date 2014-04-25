/*
ID: abhowmi1
PROG: milk2 
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <vector>
#include <new>
#include <cstdlib>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;


int main(){

	int maxMilkTime, maxEmptyTime;
	int N;
	int start, finish, prevStart, prevFinish;
	int currMilkTime, currEmptyTime;
	vector<pair<int, int> > milkTimes;	
	map<int, vector<int> > unsortedFinishTimes;
	
	ifstream myFile;
	myFile.open("milk2.in");

	myFile >> N;
	vector<int> startTimes;

	// read and sort input according to start time
	for(int i=0;i<N;i++){
		myFile >> start >> finish;	
		startTimes.push_back(start);
		unsortedFinishTimes[start].push_back(finish); 
	}
		sort(startTimes.begin(),startTimes.end());	
	
	// create new start finish vector
	for(int j=0;j<startTimes.size();j++){
		start = startTimes.at(j);
		finish = unsortedFinishTimes[start].back();			
		unsortedFinishTimes[start].pop_back();
		milkTimes.push_back(make_pair(start, finish));
	}
	

	
	maxMilkTime = maxEmptyTime = 0;
	start = finish = prevStart = prevFinish = 0;
	currMilkTime = currEmptyTime = 0;
	
	for(int i=0;i<N;i++){

	start = milkTimes.at(i).first;
	finish = milkTimes.at(i).second;
	assert(start >= prevStart);

	// If it overlaps
	if(start <= prevFinish){
		if(finish > prevFinish){	
			currMilkTime += (finish - prevFinish); 
			prevFinish = finish;
		}

	}	

	// If it is disjoint from previous
	else{
		if(currMilkTime >= maxMilkTime)
			maxMilkTime = currMilkTime;

		// Check for longest idle time
		if(prevStart != 0 && prevFinish != 0)	currEmptyTime = start - prevFinish;
		if(currEmptyTime > maxEmptyTime){
			maxEmptyTime = currEmptyTime;
			currEmptyTime = 0;
		}

		// Create new milk time
		prevStart = start;
		prevFinish = finish;
		currMilkTime = (finish - start);
	}	

	
	}
	
	if(currMilkTime > maxMilkTime)	maxMilkTime = currMilkTime;

	myFile.close();
	ofstream outFile;
	outFile.open("milk2.out");
	outFile << maxMilkTime <<  " " << maxEmptyTime << endl;
	outFile.close();
	//delete startTimes;
return 0;
}
