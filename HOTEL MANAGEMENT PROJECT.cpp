//Submitted by 
//MOAZZAM RIAZ 70111156
//JAWAD AHMAD 70110519

#include <iostream>
#include <fstream>
#include <string>
#include<string.h>
#include<conio.h>
#include <ctime>
using namespace std;

class Room{
	
	public:	
		char  floors[5], room_nu[50], name[30];
		int reserved,day ,balance,  room_no, hours=24, remaining_time, advance, pending;
		string checkin_time, checkin_date, checkout_time, checkout_date;
		string gender, search, address, age, ID_no, fullname, rm="Room no: ";
		time_t now =time(0);
		char* dt = ctime(&now);
		
		void searchh(){
			
			cin.ignore();
			cout<<"Enter your Full Name: ";
			getline(cin , fullname);

			ifstream outFile;
			outFile.open("customer.dat");
			
 			if(outFile.is_open())
 			{
				 while(getline(outFile, search))
 				{
 					if(search == fullname)
 					{
					 	
						cout<<"You are a old customer!!!"<<endl;
						cout << search << endl;
 						getline(outFile, age);
 						cout << age << endl;
 						getline(outFile, ID_no);
 						cout << ID_no << endl;
 						getline(outFile, address);
 						cout << address <<endl;
 						break;
 					}
 				}
 			 
			if(search != fullname)
 			{
 				cout<<"You are a new customer!!!"<<endl;
 				cout<<"Enter you age: ";
				cin>>age;
				cout<<"Enter your gender: ";
				cin>>gender;
				cout<<"Enter your ID card number: ";
				cin>>ID_no;
				cin.ignore();
				cout<<"Enter you address: ";
				getline(cin, address);
 			}
			 }
			outFile.close();
			 }
		void reserve(){
			cout<<"Enter number of days you want to stay: ";
			cin>>day;
			cout<<"How many rooms you want to book? ";
			cin>>reserved;
			cin.ignore();
			cout<<"Enter room number:(ranging 1-50)";
			cin.getline(room_nu, 50);
			ifstream infile;
			infile.open("room.dat");
			if(infile.is_open())
			{
				while(getline(infile, search))
				{
	
				if(search==room_nu){	
				cout<<"Room is reserved!!! "<<endl;
				cout<<"Enter room number (ranging 1-50)";
				cin.getline(room_nu, 50);
	
			}
				}
			}
		}
		
		void check_in(){
			
			cin.ignore();
			cout<<"Enter your Full Name ";
			cin.getline(name,30);
			ifstream infile;
			infile.open("customer.dat");
			if(infile.is_open())
 			{
				 while(getline(infile, search))
 				{
 					if(search == name)
 					{
 						cout << search << endl;
 						getline(infile, age);
 						cout << age << endl;
 						getline(infile, ID_no);
 						cout << ID_no << endl;
 						getline(infile, address);
 						cout << address <<endl;
 						cout<<"Checked-In successfully!!!"<<endl;
 						infile.close();
						ofstream outfile;
						outfile.open("room.dat", ios::out | ios::app);
						outfile<<"\n\n"<<dt;
						outfile<<name<<endl;
						outfile<<"\n\n\nChecked-in"<<endl;
						outfile.close();
 						break;
					 }
				}
			}
			if(search != name)
					 {
					 	cout<<"Customer not found! Register fisrt to checkin!"<<endl;
					 	
					 }

		}
		
		void check_out(){
			
			cin.ignore();
			cout<<"Enter your Full Name ";
			cin.getline(name,30);
			ifstream infile;
			infile.open("customer.dat");
			if(infile.is_open())
 			{
				 while(getline(infile, search))
 				{
 					if(search == name)
 					{
 						cout << search << endl;
 						getline(infile, age);
 						cout << age << endl;
 						getline(infile, ID_no);
 						cout << ID_no << endl;
 						getline(infile, address);
 						cout << address <<endl;
 						cout<<"Checked-out successfully!!!"<<endl;
 						infile.close();
						ofstream outfile;
						outfile.open("room.dat", ios::out | ios::app);
						outfile<<"\n\n"<<dt;
						outfile<<name<<endl;
						outfile<<"\n\n\nChecked-out"<<endl;
						outfile.close();
						break;
					 }
				}
			}
			if(search != name)
					 {
					 	cout<<"Customer not found! Register fisrt to checkin!"<<endl;
					 	
					 }
		}
		
