#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Goodwill
{
	public:
		const char *c = "books_database.txt";
		void veiwlist();
		void request_book();
		void return_book();
};
void Goodwill::veiwlist()
{
	ifstream ifs;
	ifs.open(c,ios::in);
	char data[100];
	cout<<endl;
	cout<<"copies avail. ||   Book ID  ||  Book Name\n\n";
	int i=1;
	while(!ifs.eof())
	{
		ifs.getline(data,100);
		cout<<data<<endl;
	}
	cout<<endl;	
	ifs.close();
}
void Goodwill::request_book()
{
	cout<<"Enter the book id you want ";
	int id; cin>>id;
	if(id>20 || id<1)
	{
		cout<<"Enter a Valid Id according to our list\n";
		return;
	}
	ifstream ifs;
	ofstream temp;
	temp.open("temporary.txt",ios::out);
	ifs.open(c,ios::in);
	string data;
	for(int i=0;i<id-1;i++)
	{
		getline(ifs,data);
		temp<<data<<endl;
	}
	
	string copies,ids,name;
	ifs>>copies;
	if(stoi(copies)==0)
	{
		cout<<"No copy of this book is available. You may take another\n";
		return;
	}
	cout<<"copy available for id "<<id<<" are "<<copies<<endl;
	int copy=stoi(copies);
	copy--;
	copies=to_string(copy);
	cout<<"\nBOOK ISSUED TO YOU! You may collect it from shelf!!\n\n";
	cout<<"copy available for id "<<id<<" now are "<<copies<<endl;
	ifs>>ids; getline(ifs,name);
	temp<<copies<<"  ";
	temp<<ids;
	temp<<name<<endl;
	
	for(int i=id;i<19;i++)
	{
		getline(ifs,data);
		temp<<data<<endl;
	}
	getline(ifs,data);
	temp<<data;
	
	
	ifs.close();
	temp.close();
	
	remove(c);
	rename("temporary.txt",c);

	cout<<endl;
}

void Goodwill::return_book()
{
	
	cout<<"Enter the book id you want to return: ";
	int id; cin>>id;
	if(id>20 || id<1)
	{
		cout<<"Enter a Valid Id according to our list\n";
		return;
	}
	ifstream ifs;
	ofstream temp;
	temp.open("temporary.txt",ios::out);
	ifs.open(c,ios::in);
	string data;
	for(int i=0;i<id-1;i++)
	{
		getline(ifs,data);
		temp<<data<<endl;
	}
	
	string copies,ids,name;
	ifs>>copies;
	if(stoi(copies)==0)
	{
		cout<<"No copy of this book is available. You may take another\n";
		return;
	}
	cout<<"copy available for id "<<id<<" are "<<copies<<endl;
	int copy=stoi(copies);
	copy++;
	copies=to_string(copy);
	cout<<"\nRETURN UPDATED! Now You may returned it to shelf!!\n\n";
	cout<<"copy available for id "<<id<<" now are "<<copies<<endl;
	ifs>>ids; getline(ifs,name);
	temp<<copies<<"  ";
	temp<<ids;
	temp<<name<<endl;
	
	for(int i=id;i<19;i++)
	{
		getline(ifs,data);
		temp<<data<<endl;
	}
	getline(ifs,data);
	temp<<data;
	
	
	ifs.close();
	temp.close();
	
	remove(c);
	rename("temporary.txt",c);

	cout<<endl;
}
void main_menu()
{
	cout<<"HELLO CUSTOMER, WELCOME TO GOODWILL LIBRARY\n";
	cout<<"Please select one option from below: \n";
	cout<<"       1. Veiw list of books on our shelves\n";
	cout<<"       2. Request for a new book\n";
	cout<<"       3. Return a book\n";
	cout<<"       4. Exit\n";
}
int main()
{
	Goodwill g;
	while(true)
	{
		cout<<endl;
		main_menu();
		cout<<"Enter Your Option: ";
		int option; cin>>option;
		if(option==1)
		{
			g.veiwlist();
		}
		else if(option==2)
		{
			g.request_book();
		}
		else if(option==3)
		{
			g.return_book();
		}
		else if(option==4)
		{
			cout<<"Exiting the Application!\n";
			return 0;
		}
		else
		{
			cout<<"Please enter a valid option (1 to 4)\n";
		}
	}
	
}
