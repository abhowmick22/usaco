/*
ID: abhowmi1
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <assert.h>
using namespace std;

struct Info{
int giftMoney;
int receivers;
vector<string> receiverNames;
	int netMoney; 
// Constructor
Info(){
	giftMoney = 0;
	receivers = 0;
	netMoney = 0;
 }

// Gift money received
void giveMoney(int money){
	netMoney += money;
 }

// deduct money
void takeMoney(int money){
	netMoney -= money;
 }

};

int main(){

int NP;
ifstream myfile;
myfile.open("gift1.in");
map<string,struct Info> gifters;
string name,money,value,recipient;
vector<string> words;
string * namesInOrder;
// Read NP
myfile >> NP;
namesInOrder = new string[NP];
// Read in names, create the map
struct Info * dummy = new Info(); 
for(int i=0;i<NP;i++){
	myfile >> name;	
	namesInOrder[i] = name;
	cout << namesInOrder[i] << endl;
	gifters.insert(pair<string,struct Info>(name,*dummy));
}
		
// Read in info 
for(int i=0;i<NP;i++){
	myfile >> name;
	myfile >> gifters[name].giftMoney;
	myfile >> gifters[name].receivers;
	for(int j=0;j<gifters[name].receivers;j++){
		myfile >> recipient;
		gifters[name].receiverNames.push_back(recipient);
	}	
}
myfile.close();

// Send gifts
map<string,struct Info>::iterator it;
for(int l=0;l<NP;l++){
	int toGive = 0;
	int left = 0;
	if(gifters[namesInOrder[l]].receivers != 0){
	toGive = (gifters[namesInOrder[l]].giftMoney)/(gifters[namesInOrder[l]].receivers);	
	left =  (gifters[namesInOrder[l]].giftMoney)%(gifters[namesInOrder[l]].receivers);
	}
	else left = gifters[namesInOrder[l]].giftMoney;
	for(vector<string>::iterator vit = gifters[namesInOrder[l]].receiverNames.begin();
		vit != gifters[namesInOrder[l]].receiverNames.end(); ++vit){
			gifters[*vit].giveMoney(toGive);
			gifters[namesInOrder[l]].takeMoney(toGive);
			}		
}

// print out gains
ofstream outfile;
outfile.open("gift1.out");

for(int k=0;k<NP;k++)
	outfile << namesInOrder[k] << " " << gifters[namesInOrder[k]].netMoney << endl;

outfile.close();
return 0;
}