		void showrooms(){
			ifstream infile;
			infile.open("customer.dat", ios::in);
			if(infile)
			{
				getline(infile, fullname);
				while(infile)
				{
					cout<<"\t"<<fullname;
					getline(infile, fullname);
				}
			}
			infile.close();
			}
		
		void stats(){
			ifstream infile;
			infile.open("room.dat", ios::in );
			if(infile.is_open()){
		
				getline(infile, fullname);
				while(infile)
				{				
					
					cout<<"\t"<<fullname<<"       ";
					getline(infile, fullname);
					
				}
			}
			infile.close();
		}	
			
};

class Standard:public Room{
	private:
		int price=300;
		int total_rooms=50;
		int remaining;
		int floor;
		int total_price;
		int rrate;
		int rrremaining;
		string mod="Standard";
	public:	
		
		void rate(){
		
//			ifstream infile;
//			infile.open("room.dat", ios::in | ios::app);
//			infile>>reserved;
			//infile.close();
			rrremaining=total_rooms-reserved;
			remaining=total_rooms-reserved;
			rrate=day*price;
			total_price=rrate*reserved;
			remaining_time=day*hours;
			cout<<"Total price you have to pay is: Rs. "<<total_price<<endl;
			cout<<"Enter amount you want to pay in advance: ";
			cin>>advance;
			pending=total_price-advance;
			cout<<"Pending amount is: Rs. "<<pending<<endl;
		
		}
		
		void writecust(){
			 
			 ofstream outFile;
			 outFile.open("customer.dat", ios::out | ios::app);
			 outFile <<"\n\n\n\n\n\n"<< mod <<endl;
			 outFile << fullname << endl;
			 outFile << age << endl;
			 outFile << gender << endl;
			 outFile << ID_no << endl; 
			 outFile <<"Rs."<< total_price<<endl;
			 outFile <<"Rs."<< pending <<endl;
			 outFile.close();

		}
		
		void roomdata(){
			ofstream outfile;
			outfile.open("room.dat", ios::out | ios::app);
			outfile<<"\n"<<dt;
			outfile<<mod<<endl; 
			outfile<<total_rooms<<endl; 
			outfile<<room_nu<<endl;
			outfile<<remaining<<endl;
			outfile<<remaining_time<<endl;
			outfile.close();
		}
};

class Moderate:public Room{
	private:
		int mprice=500;
		int mtotal_rooms=50;
		int mtotal_price;
		int mremaining;
		int mfloor;
		int mrate;
		string mmod="Moderate";
	public:	
		
		void rate(){
			mremaining=mtotal_rooms-reserved;
			mrate=day*mprice;
			mtotal_price=mrate*reserved;
			remaining_time=day*hours;
			cout<<"Total price you have to pay is: Rs. "<<mtotal_price<<endl;
			cout<<"Enter amount you want to pay in advance: ";
			cin>>advance;
			pending=mtotal_price-advance;
			cout<<"Pending amount is: Rs. "<<pending<<endl;
		}
		
		void writecust(){
			 
			 ofstream outFile;
			 outFile.open("customer.dat", ios::out | ios::app);
			 outFile <<"\n\n\n\n\n\n"<< mmod << endl;
			 outFile<<fullname<<endl;
			 outFile << age << endl;
			 outFile << gender << endl;
			 outFile << ID_no << endl; 
			 //outFile << checkin_date<<"/"<<checkin_time<<endl;
			 //outFile << checkout_date<<"/"<<checkout_time<<endl;
			 outFile << "Rs."<<mtotal_price<<endl;
			 outFile << "Rs."<<pending <<endl;
			 outFile.close();

		}
		
		void roomdata(){
			ofstream outfile;
			outfile.open("room.dat", ios::out | ios::app);
			outfile<<"\n"<<dt;
			outfile<<mmod<<endl; 
			outfile<<mtotal_rooms<<endl; 
			outfile<<room_nu<<endl;
			outfile<<mremaining<<endl;
			outfile<<remaining_time<<endl;
			outfile.close();
		}
};

