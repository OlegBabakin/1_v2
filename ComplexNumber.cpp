 /*
1. Определить класс CCompexVectorдля работы с векторами комплексных чисел.
Длина вектора задается в конструкторе класса.
В классе должны быть определены необходимые конструкторы, деструктор,операторы присваивания, сложения, вычитания, скалярногоумножения.
Написать функцию и конструктор сохранения переменной данного типа в файл и загрузки из файла.
В отдельном файле должен быть написан тест на данный класс.
*/

#include "ComplexNumber.hpp"

// two number constructor for complex number
Complex_num::Complex_num(double Re, double Im)
{
        this->Re_ = Re;
        this->Im_ = Im;
        this->isvalid = true;
}

// default constructor as a two random numbers constructor for complex number
Complex_num::Complex_num()
{
        this->Re_ = (double)(rand()%N)/1000;
        this->Im_ = (double)(rand()%N)/1000;
        this->isvalid = true;
}

// copy constructor
Complex_num::Complex_num(const Complex_num& cnum)
{
//     std::cout << "Copy constructor\n";
        if(cnum.isvalid)
        {
                this->Re_ = cnum.Re_;
                this->Im_ = cnum.Im_;
                this->isvalid = true;
        }
        else
        {
                this->Re_ = 0.;
                this->Im_ = 0.;
                this->isvalid = true;
        }
}

// move constructor
Complex_num::Complex_num(Complex_num&& cnum)
{
        // std::cout << "Move constructor\n";
        if(cnum.isvalid)
        {
                this->Re_ = cnum.Re_;
                this->Im_ = cnum.Im_;
                this->isvalid = true;
        }
        else
        {
                this->Re_ = 0.;
                this->Im_ = 0.;
                this->isvalid = true;
        }
}

// destructor for complex number
Complex_num::~Complex_num()
{
        // std::cout << "Destructor for complex number\n";
}

// addition operator for complex number
Complex_num Complex_num::operator+(const Complex_num &cnum)
{
        return Complex_num(this->Re_ + cnum.Re_, this->Im_ + cnum.Im_);
}

// const addition operator for complex number
Complex_num Complex_num::operator+(const Complex_num &cnum) const
{
        return Complex_num(this->Re_ + cnum.Re_, this->Im_ + cnum.Im_);
}

// subtraction operator for complex number
Complex_num Complex_num::operator-(const Complex_num &cnum)
{
        return Complex_num(this->Re_ - cnum.Re_, this->Im_ - cnum.Im_);
}

// const subtraction operator for complex number
Complex_num Complex_num::operator-(const Complex_num &cnum) const
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

// const multiplication operator for complex number
Complex_num Complex_num::operator*(const Complex_num &cnum) const
{
        Complex_num tmp;
        tmp = Complex_num(this->Re_*cnum.Re_ + this->Im_*cnum.Im_, this->Re_*cnum.Im_ + this->Im_*cnum.Re_);
        return tmp;
}

// assignment operator for complex number
Complex_num& Complex_num::operator=(Complex_num &&cnum)
{
//     std::cout << "Move operator\n";
    if((cnum.isvalid) && (this != &cnum))
        {
                this->Re_ = cnum.Re_;
                this->Im_ = cnum.Im_;
                this->isvalid = true;
        }
    return *this;
}

// assignment operator for complex number
Complex_num& Complex_num::operator=(const Complex_num &cnum)
{
//     std::cout << "Copy operator\n";
    if((cnum.isvalid) && (this != &cnum))
        {
                this->Re_ = cnum.Re_;
                this->Im_ = cnum.Im_;
                this->isvalid = true;
        }
    return *this;
}

// output operator for complex number
std::ostream& operator << (std::ostream &out, const Complex_num& cnum)
{
    out << cnum.Re_ << " + " << cnum.Im_ << "i";
    return out;
}

const double& Complex_num::get_re()
{
        return this->Re_;
}

const double& Complex_num::get_im()
{
        return this->Im_;
}

const double& Complex_num::get_re() const
{
        return this->Re_;
}

const double& Complex_num::get_im() const
{
        return this->Im_;
}