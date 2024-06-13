/*
Exercise 0: Template Practice
Consider the definition of the following function template:
template <class type>
type surprise(type x, type y)
{
return x + y;
}
Understand the code. What is the output of the following statements? Make a .cpp file to execute
this code and add the output as comments in this file.
1. cout << surprise(5, 7) << endl;
2. string str1 = "Sunny";
string str2 = " Day";
cout << surprise(str1, str2) << endl;

Exercise 1: Template Functions
Write Template function for performing arithmetic operation of type int, float, double, long. Main
for this function is given below.
void main()
{

int a, b; // this can be float, int or double too
char op;
cout << "Enter first operand ";
cin >> a;
cout << "Enter second operand ";
cin >> b;
cout << "Enter operation ";
cin >> op; // op can be +, -, * or /
if (op == '*' || op == '+' || op == '-' || op == '/')
{
performOperation(a, b, op);
}
else
{
cout << "Wrong operation";
}
}
Exercise 2: Template Function and Overloading
1. Write two function templates GetMax and GetMin that take two arguments and return the
maximum and minimum of the two respectively.
2. Then paste the following code in your source file and run the program. The program should
run peacefully.
int main ()
{
int i=5, j=6, k;
long l=10, m=5, n;
k=GetMax<int>(i,j);
n=GetMin<long>(l,m);
cout << k << endl;
cout << n << endl;
return 0;
}
3. Now remove the <int> and <long> from the code above and execute again. Does the
program still work?
4. Now replace the main function above with the main given below. You will need to change
the code (declaration and definition) for GetMin and GetMax so that the following code
works without an error.

int main ()
{
char i=’Z’;
int j=6, k;
long l=10, m=5, n;
k=GetMax<int,long>(i,m);
n=GetMin<int,char>(j,l);
cout << k << endl;
cout << n << endl;
return 0;
}

5. Now remove the <int,long> and <int,char> from this new main and re-run the program, is
there any trouble with this version?
6. Now overload these template functions so that the maximum and minimum of 3 numbers
could be found.

Exercise 3: Template Specialization
If we want to define a different implementation for a template when a specific type is passed as
template parameter, we can declare a specialization of that template.
template <>
char* maximum <char*>(char* x, char * y)
{
if (strcmp(x,y)==1)
return x;
else
return y;

}
Consider a template function increment, that receives a variable (it can be int, double, float etc)
and increase the value of that variable by 1.
Now Write a template specialization for char * variables (character arrays) that convert all letters
of character arrays to upper case.
Hint:
Lowercase characters ASCII range from 97 to 122. If the character is found to be in this range then
the program converts that character into an uppercase character. ASCII of ‘A’ and ‘a’ differs by
32.

Exercise 4: Exception Handling Practice
Consider the following C++ code:
int numOfItems;
double unitCost;
try
{
cout << "Enter the number of items: ";
cin >> numOfItems;
cout << endl;
if (numOfItems < 0)
throw numOfItems;
cout << "Enter the cost of one item: ";
cin >> unitCost;
cout << endl;
if (unitCost < 0)
throw unitCost;
cout << "Total cost: $"
<< numOfItems * unitCost << endl;

}
catch (int num)
{
cout << "Negative number of items: " << num
<< endl;
cout << "Number of items must be nonnegative."
<< endl;

}
catch (double dec)
{
cout << "Negative unit cost: " << dec
<< endl;
cout << "Unit cost must be nonnegative."
<< endl;

}
Answer the following:
a) What is the output if the input is 25 5.50?
b) What is the output if the input is -55 2.8?
c) What is the output if the input is 37 -4.5?
d) What is the output if the input is -10 -2.5?

Exercise 5: Exception Handling Problem
Write a program that prompts the user to enter a person’s date of birth in numeric form such as 8-27-
1980. The program then outputs the date of birth in the form: August 27, 1980. Your program must
contain three exception classes: invalidDay, invalidMonth, and invalidYear. If the user enters an
invalid value for day, then the program should throw and catch an invalidDay object. Follow similar
convention for the invalid values of month. Handle leap year value with invalidYear exception.
*/

#include<iostream>
#include<string>
using namespace std;


template <typename type>
type surprise(type x, type y) {
	return x + y;
}
void Exercise0() {
	cout << surprise(5, 7) << endl;
	string str1 = "Sunny";
	string str2 = " Day";
	cout << surprise(str1, str2) << endl;
	//The output of the above code is:
	//12
	// Sunny Day
}


