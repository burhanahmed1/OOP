/*
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
*/

#include <iostream>
using namespace std;

struct safeElasticArray
{
    unsigned int arrayCapicity;

    unsigned int arraySize;

    unsigned int dimensions[3];

    int* data;

    void computeArraySize()
    {
        arraySize = dimensions[0] * dimensions[1] * dimensions[2];
    }

    bool allocateMemory()
    {

        data = new int[arrayCapicity];
        for (unsigned int i = 0; i < arraySize; i++)
        {
            data[i] = 0;
        }
        return true;
    }

    void showArray(unsigned int D1 = 0, unsigned int D2 = 0, int D3 = 0)
    {
        int a = 0;
        if (D1 != 0 && D2 == 0 && D3 == 0)
        {
            for (unsigned int i = 0; i < arraySize; i++)
                cout << data[i] << "  ";
        }
        if (D2 != 0 && D1 != 0 && D3 == 0)
        {
            for (unsigned int i = 0; i < D1; i++)
            {
                for (unsigned int j = 0; j < D2; j++)
                {
                    cout << data[i * 2 + j] << " ";
                }
                cout << endl;
            }
        }
        if (D2 != 0 && D1 != 0 && D3 != 0)
        {
            for (int i = 0; i < D3; i++)
            {
                for (int j = 0; j < D1; j++)
                {
                    for (int k = 0; k < D2; k++)
                    {
                        cout << data[a] << " ";
                        a++;
                    }
                    cout << endl;
                }
                cout << endl;
            }

        }

    }

    void initArray(unsigned int D1 = 10, unsigned int D2 = 0, int D3 = 0)
    {
        if (D1 == 0)
            D1 = 10;
        dimensions[0] = D1;

        if (D2 == 0) {
            D2 = 1;
            D3 = 1;
        }
        dimensions[1] = D2;

        if (D3 == 0)
            D3 = 1;
        dimensions[2] = D3;

        computeArraySize();

        allocateMemory();
    }

    bool expandArray(unsigned int thisMuch, bool Erase = false)
    {

        if (thisMuch < 0)
        {
            return false;
        }
        else
        {
            int* exarr = nullptr;
            exarr = new int[thisMuch];
            for (int i = 0; i < arraySize; i++)
            {
                exarr[i] = data[i];
            }
            for (int i = 0; i < thisMuch - arraySize; i++)
            {
                exarr[arraySize + i] = 0;
            }
            delete[]data;
            data = exarr;
        }

        return true;
    }

    bool shrinkArray(unsigned int thisMuch, bool Erase = false)
    {

        if (thisMuch < 0)
            return false;
        else
        {
            int* sharr = nullptr;
            sharr = new int[thisMuch];
            for (int i = 0; i < thisMuch; i++)
            {
                sharr[i] = data[i];
            }
            delete[]data;
            data = sharr;
        }
        return true;
    }

    void fillArray()
    {
        for (unsigned int i = 0; i < arraySize; i++)
        {
            cout << "Data " << i << " : ";
            cin >> data[i];
        }
    }

    int safaeAccess(int index)
    {

        if (index >= arraySize)
            return -1;
        else
        {
            index %= arraySize;
            return data[index];
        }
    }

    int safaeAccess(int indexR, int indexC)
    {

        int a = 0, b = 0;
        for (int i = 0; i <= indexR; i++)
        {
            for (int j = 0; j <= indexC; j++)
            {
                a = data[b];
                b++;
            }
        }
        return a;
    }

    int safaeAccess(int indexP, int indexR, int indexC)
    {

        int a = 0, b = 0;
        for (int i = 0; i <= indexP; i++)
        {
            for (int j = 0; j <= indexR; j++)
            {
                for (int k = 0; k <= indexC; k++)
                {
                    a = data[b];
                    b++;
                }
            }
        }
        return a;
    }

    bool resizeArray(double fraction)
    {


        if (arraySize * fraction <= arrayCapicity)
        {
            arraySize *= fraction;
            return true;
        }
        else
            return false;
    }

    void clearArray()
    {
        for (int i = 0; i < arraySize; i++)
        {
            data[i] = 0;
        }
    }

    void deleteArray()
    {
        delete[]data;
    }

    int popBack()
    {

        int poarr;
        poarr = data[arraySize - 1];
        arraySize = arraySize - 1;
        return poarr;
    }

    bool pushBack(int Value)
    {

        if ((arraySize + 1) <= arrayCapicity)
        {
            data[arraySize + 1] = Value;
            return true;
        }
        else
            return false;

    }

    bool reshape(int D1, int D2 = 0, int D3 = 0)
    {

        showArray(D1, D2, D3);

        return true;
    }
};

