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
    Matrix(std::vector <std::vector <T>> vect);
    Matrix(int n_, int m_);
    Matrix();

    int sizeL() const { return n; };
    int sizeC() const { return m; };

    const Matrix operator+(const Matrix&) const;
    const Matrix operator*(T) const;
    const Matrix operator*(const Matrix&) const;

    std::vector<T>& operator[](int i) { return data[i]; };
    const std::vector<T>& operator[](int i) const { return data[i]; };

    template<typename Type> friend std::istream& operator>>(std::istream&, Matrix<Type>&);
    template<typename Type> friend std::ostream& operator<<(std::ostream&, const Matrix<Type>&);

    Matrix tpn ()
    {
        Matrix res (n, m);

        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
                res[i].push_back(data[j][i]);
        }

        return res;
    }

    Matrix degQM (int deg)
    {
        std::vector <Matrix> degMatMemory;
        std::vector <int> degTwoMemory;

        degMatMemory.push_back(*this);
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
                    *this = *this * degMatMemory[i];
                    break;
                }
            }
        }

        return *this;
    }

    T countDeterminator ()
    {
        T res = 0;

        for(int i = 0; i < m; i ++)
        {
            Matrix mom (m - 1, 0);
            for(int j = 1; j < m; j ++)
            {
                for(int k = 0; k < m; k ++)
                {
                    if(k == i)
                        continue;

                    mom[j - 1].push_back(data[j][k]);
                }
            }

            if(i % 2 == 0)
                res += data[1][i] * mom.countDeterminator();
            else
                res += data[1][i] * mom.countDeterminator();
        }

        return res;
    }

    Matrix <T> getReverseMatrix ()
    {
        Matrix <double> result (n, m);

        for(int i = 0; i < n; i ++)
            result[i][i] = 1;

        for(int i = 0; i < n; i ++)
        {
            if(data[i][i] == 0)
            {
                bool detWork = false;

                for(int j = 0; j < n; j ++)
                {
                    if(data[j][i] != 0)
                    {
                        for(int k = i; k < n; k ++)
                        {
                            data[i][k] += data[j][k];
                            result[i][k] += result[j][k];
                        }
                        detWork = true;
                    }
                }
                if(!detWork)
                {
                    Matrix <T> zero (1, 1);
                    return zero;
                }
            }

            for(int j = i; j < n; j ++)
            {
                double koef = 0;
                koef = data[j][i] / data[i][i];

                for(int k = i; k < n; k ++)
                {
                    data[i][k] -= data[j][k] * koef;
                    result[i][k] -= result[j][k] * koef;
                }
            }
        }

        return result;
    }

};

template <typename T>

Matrix<T>::Matrix()
{
    std::vector <std::vector <T>> vect;
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

    data = vect;

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
            res[i].push_back(data[i][j] * a);
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

template<typename Type>
std::ostream& operator<<(std::ostream&, const Matrix<Type>& a)
{
    for(int i = 0; i < a.sizeL(); i ++)
    {
        for(int j = 0; j < a.sizeC(); j ++)
            std::cout << a.data[i][j] << " ";

        std::cout << std::endl;
    }



}

#endif
