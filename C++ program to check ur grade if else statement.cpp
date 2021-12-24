#include <iostream>
using namespace std;
int main()
{
int marks1,marks2,marks3,marks4,marks5,marks6;
int totalmarks;
float per;
char A,B,C,D,E,F;
cout<<"Enter your marks so i will give u grade according to your marks\n";
cin>>marks1;
cin>>marks2;	
cin>>marks3;	
cin>>marks4;	
cin>>marks5;	
cin>>marks6;		
totalmarks=marks1+marks2+marks3+marks4+marks5+marks6;		
cout<<"Your Total Marks Is: "<<totalmarks<<endl;	
per=((totalmarks*100.0)/600.0);
cout<<"Your Percentage is: "<<per;
cout<<endl;

switch(per>=85)
{
case1:
cout<<"You Get Grade "<<'A';
break;
}

switch(per<85 && per>=75)
{
case2:
cout<<"You Get Grade "<<'B';
break;
}

switch(per<75 && per>=65)
{
case3:
cout<<"You Get Grade "<<'C';
break;
}

switch(per<65 && per>=55)
{
case4:
cout<<"You Get Grade "<<'D';
break;
}

switch(per<55 && per>=45)
{
case5:
cout<<"You Get Grade "<<'E';
break;
}

switch(per<45 && per>=40)
{
case6:
cout<<"You Get Grade "<<'F';
break;
}



}
return 0;
}