class Superior: public Room{
	private:
		int sprice=1000;
		int stotal_rooms=50;
		int sremaining;
		int stotal_price;
		int sfloor;
		int srrate;
		string smod="Superior";
	public:
	
		void rate(){
			sremaining=stotal_rooms-reserved;
			srrate=sprice*day;
			stotal_price=srrate*reserved;
			remaining_time=day*hours;
			cout<<"Total price you have to pay is: Rs. "<<stotal_price<<endl;
			cout<<"Enter amount you want to pay in advance: ";
			cin>>advance;
			pending=stotal_price-advance;
			cout<<"Pending amount is: Rs. "<<pending<<endl;
		}
		
		void writecust(){
			 
			 ofstream outFile;
			 outFile.open("customer.dat", ios::out | ios::app);
			 outFile<<"\n\n\n\n\n\n"<<smod<<endl;
			 outFile <<fullname << endl;
			 outFile << age << endl;
			 outFile << gender << endl;
			 outFile << ID_no << endl; 
			 //outFile << checkin_date<<"/"<<checkin_time<<endl;
			 //outFile << checkout_date<<"/"<<checkout_time<<endl;
			 outFile << "Rs."<<stotal_price<<endl;
			 outFile << "Rs."<<pending <<endl;
			 outFile.close();

		}
		
		void roomdata(){
			ofstream outfile;
			outfile.open("room.dat", ios::out | ios::app);
			outfile<<"\n"<<dt;
			outfile<<smod<<endl; 
			outfile<<stotal_rooms<<endl; 
			outfile<<room_nu<<endl;
			outfile<<sremaining<<endl;
			outfile<<remaining_time<<endl;
			outfile.close();
		}
};	


class Junior_Suite:public Room{
	private:
		int jprice=2000;
		int jtotal_rooms=50;
		int jremaining;
		int jtotal_price;
		int jfloor;
		int jrate;
		string jmod="Junior Suite";
	public:	
	
		void rate(){
			jremaining=jtotal_rooms-reserved;
			jrate=jprice*day;
			jtotal_price=jprice*reserved;
			remaining_time=day*hours;
			cout<<"Total price you have to pay is: Rs."<<jtotal_price<<endl;
			cout<<"Enter amount you want to pay in advance: ";
			cin>>advance;
			pending=jtotal_price-advance;
			cout<<"Pending amount is: Rs. "<<pending<<endl;
		}
		
		void writecust(){
			 
			 ofstream outFile;
			 outFile.open("customer.dat", ios::out | ios::app);
			 outFile<<"\n\n\n\n\n\n"<<jmod<<endl;
			 outFile <<fullname << endl;
			 outFile << age << endl;
			 outFile << gender << endl;
			 outFile << ID_no << endl; 
			 //outFile << checkin_date<<"/"<<checkin_time<<endl;
			 //outFile << checkout_date<<"/"<<checkout_time<<endl;
			 outFile <<"Rs."<< jtotal_price<<endl;
			 outFile << "Rs."<<pending <<endl;
			 outFile.close();

		}
		
		void roomdata(){
			ofstream outfile;
			outfile.open("room.dat", ios::out | ios::app);
			outfile<<"\n"<<dt;
			outfile<<jmod<<endl; 
			outfile<<jtotal_rooms<<endl; 
			outfile<<room_nu<<endl;
			outfile<<jremaining<<endl;
			outfile<<remaining_time<<endl;
			outfile.close();
		}
};

class Suite:public Room{
	private:
		int uprice=5000;
		int utotal_rooms=50;
		int uremaining;
		int utotal_price;
		int ufloor;
		int urate;
		string umod="Suite";
	public:	
	
		void rate(){
			uremaining=utotal_rooms-reserved;
			urate=uprice*day;
			utotal_price=urate*reserved;
			remaining_time=day*hours;
			cout<<"Total price you have to pay is: Rs."<<utotal_price<<endl;
			cout<<"Enter amount you want to pay in advance: ";
			cin>>advance;
			pending=utotal_price-advance;
			cout<<"Pending amount is: Rs. "<<pending<<endl;
		}
		
