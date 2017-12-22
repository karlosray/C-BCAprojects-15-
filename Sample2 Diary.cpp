#include<iostream>
#include<stdlib.h>
using namespace std;
#include<conio.h>
#include<string.h>
#include<fstream>
// Imported all required Header Files

class Diary
{
	private:
		struct Page				// A structure to hold DATE, TIME, HEADING and NOTE
		{
			char Date[10];
			char Time[10];
		 	string Head;
			string Text;
		}P;						// P is object of Structure Page
	public:
		void Add()
		{
			cout<<"Date [DD/MM/YYYY] : ";
			cin>>P.Date;
			cout<<"Time [HH:MM AM/PM] : ";
			cin>>P.Time;
			fflush(stdin);		// Flushing Input Buffer
			cout<<"Heading : ";
			getline(cin,P.Head);		// Heading
			fflush(stdin);
			cout<<"Dear Diary,"<<endl<<"\t";
			getline(cin,P.Text);				// Get Input as String
			ofstream outf("Diary.txt",ios::app);
		    outf.write((char*)(&P),sizeof(P));
		    outf.close();
		}
		void View()
		{
			string D;
			
		//	ifstream inf;
	//		inf.open("Diary",ios::in);
			ifstream inf("Diary.txt",ios::in);
			cout<<"Enter Date to View Page [DD/MM/YYYY]: "<<endl;
			cin>>D;
			while(!inf.eof())
			{
				inf.read((char*)(&P),sizeof(P));
				if(D==P.Date)
				{
					cout<<P.Date<<endl;
					cout<<P.Time<<endl;
					cout<<P.Head<<endl;
					cout<<P.Text<<endl;
				}
				
			}
			inf.close();
		}
		
		
		
		
		
		
		
		
		
		
		
		
		int Security()						// Function To Ask Password and Return 1 if True
		{
			int chance=3;
			int Pass;
			int Match=2273556;
			do
			{
				cout<<"Enter Password"<<endl;
				cin>>Pass;
				if(Pass==Match)
				{
					return 1;
				}
				else
				{
					chance--;
					cout<<"You Entered Wrong Password"<<endl;
					cout<<"You are left with "<<chance<<" Chances";
				}
			}while(chance!=0);
			if(chance==0)
			{
				system("CLS");
				return 0;
			}
		}
};

int main()
{
	int opt;						// To Get Input for Switch
	Diary ob;
	int confirm;
	cout<<"Daily Diary"<<endl;
	cout<<"0: To View Personal Information"<<endl;
	cout<<"1: To Add Personal Information"<<endl;
	cout<<"2: To Add a Page"<<endl;
	cout<<"3: To View Previous Pages"<<endl;
	cout<<"4: To Edit Previous Pages"<<endl;
	cout<<"5: To Delete Previous Pages"<<endl;
	cout<<"Enter Index for Action : ";
	cin>>opt;
	switch(opt)
	{
		case 0:
				break;
		case 2:	confirm=ob.Security();
				if(confirm==1)
				{
					system("CLS");
					ob.Add();
				}
				else
				{
					cout<<"Sorry, You are Not allowed to View/Modify the Contents";
				}
				break;
		case 3: ob.View();
	}
	return 0;
}


