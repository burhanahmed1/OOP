/*
Task1:
1- Create a class named Rectangle.
2- Define its private variables length, width, variable area.
3- Create a default constructor to initialize these variables.
4- Create a parametrized constructor.
5- Create these functions:
    a. Define set functions for length and width. These should check that the values
      are greater than zero, else this function should print “length should be greater
      than zero” “width should be greater than zero”. Name of functions should be
      like “set_length()”
    b. Define calculate area function, it should set the area =length*width.
	c. Define a get functions for all 3 member variables. Function names should like
	  “get_length()”
	d. Define a function set_values() that takes both length and width as input and
	  sets those values and also sets the area.
	e. Create a function is_square() it should return True if length=width of rectangle
	  else false.
	f. Define a function to display() rectangle. It should print a rectangle using 0, for
      example if length =3 and width = 9, display should print

	000000000
	000000000
	000000000

Task2:
1- Create a class named Cuboid.
2- Define its private variables length, width, height,
3- Create a default parametrized constructor to initialize these variables.
4- Create a copy constructor.
5- Inside this class make these functions:
	a. Define set functions of length width and height. These values cannot be &lt;=0
	b. Define get functions for all the member variables.
	c. Define a function to calculate the area of cube.
	d. Define a function to calculate volume of cube. This should calculate and
	   return volume= W*H*L
	e. Define a display function to display length, width, height and volume.
	f. Define a function is_cube() which will return true if W=L=H else return false.

Task3:

*/

#include<iostream>
using namespace std;

//task1
class Rectangle
{
private:
	int length;
	int width;
	int area;
public:
	Rectangle()
	{
		this->length = 4;
		this->width = 6;
		cout << "\nDefault Constructor Called." << endl;
	}
	Rectangle(int l, int w)
	{
		this->length = l;
		this->width = w;
		cout << "Parameterized Constructor Called." << endl;
	}
	void set_length()
	{
		if (length <= 0)
		{
			cout << "Length should be greater than zero." << endl;
			length = 1;
		}
	}
	void set_width()
	{
		if (width <= 0)
		{
			cout << "Width should be greater than zero." << endl;
			width = 1;
		}
	}
	int calculate_area()
	{
		this->area = length * width;
		return area;
	}
	void get_length()
	{
		cout << "\nEnter the length of rectangle : ";
		cin >> length;
	}
	void get_width()
	{
		cout << "Enter the width of rectangle : ";
		cin >> width;
	}
	void set_values(int l, int w)
	{
		this->length = l;
		this->width = w;
		calculate_area();
	}
	bool is_square()
	{
		if (length == width)
		{
			return true;
		}
		else
			return false;
	}
	void display()
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << "0";
			}
			cout << endl;
		}
		cout << endl;
	}
};

void task1()
{
	Rectangle R1;
	cout << "Area = " << R1.calculate_area() << endl;
	R1.display();

	Rectangle R2(0, -1);
	R2.set_length();
	R2.set_width();

	R1.get_length();
	R1.get_width();
	R1.set_length();
	R1.set_width();
	cout << "Area = " << R1.calculate_area() << endl;
	R1.display();

	int l, w;
	cout << "If you want to set the length and width of rectangle enter both values respectively : ";
	cin >> l >> w;
	R1.set_values(l, w);
	cout << "Area = " << R1.calculate_area() << endl;
	R1.display();

	bool check = R1.is_square();
	if (check == true)
		cout << "This is a square." << endl;
	else
		cout << "This is not a square." << endl;

}

//task2
class Cuboid
{
private:
	int length;
	int width;
	int height;
	int volume;
public:
	Cuboid()
	{
		this->length = 4;
		this->width = 5;
		this->height = 6;
		cout << "Default Constructor Called." << endl << endl;
	}
	Cuboid(int l, int w, int h)
	{
		this->length = l;
		this->width = w;
		this->height = h;
		cout << "Parameterized Constructor Called." << endl << endl;
	}
	void copy()
	{
		this->length = 4;
		this->width = 5;
		this->height = 6;
	}
	void set_length()
	{
		if (length <= 0)
		{
			cout << "Length should be greater than zero." << endl;
			length = 1;
		}
	}
	void set_width()
	{
		if (width <= 0)
		{
			cout << "Width should be greater than zero." << endl;
			width = 1;
		}
	}
	void set_height()
	{
		if (height <= 0)
		{
			cout << "Height should be greater than zero." << endl;
			height = 1;
		}
	}
	void get_length()
	{
		cout << "\nEnter the length of cuboid : ";
		cin >> length;
	}
	void get_width()
	{
		cout << "Enter the width of cuboid : ";
		cin >> width;
	}
	void get_height()
	{
		cout << "Enter the height of cuboid : ";
		cin >> height;
	}
	int calculate_volume()
	{
		this->volume = length * width * height;
		return volume;
	}
	void display()
	{
		cout << "\nThe length of cuboid is : " << length << endl;
		cout << "The width of cuboid is : " << width << endl;
		cout << "The height of cuboid is : " << height << endl;
		cout << "The volume of cuboid is : " << volume << endl << endl;
	}
	bool is_cube()
	{
		if (length == width == height)
		{
			return true;
		}
		else
			return false;
	}
};
void task2()
{
	Cuboid obj1;

	Cuboid obj2(0, -1, 0);
	obj2.set_length();
	obj2.set_width();
	obj2.set_height();
	obj2.copy();

	obj1.get_length();
	obj1.get_width();
	obj1.get_height();
	cout << "The volume of cuboid is : " << obj1.calculate_volume() << endl;

	obj1.display();

	bool check = obj1.is_cube();
	if (check == true)
		cout << "This is a cube." << endl;
	else
		cout << "This is not a cube." << endl;

}

int main()
{
	char repeat = 'y';
	do
	{
		int choice = 0;
		cout << "Enter 1 for task1, 2 for task2 : ";
		cin >> choice;
		if (choice == 1)
			task1();
		if (choice == 2)
			task2();
		cout << "To run the program again press('y' for yes and 'n' for  no) :";
		cin >> repeat;
		cout << endl;
	} while (repeat == 'y');

	system("pause>nul");
	return 0;
}