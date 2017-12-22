#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>;
#include<fstream>
class D_D
{
	struct st
	{
		public:
			string date="";
			string time="";
			string text="";
			string head="";
	}st1;
	public:
		void A_record(void);
		void V_record(void);
		
};
	void D_D::A_record()
	{
		cout<<"Date [DD/MM/YYYY] : ";
		cin>>st1.date;
		cout<<"Time [HH:MM AM/PM] : ";
		cin>>st1.time;
		fflush(stdin);

		cout<<"Heading : ";
		getline(cin,st1.head);
		fflush(stdin);
		cout<<"Dear Diary,"<<endl<<"\t";
		getline(cin,st1.text);				// Get Input as String
		ofstream outf("DD.txt",ios::app);
	    outf.write((char*)(&st1),sizeof(st));
	    outf.close();
	}
	void D_D::V_record()
	{
		char found='N';
		string srch_date="";
		cout<<"Enter the Record Date";
		cout<<"Date [DD/MM/YYYY] : ";
		cin>>srch_date;
		ifstream fin("DD.txt", ios::in);
		while(!fin.eof())
		{
			fin.read((char*)&st1,sizeof(st));
			if((st1.date)==(srch_date)==true)
			{
				cout<<st1.date;
				cout<<st1.time;
				cout<<st1.head;
				cout<<st1.text;
				found='Y';
				break;
			}
		}
		if(found=='N')
		{
			cout<<"No record of the desired date is found";
			fin.close();
		}
	}

main()
{
	D_D D;
	cout<<"Welcome to Daily Diary"<<endl;
	cout<<"1 : Add Records"<<endl;
	cout<<"2 : View Specific Record"<<endl;
	cout<<"3 : Close Diary"<<endl;
	cout<<"Enter your Choice"<<endl;
	int opt;
	cin>>opt;
	switch(opt)
	{
		case 1:D.A_record();
			break;
		case 2:D.V_record();
			break;
	}	
	
	
	
	
}
	
