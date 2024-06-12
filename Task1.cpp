//Write the following code and observe the output:

#include<iostream>
using namespace std;
int main()
{
	int x,y;
	x=3,y=4;
	int*p;
	int*q;
	p=&x;
	q=&y;
	cout<<x<<'\t'<<p<<'\t'<<*p<<'\t'<<&p<<'\t'<<&x<<endl;
	cout<<y<<'\t'<<q<<'\t'<<*q<<'\t'<<&q<<'\t'<<&y<<endl;
	system("pause>nul");
	return 0;
}