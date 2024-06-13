#include<iostream>
#include<cstring>
#include<string>
#include"Task11.h"
using namespace std;

void printstudentarray(student arr[], int size)
{
	for(int i=0;i<size;i++)
	{
		arr[i].print();
		cout<<endl;
	}
}

void highesttotal(student arr[], int size)
{
	cout<<"\nHighest Total Score"<<endl;
	if(arr[0].getTotalScore()>arr[1].getTotalScore() && arr[0].getTotalScore()>arr[2].getTotalScore())
		arr[0].print();
	if(arr[1].getTotalScore()>arr[0].getTotalScore() && arr[1].getTotalScore()>arr[2].getTotalScore())
		arr[1].print();
	if(arr[2].getTotalScore()>arr[0].getTotalScore() && arr[2].getTotalScore()>arr[1].getTotalScore())
		arr[2].print();
}
int main()
{
	student students_array[3];

	students_array[0].setName("Ali");
	students_array[0].setrollNo(1);
	students_array[0].setMid1(12);
	students_array[0].setMid2(15);
	students_array[0].setFinal(50);
	students_array[0].setQuizMarks(0,1);
	students_array[0].setQuizMarks(0,2);
	students_array[0].setQuizMarks(0,3);
	students_array[0].setQuizMarks(0,4);

	students_array[1].setName("Sara");
	students_array[1].setrollNo(2);
	students_array[1].setMid1(13);
	students_array[1].setMid2(14);
	students_array[1].setFinal(44);
	students_array[1].setQuizMarks(5,1);
	students_array[1].setQuizMarks(4,2);
	students_array[1].setQuizMarks(0,3);
	students_array[1].setQuizMarks(0,4);

	students_array[2].setName("Ahmed");
	students_array[2].setrollNo(3);
	students_array[2].setMid1(14);
	students_array[2].setMid2(13);
	students_array[2].setFinal(67);
	students_array[2].setQuizMarks(0,1);
	students_array[2].setQuizMarks(0,2);
	students_array[2].setQuizMarks(0,3);
	students_array[2].setQuizMarks(9,4);

	printstudentarray(students_array,3);

	highesttotal(students_array,3);

	system("pause");
	return 0;
}