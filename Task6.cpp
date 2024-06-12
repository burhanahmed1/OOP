//Task6 : Write a program that keeps taking integer input from the user until user enters -1 and displays the data in reverse order.

#include<iostream>
using namespace std;
int main()
{
	int size=0;

    int *arr=nullptr;

    arr=new int[size];

    int number=0;


    while(number!=-1)

    {

        cout<<"Enter Number: ";

        cin>>number;

        if(number==-1)

            break;

        else
 
            *(arr+(size++))=number;

    }

    for(int i=size-1; i>=0; i--)

        cout<<*(arr+i)<<endl;

	system("pause>nul");
	return 0;
}