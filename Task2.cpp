//Task2 : Given two integers x and y, find and print their sum using pointers.

#include<iostream>
using namespace std;
int main()
{
	int x,y;
	cout<<"Enter the value of x: ";
	cin>>x;
	cout<<"Enter the value of y: ";
	cin>>y;
	int *p;
	int *q;
	p=&x;
	q=&y;
	cout<<"Sum="<<(*p)+(*q);

	system("pause>nul");
	return 0;
}