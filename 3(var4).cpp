#include <iostream>

using namespace std;

class Matrix
{
private:
    short** data;
    int rows;
    int cols;
    int state;
    static int countObjects;
public:
    Matrix() : rows(4), cols(4), state(0)
    {
        data = new short*[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new short[cols];
        }
        if (!data)
        {
            state = 1;
            cout << "Not enough memory." << endl;
            return;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
        countObjects++;
    }

    Matrix(int n) : rows(n), cols(n), state(0)
    {
        data = new short*[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new short[cols];
        }
        if (!data)
        {
            state = 1;
            cout << "Not enough memory." << endl;
            return;
        }
        if (rows <= 0 || cols <= 0)
        {
            state = -1;
            cout << "Size must be greater than zero." << endl;
            return;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
        countObjects++;
    }

    Matrix(int n, int m, short value) : rows(n), cols(m), state(0)
    {
        data = new short*[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new short[cols];
        }
        if (!data)
        {
            state = 1;
            cout << "Not enough memory." << endl;
            return;
        }
        if (rows <= 0 || cols <= 0)
        {
            state = -1;
            cout << "Size must be greater than zero." << endl;
            return;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = value;
            }
        }
        countObjects++;
    }

    Matrix (const Matrix& other) : rows(other.rows), cols(other.cols), state(other.state)
    {
        data = new short*[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new short[cols];
        }
        if (!data)
        {
            state = 1;
            cout << "Not enough memory." << endl;
            return;
        }
        if (rows <= 0 || cols <= 0)
        {
            state = -1;
            cout << "Size must be greater than zero." << endl;
            return;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
        countObjects++;
    }

    Matrix& operator=(const Matrix& other)
    {
        if (this != &other)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] data[i];
            }
            delete[] data;
            rows = other.rows;
            cols = other.cols;
            state = other.state;

            data = new short*[rows];
            for (int i = 0; i < rows; i++)
            {
                data[i] = new short[cols];
            }
            if (!data)
            {
                state = 1;
                cout << "Not enough memory." << endl;
                return *this;
            }
            if (rows <= 0 || cols <= 0)
            {
                state = -1;
                cout << "Size must be greater than zero." << endl;
                return *this;
            }
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
        countObjects--;
    }

    void setElement(int i, int j, short value = 0)
    {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
        {
            data[i][j] = value;
        }
        else {
            state = 2;
            cout << "Index out of bounds." << endl;
        }
    }

    short getElement(int i, int j)
    {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
        {
            return data[i][j];
        }
        else {
            state = 2;
            cout << "Index out of bounds." << endl;
            return 0;
        }
    }

    void print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrixes must have same size." << endl;
            return *this;
        }
        Matrix result(rows, cols, 0);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrixes must have same size." << endl;
            return *this;
        }
        Matrix result(rows, cols, 0);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = this->data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrixes must have same size." << endl;
            return *this;
        }
        Matrix result(rows, cols, 0);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = this->data[i][j] * other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(short scalar) const
    {
        Matrix result(rows, cols, 0);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = this->data[i][j] * scalar;
            }
        }
        return result;
    }

    bool operator>(const Matrix& other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrixes must have same size." << endl;
            return false;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (this->data[i][j] >= other.data[i][j]) return true;
            }
        }
        return false;
    }

    bool operator<(const Matrix& other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrixes must have same size." << endl;
            return false;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (this->data[i][j] <= other.data[i][j]) return true;
            }
        }
        return false;
    }

    bool operator!=(const Matrix& other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrixes must have same size." << endl;
            return false;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (this->data[i][j] != other.data[i][j]) return true;
            }
        }
        return false;
    }

    int getState() const
    {
        return state;
    }

    static int getCountObjects()
    {
        return countObjects;
    }
};

int Matrix::countObjects = 0;

int main()
{
    Matrix m1(3);
    Matrix m2(3, 3, 2);
    Matrix m3(m2);

    cout << "Matrix m1: " << endl;
    m1.print();
    cout << "Matrix m2: " << endl;
    m2.print();
    cout << "Matrix m3: " << endl;
    m3.print();

    m1 = m3;
    cout << "Matrix m1: " << endl;
    m1.print();
    Matrix m4 = m1 * m2;
    cout << "Matrix m4: " << endl;
    m4.print();

    if (m1 != m3)
    {
        cout << "Matrix 1 not equal Matrix 3." << endl;
    }
    else cout << "Matrix 1 equal Matrix 3." << endl;
}