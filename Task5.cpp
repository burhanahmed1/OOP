//Task5 : A C++ program where you create an integer array of size 10. Your program will add 3 to each element of the array.You have to add to the elements using pointer only.Array subscript notation cannot be used(neither in addition nor while printing resultant array).


#include<iostream>
using namespace std;
int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int a=3;
	int *p;
	p=&a;
	for(int i=0;i<10;i++)
	{
		*(arr+i)+=*p;
		cout<<*(arr+i)<<endl;
	}
	

	system("pause>nul");
	return 0;
}