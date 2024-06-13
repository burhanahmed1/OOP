/*
Exercise 0 Creating Inheritance relationship:
1. Create a class shape with functions and member as shown in figure
2. Create classes circle square and rectangle as sub classes of class shape
3. Each sub class of shape should override a calculate area of class shape according the
given formula in figure.
4. Your classes should have overloaded constructors that will take the member variables as
input.

Exercise 1 Test Case:

Exercise 2 Virtual functions:
What if we wanted to use the definition of the derived class function?
To accomplish this, we can add the keyword virtual to the declaration of the area() method in
the shape class.
Specifying a function as virtual makes sure that whenever we use a base class pointer/ref
pointing to an object of a derived class to call a function, the definition of the method declared in
the derived class is used.
Modify the area method of the shape class as shown below, compile your code, and execute it
virtual float area()

Exercise 3a Use of Polymorphism, parent pointer as function parameter:
In the above exercises, we have seen a very simple implementation of Polymorphism. The real
power of this feature is realized when we have a collection of objects of multiple derived classes
and we use a pointer of the base class to call their respective overloaded methods. Or you can
pass derived class object to a function with formal parameter of base class type.
Create a function sumArea that takes two shapes of any type and return the sum of their area
(shape/rectangle/circle etc...). Note that sumArea is a nonmember function, you can declare is
above your main function. Prototype of function is given.

Exercise 3b Use of polymorphism, keeping sibling types in same array:
Another advantage of polymorphism is to keep the object of different sub types of same parent
class in one array. The array will be on parent class pointer type.
As an exercise create take 5 shapes as input from user. Store these in one array.
In one loop print the area of these shapes.
Use following pseudo code to take input from user (although a better way will be to overload
extraction operator)

Exercise 4 Virtual Destructors:
*/

#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class Shape {
public:
	string colour;
	Shape()
	{
		colour = "";
	}
	Shape(string color)
	{
		colour = color;
	}
	virtual float area() {
		return 0.0;
	}
	~Shape()
	{
		cout << "~Shape() called. " << endl;
	}
};
class rectangle : public Shape {
	float height;
	float width;
public:
	rectangle()
	{
		height = 0;
		width = 0;
	}
	rectangle(float h, float w, string color) :Shape(color)
	{
		height = h;
		width = w;
	}
	float area() {
		return height * width;
	}
	~rectangle()
	{
		cout << "~Rectangle called." << endl << endl;
	}
};
class triangle : public Shape {
	float height;
	float base;
public:
	triangle()
	{
		height = 0;
		base = 0;
	}
	triangle(float h, float b, string color) : Shape(color)
	{
		height = h;
		base = b;
	}
	float area() {
		return ((0.5) * (base * height));
	}
	~triangle()
	{
		cout << "~Triangle() called," << endl << endl;
	}
};
class circle : public Shape {
	float radius;
public:
	circle()
	{
		radius = 0;
	}
	circle(float r, string color) :Shape(color)
	{
		radius = r;
	}
	float area() {
		return 3.1416 * (radius * radius);
	}
	~circle()
	{
		cout << "~circle() called.";
	}
};
int sumArea(Shape& Shape1, Shape& Shape2)
{
	return Shape1.area() + Shape2.area();
}
void task1()
{
	cout << "EXERCISE 0,1,2" << endl << endl;
	triangle t1(1.0, 9.0, "Red");
	circle c1(2, "Blue");
	rectangle r1(6, 2, "Orange");
	cout << t1.area() << endl;
	cout << t1.colour << endl;
	cout << c1.area() << endl;
	cout << r1.area() << endl;

	Shape* sptr = &t1;
	Shape& sref = r1;
	cout << sptr->area() << endl;
	cout << sptr->colour << endl;
	cout << sref.colour << endl;
	cout << sref.area() << endl;
}
void task3a()
{
	triangle t1(1.0, 9.0, "Red");
	circle c1(2, "Blue");
	rectangle r1(6, 2, "Orange");
	Shape s1("Purple");
	cout << sumArea(t1, c1) << endl;
	cout << sumArea(s1, r1) << endl;
	cout << sumArea(s1, t1) << endl;
}
void task3b()
{
	//Exercise 3b
	const int count = 2;
	Shape** shapesArray = new Shape * [count];
	for (int i = 0; i < count; )
	{
		cout << "Press 1 for a triangle, 2 for rectangle, 3 for circle " << endl;
		switch (_getch())
		{
		case '1':
		{
			float base, height;
			string color;
			cout << "Enter the base of triangle: ";
			cin >> base;
			cout << "Enter the height of triangle: ";
			cin >> height;
			cout << "Enter the color of triangle: ";
			cin >> color;
			shapesArray[i] = new triangle(height, base, color);
			i++;
			break;
		}
		case '2':
		{
			float width, height;
			string color;
			cout << "Enter the width of rectangle: ";
			cin >> width;
			cout << "Enter the height of rectangle: ";
			cin >> height;
			cout << "Enter the color of rectangle: ";
			cin >> color;
			shapesArray[i] = new rectangle(height, width, color);
			i++;
			break;
		}
		case '3':
		{
			float radius;
			string color;
			cout << "Enter the radius of circle: ";
			cin >> radius;
			cout << "Enter the color of circle: ";
			cin >> color;
			shapesArray[i] = new circle(radius, color);
			i++;
			break;
		}
		default:
		{
			cout << "Invalid Input : Enter again " << endl << endl;
			break;
		}
		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << "The area of shape " << i + 1 << " = " << shapesArray[i]->area() << endl;
	}
	delete[] shapesArray;
}
void task4()
{
	Shape* s1 = new triangle(1.0, 9.0, "Red");
	delete s1;
}
int main()
{
	int choice;
	cout << "Enter 1 for task '0,1,2' , Enter 2 for task 3a, Enter 3 for task 3b & Enter 4 for task 4 : ";
	cin >> choice;
	if (choice == 1)
		task1();
	if (choice == 2)
		task3a();
	if (choice == 3)
		task3b();
	if (choice == 4)
		task4();

	return 0;
}