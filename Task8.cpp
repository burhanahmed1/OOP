/*
Q # 1 :
1. Write a function that reads n elements into a one dimensional integer array. Your
function must have the following prototype void cin_Array( int arr[], int n)
2. Write a function that display the first n elements into a one dimensional integer array.
Your function must have the following form also called the function prototype
void cout_Array( const int arr[], int n)
3. Write a function that computes the frequency of each digit in all the numbers stored in
an integer array of size N. The function will have the following prototype
void Digit_Frequency( const int Numbers[], int N, int F[])

Q # 2 : 
1. Write a function int* InputArray(int&amp; size) that asks user to enter size of required array,
allocates the memory on heap, takes input in array and returns its pointer.
2. Write a program void OutputArray(int* myArray, const int&amp; size) that takes a pointer to
an integer array and prints its data.
3. Implement a function int* Intersection(int* setA, int&amp; size1, int* setB, int&amp; size2, int&amp;
size3) that finds intersection (common elements) of two sets (stored using arrays).

Q # 3 :
a) Write a function int** AllocateMemory(int&amp; rows, int&amp; cols) that takes size
of matrix (rows and columns) from user, allocates memory for the matrix and
return its pointer.
b) Write a function void InputMatrix(int** matrix, const int rows, const int
cols) which takes input the values in matrix from user(console).
c) Write a function void DisplayMatrix(int** matrix, const int&amp; rows, const
int&amp; cols) that displays the matrix in proper format.
d) Write a function called maxCol that takes as parameters a pointer to a 2D
array and its dimensions. It should return the largest element in each column
of the array. Since there is more than one column in 2D array, you have to
return a dunamic array that contains largest of each column. 
For example, if the Sample Matrix is
1 4 8
9 1 6
5 7 2
Your function will return array containing maximum elements of all the
columns i.e.
9, 7, 8
e) Write a function void DeallocateMemory(int** matrix, const int&amp; rows) that
deallocates all the memory.
f) (Concatinate tables ) It takes two 2D arrays and returns a new 2D array that
is concation on y or x axis.
int ** concat_table (int **table1, int **table2, int row1, int col1, int row2, int
col2, bool axis); //axis 0 mean x axis 1 means Y axis.

*/

#include<iostream>
using namespace std;

//Q # 1
void cin_Array(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter element " << i + 1 << " of array : ";
		cin >> arr[i];
	}
}
void cout_Array(const int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
		if (i < n - 1)
		{
			cout << ",";
		}
	}
}
void Digit_Frequency(const int Numbers[], int N, int F[])
{
	for (int i = 0; i < 10; i++)
	{
		F[i] = 0;
	}
	int temp = 0, dig = 0;
	for (int i = 0; i < N; i++)
	{
		temp = Numbers[i];
		while (temp > 0)
		{
			dig = temp % 10;
			F[dig]++;
			temp /= 10;
		}

	}
}
void Q1()
{
	int n, m;
	cout << "Enter the size of array : ";
	cin >> n;
	int* F = new int[10];
	int* arr = new int[n];
	cin_Array(arr, n);
	cout << "\nEnter the number of elements you want to display from an array of size " << n << " : ";
	cin >> m;
	cout << "The array is : ";
	cout_Array(arr, m);
	Digit_Frequency(arr, n, F);
	cout << "\n\nThe array is : ";
	cout_Array(arr, n);
	cout << "\nThe frequencies of digits is : ";
	cout_Array(F, 10);
	delete[] arr;
	delete[]F;
}

