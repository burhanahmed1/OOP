#include<iostream>
#include<string>
using namespace std;

//Task1
class Date {
	unsigned int day;
	unsigned int month;
	unsigned int year;
public:
	//Constructors
	Date()
	{
		cout << "\n\nDefault Constructor Called";
		day = 1;
		month = 1;
		year = 1926;
	}
	Date(unsigned int day, unsigned int month, unsigned int year)
	{
		cout << "\n\nOverloaded Function Called";
		this->day = day;
		this->month = month;
		this->year = year;
	}

	void print()
	{
		cout << "\nDate: ";
		cout << day << "/";
		cout << month << "/";
		cout << year;
	}

	int Input()
	{
		cout << endl << endl;
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
		return 0;
	}

	//Setters
	void setday(unsigned int day)
	{
		this->day = day;
	}
	void setmonth(unsigned int month)
	{
		this->month = month;
	}
	void setyear(unsigned int year)
	{
		this->year = year;
	}

	//Getters
	int getday()
	{
		return day;
	}
	int getmonth()
	{
		return month;
	}
	int getyear()
	{
		return year;
	}
};
int Task1()
{
	Date date1;
	date1.print();

	Date Independenceday(14, 8, 2020);
	Independenceday.print();

	date1.Input();
	date1.print();

	Date xmasday;
	xmasday.print();

	xmasday.setday(25);
	xmasday.setmonth(12);
	xmasday.setyear(2020);
	xmasday.print();

	cout << "\n\nDay: " << xmasday.getday();
	cout << "\nMonth: " << xmasday.getmonth();
	cout << "\nYear: " << xmasday.getyear();
	return 0;
}

//Task2
class Student {
	string RollNo;
	string Name;
	string CNIC;
	string Degree;
	string Adress;

public:
	//Constructors
	Student()
	{
		cout << "\n\nDefault constructor called";
		RollNo = "123";
		Name = "Ali";
		CNIC = "0000000";
		Degree = "BSDS";
		Adress = "Jannat";
	}
	Student(string RollNo, string Name, string CNIC, string Degree, string Adress)
	{
		cout << "\n\nOverloaded constructor called";
		this->RollNo = RollNo;
		this->Name = Name;
		this->CNIC = CNIC;
		this->Degree = Degree;
		this->Adress = Adress;
	}

	void print()
	{
		cout << endl;
		cout << "\nRollNo: " << RollNo;
		cout << "\nName: " << Name;
		cout << "\nCNIC: " << CNIC;
		cout << "\nDegree: " << Degree;
		cout << "\nAdress: " << Adress;
	}

	void input()
	{
		cout << endl << endl;
		cin.ignore();
		cout << "Enter RollNo: ";
		getline(cin, RollNo);
		cout << "Enter Name: ";
		getline(cin, Name);
		cout << "Enter CNIC: ";
		getline(cin, CNIC);
		cout << "Enter Degree: ";
		getline(cin, Degree);
		cout << "Enter Adress: ";
		getline(cin, Adress);

	}

	//Setters
	void setRollNo(string RollNo)
	{
		this->RollNo = RollNo;
	}
	void setName(string Name)
	{
		this->Name = Name;
	}
	void setCNIC(string CNIC)
	{
		this->CNIC = CNIC;
	}
	void setDegree(string Degree)
	{
		this->Degree = Degree;
	}
	void setAdress(string Adress)
	{
		this->Adress = Adress;
	}

	//Getters
	string getRollNo()
	{
		return RollNo;
	}
	string getName()
	{
		return Name;
	}
	string getCNIC()
	{
		return CNIC;
	}
	string getDegree()
	{
		return Degree;
	}
	string getAdress()
	{
		return Adress;
	}
};
int Task2()
{
	Student student1;    //default cons.
	student1.print();

	Student student2("22L7520", "BurhanGujjar", "11002233", "BSDS", "Pakistan");   //Overloaded cons.
	student2.print();

	student1.input();      //Input Function
	student1.print();

	student1.setRollNo("0987");       //Setters
	student1.setName("Ahmad");
	student1.setCNIC("11001100");
	student1.setDegree("DSCS");
	student1.setAdress("Hell");
	student1.print();

	cout << "\n\nRollNo: " << student1.getRollNo() << endl;       //Getters
	cout << "Name: " << student1.getName() << endl;
	cout << "CNIC: " << student1.getCNIC() << endl;
	cout << "Degree: " << student1.getDegree() << endl;
	cout << "Adress: " << student1.getAdress() << endl;

	return 0;
}
int main()
{
	int a = 0;
	do
	{
		int choice;
		cout << "Enter '1' for task1 and '2' for task2 : ";
		cin >> choice;
		if (choice == 1)
			Task1();
		else if (choice == 2)
			Task2();
		cout << "\n\nEnter 1 to continue and 0 to terminate: ";
		cin >> a;
	} while (a == 1);
	system("pause>nul");
	return 0;
}