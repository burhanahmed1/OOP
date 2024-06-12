/*
Q # 1:-
Take two arrays of integers A and B of sizes M and N respectively (M and N taken from User).Then you need to mix these arrays into a third array named C such that the followingsequence is followed.
All even numbers of A from left to right are copied into C from left to right.
All odd numbers of A from left to right are copied into C from right to left.
All even numbers of B from left to right are copied into C from left to right.
All old numbers of B from left to right are copied into C from right to left.

Q # 2:-
Write a program that keeps taking integer input from the user until user enters - 1 and displays
the data in reverse order.
Your program should save the input in a dynamically allocated array.Initially create a dynamic array of five integers.Each time the array gets filled your program should  double the size of array(i.e., create a new array of double size, copy previous data in new array, delete previous array) and continue taking the input.After receiving - 1 (i.e., end of data input) your program should print the numbers in the reverse order as entered by the user.

Q # 3:-
Take size input from the user and create an array of that size.Now populate the array as well
by taking input from the user.
• First Implement void copyArray(int* arr, int*& amp; arr1, int size) that copies arr into arr1.
• Now implement another function int reduceArray(int* arr, int*& amp; arr1, int size) that
asks user to enter size to reduce the array.To reduce the array remove the elements of the arr
from the start and copy remaining into arr1.Use copyArray function to copy.
*/
#include<iostream>
using namespace std;

void Q1()
{
	int M, N;
	cout << "Enter the size of Array'A' :";
	cin >> M;
	cout << "Enter the size of Array'B' :";
	cin >> N;
	int* A = nullptr;
	A = new int[M];
	int* B = nullptr;
	B = new int[N];
	int* C = nullptr;
	C = new int[M + N];
	cout << "Enter the values in Array 1\n";
	for (int i = 0; i < M; i++)
	{
		cin >> A[i];
	}
	cout << "Enter the values in Array 2\n";
	for (int j = 0; j < N; j++)
	{
		cin >> B[j];
	}
	int a = 0;
	for (int k = 0; k < M; k++)
	{
		if (A[k] % 2 == 0)
		{
			C[a] = A[k];
			a++;
		}
	}
	for (int l = 0; l < N; l++)
	{
		if (B[l] % 2 == 0)
		{
			C[a] = B[l];
			a++;
		}
	}
	for (int n = N - 1; n >= 0; n--)
	{
		if (B[n] % 2 != 0)
		{
			C[a] = B[n];
			a++;
		}
	}
	for (int m = M - 1; m >= 0; m--)
	{
		if (A[m] % 2 != 0)
		{
			C[a] = A[m];
			a++;
		}
	}
	cout << "Mixed Array: ";
	for (int q = 0; q < a; q++)
	{
		cout << C[q] << ",";
	}
}
void Q2()
{
	int size = 5;
	int i = 0;
	int* array = nullptr;
	array = new int[size];
	bool check = true;
	cout << "Enter values(-1 to terminate):";
	while (check == true)
	{
		cin >> *(array + i);
		if (*(array + i) == -1)
		{
			break;
		}
		i++;
		if (i == size)
		{
			size = size + size;
			int* array2 = nullptr;
			array2 = new int[size];
			for (int j = 0; j < size; j++)
			{
				*(array2 + j) = *(array + j);
			}
			delete[]array;
			array = array2;

		}

	}
	for (int k = i - 1; k >= 0; k--)
	{
		cout << *(array + k) << ",";
	}
}
void copyarray(int* arr, int size, int size1)//Q3 starts here
{
	int* arr1 = nullptr;
	arr1 = new int[size - size1];
	int a = 0;
	for (int i = size1; i <= size; i++)
	{
		arr1[a] = arr[i];
		a++;
	}
	for (int i = 0; i < size - size1; i++)
	{
		cout << arr1[i] << ",";
	}
}
void reducearray(int* arr, int size)
{
	int size1;
	cout << "Enter the size of which array is to reduce: ";
	cin >> size1;
	copyarray(arr, size, size1);
}

void Q3()
{
	int size;
	cout << "Enter size of array : ";
	cin >> size;
	int* arr = nullptr;
	arr = new int[size];
	cout << "Enter the values in array:" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	reducearray(arr, size);

}
int main()
{
	int choice;
	cout << "Please press 1 for Q1, 2 for Q2, 3 for Q3: ";
	cin >> choice;
	if (choice == 1)
		Q1();
	if (choice == 2)
		Q2();
	if (choice == 3)
		Q3();
	system("pause>nul");
	return 0;
}