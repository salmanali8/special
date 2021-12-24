#include <iostream>
using namespace std;
void sum()
{
	int n1;
	int n2;
	cout<<"Enter first number"<<endl;
	cin>>n1;
	cout<<"Enter second number"<<endl;
	cin>>n2;
	cout<<"The sum of first and second number is  "<<n1 + n2<<endl;
	
}
void subtraction()
{
	int n1;
	int n2;
	cout<<"Enter first number"<<endl;
	cin>>n1;
	cout<<"Enter second number"<<endl;
	cin>>n2;
	cout<<"The subtraction of first and second number is  "<<n1 - n2<<endl;
	
}
void multiplication()
{
	int n1;
	int n2;
	cout<<"Enter first number"<<endl;
	cin>>n1;
	cout<<"Enter second number"<<endl;
	cin>>n2;
	cout<<"The multiplication of first and second number is  "<<n1 * n2<<endl;
}
void division()
{
	int n1;
	int n2;
	cout<<"Enter first number"<<endl;
	cin>>n1;
	cout<<"Enter second number"<<endl;
	cin>>n2;
	cout<<"division of first and second number is  "<<n1 / n2<<endl;
}

int main()
{
	int n;
cout<<"press  1 for addition"<<endl;
cout<<"press  2 for subtraction"<<endl;
cout<<"press  3 for multiplication"<<endl;
cout<<"press  4 for division"<<endl;

cin>>n;
if(n==1)
sum();
else if(n==2)
subtraction();
else if(n==3)
multiplication();
else if(n==4)
division();	
	
	
	
	
}


