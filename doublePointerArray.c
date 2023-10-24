#include <stdlib.h> 
#include <stdio.h>
#include <conio.h>  
#include <time.h>

float** matrixAddition(int m, int n, float **arr1, float **arr2)
{
    //Initialize array
    float **arrSum;
    arrSum = (float*)malloc(n*sizeof(float));
    arrSum = (float**)malloc(m*sizeof(float*)); 
    for (int i = 0; i < m; i++)
    {
        *(arrSum+i) = (float*)malloc(n*sizeof(float)); 
    }

    //Do addition using pointers instead
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(*(arrSum+i)+j) = *(*(arr1+i)+j) + *(*(arr2+i)+j);
        }
    }
    //Print it out
    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%f", *(*(arrSum+i)+j));
            printf(" ");
        }
        printf("\r\n");
    }
    return arrSum;
}

float** matrixSubtraction(int m, int n, float **arr1, float **arr2)
{
    float **arrSub;
    arrSub = (float*)malloc(n*sizeof(float));
    arrSub = (float**)malloc(m*sizeof(float*)); 
    for (int i = 0; i < m; i++)
    {
        *(arrSub+i) = (float*)malloc(n*sizeof(float)); 
    }

    //Subtraction with pointers
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(*(arrSub+i)+j) = *(*(arr1+i)+j) - *(*(arr2+i)+j);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%f", *(*(arrSub+i)+j));
            printf(" ");
        }
        printf("\r\n");
    }

    return arrSub;
}

float** matrixMultiplication(int m, int n, int b, float **arr1, float **arr2)
{
    //Start the clock
    clock_t start, end;
    double time_elasped;
    start = clock();

    //Initialize array
    float **arrMult;
    arrMult = (float*)malloc(b*sizeof(float));
    arrMult = (float**)malloc(m*sizeof(float*)); 
    for (int i = 0; i < m; i++)
    {
        *(arrMult+i) = (float*)malloc(b*sizeof(float)); 
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < b; j++)
        {
            *(*(arrMult+i)+j) = 0.0;
            for(int k = 0; k < n; k++)
            {
                *(*(arrMult+i)+j) += *(*(arr1+i)+k) * *(*(arr2+k)+j); 
            }
        }
    }
    end = clock();
    time_elasped = (((double) (end - start)) / (CLOCKS_PER_SEC)) * 1000000;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < b; j++)
        {
            printf("%f", *(*(arrMult+i)+j));
            printf(" ");
        }
        printf("\r\n");
    }
    printf("Amount of time taken: ");
    printf("%lf", time_elasped);
    printf(" microseconds \r\n");

    return arrMult;
}

int main(void) {
    float **arr1, **arr2, **result;
    int m, n, a, b;
    int userInput = 1;
    float userNumber;

    //Get user input for dimensions
    printf("Type dimensions for first 2-D array: ");

    scanf("%d", &m);
    scanf("%d", &n);
    printf("\r\n");

    printf("Type dimensions for second 2-D array: ");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("\r\n");

    //Creates initial arrays
    arr1 = (float*)malloc(n*sizeof(float));
    arr1 = (float**)malloc(m*sizeof(float*)); 

    arr2 = (float*)malloc(b*sizeof(float));
    arr2 = (float**)malloc(a*sizeof(float*)); 

    //Creates two dimensional arrays
    for (int i = 0; i < m; i++)
    {
        *(arr1+i) = (float*)malloc(n*sizeof(float)); 
    }

    for (int i = 0; i < a; i++)
    {
        *(arr2+i) = (float*)malloc(b*sizeof(float)); 
    }

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
                *(*(arr1+i)+j) = userNumber;
            }
        }
        printf("Enter floats for second matrix: \r\n");
        for (int i = 0; i < a; i++)
        {
            printf("Enter row: ");
            for (int j = 0; j < b; j++)
            {
                scanf("%f", &userNumber);
                *(*(arr2+i)+j) = userNumber;
            }
        }
    }
    else
    {
        //Fills array with random numbers
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                *(*(arr1+i)+j) = ((float)rand()/(float)(RAND_MAX)) * 1000.0;
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                *(*(arr2+i)+j) = ((float)rand()/(float)(RAND_MAX)) * 1000.0;
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
                    result = matrixAddition(m, n, arr1, arr2);
                    for (int i = 0; i < m; i++)
                    {
                        free(*(result+i));
                    }   
                    free(result);
                }
                break;
            case 2:
                if (m != a || n != b) 
                {
                    printf("Unable to do operation due to mismatching dimensions. \r\n");
                }
                else
                {
                    result = matrixSubtraction(m, n, arr1, arr2);
                    for (int i = 0; i < m; i++)
                    {
                        free(*(result+i));
                    }   
                    free(result);
                }
                break;
            case 3:
                if (m != b) 
                {
                    printf("Unable to do operation due to mismatching dimensions. \r\n");
                }
                else
                {
                    result = matrixMultiplication(m, n, b, arr1, arr2);
                    for (int i = 0; i < m; i++)
                    {
                        free(*(result+i));
                    }   
                    free(result);
                }
                break;
            case 4:
                // free the memory
                for (int i = 0; i < m; i++)
                {
                    free(*(arr1+i));
                }   
                for (int i = 0; i < n; i++)
                {
                    free(*(arr2+i));
                }
                free(arr1);
                free(arr2);
                printf("Type dimensions for first 2-D array: ");

                scanf("%d", &m);
                scanf("%d", &n);
                printf("\r\n");

                printf("Type dimensions for second 2-D array: ");
                scanf("%d", &a);
                scanf("%d", &b);
                printf("\r\n");

                arr1 = (float*)malloc(n*sizeof(float));
                arr1 = (float**)malloc(m*sizeof(float*)); 

                arr2 = (float*)malloc(b*sizeof(float));
                arr2 = (float**)malloc(a*sizeof(float*)); 

                for (int i = 0; i < m; i++)
                {
                    *(arr1+i) = (float*)malloc(n*sizeof(float)); 
                }

                for (int i = 0; i < a; i++)
                {
                    *(arr2+i) = (float*)malloc(b*sizeof(float)); 
                }

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
                            *(*(arr1+i)+j) = userNumber;
                        }
                    }
                    printf("Enter floats for second matrix: \r\n");
                    for (int i = 0; i < a; i++)
                    {
                        printf("Enter row: ");
                        for (int j = 0; j < b; j++)
                        {
                            scanf("%f", &userNumber);
                            *(*(arr2+i)+j) = userNumber;
                        }
                    }
                }
                else
                {
                    //Fills array with random numbers
                    for (int i = 0; i < m; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            *(*(arr1+i)+j) = ((float)rand()/(float)(RAND_MAX)) * 1000.0;
                        }
                    }

                    for (int i = 0; i < m; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            *(*(arr2+i)+j) = ((float)rand()/(float)(RAND_MAX)) * 1000.0;
                        }
                    }
                }
                break;
        }
    }

    //Frees arrays from memory
    for (int i = 0; i < m; i++)
    {
        free(*(arr1+i));
    }
    for (int i = 0; i < n; i++)
    {
        free(*(arr2+i));
    }

    printf("Finished");
    return 0;
}