# OOP with C++

# Task1 : 
Write the following code and observe the output.

# Task2 : 
Given two integers x and y, find and print their sum using pointers.

# Task3 : 
Write a C++ program that creates a pointer to an integer and print the following: Square of the integer, cube of the integer, half of the integer.

# Task4 : 
Write a C++ program that finds and prints the median of following three integers using their pointers.

# Task5 : 
A C++ program where you create an integer array of size 10. Your program will add 3 to each element of the array.You have to add to the elements using pointer only.Array subscript notation cannot be used(neither in addition nor while printing resultant array).

# Task6 : 
Write a program that keeps taking integer input from the user until user enters -1 and displays the data in reverse order.

# Task7 :
  Q # 1:-
  
  Take two arrays of integers A and B of sizes M and N respectively (M and N taken from User).Then you need to mix these arrays into a third array named C such that the followingsequence is followed.
  All even numbers of A from left to right are copied into C from left to right.
  All odd numbers of A from left to right are copied into C from right to left.
  All even numbers of B from left to right are copied into C from left to right.
  All old numbers of B from left to right are copied into C from right to left.
  
  Q # 2:-
  
  Write a program that keeps taking integer input from the user until user enters - 1 and displays
  the data in reverse order.
  Your program should save the input in a dynamically allocated array.Initially create a dynamic array of five integers.Each time the array gets filled your program should  double the size of array(i.e., create a new   
  array of double size, copy previous data in new array, delete previous array) and continue taking the input.After receiving - 1 (i.e., end of data input) your program should print the numbers in the reverse order as 
  entered by the user.
  
  Q # 3:-
  
  Take size input from the user and create an array of that size.Now populate the array as well
  by taking input from the user.
  • First Implement void copyArray(int* arr, int*& amp; arr1, int size) that copies arr into arr1.
  • Now implement another function int reduceArray(int* arr, int*& amp; arr1, int size) that
    asks user to enter size to reduce the array.To reduce the array remove the elements of the arr
    from the start and copy remaining into arr1.Use copyArray function to copy.

# Task8 :
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

# Task9 :
Exercise 0 :Creating Inheritance relationship:

1. Create a class shape with functions and member as shown in figure.
2. Create classes circle square and rectangle as sub classes of class shape
3. Each sub class of shape should override a calculate area of class shape according the
given formula in figure.
4. Your classes should have overloaded constructors that will take the member variables as
input.

Exercise 1 Test Case:

Exercise 2 Virtual functions:

Exercise 3a Use of Polymorphism, parent pointer as function parameter:Create a function sumArea that takes two shapes of any type and return the sum of their area
(shape/rectangle/circle etc...). Note that sumArea is a nonmember function, you can declare is
above your main function.

Exercise 3b Use of polymorphism, keeping sibling types in same array:As an exercise create take 5 shapes as input from user. Store these in one array.
In one loop print the area of these shapes.

Exercise 4 Virtual Destructors:

# Task10 :
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



# Task11 :
Exercise 0: Template Practice

Exercise 1: Template Functions: 
Write Template function for performing arithmetic operation of type int, float, double, long.

Exercise 2: Template Function and Overloading :
1. Write two function templates GetMax and GetMin that take two arguments and return the
maximum and minimum of the two respectively.
2. Then paste the following code in your source file and run the program. The program should
run peacefully.
3. Now remove the <int> and <long> from the code above and execute again. Does the
program still work?
4. Now replace the main function above with the main given below. You will need to change
the code (declaration and definition) for GetMin and GetMax so that the following code
works without an error.
5. Now remove the <int,long> and <int,char> from this new main and re-run the program, is
there any trouble with this version?
6. Now overload these template functions so that the maximum and minimum of 3 numbers
could be found.

Exercise 3: Template Specialization: 
If we want to define a different implementation for a template when a specific type is passed as
template parameter, we can declare a specialization of that template.
Consider a template function increment, that receives a variable (it can be int, double, float etc)
and increase the value of that variable by 1.
Now Write a template specialization for char * variables (character arrays) that convert all letters
of character arrays to upper case.
Hint:
Lowercase characters ASCII range from 97 to 122. If the character is found to be in this range then
the program converts that character into an uppercase character. ASCII of ‘A’ and ‘a’ differs by
32.


# Task12 :
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
1. Declare and define a class Set representing a set of integers. A set is a collection of data
without repetition or ordering. The class should have only private data members: a
pointer to a dynamically allocated array of integers and an integer that holds the size of
the set. The following shows the operators to be defined for a set.
Member Functions:
2. A constructor to create an empty set.
3. A destructor.
4. A function to add element to the set. (A set has no duplicate elements, so
design add function accordingly. Also make sure set remain in ascending
order and newly added elements are inserted in their correct positions)
5. A binary friend function to get the union of two sets (overload the + operator).
6. A binary friend function to determine the difference of two sets (overload the – operator)

