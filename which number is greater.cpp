#include <iostream>
using namespace std;
int main()
{
int num1,num2,num3,num4;
cout<<"Enter four numbers so i will tell u which one is the biggest number\n";
cin>>num1>>num2>>num3>>num4;

if(num1>=num2 && num1>=num3 && num1>=num4)

{cout<<"Num:1 is greater which is  "<<num1;}

if(num2>=num1 && num2>=num3 && num2>=num4)	
{cout<<"Num:2 is greater which is "<<num2;}	
	
	if(num3>=num1 && num3>=num2 && num3>=num4)
{cout<<"Num:3 is greater which is "  <<num3;}

if(num4>=num1 && num4>=num2 && num4>=num3)
{cout<<"Num:4 is greater which is "  <<num4;}
		
return 0;	
}