//Q # 2
int* InputArray(int& size)
{
	cout << "Enter the size of array : ";
	cin >> size;
	int* a = new int[size];
	cout << "Enter " << size << " elements of array : ";
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	return a;
}
void OutputArray(int* myArray, const int& size)
{
	cout << "{";
	for (int i = 0; i < size; i++)
	{
		cout << myArray[i];
		if (i < size - 1)
		{
			cout << ",";
		}
	}
	cout << "}";
}
int* Intersection(int* setA, int& size1, int* setB, int& size2, int& size3)
{
	int* setC = new int[size3];
	int count = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int a = 0; a < count; a++)
		{
			if (setA[i] == setC[a])
			{
				i++;
				break;
			}
		}
		for (int j = 0; j < size2; j++)
		{
			if (setA[i] == setB[j])
			{
				setC[count] = setA[i];
				count++;
				break;
			}
		}
	}
	size3 = count;
	return setC;
}
void Q2()
{
	int size1 = 0, size2 = 0;
	int* setA = InputArray(size1);
	int* setB = InputArray(size2);
	int size3 = size1 + size2;
	int* setC = Intersection(setA, size1, setB, size2, size3);
	cout << "A = ";
	OutputArray(setA, size1);
	delete[]setA;
	cout << "\nB = ";
	OutputArray(setB, size2);
	delete[]setB;
	cout << "\nA intersection B = ";
	OutputArray(setC, size3);
	delete[]setC;
}

//Q # 3
int** AllocateMemory(int& row, int& col)
{
	cout << "Enter the no. of rows of matrix : ";
	cin >> row;
	cout << "Enter the no. of cols of matrix : ";
	cin >> col;
	int** matrix = new int* [row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}
	return matrix;
}
void InputMatrix(int** matrix, const int row, const int col)
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << "Enter the value of col " << i + 1 << " row " << j + 1 << " : ";
			cin >> matrix[j][i];
		}
	}
}
void DisplayMatrix(int** matrix, const int& row, const int& col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
int* maxCol(int** matrix, const int& row, const int& col)
{
	int temp = 0, j = 0;
	int* arr = new int[col];
	for (int i = 0; i < col; i++)
	{
		temp = matrix[0][i];
		for (j = 0; j < row; j++)
		{
			if (matrix[i][j] > temp)
			{
				temp = matrix[i][j];
			}
		}
		arr[i] = temp;
	}
	return arr;
}
void DeallocateMemory(int** matrix, const int& rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]matrix[i];
	}

	delete[]matrix;
}
int** concat_table(int** table, int** table1, int row1, int col1, int row2, int col2, bool axis)
{
	if (axis == 0)
	{
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col1; j++)
			{
				cout << table[i][j] << " ";
			}
			for (int j = 0; j < col1; j++)
			{
				cout << table1[i][j] << " ";
			}
			cout << endl;
		}
	}
	if (axis == 1)
	{
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col1; j++)
			{
				cout << table[i][j] << " ";

			}
			cout << endl;
		}
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col1; j++)
			{
				cout << table1[i][j] << " ";

			}
			cout << endl;
		}
	}
	return 0;
}

void Q3()
{
	int row = 0, col = 0;
	int** matrix = AllocateMemory(row, col);
	InputMatrix(matrix, row, col);
	DisplayMatrix(matrix, row, col);
	int* arr = maxCol(matrix, row, col);
	cout << "The largest of column values are : ";
	for (int i = 0; i < col; i++)
	{
		cout << arr[i];
		if (i < col - 1)
		{
			cout << ",";
		}
	}
	DeallocateMemory(matrix, row);
	int row1 = 0, col1 = 0;
	int** table = AllocateMemory(row1, col1);
	InputMatrix(table, row1, col1);
	DisplayMatrix(table, row1, col1);
	int row2 = 0, col2 = 0;
	int** table1 = AllocateMemory(row2, col2);
	InputMatrix(table1, row2, col2);
	DisplayMatrix(table1, row2, col2);
	bool axis;
	cout << "Enter axis to concatinate (0 for x-axis) and (1 for y_axis) : ";
	cin >> axis;
	cout << "Concatinated Table";
	concat_table(table, table1, row1, col1, row2, col2, axis);

}
int main()
{
	int choice;
	cout << "Press 1 for task1, 2 for task2, 3 for task3 : ";
	cin >> choice;
	if (choice == 1)
	{
		Q1();
	}
	else if (choice == 2)
	{
		Q2();
	}
	else if (choice == 3)
	{
		Q3();
	}
	system("pause>nul");
	return 0;
}