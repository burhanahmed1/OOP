/*
Task1:
Write a class called Fraction that represents a fraction (i.e., a rational number). Overload the +, -, *, and
/ operators to allow addition, subtraction, multiplication, and division of two fractions. The class should
also implement a method called simplify() that simplifies the fraction to lowest terms. The class should
have the following attributes: numerator (the numerator of the fraction) and denominator (the
denominator of the fraction).

Task2:
Write a class called String that represents a string. Overload the + operator to allow concatenation of
two strings. The class should also implement a method called reverse() that reverses the string. The
class should have the following attribute: str (the string).

Task3:
Write a class called Vector that represents a 1D vector of integers. Overload the - operator to allow
negation of a vector (i.e., negate each element of the vector). The class should also implement a method
called magnitude() that returns the magnitude of the vector. The class should have the following
attributes: size (the size of the vector) and elements (an array of integers representing the elements of
the vector).

Task4:
Write a class called ComplexNumber that represents a complex number. Overload the ++ and --
operators to allow incrementing and decrementing the real and imaginary parts of the complex
number. The class should have the following attributes: real (the real part of the complex number) and
imag (the imaginary part of the complex number).

Task5:
Declare and define a class Set representing a set of integers. A set is a collection of data
without repetition or ordering. The class should have only private data members: a
pointer to a dynamically allocated array of integers and an integer that holds the size of
the set. The following shows the operators to be defined for a set.
Member Functions:
ii. A constructor to create an empty set.
iii. A destructor.
iv. A function to add element to the set. (A set has no duplicate elements, so
design add function accordingly. Also make sure set remain in ascending
order and newly added elements are inserted in their correct positions)
v. A binary friend function to get the union of two sets (overload the + operator).
vi. A binary friend function to determine the difference of two sets (overload the – operator)

*/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class fraction
{

private:
	int numerator;
	int denominator;
public:
	fraction(int numerator = 0, int denominator = 1)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}
	fraction operator +(const fraction& other)const
	{
		int new_denominator = denominator * other.denominator;
		int new_numerator = (numerator * other.denominator) + (other.numerator * denominator);
		return fraction(new_numerator, new_denominator).simplify();
	}
	fraction operator -(const fraction& other)const
	{
		int new_denominator = denominator * other.denominator;
		int new_numerator = (numerator * other.denominator) - (other.numerator * denominator);
		return fraction(new_numerator, new_denominator).simplify();
	}
	fraction operator *(const fraction& other)const
	{
		int new_denominator = denominator * other.denominator;
		int new_numerator = numerator * other.numerator;
		return fraction(new_numerator, new_denominator).simplify();
	}
	fraction operator /(const fraction& other)const
	{
		int new_denominator = denominator * other.numerator;
		int new_numerator = numerator * other.denominator;
		return fraction(new_numerator, new_denominator).simplify();
	}
	fraction simplify() {
		int gcd = find_gcd(numerator, denominator);
		return fraction(numerator / gcd, denominator / gcd);
	}

	int find_gcd(int a, int b) {
		if (b == 0) {
			return a;
		}
		return find_gcd(b, a % b);
	}
	void print() {
		cout << numerator << "/" << denominator << endl;
	}
};
void task1()
{

	fraction f1(5, 4);
	fraction f2(4, 6);

	fraction sum = f1 + f2;
	fraction difference = f1 - f2;
	fraction product = f1 * f2;
	fraction quotient = f1 / f2;

	cout << "Fraction 1 = ";
	f1.print();
	cout << "Fraction 2 = ";
	f2.print();
	cout << "Sum = ";
	sum.print();
	cout << "Difference = ";
	difference.print();
	cout << "Product = ";
	product.print();
	cout << "Quotient = ";
	quotient.print();
}

class String
{
private:
	string str;
public:
	String(const string& str = "")
	{
		this->str = str;
	}
	String operator +(const String& other)
	{
		String result;
		result.str = str + other.str;
		return result;
	}
	void reverse()
	{
		int n = str.length();
		for (int i = 0; i < n / 2; i++)
			swap(str[i], str[n - i - 1]);
	}
	void print()
	{
		cout << str << endl;
	}

};
void task2()
{
	String s1("Burhan"), s2("Ahmed");
	String s3 = s1 + s2;
	s3.print();
	s3.reverse();
	s3.print();
}

