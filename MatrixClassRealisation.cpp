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

    std::cout << "uuuuhuuu";

    for(int i = 0; i < l1; i ++)
    {
        for(int j = 0; j << c1; j ++)
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

    Matrix <double> res();

    res = m1 + m2;

    std::cout << "m1 + m2" << res << std::endl;





    return 0;
}
