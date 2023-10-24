#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

class matrix{
    private:
        float **arr;
    public:
        int m, n;

        matrix(int x, int y)
        {
            //Allocating variables
            m = x;
            n = y;

            //Creating new arrays
            arr = new float*[m];

            for (int i = 0; i < m; i++)
            {
                *(arr+i) = new float[n];
            }

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    *(*(arr+i)+j) = ((float)rand()/(float)(RAND_MAX)) * 1000.0;
                }
            }
        }

        matrix operator+(matrix matrix2)
        {
            matrix result(m,n);
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    *(*(result.arr+i)+j) = *(*(arr+i)+j) + *(*(matrix2.arr+i)+j);
                }
            }
            return result;
        }

        matrix operator-(matrix matrix2)
        {
            matrix result(m,n);
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    *(*(result.arr+i)+j) = *(*(arr+i)+j) - *(*(matrix2.arr+i)+j);
                }
            }
            
            return result;
        }

        matrix operator*(matrix matrix2)
        {
            matrix result(m, matrix2.n);
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < matrix2.n; j++)
                {
                    *(*(result.arr+i)+j) = 0.0;
                    for(int k = 0; k < n; k++)
                    {
                        *(*(result.arr+i)+j) += *(*(arr+i)+k) * *(*(matrix2.arr+k)+j); 
                    }
                }
            }
            return result;
        }

        //Function to create new matrix
        void createNewMatrix(int x, int y)
        {
            int userInput;
            float userNumber;

            // Must delete previous matrix
            for(int i = 0; i < m; i++)
            {
                delete[] *(arr+i);
            }
            delete[] arr;

            m = x;
            n = y;

            //Creates new array
            arr = new float*[m];
            for (int i = 0; i < m; i++)
            {
                *(arr+i) = new float[n];
            }

            cout << "Would you like to:" << endl;
            cout << "1. Manually input floats" << endl;
            cout << "2. Automatically generate floats" << endl;
            cin >> userInput;

            if (userInput == 1)
            {
                cout << "Enter floats for matrix: " << endl;
                for (int i = 0; i < m; i++)
                {
                    cout << "Enter row: ";
                    for (int j = 0; j < n; j++)
                    {
                        cin >> userNumber;
                        *(*(arr+i)+j) = userNumber;
                    }
                }
            }
            else
            {
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        *(*(arr+i)+j) = ((float)rand()/(float)(RAND_MAX)) * 1000.0;
                    }
                }
            }
        }

        void printMatrix()
        {
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    cout << *(*(arr+i)+j) << " ";
                }
                cout << endl;
            }
        }

        //Deletes dynamic arrays when finished
        void deleteMatrix()
        {
            for(int i = 0; i < m; i++)
            {
                delete[] *(arr+i);
            }
            delete[] arr;
        }
};

int main(){
    int m, n, a, b;
    int userInput = 0;
    cout << "Type dimensions for first 2-D array: ";
    cin >> m >> n;


    cout << "Type dimensions for second 2-D array: ";
    cin >> a >> b;

    matrix matrix1(m, n);
    matrix matrix2(a, b);
    matrix1.createNewMatrix(m, n);
    matrix2.createNewMatrix(m, n);
    
    while(userInput != 5)
    {
        cout << "Choose an operation:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Create new matrices" << endl;
        cout << "5. Quit the program" << endl;
        cin >> userInput;
        switch (userInput)
        {
            case 1:
                if (m != a || n != b) {cout << "Unable to do operation due to mismatching dimensions." << endl; }
                else
                {
                    matrix result(m, n);
                    result = matrix1 + matrix2;
                    result.printMatrix();
                    result.deleteMatrix();
                }
                break;
            case 2:
                if (m != a || n != b) {cout << "Unable to do operation due to mismatching dimensions." << endl; }
                else
                {
                    matrix result(m, n);
                    result = matrix1 - matrix2;
                    result.printMatrix();
                    result.deleteMatrix();
                }
                break;
            case 3:
                if (m != b) {cout << "Unable to do operation due to mismatching dimensions." << endl; }
                else
                {
                    matrix result(m, b);
                    // Start timer
                    auto start = high_resolution_clock::now();
                    result = matrix1 * matrix2;

                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    cout << "Amount of time taken: " << duration.count() << " microseconds" << endl;

                    result.printMatrix();
                    result.deleteMatrix();
                }
                break;
            case 4:
                cout << "Type dimensions for first 2-D array: ";
                cin >> m >> n;


                cout << "Type dimensions for second 2-D array: ";
                cin >> a >> b;
                matrix1.createNewMatrix(m, n);
                matrix2.createNewMatrix(a, b);
                break;
        }
    }
    matrix1.deleteMatrix();
    matrix2.deleteMatrix();
    return 0;
}