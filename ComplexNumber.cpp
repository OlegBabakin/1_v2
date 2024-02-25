 /*
1. Определить классCCompexVectorдля работы с векторами ком-плексных чисел.
Длина вектора задается в конструкторе класса.
В классе должны быть определены необходимые конструкторы, деструктор,операторы присваивания, сложения, вычитания, скалярногоумножения.
Написать функцию и конструктор сохранения переменной данноготипа в файл и загрузки из файла.
В отдельном файле должен быть написан тест на данный класс.
*/

#include "ComplexNumber.hpp"

// two number constructor for complex number
Complex_num::Complex_num(double Re, double Im)
{
        Re_ = Re;
        Im_ = Im;
}

// default constructor as a two random numbers constructor for complex number
Complex_num::Complex_num()
{
        this->Re_ = (double)(rand()%N)/1000;
        this->Im_ = (double)(rand()%N)/1000;
}

// copy constructor
Complex_num::Complex_num(const Complex_num& cnum)
{
    std::cout << "Copy constructor\n";
        this->Re_ = cnum.Re_;
        this->Im_ = cnum.Im_;
}

// move constructor
Complex_num::Complex_num(Complex_num&& cnum)
{
        std::cout << "Move constructor\n";
        this->Re_ = cnum.Re_;
        this->Im_ = cnum.Im_;
}

// destructor for complex number
Complex_num::~Complex_num()
{
        std::cout << "Destructor for complex number\n";
}

// addition operator for complex number
Complex_num Complex_num::operator+(const Complex_num &cnum)
{
        return Complex_num(this->Re_ + cnum.Re_, this->Im_ + cnum.Im_);
}

// subtraction operator for complex number
Complex_num Complex_num::operator-(const Complex_num &cnum)
{
        return Complex_num(this->Re_ - cnum.Re_, this->Im_ - cnum.Im_);
}

// multiplication operator for complex number
Complex_num Complex_num::operator*(const Complex_num &cnum)
{
        Complex_num tmp;
        tmp = Complex_num(this->Re_*cnum.Re_ + this->Im_*cnum.Im_, this->Re_*cnum.Im_ + this->Im_*cnum.Re_);
        return tmp;
}

// assignment operator for complex number
Complex_num& Complex_num::operator=(Complex_num &&cnum)
{
    std::cout << "Move operator\n";
    this->Re_ = cnum.Re_;
    this->Im_ = cnum.Im_;
    return *this;
}

// assignment operator for complex number
Complex_num& Complex_num::operator=(const Complex_num &cnum)
{
    std::cout << "Copy operator\n";
    this->Re_ = cnum.Re_;
    this->Im_ = cnum.Im_;
    return *this;
}

// output operator for complex number
std::ostream& operator << (std::ostream &out, const Complex_num& cnum)
{
    out << cnum.Re_ << " + " << cnum.Im_ << "i";
    return out;
}
