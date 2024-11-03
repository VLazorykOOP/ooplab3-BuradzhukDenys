#include <iostream>

using namespace std;

class Vector
{
private:
    short* data;
    int size;
    int state;
    static int countObjects;
public:
    Vector() : size(1), state(0)
    {
        data = new short[size];
        data[0] = 0;
        countObjects++;
    }

    Vector(int n) : size(n), state(0)
    {
        if (size <= 0)
        {
            data = nullptr;
            size = 0;
            state = 1;
            cout << "Size of vector must be greater than zero." << endl;
            return;
        }
        data = new short[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
        countObjects++;
    }

    Vector(int n, short value) : size(n), state(0)
    {
        if (size <= 0)
        {
            data = nullptr;
            size = 0;
            state = 1;
            cout << "Size of vector must be greater than zero." << endl;
            return;
        }
        data = new short[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = value;
        }
        countObjects++;
    }

    Vector(const Vector& other) : size(other.size), state(other.state)
    {
        data = new short[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
        countObjects++;
    }

    Vector& operator=(const Vector& other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            state = other.state;
            data = new short[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        else 
        {
            state = 1;
            cout << "ERROR";
        }
        return *this;
    }

    ~Vector()
    {
        delete[] data;
        countObjects--;
    }

    void setElement(int index, short value = 0)
    {
        if (index >= 0 && index < size)
        {
            data[index] = value;
        }
        else state = 2;
    }

    short getElement(int index)
    {
        if (index >= 0 && index < size)
        {
            return data[index];
        }
        else return -404;
    }

    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    Vector operator+(const Vector& other)
    {
        Vector result(size);
        for (int i = 0; i < size; i++)
        {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }

    Vector operator-(const Vector& other)
    {
        Vector result(size);
        for (int i = 0; i < size; i++)
        {
            result.data[i] = this->data[i] - other.data[i];
        }
        return result;
    }

    Vector operator*(unsigned char value)
    {
        Vector result(size);
        for (int i = 0; i < size; i++)
        {
            result.data[i] = this->data[i] * value;
        }
        return result;
    }

    bool operator>(const Vector& other)
    {
        for (int i = 0; i < size; i++)
        {
            if (this->data[i] <= other.data[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Vector& other)
    {
        for (int i = 0; i < size; i++)
        {
            if (this->data[i] != other.data[i])
            {
                return true;
            }
        }
        return false;
    }

    bool operator==(const Vector& other)
    {
        for (int i = 0; i < size; i++)
        {
            if (this->data[i] != other.data[i])
            {
                return false;
            }
        }
        return true;
    }

    int GetState()
    {
        return state;
    }

    static int GetObjects()
    {
        return countObjects;
    }
};

int Vector::countObjects = 0;

int main()
{
    Vector v1(3, 10);
    v1.print();
    Vector v2(5);
    v2.print();
    Vector v3(v1);
    v3.print();
    v3 = v2;
    v3.print();
    v3.setElement(2, 14);
    v3.print();
    v3.setElement(2);
    v3.print();
    cout << "Element with index 10 in vector 1: " << v1.getElement(10) << " " << v1.GetState() << endl;
}