#include<iostream>
using namespace std;

class expensivecar
{
	private:
		string carname;
		long double price;
		string colour;
		int model;
		public:
			void setdata()
			{
				
		cout<<"Enter the name of the car:"<<endl;
		cin>>carname;
			cout<<"Enter the price of the car:"<<endl;
		cin>>price;
			cout<<"Enter the colour of the car:"<<endl;
		cin>>colour;
			cout<<"Enter the model name of the car:"<<endl;
		cin>>model;
		
			}
	void		showdata()
			{
				cout<<carname<<endl;
				cout<<price<<endl;
				cout<<colour<<endl;
				cout<<model<<endl;
			}
};
int main()
{
	expensivecar s1;
	expensivecar s2;
	s1.setdata();
	s2.setdata();
	s1.showdata();
	s2.showdata();
	
	
	
	return 0;
}