		void writecust(){
			 
			 ofstream outFile;
			 outFile.open("customer.dat", ios::out | ios::app);
			 outFile<<"\n\n\n\n\n\n"<<umod<<endl;
			 outFile <<fullname << endl;
			 outFile << age << endl;
			 outFile << gender << endl;
			 outFile << ID_no << endl; 
			 //outFile << checkin_date<<"/"<<checkin_time<<endl;
			 //outFile << checkout_date<<"/"<<checkout_time<<endl;
			outFile <<"Rs."<< utotal_price <<endl;
			outFile<<"Rs."<<pending<<endl;
			 outFile.close();

		}
		
		void roomdata(){
			ofstream outfile;
			outfile.open("room.dat", ios::out | ios::app);
			outfile<<"\n"<<dt;
			outfile<<umod<<endl; 
			outfile<<utotal_rooms<<endl; 
			outfile<<room_nu<<endl;
			outfile<<uremaining<<endl;
			outfile<<remaining_time<<endl;
			outfile.close();
		}
};


int main(){
	
	Standard  s1;
	Moderate m1;
	Superior sa1;
	Junior_Suite j1;
	Suite u1;
	int e=1,x,y,z;
	while(e!=0)
	{
		cout<<"\n\t\tHOTEL MANAGEMENT SYSTEM MAIN MENU "<<endl;
		cout<<"\t\t------------------------------------"<<endl;
		cout<<"\t\tPress 1 to reserve a room "<<endl;
		cout<<"\t\tPress 2 to checkin a customer "<<endl;
		cout<<"\t\tPress 3 to view reserved rooms "<<endl;
		cout<<"\t\tPress 4 to see report details "<<endl;
		cout<<"\t\tPress 5 to exit "<<endl;	
		cout<<"\t\t------------------------------------"<<endl;
		cout<<"\n\t\tSelect your choice ";
		cin>>x;
		switch(x)
		{
			case 1:
				{
					while(e!=0){
					cout<<"\t\tPress 1 for Standard Room: "<<endl;
					cout<<"\t\tPress 2 for Moderate Room: "<<endl;
					cout<<"\t\tPress 3 for Superior Room: "<<endl;
					cout<<"\t\tPress 4 for Junior Suite: "<<endl;
					cout<<"\t\tPress 5 for Suite Room: "<<endl;
					cout<<"\t\tPress 6 for exit "<<endl;
					cout<<"\t\tEnter your choice ";
					cin>>y;
					switch(y)
					{
						case 1:
							{
								cout<<"Room price is: Rs.300 "<<endl;
								cout<<"Note: Enter room no by 1A, 2A etc!!!"<<endl;
								s1.searchh();
								s1.reserve();
								s1.rate();
								s1.writecust();
								s1.roomdata();
								cout<<"Registered Successfully!!!"<<endl;
								break;
							}
							
						case 2:
							{
								cout<<"Room price is: Rs.500 "<<endl;
								cout<<"Note: Enter room no by 1B, 2B etc!!!"<<endl;
								m1.searchh();
								m1.reserve();
								m1.rate();
								m1.writecust();
								m1.roomdata();
								cout<<"Registered Successfully!!!"<<endl;
								break;
							}	
							
						case 3:
							{
								cout<<"Room price is: Rs.1000 "<<endl;
								cout<<"Note: Enter room no by 1C, 2C etc!!!"<<endl;
								sa1.searchh();
								sa1.reserve();
								sa1.rate();
								sa1.writecust();
								sa1.roomdata();
								cout<<"Registered Successfully!!!"<<endl;
								break;
								}	
						
						case 4:
							{
								cout<<"Room price is: Rs.2000 "<<endl;
								cout<<"Note: Enter room no by 1D, 2D etc!!!"<<endl;
								j1.searchh();
								j1.reserve();
								j1.rate();
								j1.writecust();
								j1.roomdata();
								cout<<"Registered Successfully!!!"<<endl;
								break;
							}
						
						case 5:
							{
								cout<<"Room price is: Rs.5000 "<<endl;
								cout<<"Note: Enter room no by 1E, 2E etc!!!"<<endl;
								u1.searchh();	
								u1.reserve();
								u1.rate();
								u1.writecust();
								u1.roomdata();
								cout<<"Registered Successfully!!!"<<endl;
								break;
							}
						case 6:
						 	{
								e=6;
								break;
							}	
					}
					}
				}
			
			case 2:
				{
					while(e!=0){
						cout<<"\t\tPress 1 for Check-in"<<endl;
						cout<<"\t\tPress 2 for Check-out"<<endl;
						cout<<"\t\tPress 3 for Check-in as visitor"<<endl;
						cin>>z;
						switch(z){
							case 1:
								{
									s1.check_in();
									break;
								}
							
							case 2:
							{
								s1.check_out();
								break;
								}	
							
							case 3:
							{
							while(e!=0){
							cout<<"\t\tPress 1 for Standard Room: "<<endl;
							cout<<"\t\tPress 2 for Moderate Room: "<<endl;
							cout<<"\t\tPress 3 for Superior Room: "<<endl;
							cout<<"\t\tPress 4 for Junior Suite: "<<endl;
							cout<<"\t\tPress 5 for Suite Room: "<<endl;
							cout<<"\t\tPress 6 for exit "<<endl;
							cout<<"\t\tEnter your choice ";
							cin>>y;
							switch(y)
							{
								case 1:
								{
									cout<<"Room price is: Rs.300 "<<endl;
									cout<<"Note: Enter room no by 1A, 2A etc!!!"<<endl;
									s1.searchh();
									s1.reserve();
									s1.rate();
									s1.writecust();
									s1.roomdata();
									cout<<"Registered Successfully!!!"<<endl;
									break;
								}
							
								case 2:
								{
								cout<<"Room price is: Rs.500 "<<endl;
								cout<<"Note: Enter room no by 1B, 2B etc!!!"<<endl;
								m1.searchh();
								m1.reserve();
								m1.rate();
								m1.writecust();
								m1.roomdata();
								cout<<"Registered Successfully!!!"<<endl;
								break;
								}	
							
								case 3:
								{
								cout<<"Room price is: Rs.1000 "<<endl;
								cout<<"Note: Enter room no by 1C, 2C etc!!!"<<endl;
								sa1.searchh();
								sa1.reserve();
								sa1.rate();
								sa1.writecust();
								sa1.roomdata();
								cout<<"Registered Successfully!!!"<<endl;
								break;
								}	
						
								case 4:
								{
								cout<<"Room price is: Rs.2000 "<<endl;
								cout<<"Note: Enter room no by 1D, 2D etc!!!"<<endl;
								j1.searchh();
								j1.reserve();
								j1.rate();
								j1.writecust();
								j1.roomdata();
								cout<<"Registered Successfully!!!"<<endl;
								break;
								}
						
								case 5:
								{
								cout<<"Room price is: Rs.5000 "<<endl;
								cout<<"Note: Enter room no by 1E, 2E etc!!!"<<endl;
								u1.searchh();	
								u1.reserve();
								u1.rate();
								u1.writecust();
								u1.roomdata();
								cout<<"Registered Successfully!!!"<<endl;
								break;
								}
								case 6:
						 	{
								e=6;
								break;
							}	
					}
					}
				}	
									
						}
					}
				}
			
			case 3:
				{
					cout<<"\n---------------------------------------------------------------------------------------------------"<<endl;
					cout<<"\n\tRoom Type"<<"\tName"<<"\t\tage"<<"\tGender"<<"\t ID-card no"<<"    Total"<<"\tPending amount\n"<<endl;				
					s1.showrooms();
					cout<<"\n---------------------------------------------------------------------------------------------------"<<endl;
					break;
				}	
				
			case  4:
				{
					cout<<"\n-------------------------------------------------------------------------------------------------"<<endl;
					cout<<"\n\t\t\t\t        Room Type "<<"   Total rooms  "<< "  Room no "<<"\tRemaining "<<"\tTotal hours"<<endl;
					s1.stats();
					cout<<"\n-------------------------------------------------------------------------------------------------"<<endl;
					break;
				}	
			case 5:
				{
					e=5;
					break;
					}	
		}
	
	cout<<"\n\tBYE BYE !!!"<<endl;	
}
	return 0;
}
