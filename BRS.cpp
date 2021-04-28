#include<iostream>
#include<conio.h>
#include<string.h>
#include<cstdio>
#include<cstdlib>
using namespace std;
static int p;
class a
{
	char busn[5],driver [10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
	public:
		void install();
		void allotment();
		void empty();
		void show();
		void avail();
		void position(int i);
}
bus[10];
void vline(char ch)
{
	for(int i=80;i>0;i--)
	cout<<ch;
}
void a :: install()
{
	cout<<"Enter bus no:";
	cin>>bus[p].busn;
	cout<<"\nEnter Driver's name:";
	cin>>bus[p].driver;
	cout<<"\nEnter Arrival time:";
	cin>>bus[p].arrival;
	cout<<"\nEnter departure time:";
	cin>>bus[p].depart;
	cout<<"\nFrom:";
	cin>>bus[p].from;
	cout<<"\nTo :";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
}
void a :: allotment()
{
	int seat;
	char number[5];
	top:
		cout<<"Bus no:";
		cin>>number;
		int n;
		for(n=0;n<=p;n++)
		{
			if(strcmp(bus[n].busn,number)==0)
			break;
		}
		while(n<=p)
		{
			cout<<"\nseat number:";
			cin>>seat;
			if(seat>32)
			{
				cout<<"\nThere are only 32 seats available in this bus";
			}
			else
			{
				if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
				{
					cout<<"Enter passenger's name:";
					cin>>bus[n].seat[seat/4][(seat%4)-1];
					break;
				}
				else
				   cout<<"This seat number is reserved\n";
			}
		}
		if(n>p)
		{
			cout<<"Enter correct bus number\n";
			goto top;
		}
}
void a :: empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j],"Empty");
		}
	}
}
void a :: show()
{
	int n;
	char number[5];
	cout<<"Enter bus no:";
	cin>>number;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n<=p)
	{
		vline('*');
		cout<<"Bus no:\t\t"<<bus[n].busn
		<<"\nDriver:\t\t"<<bus[n].driver
		<<"\nArrival time:\t\t"<<bus[n].arrival
		<<"\nDeparture time:\t\t"<<bus[n].depart
		<<"\nFrom:\t\t"<<bus[n].from
		<<"\nTo:\t\t"<<bus[n].to<<"\n";
		vline('*');
		bus[0].position(n);
		int a;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<4;j++)
			{
				a++;
				if(strcmp(bus[n].seat[i][j],"Empty")!=0)
				cout<<"\nThe seat number"<<(a-1)<<"is reserved for"<<bus[n].seat[i][j]<<".";
			}
		}
		break;
	}
	if(n>p)
	    cout<<"Enter correct bus no:";
}
void a:: position(int i)
{
	int s=0,p=0;
	for(int i=0;i<8;i++)
	{
		cout<<"\n";
		for(int j=0;j<4;j++)
		{
			s++;
			if(strcmp(bus[1].seat[i][j],"Empty")==0)
			{
				cout.width(5);
				cout.fill('.');
				cout<<s<<".";
				cout.width(10);
				cout.fill('.');
				cout<<bus[1].seat[i][j];
				p++;
			}
			else
			{
				cout.width(5);
				cout.fill('.');
				cout<<s<<".";
				cout.width(10);
				cout.fill('.');
				cout<<bus[1].seat[i][j];                                         
			}
		}
	}
	cout<<"\nThere are"<<p<<"seats empty in Bus no:"<<bus[1].busn;
}
void a :: avail()
{
	for(int n=0;n<p;n++)
	{
		vline('*');
		cout<<"Bus no:\t"<<bus[n].busn
		<<"\nDriver:\t"<<bus[n].driver
		<<"\nArrival time:\t"<<bus[n].arrival
		<<"\nDeparture time:\t"<<bus[n].depart
		<<"\nFrom:\t\t"<<bus[n].from
		<<"\nTo:\t\t"<<bus[n].to<<"\n";
		vline('*');
		vline('_');
	}
}
int main()
{
	int n;
	while(1)
	{
		cout<<"\n\n\n\n\n";
		cout<<"\t\t\t1.Install\n\t\t\t"
		<<"2.Reservation\n\t\t\t"
		<<"3.Show\n\t\t\t"
		<<"4.Buses Available\n\t\t\t"
		<<"5.Exit";
		cout<<"\n\t\t\tEnter your choice:";
		cin>>n;
		switch(n)
		{
			case 1:bus[p].install();
			       break;
			case 2:bus[p].allotment();
			       break;
			case 3:bus[0].show();
			       break;
			case 4:bus[0].avail();
			       break;
			case 5:exit(0);
		}
	}
	return 0;
}
