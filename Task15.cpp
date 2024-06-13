/*
1. For simplicity, create a single .cpp file with the following classes: Faculty, Administrator,
Teacher, & AdministratorTeacher.
2. Faculty inherits Administrator and Teacher. While AdministratorTeacher has two
parents Administrator and Teacher which represents that an Administrator can be a
Teacher and vice versa

Task 1:
3. Add a print() method to Faculty, Administrator, and Teacher which displays the class
name.
4. In the driver, create a pointer array of 3 Faculty objects.
5. Create one object for each of the remaining three classes as well and assign these three object
to the Faculty object array.
6. Now, in a loop call the print method on the Faculty object array and observe the code
behavior.
7. You may observe that “Faculty” is displayed on the console 3 times which is wrong.
8. To make corrections, use polymorphism. Make the print() method virtual and execute again.
9. This time you will encounter an error. It occurs because the AdministratorTeacher object
shows ambiguous behavior when calling the print() method (It does not know which print
method it should call)

10. To resolve this issue, we are going to use virtual inheritance. First, make the print() method
pure virtual in Faculty. And add a print() method in the AdministratorTeacher class as
well. Qualify or override this print() method by calling the print() of either Teacher or
Administrator specifically.
11. Execute the program and report the issue in comment
12. Now, use virtual inheritance i.e. declare Faculty inheritance using public virtual keyword for
Teacher and Administrator classes.
13. Execute the program again. This time you will observe that correct class names are displayed
on console.


Task 2:
14. Each faculty member is assigned an id by the university. To represent this, add an get_id()
method to both Administrator and Teacher which returns a unique integer number.
15. Call the get_id() method using the AdministratorTeacher object. Observe the error. Can
you explain why?
16. One approach would be to qualify the get_id() method as we did with print(). But if we are
making use of inheritance, there should only be one get_id() method in the Faculty class.
Remove the get_id() method from the child classes. Execute the program and observe that it
works. Can you explain why is there no ambiguity when calling the get_id() method from
AdministratorTeacher object?

Abstract Classes & Pure Virtual Functions
Define a pure abstract base class called BasicShape. The BasicShape class should have the
following members:
Private Member Variable:
area, a double used to hold the shape's area.
Public Member Functions:
getArea.:
This function should return the value in the member variable area.
calcArea.:
This function should be a pure virtual function.
Next, define a class named Circle. It should be derived from the BasicShape class. It should have
the following members:
Private Member Variables:
centerX, a long integer used to hold the x coordinate of the circle’s center.
centerY, a long integer used to hold the y coordinate of the circle’s center.
radius, a double used to hold the circle's radius.

Public Member Functions:
constructor—accepts values for centerX, centerY, and radius.
Should call the overridden calcArea function described below.
getCenterX—returns the value in centerX.
getCenterY—returns the value in centerY.
calcArea—calculates the area of the circle(area = 3.14159 * radius * radius) and stores the result
in the inherited member area.
Next, define a class named Rectangle. It should be derived from the BasicShape class. It should
have the following members:
Private Member Variables:
width, a long integer used to hold the width of the rectangle.
length,a long integer used to hold the length of the rectangle.
Public Member Functions:
constructor—accepts values for width and length. Should call the overridden calcArea function
described below.
getWidth—returns the value in width.
getLength—returns the value in length.
calcArea—calculates the area of the rectangle (area = length * width) and stores the result in the
inherited member area.
After you have created these classes, create a driver program that defines a Circle object and a
Rectangle object. Demonstrate that each object properly calculates and reports its area.
Note:
a. Follow all the code indentation, naming conventions and code commenting guidelines.
b. Make sure your program is executable.
*/

#include<iostream>
using namespace std;
class Faculty {

public:
	virtual void print() = 0;
	virtual int get_id() = 0;
};

class Administrator :virtual public Faculty {

public:
	virtual void print()
	{
		cout << "Administrator\n";
	}
	int get_id()
	{
		return 1;
	}
};

class Teacher :virtual public Faculty {

public:
	virtual void print()
	{
		cout << "Teacher\n";
	}
	int get_id()
	{
		return 2;
	}
};

class AdministratorTeacher : public Administrator, public Teacher {

public:
	void print()
	{
		cout << "AdministratorTeacher\n";
	}
	int get_id()
	{
		return 3;
	}
	//issue: cannot declare variable 'AT' to be of abstract type 'AdministratorTeacher'
};
void Task1()
{
	Faculty* arr[3];
	Administrator A;
	Teacher T;
	AdministratorTeacher AT;
	arr[0] = &A;
	arr[1] = &T;
	arr[2] = &AT;
	for (int i = 0; i < 3; i++)
	{
		arr[i]->print();
	}
	cout << "The ID is : " << AT.get_id() << endl << endl;
}


class BasicShape {
	double area;
public:
	double get_area()
	{
		return area;
	}
	void set_area(double area)
	{
		this->area = area;
	}
	virtual void calcArea() = 0;
};
class Circle : public BasicShape {
	long int centerX;
	long int centerY;
	double radius;
public:
	Circle() {
		centerX = 0;
		centerY = 0;
		radius = 0;
	}
	Circle(const long int x, const long int y, const double r) {
		centerX = x;
		centerY = y;
		radius = r;
		calcArea();
	}
	long int getcentX() {
		return centerX;
	}
	long int getcentY() {
		return centerY;
	}
	void calcArea() {
		set_area(3.1416 * radius * radius);
	}
	~Circle() {}
};

class Rectangle :public BasicShape {
	long int width;
	long int length;
public:
	Rectangle() {
		width = 0;
		length = 0;
	}
	Rectangle(long int l, long int w) {
		length = l;
		width = w;
		calcArea();
	}
	long int get_length() {
		return length;
	}
	long int get_width() {
		return width;
	}
	void calcArea() {
		set_area(length * width);
	}
	~Rectangle() {}
};

void Task2() {
	Circle c(0, 0, 5);
	Rectangle r(10, 20);
	cout << "Circle area = " << c.get_area() << endl;
	cout << "Rectangle area = " << r.get_area() << endl;
}
int main() {
	int choice;
	cout << "Press 1 for Faculty tasks and 2 for BasicShape tasks : ";
	cin >> choice;
	if (choice == 1)
		Task1();
	else if (choice == 2)
		Task2();
	system("pause");
	return 0;
}