template<typename T>
T performOperation(T x, T y, char c) {
	T result;
	switch (c) {
	case('+'):
		result = x + y;
		break;
	case('-'):
		result = x - y;
		break;
	case('*'):
		result = x * y;
		break;
	case('/'):
		result = x / y;
		break;
	default:
		cout << "Invalid Operation\n";
		result = 0;
		break;
	}
	return result;
}
void Exercise1() {
	int a, b; // this can be float, int or double too
	char op;
	cout << "Enter first operand ";
	cin >> a;
	cout << "Enter second operand ";
	cin >> b;
	cout << "Enter operation ";
	cin >> op; // op can be +, -, * or /
	if (op == '*' || op == '+' || op == '-' || op == '/')
	{
		cout << a << op << b << " = " << performOperation(a, b, op) << endl;
	}
	else
		cout << "Wrong operation\n";
}


template <typename U, typename V, typename X>
U getMin(U x1, V x2, X x3) {
	if (x1 < x2 && x1 < x3)
		return x1;
	if (x2 < x1 && x2 < x3)
		return x2;
	else
		return x3;
}
template <typename U, typename V, typename X>
U getMax(U x1, V x2, X x3) {
	if (x1 > x2 && x1 > x3)
		return x1;
	if (x2 > x1 && x2 > x3)
		return x2;
	else
		return x3;
}
void Exercise2() {
	//After running the code in Q:2 it gives 6 <<endl 5 and the same output was produced in Q3.
	//in Q4: the output was 90 <<endl 6 and the same output was in Q5.

	char i = 'Z', h = 'L';
	int j = 6, k;
	long l = 10, m = 5, g = 2, n;
	k = getMax(i, m, h);
	n = getMin(j, l, g);
	cout << k << endl;
	cout << n << endl;
}

template<typename T>
T increament(T x) {
	return x + 1;
}
template<typename T>
void variable(T* X, int size) {
	for (int i = 0; i < size; i++) {
		if (X[i] >= 97 && X[i] <= 122) {
			X[i] -= 32;
		}
	}
}
void Exercise3() {
	int num;
	cout << "Enter a number : ";
	cin >> num;
	cout << "After increament : " << increament(num) << endl;

	char* arr;
	int size;
	cout << "How many variables do you want to convert from lower to upper case : ";
	cin >> size;
	arr = new char[size];
	cout << "Enter alphabets : \n";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	variable(arr, size);
	cout << "The converted alphabets are : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}


class InvalidDay {
public:
	InvalidDay(int day) : day_(day) {}

	int getDay() const {
		return day_;
	}

private:
	int day_;
};

class InvalidMonth {
public:
	InvalidMonth(int month) : month_(month) {}

	int getMonth() const {
		return month_;
	}

private:
	int month_;
};

class InvalidYear {
public:
	InvalidYear(int year) : year_(year) {}

	int getYear() const {
		return year_;
	}

private:
	int year_;
};

class DateOfBirth {
public:
	DateOfBirth(int day, int month, int year) : day_(day), month_(month), year_(year) {}

	void validate() {
		if (day_ < 1 || day_ > 31) {
			throw InvalidDay(day_);
		}
		if (month_ < 1 || month_ > 12) {
			throw InvalidMonth(month_);
		}
		if (year_ % 4 != 0 && month_ == 2 && day_ > 28) {
			throw InvalidYear(year_);
		}
	}

	string getFormattedDate() const {
		static const string months[] = {
			"January", "February", "March", "April", "May", "June",
			"July", "August", "September", "October", "November", "December"
		};

		return months[month_ - 1] + " " + to_string(day_) + ", " + to_string(year_);
	}

private:
	int day_;
	int month_;
	int year_;
};
void Exercise5() {
	int day, month, year;

	cout << "Enter the date of birth (format: day-month-year): ";
	cin >> day >> month >> year;

	try {
		DateOfBirth dob(day, month, year);
		dob.validate();
		cout << "Formatted date of birth: " << dob.getFormattedDate() << endl;
	}
	catch (const InvalidDay& e) {
		cout << "Invalid day value: " << e.getDay() << endl;
	}
	catch (const InvalidMonth& e) {
		cout << "Invalid month value: " << e.getMonth() << endl;
	}
	catch (const InvalidYear& e) {
		cout << "Invalid year value for February: " << e.getYear() << endl;
	}
}

int main() {

	int choice;
	do {
		do {
			cout << "Enter '0' for Exercise 0\n1 for Exercise 1\n2 for exercise 2\n3 for exercise 3\n4 for exercise 4\n5 for Exit\n";
			cin >> choice;
		} while (1 > choice || choice > 5);
		if (choice == '0') {
			Exercise0();
		}
		if (choice == '1') {
			Exercise1();
		}
		if (choice == '2') {
			Exercise2();
		}
		if (choice == '3') {
			Exercise3();
		}
		//The outputs of Q4 are
		//a. Total cost: $137.5
		//b. Negative number of items: -55
		//   Number of items must be nonnegative.
		//c. Negative unit cost: -4.5
		//   Unit cost must be nonnegative.
		//d. Negative number of items: -10
		//   Number of items must be nonnegative.
		if (choice == '4') {
			Exercise5();
		}

	} while (choice != 5);



	system("pause>nul");
	return 0;
}