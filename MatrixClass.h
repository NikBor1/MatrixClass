#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>
#include <vector>

template <typename T>
class Matrix
{
    int n;
    int m;
    std::vector <std::vector <T>> data;
public:
    Matrix();
    Matrix(std::vector <std::vector <T>> vect);
    Matrix(int n_, int m_);

    int sizeL() const { return n; };
    int sizeC() const { return m; };

    const Matrix operator+(const Matrix&) const;
    const Matrix operator*(T) const;
    const Matrix operator*(const Matrix&) const;

    std::vector<T>& operator[](int i) { return data[i]; };
    const std::vector<T>& operator[](int i) const { return data[i]; };

    template<typename Type> friend std::istream& operator>>(std::istream&, Matrix<Type>&);
    template<typename Type> friend std::ostream& operator<<(std::ostream&, const Matrix<Type>&);

    Matrix tpn (Matrix mat)
    {
        Matrix res (mat.sizeC());

        for(int i = 0; i < mat.sizeC(); i ++)
        {
            for(int j = 0; j < mat.sizeL(); j ++)
                res[i].push_back(mat[j][i]);
        }

        return res;
    }

    Matrix degQM (Matrix mat, int deg)
    {
        std::vector <Matrix> degMatMemory (0);
        std::vector <int> degTwoMemory (0);

        degMatMemory.push_back(mat);
        degTwoMemory.push_back(2);

        int tDeg = 1;

        for(int i = 0; i > -1; i ++)
        {
            degMatMemory.push_back(degMatMemory[i] * degMatMemory[i]);
            degTwoMemory.push_back(deg);
            tDeg *= 2;
            if(tDeg >= n)
                break;
        }

        while(deg > 0)
        {
            for(int i = degMatMemory.size(); i >= 0; i --)
            {
                if(deg >= degTwoMemory[i])
                {
                    deg -= degTwoMemory[i];
                    mat *= degMatMemory[i];
                    break;
                }
            }
        }

        return mat;
    }

};

template <typename T>

Matrix<T>::Matrix()
{
    std::vector <T> vect (0, 0);
    data = vect;
    n = 0;
    m = 0;
}



template <typename T>

Matrix<T>::Matrix(std::vector <std::vector <T>> vect)
{
    data = vect;
    n = vect.size();
    m = vect[0].size();
}

template <typename T>

Matrix<T>::Matrix(int n_, int m_)
{
    std::vector < std::vector <T> > vect(n);

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
            vect[i].push_back(0);
    }

    n = n_;
    m = m_;
}

template <typename T>

const Matrix<T> Matrix<T>::operator+(const Matrix& a) const
{
    std::vector <std::vector <T>> res(n);

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
            res[i].push_back(data[i][j] + a.data[i][j]);
    }

    return Matrix(res);
}

template <typename T>

const Matrix<T> Matrix<T>::operator*(T a) const
{
    std::vector <std::vector <T>> res(n);

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
            res[i][j].push_back(data[i][j] * a);
    }

    return Matrix(res);
}


template <typename T>

const Matrix<T> Matrix<T>::operator*(const Matrix& a) const
{
    std::vector <std::vector <T>> res(n);

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < a.sizeC(); j ++)
        {
            res[i].push_back(0);
            for(int k = 0; k < m; k ++)
                res[i][j] += data[i][k] * a.data[k][j];

        }

    }

    return Matrix(res);
}

#endif