# Task13 :
Exercise 1:
Consider the following hierarchy as it exists in a university:
1. There are two types of persons in the university i.e. Student and Faculty
2. Every Person has some basic information that is common to all persons i.e. the first_name and
last_name stored as private attributes and age which is a protected attribute.
3. A student can in turn be either an Undergraduate or a Graduate student, every student has a cgpa.
4. An undergraduate student has a fyp_name as his private attribute.
5. A graduate student has a thesis topic as his private attribute.
6. A faculty member has private attributes about the number of courses he is currently teaching, i.e.
his course_count and a three digit telephone extension number.
Draw Class Diagram (on paper) to represent the hierarchy of classes that you see in the description
above. Include all the attributes in your diagram.

Exercise 2:
Implement the entire hierarchy of the Class diagram you created in Exercise 1 i.e. define all the classes
along with their attributes and their inheritance. Every class should be defined in a separate header file
named according to the class name.

Exercise 3:
Add appropriate constructors and destructors to all the classes created in Exercise 2. For example the
constructor for the Person class should take three inputs (for first_name, last_name and age). The
student constructor should take four inputs, three for its parent class (i.e. Person) and one float value to
be assigned to the cgpa attribute.

Exercise 4:
In .h files and .cpp file, add getters and setters function headings and implementation (resp) for all
attributes in all the classes that you have defined.

Exercise 5:
Create a C++ source file called Lab_Inheritance.cpp. This file contains the main() function. In this
main function create an undergraduate student “Ted Thompson” with cgpa 3.91 who is 22 years of age
and a faculty member “Richard Karp” who is 45 years of age and who is teaching 2 courses this semester
and his extension number is 420. Build and execute the code, copy the output and paste inside 
comments  in your Lab_Inheritance.cpp file.

Exercise 6:
You should notice that the age attribute in a Person is protected, while the first_name and
last_name attributes are private. What could be the reason for this?

Exercise 7: Overriding parent functions: 
Add a member function void print() in the Person class. This method should print the name and age
of the person.

# Task14 :
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

# Task15 :
1. For simplicity, create a single .cpp file with the following classes: Faculty, Administrator,
Teacher, & AdministratorTeacher.
2. Faculty inherits Administrator and Teacher. While AdministratorTeacher has two
parents Administrator and Teacher which represents that an Administrator can be a
Teacher and vice versa
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
14. Each faculty member is assigned an id by the university. To represent this, add an get_id()
method to both Administrator and Teacher which returns a unique integer number.
15. Call the get_id() method using the AdministratorTeacher object. Observe the error. Can
you explain why?
16. One approach would be to qualify the get_id() method as we did with print(). But if we are
making use of inheritance, there should only be one get_id() method in the Faculty class.
Remove the get_id() method from the child classes. Execute the program and observe that it
works. Can you explain why is there no ambiguity when calling the get_id() method from
AdministratorTeacher object?

Abstract Classes & Pure Virtual Functions: 

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
1. Follow all the code indentation, naming conventions and code commenting guidelines.
2. Make sure your program is executable.

# Task16 : 
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
1. What is the output if the input is 25 5.50?
2. What is the output if the input is -55 2.8?
3. What is the output if the input is 37 -4.5?
4. What is the output if the input is -10 -2.5?

Exercise 5: Exception Handling Problem
Write a program that prompts the user to enter a person’s date of birth in numeric form such as 8-27-
1980. The program then outputs the date of birth in the form: August 27, 1980. Your program must
contain three exception classes: invalidDay, invalidMonth, and invalidYear. If the user enters an
invalid value for day, then the program should throw and catch an invalidDay object. Follow similar
convention for the invalid values of month. Handle leap year value with invalidYear exception.

# Task17 :
In this assignment we are going to extend C++ by implementing a new way of creating arrays in C++.
This array like structure will be elastic in the sense that the programmer using it will be able to change
the size and dimensions of the array during program execution. Initially support will be provided for
up to 3 dimensions and hence programmer will be allowed to use an array either as a 1D, 2D or 3D
array as per need.

Programmer using these arrays will be allowed to use both non-negative and negative indices to access
the data stored in these arrays and the arrays will be safe in the sense that the programmer will be
unable to access an index that is not part of the array or in other words each integer will be mapped to
a valid index in the array.

To implement this notion we will need to keep a record of number of dimensions and size of each
dimension of the array along with the memory area reserved to store the array data. As discussed in
class, for this assignment we will keep this information in a structure/record defined using the struct
defining facility available in the language.

A proposed struct definition and some basic functions have been defined for your convenience and
your main responsibility is to complete this definition and provide definition of all necessary functions
needed to implement the notion of SAFE ELASTIC ARRAYS.


# Task18 :


# Task19 :

