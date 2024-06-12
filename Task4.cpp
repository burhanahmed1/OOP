//Task4 : Write a C++ program that finds and prints the median of following three integers using their pointers.

#include<iostream>
using namespace std;
int main()
{
	int x,y,z;
	cout<<"Enter the value of x: ";
	cin>>x;
	cout<<"Enter the value of y: ";
	cin>>y;
	cout<<"Enter the value of z: ";
	cin>>z;
	int *p;
	int *q;
	int *r;

	p=&x;
	q=&y;
	r=&z;

	cout<<"Median="<<(*p+*q+*r)/3;

	system("pause>nul");
	return 0;
}