/*
This assignment is about implementing a new classes to represent a 2D matrix. A 2D matrix is a
rectangular array of numbers arranged in M rows and N columns. Some examples matrices are shown
below and are commonly used to represent transformation of vectors, system of equations, graphs
images, computation graphs and many other interesting objects.
For the matrices used in algebra, several binary operations (i.e. operations involving two matrices) are
defined on the set of all possible matrices with each binary operations combining two matrices to form
a new matrix. Some well-known binary operations defined on the set of all matrices are listed below.

List of Binary Operations Defined on Matrices

Plus, Minus, Multiply, Divide (Matrix (+\-\*\ /) Matrix, Matrix (+\-\*\ /) = Matrix ) where
division can be point by point division or some other definition of division

Assignment operation (Matrix = Matrix)

Add/subtract/multiply/divide a constant with a Matrix ( Matrix (+\-\*\ /) C, and C (+\-\*\ /) Matrix)
where C is a constant
Several unary operations can also be applied on matrices where a unary operation generates a new
matrix from a given input matrix. Several unary operations defined on matrices are listed below

List of Unary Operations Defined on Matrices

Transpose of a matrix, Trace of a square matrix, power of a matrix (point by point power) and
Apply a function to each element of the matrix point by point (study about function pointers and see
if you can come up with a generic implementation)

For this assignment you must design a hierarchy of two classes named dynamic2DArray and Matrix
respectively.
The dynamic2DArray class will be used to create a 2D array of real numbers having M rows and N
columns with M and N being non-negative integers representing the size of the matrix. At minimum,
you must provide the following functionality for this class.
I/O from an I/O stream by overloading the stream operations and I/O from a file

Changing size of the array

Safe access of any element of the array by specifying index. Make sure that user is allowed to use
any index (positive or negative value) with -1 representing the last valid index -2 the second last ...
The Matrix class will inherit the functionality of dynamic2DArray class and extend it by providing
all the binary and unary operations defined in the lists of binary and unary operations defined above.

You are also required to provide a program (main function) that will allow the user to demonstrate
each of the function created in the two classes. It might be a good idea to create a menu for the user
to test your functionality.
You will submit the assignment in three parts
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;
class dynamic2DArray {
	int M, N;
	float** array;
public:
	dynamic2DArray() {
		M = 0;
		N = 0;
	}
	dynamic2DArray(int M, int N) {
		this->M = M;
		this->N = N;
		array = new float* [M];
		for (int i = 0; i < M; i++) {
			array[i] = new float[N];
		}
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				array[i][j] = 0;
			}
		}
	}
	~dynamic2DArray()
	{

	}
	void createArray() {
		array = new float* [M];
		for (int i = 0; i < M; i++) {
			array[i] = new float[N];
		}
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				array[i][j] = 0;
			}
		}
	}

	void set_M(int M) {
		this->M = M;
	}
	void set_N(int N) {
		this->N = N;
	}
	int getM()
	{
		return M;
	}
	int getN()
	{
		return N;
	}

	friend ostream& operator<<(ostream& os, const dynamic2DArray& arr)
	{
		cout << "The Matrix is: \n";
		for (int i = 0; i < arr.M; i++) {
			for (int j = 0; j < arr.N; j++) {
				os << arr.array[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}
	friend istream& operator>>(istream& is, dynamic2DArray& arr)
	{
		for (int i = 0; i < arr.M; i++) {
			for (int j = 0; j < arr.N; j++) {
				cout << "Enter the value at index (" << i + 1 << "," << j + 1 << ") of the matrix : ";
				is >> arr.array[i][j];
			}
		}
		return is;
	}

	void resize(int M, int N) {
		delete[]array;
		this->M = M;
		this->N = N;
		createArray();
		cout << "Array successfully resized.\n";
	}
	int safeAccess(int index_r, int index_c)
	{
		index_r %= M;
		index_r += M;
		index_r %= M;

		index_c %= N;
		index_c += N;
		index_c %= N;

		return array[index_r][index_c];

	}
	void setValue(int index_r, int index_c, float k)
	{
		array[index_r][index_c] = k;
	}
	void saving()
	{
		ofstream fout;
		fout.open("Matrix.txt");
		fout << M << endl;
		fout << N << endl;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				fout << array[i][j] << " ";
			}
		}
		fout.close();
		cout << "The matrix is saved." << endl;
	}
	void saving1()
	{
		ofstream fout;
		fout.open("Matrix1.txt");
		fout << M << endl;
		fout << N << endl;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				fout << array[i][j] << " ";
			}
		}
		fout.close();
		cout << "The first matrix is saved." << endl;
	}
	void saving2()
	{
		ofstream fout;
		fout.open("Matrix2.txt");
		fout << M << endl;
		fout << N << endl;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				fout << array[i][j] << " ";
			}
		}
		fout.close();
		cout << "The second matrix is saved." << endl;
	}
	void saving3()
	{
		ofstream fout;
		fout.open("Matrix3.txt");
		fout << M << endl;
		fout << N << endl;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				fout << array[i][j] << " ";
			}
		}
		fout.close();
		cout << "The matrix is saved." << endl;
	}
	void loading()
	{
		ifstream fin;
		fin.open("Matrix.txt");
		fin >> M;
		fin >> N;
		createArray();
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				fin >> array[i][j];
			}
		}
		cout << "The matrix is loaded." << endl;
		fin.close();
	}
	void loading1()
	{
		ifstream fin;
		fin.open("Matrix1.txt");
		fin >> M;
		fin >> N;
		createArray();
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				fin >> array[i][j];
			}
		}
		cout << "The first matrix is loaded." << endl;
		fin.close();
	}
	void loading2()
	{
		ifstream fin;
		fin.open("Matrix2.txt");
		fin >> M;
		fin >> N;
		createArray();
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				fin >> array[i][j];
			}
		}
		cout << "The second matrix is loaded." << endl;
		fin.close();
	}
	void loading3()
	{
		ifstream fin;
		fin.open("Matrix3.txt");
		fin >> M;
		fin >> N;
		createArray();
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				fin >> array[i][j];
			}
		}
		cout << "The matrix is loaded." << endl;
		fin.close();
	}
};

class Matrix : public dynamic2DArray {
public:
	Matrix()
		:dynamic2DArray()
	{

	}
	Matrix(int M, int N)
		:dynamic2DArray(M, N)
	{

	}

	Matrix operator =(Matrix& m)
	{
		resize(m.getM(), m.getN());
		for (int i = 0; i < m.getM(); i++)
		{
			for (int j = 0; j < m.getN(); j++)
			{
				setValue(i, j, m.safeAccess(i, j));
			}
		}
		return *this;
	}

	Matrix operator +=(Matrix& m)
	{
		if (getM() == m.getM() && getN() == m.getN())
		{
			for (int i = 0; i < getM(); i++)
			{
				for (int j = 0; j < getN(); j++)
				{
					setValue(i, j, safeAccess(i, j) + m.safeAccess(i, j));
				}
			}
			return *this;
		}
		else
			cout << "Addition not possible because of different dimensions. " << endl;
	}
	Matrix operator -=(Matrix& m)
	{
		if (getM() == m.getM() && getN() == m.getN())
		{
			for (int i = 0; i < getM(); i++)
			{
				for (int j = 0; j < getN(); j++)
				{
					setValue(i, j, safeAccess(i, j) - m.safeAccess(i, j));
				}
			}
			return *this;
		}
		else
			cout << "Subtraction not possible because of different dimensions. " << endl;
	}
	Matrix operator /=(Matrix& m)
	{
		if (getM() == m.getM() && getN() == m.getN())
		{
			for (int i = 0; i < getM(); i++)
			{
				for (int j = 0; j < getN(); j++)
				{
					setValue(i, j, safeAccess(i, j) / m.safeAccess(i, j));
				}
			}
			return *this;
		}
		else
			cout << "Division not possible because of different dimensions. " << endl;
	}
	Matrix operator *=(Matrix& m)
	{
		if (getN() == m.getM())
		{
			Matrix temp(getM(), m.getN());
			for (int i = 0; i < getM(); i++)
			{
				for (int j = 0; j < m.getN(); j++)
				{
					for (int k = 0; k < getN(); k++)
					{
						temp.setValue(i, j, temp.safeAccess(i, j) + (safeAccess(i, k) * m.safeAccess(k, j)));
					}
				}
			}
			*this = temp;
			return *this;
		}
		else
			cout << "Multiplication not possible. " << endl;
	}

	Matrix operator + (Matrix& m)
	{
		if (getM() == m.getM() && getN() == m.getN())
		{
			Matrix temp(m.getM(), m.getN());
			for (int i = 0; i < getM(); i++)
			{
				for (int j = 0; j < getN(); j++)
				{
					temp.setValue(i, j, safeAccess(i, j) + m.safeAccess(i, j));
				}
			}
			return temp;
		}
		else
			cout << "Addition not possible because of different dimensions. " << endl;
	}
	Matrix operator - (Matrix& m)
	{
		if (getM() == m.getM() && getN() == m.getN())
		{
			Matrix temp(m.getM(), m.getN());
			for (int i = 0; i < getM(); i++)
			{
				for (int j = 0; j < getN(); j++)
				{
					temp.setValue(i, j, safeAccess(i, j) - m.safeAccess(i, j));
				}
			}
			return temp;
		}
		else
			cout << "Subtraction not possible because of different dimensions. " << endl;
	}
	Matrix operator / (Matrix& m)
	{
		if (getM() == m.getM() && getN() == m.getN())
		{
			Matrix temp(m.getM(), m.getN());
			for (int i = 0; i < getM(); i++)
			{
				for (int j = 0; j < getN(); j++)
				{
					temp.setValue(i, j, safeAccess(i, j) / m.safeAccess(i, j));
				}
			}
			return temp;
		}
		else
			cout << "Division not possible because of different dimensions. " << endl;
	}
	Matrix operator * (Matrix& m)
	{
		if (getN() == m.getM())
		{
			Matrix temp(getM(), m.getN());
			for (int i = 0; i < getM(); i++)
			{
				for (int j = 0; j < m.getN(); j++)
				{
					for (int k = 0; k < getN(); k++)
					{
						temp.setValue(i, j, temp.safeAccess(i, j) + (safeAccess(i, k) * m.safeAccess(k, j)));
					}
				}
			}
			return temp;
		}
		else
			cout << "Multiplication not possible. " << endl;
	}

	Matrix operator + (const float C)
	{
		Matrix temp(getM(), getN());
		for (int i = 0; i < getM(); i++)
		{
			for (int j = 0; j < getN(); j++)
			{
				temp.setValue(i, j, (safeAccess(i, j) + C));
			}
		}
		return temp;
	}
	Matrix operator - (const float C)
	{
		Matrix temp(getM(), getN());
		for (int i = 0; i < getM(); i++)
		{
			for (int j = 0; j < getN(); j++)
			{
				temp.setValue(i, j, (safeAccess(i, j) - C));
			}
		}
		return temp;
	}
	Matrix operator * (const float C)
	{
		Matrix temp(getM(), getN());
		for (int i = 0; i < getM(); i++)
		{
			for (int j = 0; j < getN(); j++)
			{
				temp.setValue(i, j, (safeAccess(i, j) * C));
			}
		}
		return temp;
	}
	Matrix operator / (const float C)
	{
		Matrix temp(getM(), getN());
		for (int i = 0; i < getM(); i++)
		{
			for (int j = 0; j < getN(); j++)
			{
				temp.setValue(i, j, (safeAccess(i, j) / C));
			}
		}
		return temp;
	}

	friend Matrix operator + (const float C, Matrix& A)
	{
		return A + C;
	}
	friend Matrix operator - (const float C, Matrix& A)
	{
		return A - C;
	}
	friend Matrix operator * (const float C, Matrix& A)
	{
		return A * C;
	}
	friend Matrix operator / (const float C, Matrix& A)
	{
		return A / C;
	}

	Matrix operator ++()
	{
		for (int i = 0; i < getM(); i++)
		{
			for (int j = 0; j < getN(); j++)
			{
				setValue(i, j, safeAccess(i, j) + 1);
			}
		}
		return *this;
	}
	Matrix operator --()
	{
		for (int i = 0; i < getM(); i++)
		{
			for (int j = 0; j < getN(); j++)
			{
				setValue(i, j, safeAccess(i, j) - 1);
			}
		}
		return *this;
	}
	Matrix operator ++(int c)
	{
		for (int i = 0; i < getM(); i++)
		{
			for (int j = 0; j < getN(); j++)
			{
				setValue(i, j, safeAccess(i, j) + c);
			}
		}
		return *this;
	}
	Matrix operator --(int c)
	{
		for (int i = 0; i < getM(); i++)
		{
			for (int j = 0; j < getN(); j++)
			{
				setValue(i, j, safeAccess(i, j) - c);
			}
		}
		return *this;
	}

	Matrix Transpose(Matrix& m)
	{
		Matrix temp(getN(), getM());
		for (int i = 0; i < getM(); i++)
		{
			for (int j = 0; j < getN(); j++)
			{
				temp.setValue(j, i, safeAccess(i, j));
			}
		}
		return temp;
	}
	float TraceofMatrix(Matrix& m)
	{
		int trace = 0;
		for (int i = 0; i < getM(); i++)
		{
			for (int j = 0; j < getN(); j++)
			{
				if (i == j)
				{
					trace += safeAccess(i, j);
				}
			}
		}
		return trace;
	}
	Matrix operator ^ (const float C)
	{
		Matrix temp(getM(), getN());
		for (int i = 0; i < getM(); i++)
		{
			for (int j = 0; j < getN(); j++)
			{
				temp.setValue(i, j, pow(safeAccess(i, j), C));
			}
		}
		return temp;
	}
	Matrix Square()
	{
		Matrix temp(getM(), getN());
		for (int i = 0; i < getM(); i++)
		{
			for (int j = 0; j < getN(); j++)
			{
				temp.setValue(i, j, pow(safeAccess(i, j), 2));
			}
		}
		return temp;
	}

};

int main()
{
	char choice = 'd';
	do {
		int classchoice;
		cout << "Which Class do you want to implement?(Enter 1 for dynamic2DArray, 2 for Matrix): ";
		cin >> classchoice;
		if (classchoice == 1) {
			int choice1 = 10;
			char choice2 = 'n';
			char save;
			int M, N;
			dynamic2DArray d();
			dynamic2DArray d1(1, 1);
			cout << "\nDo you want to reload last program or run new one (Enter 'r' for reload and 'n' for new):";
			cin >> choice2;
			if (choice2 == 'r' || choice2 == 'R')
			{
				d1.loading();
				cout << d1;
			}
			else if (choice2 == 'n' || choice2 == 'N')
			{
				cout << "Enter the number of rows : ";
				cin >> M;
				d1.set_M(M);
				cout << "Enter the number of columns: ";
				cin >> N;
				d1.set_N(N);
				d1.createArray();
			}
			while (choice1 != 0) {
				if (choice1 == 10 && choice2 == 'n')
				{
					cout << "\nWhat do you want to do (Enter number)? but first you have to choose 1 to input values in Matrix : \n1.  Input in the Matrix\n2.  Display the Matrix\n3.  Resize the Matrix\n4.  Safely Access the index of Matrix\n5.  Enter 0 to Exit or to save\n";
					cin >> choice1;
				}
				else
				{
					cout << "\nWhat do you want to do (Enter number) : \n1.  Input in the Matrix\n2.  Display the Matrix\n3.  Resize the Matrix\n4.  Safely Access the index of Matrix\n5.  Enter 0 to Exit or to save\n";
					cin >> choice1;
				}
				if (choice1 == 1) {
					cin >> d1;
				}
				else if (choice1 == 2) {
					cout << d1;
				}
				else if (choice1 == 3) {
					cout << "Enter the new rows and columns sizes respectively : ";
					cin >> M >> N;
					d1.resize(M, N);
					cin >> d1;
					cout << d1;
				}
				else if (choice1 == 4) {
					int r_ind, c_ind;
					cout << "Enter the row index you want to access, starting from '0'(either '+' or '-') : ";
					cin >> r_ind;
					cout << "Enter the column index you want to access, starting from '0' (either '+' or '-') : ";
					cin >> c_ind;
					cout << "The value at the index [" << r_ind << "][" << c_ind << "] is : " << d1.safeAccess(r_ind, c_ind) << endl;
				}
			}
			if (choice1 == 0)
			{
				cout << "Do you want to save the matrix (y for yes and n for no) : ";
				cin >> save;
				choice1 = 10;
				if (save == 'y' || save == 'Y')
				{
					d1.saving();
				}
			}
		}
		else if (classchoice == 2) {
			int choice1_m = 100;
			int choice2_m = 100;
			int op_choice = 10;
			int exit = 1;
			int M, N, M1, N1;
			float C;
			char save, save1;
			while (choice1_m != 0 && choice2_m != 0 && exit != 0)
			{
				cout << "\nWhich type of operations you want to perform (Enter number)\n1. Binary operations\n2. Unary operations\n";
				cin >> op_choice;
				if (op_choice == 1)
				{
					cout << "Do you want to reload last matrices or create new (Enter 'r' for reload & 'n' for new) . ";
					cin >> save;
					Matrix m1(1, 1);
					Matrix m2(1, 1);
					if (save == 'r' || save == 'R')
					{
						m1.loading1();
						cout << m1;
						m2.loading2();
						cout << m2;
					}
					if (save == 'n' || save == 'N')
					{
						cout << "\nEnter the number of rows of first matrix : ";
						cin >> M;
						m1.set_M(M);
						cout << "Enter the number of columns of first matrix : ";
						cin >> N;
						m1.set_N(N);
						m1.createArray();
						cout << "Enter values into the first Matrix: \n";
						cin >> m1;
						m1.saving1();
						cout << m1;
						cout << "Enter the number of rows of second matrix : ";
						cin >> M1;
						m2.set_M(M1);
						cout << "Enter the number of columns of second matrix : ";
						cin >> N1;
						m2.set_N(N1);
						m2.createArray();
						cout << "Enter values into the second Matrix: \n";
						cin >> m2;
						m2.saving2();
						cout << m2;
					}
					cout << "\nWhat do you want to do (Enter Number)?\n1.  Add two matrices(+)\n2.  Subtract two matrices(-)\n3.  Multiply two matrices(*)\n4.  Divide two matrices(/)\n5.  Addition using (+=)\n6.  Subtraction using (-=)\n7.  Multiplication using (*=)\n8.  Division using (/=)\n";
					cin >> choice1_m;
					if (choice1_m == 1)
					{
						Matrix result = m1 + m2;
						cout << "After addition ";
						cout << result;
					}
					else if (choice1_m == 2)
					{
						Matrix result = m1 - m2;
						cout << "After Subtraction ";
						cout << result;
					}
					else if (choice1_m == 3)
					{
						Matrix result = m1 * m2;
						cout << "After Multiplication ";
						cout << result;
					}
					else if (choice1_m == 4)
					{
						Matrix result = m1 / m2;
						cout << "After Divsion";
						cout << result;
					}
					else if (choice1_m == 5)
					{
						m1 += m2;
						cout << "After Addtion ";
						cout << m1;
					}
					else if (choice1_m == 6)
					{
						m1 -= m2;
						cout << "After Subtraction ";
						cout << m1;
					}
					else if (choice1_m == 7)
					{
						m1 *= m2;
						cout << "After Multiplication ";
						cout << m1;
					}
					else if (choice1_m == 8)
					{
						m1 /= m2;
						cout << "After division ";
						cout << m1;
					}
					cout << "\nIf you want to exit, press '0' otherwise '1' ";
					cin >> exit;
				}
				else if (op_choice == 2)
				{
					cout << "Do you want to reload last matrix or create new one (Enter 'r' for reload & 'n' for new) . ";
					cin >> save;
					Matrix m1(1, 1);
					if (save == 'r' || save == 'R')
					{
						m1.loading3();
						cout << m1;
					}
					if (save == 'n' || save == 'N')
					{
						cout << "\nEnter the number of rows : ";
						cin >> M;
						cout << "Enter the number of columns : ";
						cin >> N;
						m1.set_M(M);
						m1.set_N(N);
						m1.createArray();
						cin >> m1;
						m1.saving3();
						cout << m1;
					}
					cout << "Enter Constant: ";
					cin >> C;
					cout << "\nWhat do you want to do (Enter Number)?\n1.  Add a constant to a Matrix\n2.  Substract a constant from a Matrix\n3.  Multiply a Matrix with a constant\n4.  Divide a Matrix with a constant.\n5.  Find transpose of a matrix\n6.  Find trace of a matrix\n7.  Multiply each element of a Matrix with an exponent\n8.  Pre - increament the Matrix\n9.  Pre - decrement the Matrix\n10. Take the square of a Matrix\n";
					cin >> choice2_m;
					if (choice2_m == 1) {
						Matrix result = m1 + C;
						cout << "After Adding constant ";
						cout << result;
					}
					else if (choice2_m == 2) {
						Matrix result = m1 - C;
						cout << "After subtracting constant ";
						cout << result;
					}
					else if (choice2_m == 3) {
						Matrix result = m1 * C;
						cout << "After Multiplication with constant ";
						cout << result;
					}
					else if (choice2_m == 4) {
						Matrix result = m1 / C;
						cout << "After Dividing with constant ";
						cout << result;
					}
					else if (choice2_m == 5)
					{
						Matrix result = m1.Transpose(m1);
						cout << "After Transpose ";
						cout << result;
					}
					else if (choice2_m == 6)
					{
						int retval = m1.TraceofMatrix(m1);
						cout << "The trace is of the Matrix is " << retval << endl;
					}
					else if (choice2_m == 7) {
						cout << "Enter the Power: ";
						cin >> C;
						Matrix result = m1 ^ C;
						cout << result;
					}
					else if (choice2_m == 8) {
						++m1;
						cout << "After increament ";
						cout << m1;
					}
					else if (choice2_m == 9) {
						--m1;
						cout << "After decrement ";
						cout << m1;
					}
					else if (choice2_m == 10) {
						Matrix result = m1.Square();
						cout << result;
					}
					cout << "\nIf you want to exit, press '0' otherwise '1' ";
					cin >> exit;
				}
			}
		}
		cout << "\nPress 'c' to continue and 'd' to discontinue or terminate : ";
		cin >> choice;
	} while (choice == 'c');

	system("pause");
	return 0;

}