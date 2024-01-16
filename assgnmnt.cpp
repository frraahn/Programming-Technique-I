#include <iostream>
#include <cstring>
using namespace std;
void getInput (int &total,int &newc, int &death, int &recovered);
void dispOutput (int acases);
void dispStatus(int acases);
double calcAverage(int count, int tacases);

int main () {
	int i=0, acases, count=0, tacases=0, highest=-99, total, newc, death, recovered;
	double average;
	string state[20];
	
	cout<<"<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>>"<<endl;
	
	do{
		cout<<"State name: ";
		getline(cin,state[20]);
		   		
		getInput(total, newc, death, recovered);
		acases = total + newc - death - recovered;
		dispOutput(acases);

		count++;
		tacases += acases;
		
		if (acases>highest)
		highest=acases;
		
		cout<<"Press <ENTER> to continue...";
	}while (state[20]!="N");
	
	
	average=calcAverage(count, tacases);
	
	cout<<"Total: "<<tacases;
	cout<<"Highest: "<<highest;
	cout<<"Average for "<<count<<"states: "<<average;
	
	return 0;
}

void getInput (int &total,int &newc, int &death, int &recovered){
	cout<<"Total cases     : ";
	cin>>total;
	cout<<"New cases       : ";
	cin>>newc;
	cout<<"Total death     : ";
	cin>>death;
	cout<<"Total recovered : ";
	cin>>recovered;
}

void dispOutput (int acases){
	cout<<"<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>"<<endl;
	cout<<"Active cases: "<<acases<<endl;
	dispStatus (acases);
}

void dispStatus(int acases){
	if (acases>40)
	cout<<"Status: Red Zone"<<endl;
	else if (acases>=21 && acases<=40)
	cout<<"Status: Orange Zone"<<endl;
	else if (acases>=1 && acases<=20)
	cout<<"Status: Orange Zone"<<endl;
	else
	cout<<"Status: Green Zone"<<endl;
}

double calcAverage(int count, int tacases){
	double average;
	
	average=tacases/count;
	
	return average;
}
