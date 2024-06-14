#include<iostream>
using namespace std;

//Q1
class Account {
	int Num;
	float Bal;
public:
	Account() {
		Num = 0;
		Bal = 0;
	}
	Account(int Num,float Bal) {
		this->Num = Num;
		this->Bal = Bal;
	}
	~Account() {
		cout << "Account Destructor Called." << endl;
	}
	void set_Num(const int Num) {
		this->Num = Num;
	}
	void set_Bal(const float Bal) {
		this->Bal = Bal;
	}
	int get_Num() {
		return Num;
	}
	float get_Bal() {
		return Bal;
	}

	virtual void credit(float X) = 0;
	virtual void debit(float X) = 0;

	virtual void print() {
		cout << "Account Number  : " << Num << endl;
		cout << "Account Balance : " << Bal << endl;
	}
};
class CurrentAccount : public Account{
	float serviceCh;
	float minBal;
public:
	CurrentAccount(){
		serviceCh = 0;
		minBal = 0;
	}
	CurrentAccount(int Num,float Bal,float serviceCh,float minBal):Account(Num,Bal) {
		this->serviceCh = serviceCh;
		this->minBal = minBal;
	}
	~CurrentAccount() {
		cout << "Current Account Destructor Called." << endl;
	}
	void print() {
		cout << "Account Number  : " << get_Num() << endl;
		cout << "Account Balance : " << get_Bal() << endl;
		cout << "Minimum Balance : " << minBal << endl;
		cout << "Service Charges : " << serviceCh << endl;
	}
	void credit(float X) {
		bool ded=false;
		if (get_Bal() < minBal) {
			ded = true;
		}
		set_Bal(get_Bal() + X);
		if (ded == true) {
			set_Bal(get_Bal() - serviceCh);
		}
	}
	void debit(float X) {
		if (X <= get_Bal()) {
			set_Bal(get_Bal() - X);
		}
		else
			cout << "Your account balance is less than the debit amount." << endl;
	}
};
class SavingAccount : public Account{
	float interest;
public:
	SavingAccount() {
		interest = 0;
	}
	SavingAccount(int Num, float Bal, float interest) :Account(Num, Bal) {
		this->interest = interest;
	}
	~SavingAccount() {
		cout << "Saving Account Destructor Called." << endl;
	}
	void print() {
		cout << "Account Number  : " << get_Num() << endl;
		cout << "Account Balance : " << get_Bal() << endl;
		cout << "Interest Rate   : " << interest << "%" << endl;
	}
	void credit(float X) {
		set_Bal(get_Bal() + X);
	}
	void debit(float X) {
		if (X <= get_Bal()) {
			set_Bal(get_Bal() - X);
		}
		else
			cout << "Your account balance is less than the debit amount." << endl;
	}
};
void Q1() {
	Account* arr[2];
	CurrentAccount Cacc(1, 5000, 100, 500);
	SavingAccount Sacc(2, 200, 4.5);
	arr[0] = &Cacc;
	arr[1] = &Sacc;
	int choice = 0, choice1 = 0;
	float debit = 0, credit = 0;
	do {
		do {
			cout << "What do you want to do : Press : 1 for credit, 2 for debit, 3 for Check Account, 4 for exit : ";
			cin >> choice;
		} while (choice < 1 || choice>4);
		if (choice == 1) {
			choice1 = 0;
			cout << "Enter the Credit amount : ";
			cin >> credit;
			cout << "Enter the type of account you want to credit : Press : 1 for Current and 2 for Saving : ";
			cin >> choice1;
			if (choice1 == 1) {
				Cacc.credit(credit);
				Cacc.print();
			}
			else if (choice1 == 2) {
				Sacc.credit(credit);
				Sacc.print();
			}
		}
		else if (choice == 2) {
			choice1 = 0;
			cout << "Enter the Debit amount : ";
			cin >> debit;
			cout << "Enter the type of account you want to debit : Press : 1 for Current and 2 for Saving : ";
			cin >> choice1;
			if (choice1 == 1) {
				Cacc.debit(debit);
				Cacc.print();
			}
			else if (choice1 == 2) {
				Sacc.debit(debit);
				Cacc.print();
			}
		}
		else if (choice == 3) {
			for (int i = 0; i < 2; i++) {
				arr[i]->print();
				cout << endl;
			}
		}
		else if (choice == 4) {
			exit(0);
		}
	} while (choice != 4);
}

//Q2
class Point {
	int x;
	int y;
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
		cout<<"Point Called."<<endl;
	}
	~Point() {
		cout << "~Point Called." << endl;
	}
	void print() {
		cout<<" ("<<x<<","<<y<<")";
	}
};
class Circle  {
	float radius;
	Point center;
public:
	Circle() {
		radius = 0;
	}
	Circle(int x,int y,float radius):center(x,y) {
		this->radius = radius;
		cout<<"Circle Called."<<endl;
	}
	~Circle() {
		cout << "~Circle Called." << endl;
	}
	void print() {
		cout << "The circle is centered at "; center.print();
		cout << endl;
		cout << "The radius of the circle is " << radius << endl;
	}

};
class Quadrilateral {
	Point w;
	Point x;
	Point y;
	Point z;
public:
	Quadrilateral() {}
	Quadrilateral(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4):w(x1,y1),x(x2,y2),y(x3,y3),z(x4,y4){
		cout << "Quadrilateral called." << endl;
	}
	~Quadrilateral() {
		cout << "~Quadrilateral called."<<endl;
	}
	void print() {
		cout << "The corner w of quadrilateral is : "; w.print(); cout << endl;
		cout << "The corner x of quadrilateral is : "; x.print(); cout << endl;
		cout << "The corner y of quadrilateral is : "; y.print(); cout << endl;
		cout << "The corner z of quadrilateral is : "; z.print(); cout << endl;
	}
};
void Q2() {
	Circle c(3,4,2.5);
	c.print();
	cout << endl;
	Quadrilateral q(1, 0, 0, 1, 1, 1, 0, 0);
	q.print();
}

//Q3
class Teacher {
	int employeeID;
	char* name;
public:
	Teacher() {
		employeeID = 0;
		name = NULL;
	}
	Teacher(int employeeID,char*name):employeeID(employeeID),name(name){}
	~Teacher(){}
	void display() {
		cout << "The ID of teacher : " << employeeID<<endl;
		cout << "The name of teacher : " <<* name<<endl;
	}
};
class Student {
	char* roll;
	char* name;
	Teacher* teacherlist;
public:
	Student() {
		roll = nullptr;
		name = nullptr;
		teacherlist = nullptr;
	}
	Student(char* Roll, char* Name, Teacher* Teacherl) :roll(Roll), name(Name), teacherlist(Teacherl) {}
	~Student() {}
	void display() {
		cout << "The roll no. of student : " << roll<<endl;
		cout << "The name of student :" << name << endl;
		teacherlist->display();
	}
};

int main() {
	int choice = 0;
	do {
		cout<<"Press 1 for Q1, 2 for Q2, 3 for Q3, 4 for Q4, 5 for exit : ";
		cin >> choice;
		if (choice == 1) {
			Q1();
		}
		else if (choice == 2) {
			Q2();
		}
		else if (choice == 3) {
			Q3();
		}
		else if (choice == 4) {
			Q4();
		}
		else if (choice == 5) {
			exit(0);
		}
	} while (choice != 5);
	system("pause>nul");
	return 0;
}



