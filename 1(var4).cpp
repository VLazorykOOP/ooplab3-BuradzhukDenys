#include <iostream>
#include <string>

using namespace std;

class Paralelogram
{
private:
    double base;
    double height;
    double lateralSide;
    string color;
public:
    Paralelogram() : base(5), height(5), lateralSide(5), color("black") {}
    Paralelogram(double b) : base(b), height(5), lateralSide(5), color("black") {}
    Paralelogram(double b, double h) : base(b), height(h), lateralSide(5), color("black") {}
    Paralelogram(double b, double h, double l) : base(b), height(h), lateralSide(l), color("black") {}
    Paralelogram(double b, double h, double l, string c) : base(b), height(h), lateralSide(l), color(c) {}

    double Area()
    {
        return base * height;
    }

    double Perymetr()
    {
        return 2 * base + 2 * lateralSide;
    }

    void SetBase(double b)
    {
        if (b < 0 || b > 9999999)
        {
            cout << "Enter a valid base." << endl;
            return;
        }
        this->base = b;
    }

    void SetHeight(double h)
    {
        if (h < 0 || h > 9999999)
        {
            cout << "Enter a valid height." << endl;
            return;
        }
        this->height = h;
    }

    void SetLateralSide(double l)
    {
        if (l < 0 || l > 9999999)
        {
            cout << "Enter a valid lateral side." << endl;
            return;
        }
        this->lateralSide = l;
    }

    void SetColor(string c)
    {
        for (int i = 0; i < c.size(); i++)
        {
            if (!isalpha(c[i]))
            {
                cout << "Enter a valid color." << endl;
                return;
                break;
            }
        }
        this->color = c;
    }

    double GetBase()
    {
        return base;
    }

    double GetHeight()
    {
        return height;
    }

    double GetLateralSide()
    {
        return lateralSide;
    }

    string GetColor()
    {
        return color;
    }

    void Info()
    {
        cout << "Base: " << base << ", Height: " << height << ", Lateral side: " << lateralSide << ", Color: " << color << endl;
        cout << "Area: " << Area() << ", Perymetr: " << Perymetr() << endl;
    }
};

int main()
{
    Paralelogram para1;
    cout << "Paralelogram 1: " << endl;
    para1.GetBase();
    para1.GetHeight();
    para1.GetLateralSide();
    para1.GetColor();
    para1.Info();

    Paralelogram para2(10, 8, 15, "green");
    cout << "Paralelogram 2: " << endl;
    para2.GetBase();
    para2.GetHeight();
    para2.GetLateralSide();
    para2.GetColor();
    para2.Info();
    
    cout << "Paralelogram 1 after changes: " << endl;
    para1.SetBase(20);
    para1.SetHeight(13);
    para1.SetLateralSide(14.5);
    para1.SetColor("Red");
    para1.Info();
}