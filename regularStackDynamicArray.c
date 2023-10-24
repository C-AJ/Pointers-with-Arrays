#include <stdlib.h> 
#include <stdio.h>
#include <conio.h>  
#include <time.h>

#define MAX 100

void matrixAddition(int m, int n, float arr1[MAX][MAX], float arr2[MAX][MAX])
{
    float arrSum[MAX][MAX];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arrSum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%f", arrSum[i][j]);
            printf(" ");
        }
        printf("\r\n");
    }
}

void matrixSubtraction(int m, int n, float arr1[MAX][MAX], float arr2[MAX][MAX])
{
    float arrSub[MAX][MAX];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arrSub[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%f", arrSub[i][j]);
            printf(" ");
        }
        printf("\r\n");
    }
}

void matrixMultiplication(int m, int n, int b, float arr1[MAX][MAX], float arr2[MAX][MAX])
{
    //Start the clock
    clock_t start, end;
    double time_elasped;
    start = clock();

    float arrMult[MAX][MAX];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < b; j++)
        {
            arrMult[i][j] = 0;
            for(int k = 0; k < n; k++)
            {
                arrMult[i][j] += arr1[i][k] * arr2[k][j]; 
            }
        }
    }
    end = clock();
    time_elasped = (((double) (end - start)) / (CLOCKS_PER_SEC)) * 1000000;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < b; j++)
        {
            printf("%f", arrMult[i][j]);
            printf(" ");
        }
        printf("\r\n");
    }
    printf("Amount of time taken: ");
    printf("%lf", time_elasped);
    printf(" microseconds \r\n");
}

int main(void) {
    // Initialize 2 arrays
    int m, n, a, b, c;
    int userInput = 1;
    float arr1[MAX][MAX];
    float arr2[MAX][MAX];
    float userNumber;

    //Get user input for dimensions
    printf("Type dimensions for first 2-D array, max 100: ");

    scanf("%d", &m);
    scanf("%d", &n);
    printf("\r\n");

    printf("Type dimensions for second 2-D array, max 100: ");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("\r\n");

    printf("Would you like to: \r\n");
    printf("1. Manually input floats \r\n");
    printf("2. Automatically generate floats \r\n");
    scanf("%d", &userInput);

    if (userInput == 1)
    {
        printf("Enter floats for first matrix: \r\n");
        for (int i = 0; i < m; i++)
        {
            printf("Enter row: ");
            for (int j = 0; j < n; j++)
            {
                scanf("%f", &userNumber);
                arr1[i][j] = userNumber;
            }
        }
        printf("Enter floats for second matrix: \r\n");
        for (int i = 0; i < a; i++)
        {
            printf("Enter row: ");
            for (int j = 0; j < b; j++)
            {
                scanf("%f", &userNumber);
                arr2[i][j] = userNumber;
            }
        }
    }
    else
    {
        //Randomize numbers in arrays
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr1[i][j] = ((float)rand()/(float)(RAND_MAX)) * 1000.0;
            }
        }

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                arr2[i][j] = ((float)rand()/(float)(RAND_MAX)) * 1000.0;
            }
        }
    }

    //Creates loop for user to choose operation
    while(userInput != 5)
    {
        printf("Choose an operation: \r\n");
        printf("1. Addition \r\n");
        printf("2. Subtraction \r\n");
        printf("3. Multiplication \r\n");
        printf("4. Create new matrices\r\n");
        printf("5. Quit the program \r\n");
        scanf("%d", &userInput);

        //Does function based on user input
        switch(userInput)
        {
            case 1:
                if (m != a || n != b) 
                {
                    printf("Unable to do operation due to mismatching dimensions. \r\n");
                }
                else
                {
                    matrixAddition(m, n, arr1, arr2);
                }
                break;
            case 2:
                if (m != a || n != b) 
                {
                    printf("Unable to do operation due to mismatching dimensions. \r\n");
                }
                else
                {
                    matrixSubtraction(m, n, arr1, arr2);
                }
                break;
            case 3:
                if (m != b) 
                {
                    printf("Unable to do operation due to mismatching dimensions. \r\n");
                }
                else
                {
                    matrixMultiplication(m, n, b, arr1, arr2);
                }
                break;
            case 4:
                printf("Type dimensions for first 2-D array, max 100: ");

                scanf("%d", &m);
                scanf("%d", &n);
                printf("\r\n");

                printf("Type dimensions for second 2-D array, max 100: ");
                scanf("%d", &a);
                scanf("%d", &b);
                printf("\r\n");

                printf("Would you like to: \r\n");
                printf("1. Manually input floats \r\n");
                printf("2. Automatically generate floats \r\n");
                scanf("%d", &userInput);

                if (userInput == 1)
                {
                    printf("Enter floats for first matrix: \r\n");
                    for (int i = 0; i < m; i++)
                    {
                        printf("Enter row: ");
                        for (int j = 0; j < n; j++)
                        {
                            scanf("%f", &userNumber);
                            arr1[i][j] = userNumber;
                        }
                    }
                    printf("Enter floats for second matrix: \r\n");
                    for (int i = 0; i < a; i++)
                    {
                        printf("Enter row: ");
                        for (int j = 0; j < b; j++)
                        {
                            scanf("%f", &userNumber);
                            arr2[i][j] = userNumber;
                        }
                    }
                }
                else
                {
                    //Randomize numbers in arrays
                    for (int i = 0; i < m; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            arr1[i][j] = ((float)rand()/(float)(RAND_MAX)) * 1000.0;
                        }
                    }

                    for (int i = 0; i < a; i++)
                    {
                        for (int j = 0; j < b; j++)
                        {
                            arr2[i][j] = ((float)rand()/(float)(RAND_MAX)) * 1000.0;
                        }
                    }
                }
                break;
        }
    }

    //Free Arrays from memory
    for (int i = 0; i < m; i++)
    {
        free(arr1[i]);
    }
    for (int i = 0; i < a; i++)
    {
        free(arr2[i]);
    }

    printf("Finished");
    return 0;
}
