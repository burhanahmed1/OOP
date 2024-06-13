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


# Task12 :


# Task13 :


# Task14 :


# Task15 :


# Task16 :




