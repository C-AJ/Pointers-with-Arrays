import java.util.*;

public class javaMatrix {

    public static void createArray(int m, int n, int a, int b, float[][] arr1, float[][]arr2){
        Random rand = new Random();
        Scanner scanner = new Scanner(System.in);
        int userInput;
        float userNumber;
        System.out.println("Would you like to:");
        System.out.println("1. Manually input floats");
        System.out.println("2. Automatically generate floats");

        userInput = scanner.nextInt();

        if (userInput == 1)
        {
            System.out.println("Enter floats for first Matrix");
            for (int i = 0; i < m; i++)
            {
                System.out.print("Enter row: ");
                for (int j = 0; j < n; j++)
                {
                    userNumber = scanner.nextFloat();
                    arr1[i][j] = userNumber;
                }
            }
            System.out.println("Enter floats for second Matrix");
            for (int i = 0; i < a; i++)
            {
                System.out.print("Enter row: ");
                for (int j = 0; j < n; j++)
                {
                    userNumber = scanner.nextFloat();
                    arr2[i][j] = userNumber;
                }
            }
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    arr1[i][j] = rand.nextFloat() * 100f;
                }
            }
            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    arr2[i][j] = rand.nextFloat() * 100f;
                }
            }
        }
    }

    public static void printArray(int m, int n, float[][]arr1)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                System.out.printf("%f", arr1[i][j]);
                System.out.print(" ");
            }
            System.out.println("");
        }
    }

    public static void addMatrix(int m, int n, float[][]arr1, float[][]arr2)
    {
        float[][] arrSum = new float[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arrSum[i][j] = arr1[i][j] + arr2[i][j];
            }
        }
        printArray(m, n, arrSum);
    }

    public static void subMatrix(int m, int n, float[][]arr1, float[][]arr2)
    {
        float[][] arrSub = new float[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arrSub[i][j] = arr1[i][j] - arr2[i][j];
            }
        }
        printArray(m, n, arrSub);
    }

    public static void multMatrix(int m, int n, int b, float[][]arr1, float[][]arr2)
    {
        long start = System.currentTimeMillis();

        float[][] arrMult = new float[m][b];
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

        long end = System.currentTimeMillis();
        System.out.println("Amount of time taken: " + ((end - start) * 1000) + " microseconds");

        printArray(m, b, arrMult);
    }


    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int m, n, a, b;
        int userInput = 0;
        float [][] arr1;
        float [][] arr2;
        //Gets user input
        System.out.print("Type dimensions for first 2-D array: ");
        m = scanner.nextInt();
        n = scanner.nextInt();

        System.out.print("Type dimensions for second 2-D array: ");
        a = scanner.nextInt();
        b = scanner.nextInt();

        arr1 = new float[m][n];
        arr2 = new float[a][b];
        createArray(m, n, a, b, arr1, arr2);
        
        while(userInput != 5)
        {
            System.out.println("Choose an operation:");
            System.out.println("1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Create new Matrices");
            System.out.println("5. Quit the Program");

            userInput = scanner.nextInt();

            switch(userInput)
            {
                case 1:
                    if (m != a || n != b) { System.out.println("Unable to do operation due to mismatching dimensions. \r\n"); }
                    else { addMatrix(m, n, arr1, arr2);}
                    break;
                case 2:
                    if (m != a || n != b) { System.out.println("Unable to do operation due to mismatching dimensions. \r\n"); }
                    else { subMatrix(m, n, arr1, arr2);}
                    break;
                case 3:
                    if (m != b) { System.out.println("Unable to do operation due to mismatching dimensions. \r\n"); }
                    else { multMatrix(m, n, b, arr1, arr2);}
                    break;
                case 4:
                    System.out.print("Type dimensions for first 2-D array: ");
                    m = scanner.nextInt();
                    n = scanner.nextInt();

                    System.out.print("Type dimensions for second 2-D array: ");
                    a = scanner.nextInt();
                    b = scanner.nextInt();

                    arr1 = new float[m][n];
                    arr2 = new float[a][b];
                    createArray(m, n, a, b, arr1, arr2);
                    break;

            }
        }

        scanner.close();
    }
}