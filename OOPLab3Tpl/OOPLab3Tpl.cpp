
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class triangle
{
public:
    double a, b, c;
    string color;
    bool flag = true;



    triangle() : a(11.0), b(14.0), c(10.0), color("blue")
    {
    }

    triangle(double a, double b, double c, string color = "blue")
    {
        setside(a, b, c);
        setcolor(color);

    }

    void setside(double a, double b, double c)
    {
        if (a > b + c || b > c + a || c > a + b)
        {
            cout << "error not correct value !" << endl;
            flag = false;

        }


        else
        {
            this->a = a;
            this->b = b;
            this->c = c;
            flag = true;
        }
    }
    double getsideA()const
    {
        return a;
    }
    double getsideB()const
    {
        return b;
    }
    double getsideC()const
    {
        return c;
    }

    void setcolor(string color)
    {
        this->color = color;
    }
    string getcolor()const
    {
        return color;
    }
    double Pir()
    {
        return a + b + c;
    }
    double S()
    {
        double d = Pir() / 2.0;
        return sqrt(d * (d - a) * (d - b) * (d - c));
    }

    void output()
    {
        if (flag == true)
        {

            cout << "color = " << color << endl;
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            cout << "c = " << c << endl;
            cout << "Pir = " << Pir() << endl;
            cout << "S = " << S() << endl;
        }

        else cout << "The triangle is not correct" << endl;
    }
};


void task1()
{
    double in_a, in_b, in_c;
    string in_color;

    triangle t;
    cout << "no correct triangle test: " << endl;
    t.setside(12.0, 1.0, 1.0);
    t.setcolor("red");
    t.output();

    cout << "\n test correct triangle \n" << endl;

    triangle t1;
    t1.setside(9.5, 8.0, 11.0);
    t1.setcolor("green");
    t1.output();

    cout << "\n test getside \n" << endl;
    cout << "a = " << t1.getsideA() << endl;
    cout << "b = " << t1.getsideB() << endl;
    cout << "c = " << t1.getsideC() << endl;

    cout << "\n constructor test \n" << endl;

    triangle t2;
    t2.output();

    cout << "\n constructor 2 test \n" << endl;

    triangle t3;
    t3.setside(12.0, 10.0, 11.0), t3.setcolor("green");
    t3.output();

    triangle t4;
    cout << " test input value:  \n" << endl;
    cout << "input 3 value of size: " << endl;
    cin >> in_a >> in_b >> in_c;
    t4.setside(in_a, in_b, in_c);
    cout << "input a color : " << endl;
    cin >> in_color;
    t4.setcolor(in_color);
    cout << "result : " << endl;
    t4.output();



}



class Vector {
public:
    enum STATE {
        OK,
        BAD_INIT,
        BAD_DIV,
    };

private:
    long* data;
    size_t size;
    STATE state;

    static int objectCount;

public:

    Vector() {
        size = 1;
        data = new(nothrow) long[size];
        if (!data) {
            state = BAD_INIT;
            return;
        }
        data[0] = 0;
        state = OK;
        objectCount++;
    }


    Vector(size_t n) {
        size = n;
        data = new(nothrow) long[size];
        if (!data) {
            state = BAD_INIT;
            return;
        }
        for (size_t i = 0; i < size; i++)
            data[i] = 0;
        state = OK;
        objectCount++;
    }


    Vector(size_t n, long value) {
        size = n;
        data = new(nothrow) long[size];
        if (!data) {
            state = BAD_INIT;
            return;
        }
        for (size_t i = 0; i < size; i++)
            data[i] = value;
        state = OK;
        objectCount++;
    }


    Vector(const Vector& other) {
        size = other.size;
        data = new(nothrow) long[size];
        if (!data) {
            state = BAD_INIT;
            return;
        }
        for (size_t i = 0; i < size; i++)
            data[i] = other.data[i];
        state = other.state;
        objectCount++;
    }


