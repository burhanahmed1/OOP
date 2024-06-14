#include<iostream>
using namespace std;

class Image
{
    int rows, cols;
    int** img;

public:
    Image()
    {
        rows = 0;
        cols = 0;
        img = nullptr;
    }

    Image(int rows, int cols, int** img_ptr)
    {
        this->rows = rows;
        this->cols = cols;

        // Dynamically allocate memory for the img matrix
        img = new int* [rows];
        for (int i = 0; i < rows; ++i)
        {
            img[i] = new int[cols];
            // Copy the values from img_ptr to img
            for (int j = 0; j < cols; ++j)
            {
                img[i][j] = img_ptr[i][j];
            }
        }
    }

    ~Image()
    {
        // Deallocate memory for the img matrix
        for (int i = 0; i < rows; ++i)
        {
            delete[] img[i];
        }
        delete[] img;
    }

    int** Filtering(int** filter, int stride)
    {
        int filterSize = 3; // Assuming filter size is 3x3

        int** filteredImg = new int* [rows];
        for (int i = 0; i < rows; ++i)
        {
            filteredImg[i] = new int[cols];
            for (int j = 0; j < cols; ++j)
            {
                int sum = 0;
                int divisor = 0;

                for (int m = -filterSize / 2; m <= filterSize / 2; ++m)
                {
                    for (int n = -filterSize / 2; n <= filterSize / 2; ++n)
                    {
                        int rowIndex = i + (m * stride);
                        int colIndex = j + (n * stride);

                        if (rowIndex >= 0 && rowIndex < rows && colIndex >= 0 && colIndex < cols)
                        {
                            sum += img[rowIndex][colIndex] * filter[m + filterSize / 2][n + filterSize / 2];
                            divisor += filter[m + filterSize / 2][n + filterSize / 2];
                        }
                    }
                }

                filteredImg[i][j] = sum / divisor;
            }
        }

        return filteredImg;
    }

};

int main()
{
    // Create an example image
    int rows = 5;
    int cols = 5;
    int** img = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        img[i] = new int[cols];
        for (int j = 0; j < cols; ++j)
        {
            img[i][j] = i * cols + j + 1;
        }
    }

    // Create an Image object using the parameterized constructor
    Image myImage(rows, cols, img);

    // Define the filter
    int** filter = new int* [3];
    for (int i = 0; i < 3; ++i)
    {
        filter[i] = new int[3];
        for (int j = 0; j < 3; ++j)
        {
            filter[i][j] = 1;
        }
    }

    // Apply filtering
    int** filteredImg = myImage.Filtering(filter, 1);

    // Display the filtered image
    cout << "Filtered Image:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << filteredImg[i][j] << " ";
        }
        cout << endl;
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < rows; ++i)
    {
        delete[] img[i];
        delete[] filteredImg[i];
    }
    delete[] img;
    delete[] filteredImg;

    // Clean up filter memory
    for (int i = 0; i < 3; ++i)
    {
        delete[] filter[i];
    }
    delete[] filter;

    system("pause>nul");
    return 0;
}