int main()
{
    safeElasticArray Array;

    cout << "Define the capacity of array : ";
    cin >> Array.arrayCapicity;

    Array.initArray();
    Array.showArray();

    cout << "Please press '1' for 1D array, '2' for 2D array, '3' for 3D array : ";
    int d;
    cin >> d;

    if (d == 1)
    {
        cout << "Define the size of array: ";
        int size;
        cin >> size;
        Array.initArray(size);
        Array.fillArray();
        Array.showArray(size);

    }

    if (d == 2)
    {
        int row, col;
        cout << "Define the no. of rows : ";
        cin >> row;
        cout << "Define the no. of columns : ";
        cin >> col;
        Array.initArray(row, col);
        Array.fillArray();
        Array.showArray(row, col);

    }

    if (d == 3)
    {
        int row, col, page;
        cout << "Define the no. of pages : ";
        cin >> page;
        cout << "Define the no. of rows : ";
        cin >> row;
        cout << "Define the no. of columns : ";
        cin >> col;
        Array.initArray(row, col, page);
        Array.fillArray();
        Array.showArray(row, col, page);

    }

    int ch;
    cout << endl << "If you want to expand the array plz press 1 (0 for No) : ";
    cin >> ch;
    if (ch)
    {
        cout << "Enter the number by which you want to expand :";
        int expand;
        cin >> expand;
        bool exp;
        if (expand < 0)
            exp = false;
        else
            exp = true;
        if (!Array.expandArray(expand, exp))
            cout << "Try Again" << endl;
        else
            cout << "Done" << endl;
    }

    cout << "If you want to shrink the array plz press 1 (0 for No) : ";
    cin >> ch;
    if (ch)
    {
        cout << "Enter the number by which you want to shrink :";
        int shrink;
        cin >> shrink;
        bool shr;
        if (shrink < 0)
            shr = false;
        else
            shr = true;
        if (!Array.shrinkArray(shrink, shr))
            cout << "Try Again" << endl;
        else
            cout << "Done" << endl;
    }

    int check;
    cout << "To access any element plz press 1 (0 for no ) : ";
    cin >> check;
    if (check)
    {
        if (d == 1)
        {
            cout << "Define the index : ";
            int n;
            cin >> n;
            cout << Array.safaeAccess(n) << endl;
        }
        if (d == 2)
        {
            int row, col;
            cout << "Define the no. of rows : ";
            cin >> row;
            cout << "Define the no. of columns : ";
            cin >> col;
            cout << Array.safaeAccess(row, col) << endl;
        }
        if (d == 3)
        {
            int row, col, page;
            cout << "Define the no. of pages : ";
            cin >> page;
            cout << "Define the no. of rows : ";
            cin >> row;
            cout << "Define the no. of columns : ";
            cin >> col;
            cout << Array.safaeAccess(page, row, col) << endl;
        }
    }

    cout << "To resize array plz press 1( 0 for no ) : ";
    cin >> check;
    if (check)
    {
        cout << "Enter the number : ";
        double fraction;
        cin >> fraction;
        if (!Array.resizeArray(fraction))
        {
            cout << "Try Again " << endl;
        }
    }

    cout << "To clear array plz press 1(0 for no ) : ";
    cin >> check;
    if (check)
        Array.clearArray();

    cout << "To delete array plz press 1( 0 for no ) : ";
    cin >> check;
    if (check)
        Array.deleteArray();

    cout << "To pushback array plz press 1( 0 for no ) : ";
    cin >> check;
    if (check)
    {
        cout << "enter number : ";
        int value;
        cin >> value;
        if (!Array.pushBack(value))
            cout << "Try Again ";
        else
            cout << "Successful" << endl;

    }

    cout << "To popback array plz press 1( 0 for no ) : ";
    cin >> check;
    if (check)
        cout << Array.popBack() << endl;

    cout << "To reshape array plz press 1(0 for no ) : ";
    cin >> check;
    if (check)
    {
        cout << "Please press '1' for 1D array, '2' for 2D array, '3' for 3D array : ";
        cin >> d;
        if (d == 1)
        {
            cout << "Define the size of array : ";
            int size;
            cin >> size;
            Array.reshape(size);
        }

        if (d == 2)
        {
            int row, col;
            cout << "Define the no. of rows: ";
            cin >> row;
            cout << "Define the no. of columns: ";
            cin >> col;
            Array.reshape(row, col);

        }

        if (d == 3)
        {
            int row, col, page;
            cout << "Define the no. of pages: ";
            cin >> page;
            cout << "Define the no. of rows: ";
            cin >> row;
            cout << "Define the no. of columns: ";
            cin >> col;
            Array.reshape(row, col, page);

        }

    }

    system("pause>nul");
    return 0;
}