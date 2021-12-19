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
    void set_elem(int a, int b, T c) {data[a][b] = c;};
    void plusLine(int idFrom, int idTo, T koeff){for(int i = 0; i < m; i ++){data[idTo][i] += data[idFrom][i] * koeff;}};

    const Matrix operator+(const Matrix&) const;
    const Matrix operator*(T) const;
    const Matrix operator*(const Matrix&) const;

    std::vector<T>& operator[](int i) { return data[i]; };
    const std::vector<T>& operator[](int i) const { return data[i]; };

    template<typename Type> friend std::istream& operator>>(std::istream&, Matrix<Type>&);
    template<typename Type> friend std::ostream& operator<<(std::ostream&, const Matrix<Type>&);

    Matrix tpn ();

    Matrix degQM (int deg)
    {
        std::vector <Matrix> degMatMemory;
        std::vector <int> degTwoMemory;

        deg--;

        degMatMemory.push_back(*this);
        degTwoMemory.push_back(1);

        int tDeg = 2;

        for(int i = 0; i > -1; i ++)
        {
            degMatMemory.push_back(degMatMemory[i] * degMatMemory[i]);
            degTwoMemory.push_back(tDeg);
            tDeg *= 2;
            if(tDeg >= deg)
                break;
        }

    std::cout << "ok";

        while(deg > 0)
        {
            for(int i = degMatMemory.size() - 1; i >= 0; i --)
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

        if(m == 1)
            return data[0][0];

        for(int i = 0; i < m; i ++)
        {
            Matrix mom (m - 1, m - 1);
            for(int j = 1; j < m; j ++)
            {
                for(int k = 0; k < i; k ++)
                    mom.set_elem(j - 1, k, data[j][k]);

                for(int k = i + 1; k < m; k ++)
                    mom.set_elem(j - 1, k - 1, data[j][k]);
            }

            if(i % 2 == 0)
                res += data[0][i] * mom.countDeterminator();
            else
                res -= data[0][i] * mom.countDeterminator();
        }

        return res;
    }

    Matrix <T> gauss();

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
    n = n_;
    m = m_;
    std::vector < std::vector <T> > vect(n, std::vector<T> (m, 0));
    data = vect;


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
std::ostream& operator<<(std::ostream& s_tream, const Matrix<Type>& a)
{
    for(int i = 0; i < a.sizeL(); i ++)
    {
        for(int j = 0; j < a.sizeC(); j ++)
            std::cout << a.data[i][j] << " ";

        std::cout << std::endl;
    }

    return s_tream;
}


template<typename Type>
Matrix<Type> Matrix<Type>::tpn ()
    {

        Matrix res(m, n);



        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
                res.set_elem(i, j, data[j][i]);
        }
        return res;
    }

template<typename Type>
Matrix <Type> Matrix<Type>::gauss()
{
    int nowAt = 0;

    for(int i = 0; i < this->sizeL(); i ++)
    {

        while((*this)[i][nowAt] == 0)
        {
            for(int j = i + 1; j < this->sizeL(); j ++)
            {
                if((*this)[j][nowAt] != 0)
                {
                    this->plusLine(j, i, 1);
                    break;
                }
            }
            if((*this)[i][nowAt] == 0)
                nowAt ++;
        }

        if(nowAt == this->sizeC() - 1)
            break;

        //std::cout << *this;

        //std::cout << i <<nowAt;

        for(int j = i + 1; j < this->sizeL(); j ++)
            this->plusLine(i, j, - (*this)[j][nowAt] / (*this)[i][nowAt]);


    }



    for(int i = this->sizeL() - 1; i >= 0; i --)
    {
        nowAt = 0;

        while((*this)[i][nowAt] == 0)
        {
            nowAt ++;

            if(nowAt == this->sizeC() - 1)
                break;
        }

        if((*this)[i][nowAt] != 0)
        {
            for(int j = i - 1; j >= 0; j --)
                this->plusLine(i, j, - (*this)[j][nowAt] / (*this)[i][nowAt]);
        }

    }

    return *this;

}

#endif
