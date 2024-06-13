#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class student{
	string Name;
	int Rollno;
	float Mid1;
	float Mid2;
	float Finalexam;
	float *Quiz;
public:
	student()
	{
		Name="";
		Rollno=0;
		Mid1=0;
		Mid2=0;
		Finalexam=0;
		Quiz=new float[4];
		Quiz[0]=0;
		Quiz[1]=0;
		Quiz[2]=0;
		Quiz[3]=0;
	}
	student(string name,int rollno)
	{
		this->Name=name;
		this->Rollno=rollno;
		Mid1=0;
		Mid2=0;
		Finalexam=0;
		Quiz=new float[4];
		Quiz[0]=0;
		Quiz[1]=0;
		Quiz[2]=0;
		Quiz[3]=0;
	}
	void print()
	{
		cout<<"Name : "<<Name<<endl;
		cout<<"Roll No : "<<Rollno<<endl;
		cout<<"Mid1 Marks : "<<Mid1<<endl;
		cout<<"Mid2 Marks : "<<Mid2<<endl;
		cout<<"Final Exam Marks : "<<Finalexam<<endl;
		cout<<"Quiz1 Marks : "<<Quiz[0]<<endl;
		cout<<"Quiz2 Marks : "<<Quiz[1]<<endl;
		cout<<"Quiz3 Marks : "<<Quiz[2]<<endl;
		cout<<"Quiz4 Marks : "<<Quiz[3]<<endl;
	}
	void setName(string name)
	{
		this->Name=name;
	}
	void setrollNo(int rollno)
	{
		this->Rollno=rollno;
	}
	void setMid1(float marks)
	{
		this->Mid1=marks;
	}
	void setMid2(float marks)
	{
		this->Mid2=marks;
	}
	void setFinal(float marks)
	{
		this->Finalexam=marks;
	}
	void setQuizMarks(float marks, int quiz_number)
	{
		this->Quiz[quiz_number-1]=marks;
	}
    float getTotalScore()
	{
		float total=Quiz[0]+Quiz[1]+Quiz[2]+Quiz[3]+Mid1+Mid2+Finalexam;
		return total;
	}
	int compare(student &S)
	{
		if(S.getTotalScore()==getTotalScore())
		{
			return 0; 
		}
		if(S.getTotalScore()>getTotalScore())
		{
			return 1;
		}
		if(S.getTotalScore()<getTotalScore())
		{
			return 2;
		}
	}
	void copy(student &S)
	{
		this->Name=S.Name;
		this->Rollno=S.Rollno;
		this->Mid1=S.Mid1;
		this->Mid2=S.Mid2;
		this->Finalexam=S.Finalexam;
		this->Quiz[0]=S.Quiz[0];
		this->Quiz[1]=S.Quiz[1];
		this->Quiz[2]=S.Quiz[2];
		this->Quiz[3]=S.Quiz[3];
	}
	~student()
	{
		cout<<"Destructor invoked for <student name>"; 
	}
};