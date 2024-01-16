#include <iostream>
using namespace std;

int main() {
    int num, snum, sum=0;

    cout<<"Enter an integer number: ";
    cin>>num;

    do {
        snum=num%10;
        cout<<snum;
        if (num>=10)
        cout<<" + ";
        else
        cout<<" = ";
        sum+=snum;
        num/=10;
    }while (num>0);
 	
 	cout<<""<<sum<<endl;
    
    	if (sum%3==0 && sum%4==0 && sum%5==0)
    		cout<<""<<sum<<" is multiples of 3, 4 and 5";
        else if (sum%3==0 && sum%4==0)
        	cout<<""<<sum<<" is multiples of 3 and 4";
        else if (sum%3==0 && sum%5==0) 
        	cout<<""<<sum<<" is multiples of 3 and 5";
        else if (sum%4==0 && sum%5==0)
        	cout<<""<<sum<<" is multiples of 4 and 5";
    	else if (sum%3==0)
        	cout<<""<<sum<<" is multiples of 3";
        else if (sum%4==0)
        	cout<<""<<sum<<" is multiples of 4";
        else if (sum%5==0)
        	cout<<""<<sum<<" is multiples of 5";
        else
        	cout<<""<<sum<<"is not a multiples of 3, 4 and 5";
       
    return 0;
   
}
    
