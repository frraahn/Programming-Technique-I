#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void readFile(const string &fileName, float fahrenheit[], int &numberofData);
void computeC(float fahrenheit[], float celcius[], int numberofData);
float average(float celcius[], int &numberofData);
char grade(float celcius[], int &numberofData, char gradeCelcius[]);
void writeFile(float fahrenheit[], float celcius[], int numberofData, char gradeCelcius[]);

int main()
{
	const int i=50;
	int  high=0, medium=0, low=0, numberofData;
	float fahrenheit[i], celcius[i], avg;
	char gradeCelcius[i];
	
    readFile ("fahrenheit.txt", fahrenheit, numberofData);
    computeC (fahrenheit, celcius, numberofData);
	avg=average(celcius, numberofData); 
	grade (celcius, numberofData, gradeCelcius); 
	
	for (int i=0; i<numberofData; i++) {
		if(gradeCelcius[i]=='H')
		high++;
		else if(gradeCelcius[i]=='M')
		medium++;
		else 
		low++;
	} 
	 
	writeFile(fahrenheit, celcius, numberofData, gradeCelcius);
	

	cout<<"Average of the temperature in Celcius : "<<fixed<<setprecision(1)<<avg<<endl;
	cout<<"Number of high temperature : "<<high<<endl;
	cout<<"Number of medium temperature : "<<medium<<endl;
	cout<<"Number of low temperature : "<<low<<endl;

	
}

void readFile (const string &fileName, float fahrenheit[], int &numberofData) {
	int i=0;
	
	ifstream iFile;
	iFile.open("fahrenheit.txt");
	
	if (!iFile)
		cout << "While opening a file an error is encountered" << endl;
	
	numberofData=0;
	
	 while (iFile>>fahrenheit[i])
    {
        numberofData++;
        i++; 
    }
	
	iFile.close();
}

void computeC(float fahrenheit[], float celcius[], int numberofData){
    for (int i=0; i<numberofData; i++)
        celcius[i]=(5.0 / 9.0)*(fahrenheit[i]-32);
}

float average(float celcius[], int &numberofData)
{
	float sumofCelcius=0, avg;
	int i;
	
	for (i=0; i<numberofData; ++i)
		sumofCelcius += celcius[i];

	avg = sumofCelcius/static_cast<float>(numberofData);
	return avg;
}

char grade(float celcius[], int &numberofData, char gradeCelcius[])
{
	int i, high=0, medium=0, low=0;
	
	for(i=0; i<numberofData; i++)
	{
		if(celcius[i]>=35)
		gradeCelcius[i] = 'H';
		else if((celcius[i]<35)&&(celcius[i]>=20))
		gradeCelcius[i] = 'M';
		else
		gradeCelcius[i] = 'L';
	}
	
	return gradeCelcius[i];
}

void writeFile(float fahrenheit[], float celcius[], int numberofData, char gradeCelcius[])
{
	int i;
	
	ofstream oFile;
	oFile.open("celcius.txt");
	
	oFile<<setw(15)<<"C(Celcius)"<<setw(15)<<"F(Fahrenheit)"<<setw(15)<<"Description"<<endl;
	oFile<<setw(15)<<"=========="<<setw(15)<<"============="<<setw(15)<<"==========="<<endl;
	
	for (int i=0; i<numberofData; i++)
        oFile << setw(13)<<fixed<<setprecision(2)<<celcius[i]<<setw(14)<<fixed<<setprecision(2)<<fahrenheit[i]<<setw(13)<<gradeCelcius[i]<<endl;
	
	oFile.close();
}