class vector
{
private:
	int size;
	int* elements;
public:
	vector(int size)
	{
		this->size = size;
		elements = new int[size];
		for (int i = 0; i < size; i++)
		{
			elements[i] = i + 1;
		}
	}
	~vector()
	{
		cout << "Destructor called" << endl;
	}
	vector operator -()
	{
		for (int i = 0; i < size; i++)
		{
			this->elements[i] = -(this->elements[i]);
		}
		return 0;
	}
	float magnitude()const
	{
		float mag = 0;
		for (int i = 0; i < size; i++)
		{
			mag += elements[i] * elements[i];
		}
		mag = sqrt(mag);
		return mag;
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << elements[i];
		}
	}
};
void task3()
{
	int size;
	cout << "Enter the size of array: ";
	cin >> size;
	cout << "\n";
	vector v1(size);
	v1.print();

	float magnitude = v1.magnitude();
	cout << "\nThe magnituge of vector is: " << magnitude << endl;

	-v1;
	v1.print();
}

class ComplexNumber {
private:
	double real;
	double imag;
public:
	ComplexNumber(double real = 0, double imag = 0)
	{
		this->real = real;
		this->imag = imag;
	}
	ComplexNumber operator ++()// prefix increment
	{
		ComplexNumber temp;
		temp.real = ++real;
		temp.imag = ++imag;
		return 0;
	}
	ComplexNumber operator ++(int) // postfix increment
	{
		ComplexNumber temp;
		temp.real = real++;
		temp.imag = imag++;
		return 0;
	}
	ComplexNumber operator --() // prefix decrement
	{
		ComplexNumber temp;
		temp.real = --real;
		temp.imag = --imag;
		return 0;
	}
	ComplexNumber operator --(int) // postfix decrement
	{
		ComplexNumber temp;
		temp.real = real--;
		temp.imag = imag--;
		return 0;
	}
	void input() {
		cout << "Enter real and imaginary parts respectively: ";
		cin >> real;
		cin >> imag;
	}
	void print()
	{
		if (imag < 0)
			cout << "\nOutput Complex number: " << real << imag << "i";
		else
			cout << "\nOutput Complex number: " << real << "+" << imag << "i";
	}
};
void task4()
{
	ComplexNumber c1;
	cout << "Enter the complex number: ";
	cout << endl;
	c1.input();

	++c1;
	c1.print();

	c1++;
	c1.print();

	--c1;
	c1.print();

	c1--;
	c1.print();
}

class Set
{
private:
	int* set = nullptr;
	int size;
public:
	Set()
	{
		cout << "Enter the number of elements of set : ";
		cin >> this->size;
		set = new int[size];
	}
	~Set()
	{
		cout << "Destructor Called" << endl;
	}
	void add(const int num)
	{
		static int i = 0;
		if (i == 0)
		{
			set[i] = num;
			i++;
		}
		else
		{
			int b = 0;
			for (int a = 0; a < i; a++)
			{
				if (num != set[a])
					b++;
			}
			if (b == i)
			{
				set[i] = num;
				i++;
			}
		}
		for (int j = 0; j < i; j++)
		{
			for (int k = 1; k <= i; k++)
			{
				if (set[j] < set[j - 1])
					swap(set[j - 1], set[j]);
			}
		}
	}

	Set operator +(const Set& other)const
	{
		Set temp;

		return temp;
	}
	Set operator -(const Set& other)const
	{
		Set temp;

		return temp;
	}
	void print()
	{
		cout << "{";
		for (int i = 0; i < size; i++)
		{
			cout << set[i];
			if (i < size - 1)
				cout << ",";
		}
		cout << "}";
	}
};
void task5()
{
	Set A, B;
	A.add(7);
	A.add(2);
	A.add(5);
	B.add(5);
	B.add(3);
	B.add(8);
	cout << "Set A = ";
	A.print();
	cout << "Set B = ";
	B.print();
	Set C = A + B;
	cout << "A + B = ";
	C.print();
	Set D = A - B;
	cout << "A - B = ";
	D.print();
}
int main()
{
	char run = 'c';
	do
	{
		int choice;
		cout << "Enter 1 for task1, 2 for task2, 3 for task3, 4 for task4, 5 for task5 : ";
		cin >> choice;
		if (choice == 1)
			task1();
		if (choice == 2)
			task2();
		if (choice == 3)
			task3();
		if (choice == 4)
			task4();
		if (choice == 5)
			task5();
		cout << "Enter 'c' to continue and 'd' to discontinue : ";
		cin >> run;
	} while (run == 'c');


	system("pause>nul");
	return 0;
}
