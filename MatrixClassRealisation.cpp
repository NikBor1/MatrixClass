#include <iostream>
#include "MatrixClass.h"
#include <fstream>

int main()
{
    int optionChooseValue = 0;

    std::cout << "Hello! \nIf you want to summarize two matrix, enter 1.";
    std::cout << "\nIf you want to multiply a matrix and a number, enter 2.";
    std::cout << "\nIf you want to multiply two matrix, enter 3.";
    std::cout << "\nIf you want to transpose a matrix, enter 4.";
    std::cout << "\nIf you want to elevate a square matrix, enter 5.";
    std::cout << "\nIf you want to count a matrix determinant, enter 6.";
    std::cout << "\nIf you want to contact the developer, enter 7.";
    std::cout << "\nIf you want to know more about creating of this code, enter 8.";
    std::cout << "\nIf you want to get better mood, enter 9.\n";
    std::cout << "\nIf you want to get better mood, enter 10:\n";

    std::cin >> optionChooseValue;


    switch (optionChooseValue)
    {
        case 1:
            {
            int lines = 0;
            std::cout << "Enter amount of lines in matrix, please: \n";
            std::cin >> lines;

            int cols = 0;
            std::cout << "Enter amount of columns in matrix, please: \n";
            std::cin >> cols;

            std::cout << "Enter first matrix, please: \n";
            Matrix < double > matrix1 (lines, cols);

            for(int i = 0; i < lines; i ++)
            {
                for(int j = 0; j < cols; j ++)
                    std::cin >> matrix1[i][j];
            }

            std::cout << "Enter second matrix, please: \n";
            Matrix < double > matrix2 (lines, cols);

            for(int i = 0; i < lines; i ++)
            {
                for(int j = 0; j < cols; j ++)
                    std::cin >> matrix2[i][j];
            }

            Matrix < double > result (lines, cols);

            result = matrix1 + matrix2;

            std::cout << "Your result is: \n" << result;

            break;
            }
        case 2:
            {
            int lines = 0;
            std::cout << "Enter amount of lines in matrix, please: \n";
            std::cin >> lines;

            int cols = 0;
            std::cout << "Enter amount of columns in matrix, please: \n";
            std::cin >> cols;


            std::cout << "Enter matrix, please: \n";
            Matrix < double > matrix1 (lines, cols);

            for(int i = 0; i < lines; i ++)
            {
                for(int j = 0; j < cols; j ++)
                    std::cin >> matrix1[i][j];
            }

            int factor = 0;
            std::cout << "Enter multiplier, please: \n";
            std::cin >> factor;

            Matrix < double > result (lines, cols);

            result = matrix1 * factor;

            std::cout << "Your result is: \n" << result;

            break;
            }
        case 3:
            {
            int lines1 = 0;
            std::cout << "Enter amount of lines in first matrix, please: \n";
            std::cin >> lines1;

            int cols1 = 0;
            std::cout << "Enter amount of columns first in matrix, please: \n";
            std::cin >> cols1;


            std::cout << "Enter matrix, please: \n";
            Matrix < double > matrix1 (lines1, cols1);

            for(int i = 0; i < lines1; i ++)
            {
                for(int j = 0; j < cols1; j ++)
                    std::cin >> matrix1[i][j];
            }


            int lines2 = 0;
            std::cout << "Enter amount of lines in first matrix, please: \n";
            std::cin >> lines2;

            int cols2 = 0;
            std::cout << "Enter amount of columns first in matrix, please: \n";
            std::cin >> cols2;


            std::cout << "Enter matrix, please: \n";
            Matrix < double > matrix2 (lines2, cols2);

            for(int i = 0; i < lines2; i ++)
            {
                for(int j = 0; j < cols2; j ++)
                    std::cin >> matrix2[i][j];
            }

            Matrix < double > result (lines1, cols2);

            result = matrix1 * matrix2;

            std::cout << "Your result is: \n" << result;

            break;
            }

            case 4:
            {
            int lines = 0;
            std::cout << "Enter amount of lines in matrix, please: \n";
            std::cin >> lines;

            int cols = 0;
            std::cout << "Enter amount of columns in matrix, please: \n";
            std::cin >> cols;


            std::cout << "Enter matrix, please: \n";
            Matrix < double > matrix1 (lines, cols);

            for(int i = 0; i < lines; i ++)
            {
                for(int j = 0; j < cols; j ++)
                    std::cin >> matrix1[i][j];
            }

            Matrix < double > result (cols, lines);

            result = matrix1.tpn();

            std::cout << "Your result is: \n" << result;

            break;
            }
            case 5:
            {
            int lines = 0;
            std::cout << "Enter amount of lines in matrix, please: \n";
            std::cin >> lines;

            int cols = 0;
            std::cout << "Enter amount of columns in matrix, please: \n";
            std::cin >> cols;


            std::cout << "Enter matrix, please: \n";
            Matrix < double > matrix1 (lines, cols);

            for(int i = 0; i < lines; i ++)
            {
                for(int j = 0; j < cols; j ++)
                    std::cin >> matrix1[i][j];
            }

            int degree = 0;
            std::cout << "Enter degree, please: \n";
            std::cin >> degree;

            Matrix < double > result (lines, cols);

            result = matrix1.degQM(degree);

            std::cout << "Your result is: \n" << result;

            break;
            }
            case 6:
            {
            int lines = 0;
            std::cout << "Enter amount of lines in matrix, please: \n";
            std::cin >> lines;

            int cols = 0;
            std::cout << "Enter amount of columns in matrix, please: \n";
            std::cin >> cols;


            std::cout << "Enter matrix, please: \n";
            Matrix < double > matrix1 (lines, cols);

            for(int i = 0; i < lines; i ++)
            {
                for(int j = 0; j < cols; j ++)
                    std::cin >> matrix1[i][j];
            }

            double result = 0;

            result = matrix1 * factor;

            std::cout << "Your result is: \n" << result;

            break;
            }


    }

    std::cout << "\nThank you for using this program! Estimate it from 1 to 5: \n";
    int mark = 0;

    std::cin >> mark;

    bool errorCatch = false;

    if(mark < 1 || mark > 5)
        errorCatch = true;

    while(errorCatch)
    {
        std::cout << "Sorry, this value is not available. Please, try again: \n";
        std::cin >> mark;

        errorCatch = (mark >= 1 && mark <= 5);
    }

    std::ofstream fout("marksList.txt", std::ios::app);

    fout << mark << std::endl;

    fout.close();


    return 0;
}
