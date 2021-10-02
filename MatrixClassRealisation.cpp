#include <iostream>
#include "MatrixClass.h"

int main()
{
    int c1, c2, l1, l2;

    std::cout << "Enter amount of lines in a first matrix, please: " << std::endl;
    std::cin >> l1;

    std::cout << "Enter amount of columns in the first matrix, please: " << std::endl;
    std::cin >> c1;

    std::cout << "Enter amount of lines in a second matrix, please: " << std::endl;
    std::cin >> l2;

    std::cout << "Enter amount of columns in the second matrix, please: " << std::endl;
    std::cin >> c2;

    std::cout << "Enter elements of the first matrix, please: " << std::endl;

    Matrix <double> m1 (l1, c1);

    for(int i = 0; i < l1; i ++)
    {
        for(int j = 0; j < c1; j ++)
        {
            double d;
            std::cin >> d;
            m1[i][j] = d;

        }
    }

    std::cout << "Enter elements of the second matrix, please: " << std::endl;

    Matrix <double> m2 (l2, c2);

    for(int i = 0; i < l2; i ++)
    {
        for(int j = 0; j << c2; j ++)
        {
            double d;
            std::cin >> d;
            m2[i][j] = d;
        }
    }

    int menuChoise;

    std::cout << "If you want to get sum of two matrix, enter 1; if you want to get product of two matrix, enter 2; if you want to get product of matrix and number, enter 3; if you want to get transposed matrix, enter 4; if you want to get matrix in natural degree, enter 5; if you want to get better mood, enter 6: ";

    std::cin >> menuChoise;

    switch(menuChoise)
    {
    case 1:

        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:

        break;

    case 6:
        std::cout << "O   O" << std::endl << "  |  " << std::endl <<  "  /  " << std::endl  << "\\____/"<< std::endl << " You are the best, so you'll reach all you purposes! Have a nice day! :)" << std::endl;
        break;




    }





    return 0;
}
