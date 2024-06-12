//Task3 : Write a C++ program that creates a pointer to an integer and print the following: Square of the integer, cube of the integer, half of the integer

#include<iostream>
using namespace std;
int main()
{
	int x;
	cout<<"Enter the value of x: ";
	cin>>x;
	int *p;
	p=&x;
	int cube=(*p)*(*p)*(*p);
	int square=(*p)*(*p);
	float half=(0.5)*(*p);
	cout<<"Square "<<square<<endl;
	cout<<"Cube   "<<cube<<endl;
	cout<<"half   "<<half<<endl;
	system("pause>nul");
	return 0;
}