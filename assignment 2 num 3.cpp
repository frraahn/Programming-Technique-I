#include <iostream>
using namespace std;

int main() {
    int num, snum, total=1;

    cout<<"Enter an integer number: ";
    cin>>num;

    while (num>0){
        snum=num % 10;
        cout<<snum;
        if (num>=10)
        cout<<" * ";
        else
        cout<<" = ";
        total*=snum;
        num/=10;
    }
 	
 	cout<<""<<total<<endl;
    
    	if (total%4==0 && total%5==0 && total%7==0)
    		cout<<""<<total<<" is multiples of 4, 5 and 7";
        else if (total%4==0 && total%5==0)
        	cout<<""<<total<<" is multiples of 4 and 5";
        else if (total%4==0 && total%7==0) 
        	cout<<""<<total<<" is multiples of 4 and 7";
        else if (total%5==0 && total%7==0)
        	cout<<""<<total<<" is multiples of 5 and 7";
    	else if (total%4==0)
        	cout<<""<<total<<" is multiples of 4";
        else if (total%5==0)
        	cout<<""<<total<<" is multiples of 5";
        else if (total%7==0)
        	cout<<""<<total<<" is multiples of 7";
        else
        	cout<<""<<total<<"is not a multiples of 4, 5 and 7";
       
    return 0;
   
}