    Vector& operator=(const Vector& other) {
        if (this == &other)
            return *this;

        delete[] data;

        size = other.size;
        data = new(nothrow) long[size];
        if (!data) {
            state = BAD_INIT;
            return *this;
        }

        for (size_t i = 0; i < size; i++)
            data[i] = other.data[i];

        state = other.state;
        return *this;
    }


    ~Vector() {
        delete[] data;
        objectCount--;
    }


    void set(size_t index, long value) {
        if (index >= size) {
            state = BAD_DIV;
            return;
        }
        data[index] = value;
        state = OK;
    }


    long get(size_t index) {
        if (index >= size) {
            state = BAD_DIV;
            return 0;
        }
        state = OK;
        return data[index];
    }


    void print() const {
        for (size_t i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }


    Vector add(const Vector& other) const {
        Vector result(size);
        if (size != other.size) {
            result.state = BAD_DIV;
            return result;
        }
        for (size_t i = 0; i < size; i++)
            result.data[i] = data[i] + other.data[i];
        return result;
    }


    Vector sub(const Vector& other) const {
        Vector result(size);
        if (size != other.size) {
            result.state = BAD_DIV;
            return result;
        }
        for (size_t i = 0; i < size; i++)
            result.data[i] = data[i] - other.data[i];
        return result;
    }


    Vector mul(unsigned int k) const {
        Vector result(size);
        for (size_t i = 0; i < size; i++)
            result.data[i] = data[i] * k;
        return result;
    }


    bool equals(const Vector& other) const {
        if (size != other.size) return false;
        for (size_t i = 0; i < size; i++)
            if (data[i] != other.data[i]) return false;
        return true;
    }

    bool notEquals(const Vector& other) const {
        return !equals(other);
    }

    bool lessThan(const Vector& other) const {
        if (size != other.size) return false;
        for (size_t i = 0; i < size; i++)
            if (data[i] >= other.data[i]) return false;
        return true;
    }


    STATE getState() const {
        return state;
    }


    static int getObjectCount() {
        return objectCount;
    }
};

int Vector::objectCount = 0;
void task2()
{
    cout << "test const 1: 1 element = 0: " << endl;
    Vector v1;
    v1.print();
    cout << "test const 2:  n element = 0: " << endl;
    Vector v2(3);
    v2.print();
    cout << "test const 3:  n element = s: " << endl;
    Vector v3(3, 4);
    v3.print();
    cout << "test const 4:  n element = s: " << endl;
    cout << "test seters " << endl;
    Vector v4(4, 5);
    v4.set(3, 4);
    v4.print();
    cout << "test error code 1:  " << endl;
    v2.get(100);
    if (v2.getState() == Vector::BAD_DIV)
        cout << "error code (1), no element" << endl;
    cout << "test add" << endl;
    Vector v5 = v2.add(Vector(3, 4));
    v5.print();
    cout << "test sub" << endl;
    Vector v6 = v2.sub(Vector(3, 4));
    v6.print();
    cout << "test mul" << endl;
    Vector v7 = v3.mul(4);
    v7.print();
    cout << "test equals" << endl;
    cout << "v2 == v3: " << (v2.equals(v3) ? "true" : "false") << endl;
    cout << "v2 != v3: " << (v2.notEquals(v3) ? "true" : "false") << endl;
    cout << "v2 < v3: " << (v2.lessThan(v3) ? "true" : "false") << endl;
    cout << "test copy" << endl;
    Vector v8 = v4;
    v8.print();

    cout << "num of value =  " << Vector::getObjectCount() << endl;
}

    int main()
    {
        int choice;

        do {
            cout << endl;
            cout << "MENU" << endl;
            cout << "1 - Task 1" << endl;
            cout << "2 - Task 2" << endl;
            
            cout << "0 - Exit" << endl;
            cout << "Choose: ";
            cin >> choice;

            switch (choice)
            {
            case 1: task1(); break;
            case 2: task2(); break;
            
            case 0: cout << "Exit program" << endl; break;
            default: cout << "Wrong choice" << endl;
            }

        } while (choice != 0);

        return 0;
    }
    



