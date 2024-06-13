/*
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

Exercise 7: Overriding parent functions
Add a member function void print() in the Person class. This method should print the name and age
of the person.
*/

#include <iostream>
#include <string>
using namespace std;

class person {
    string first_name;
    string last_name;
protected:
    int age;
public:
    person(string first_name, string last_name, int age)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->age = age;
        cout << "Person constructor called." << endl;
    }
    ~person()
    {
        cout << "Person destructor called." << endl;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void setFirstName(string first_name)
    {
        this->first_name = first_name;
    }
    void setLastName(string last_name)
    {
        this->last_name = last_name;
    }
    int getAge() const
    {
        return age;
    }
    string getFirstName() const
    {
        return first_name;
    }
    string getLastName() const
    {
        return last_name;
    }

    virtual void print() const
    {
        cout << "The age of "<<first_name<<" "<<last_name<<" is "<<age<<"." << endl;
    }
};

class student : public person {
protected:
    float cgpa;

public:
    student(string first_name, string last_name, int age, float cgpa)
        : person(first_name, last_name, age), cgpa(cgpa)
    {
        cout << "Student constructor called." << endl;
    }

    ~student()
    {
        cout << "Student destructor called." << endl;
    }

    void setCGPA(float cgpa)
    {
        this->cgpa = cgpa;
    }

    float getCGPA()
    {
        return cgpa;
    }

    virtual void print() const override
    {
        person::print();
        cout << "The CGPA is : " << cgpa << endl;
    }
};

class graduate : public student {
private:
    string thesis_topic;

public:
    graduate(string first_name, string last_name, int age, float cgpa, string thesis_topic)
        : student(first_name, last_name, age, cgpa), thesis_topic(thesis_topic)
    {
        cout << "Graduate constructor called." << endl;
    }

    ~graduate()
    {
        cout << "Graduate destructor called." << endl;
    }

    void setThesisTopic(string thesis_topic)
    {
        this->thesis_topic = thesis_topic;
    }

    string getThesisTopic() const
    {
        return thesis_topic;
    }

    virtual void print() const override
    {
        student::print();
        cout << "Graduate student, Thesis Topic: " << thesis_topic << endl;
    }
};

class undergraduate : public student {
private:
    string fyp_name;

public:
    undergraduate(string first_name, string last_name, int age, float cgpa, string fyp_name)
        : student(first_name, last_name, age, cgpa), fyp_name(fyp_name)
    {
        cout << "Undergraduate constructor called." << endl;
    }

    ~undergraduate()
    {
        cout << "Undergraduate destructor called." << endl;
    }

    void setFYPName(string fyp_name)
    {
        this->fyp_name = fyp_name;
    }

    string getFYPName() const
    {
        return fyp_name;
    }

    virtual void print() const override
    {
        student::print();
        cout << "Undergraduate student, FYP Title : " << fyp_name << endl;
    }
};

class faculty : public person {
private:
    int course_count;
    int extension_number;
public:
    faculty(string first_name,string last_name, int age, int course_count, int extension_number) :
        person(first_name, last_name, age), course_count(course_count), extension_number(extension_number) {
        cout << "Faculty constructor called" << endl;
    }
    ~faculty() {
        cout << "Faculty destructor called" << endl;
    }
    
    void set_course_count(int count) {
        course_count = count;
    }
    void set_extension_number(int ext) {
        extension_number = ext;
    }
    int get_course_count() const {
        return course_count;
    }
    int get_extension_number() const {
        return extension_number;
    }

    void print() const {
        cout << "Faculty member name: " << getFirstName() << " " << getLastName()<< ", Age: " << getAge() << ", Number of courses: " << course_count<< ", Ext. " << extension_number <<endl;
    }
};

int main() {
    student s("Ted", "Thompson", 22, 3.91);
    faculty f("Richard", "Karp", 45, 2, 420);

    undergraduate u("Ted", "Thompson", 22, 3.91, "The Event Locator");
    graduate g("Arnold", "Gates", 25, 3.01, "Distributed Algorithms");
    s.print();
    f.print();
    u.print();
    g.print();

    system("pause");
    return 0;
}