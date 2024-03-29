/*
1. Определить классCCompexVectorдля работы с векторами ком-плексных чисел.
Длина вектора задается в конструкторе класса.
В классе должны быть определены необходимые конструкторы, деструктор,операторы присваивания, сложения, вычитания, скалярного умножения.
Написать функцию и конструктор сохранения переменной данного типа в файл и загрузки из файла.
В отдельном файле должен быть написан тест на данный класс.
*/

#ifndef __H_COMPLEX  // recompilation protection
#define __H_COMPLEX

#define N 100000 // Number for random number generator
#define M 100000

#include <iostream>
#include <ostream>
#include <time.h>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <stdbool.h>
#include <float.h>

class Complex_vec;

// Complex number class
class Complex_num
{

friend class Complex_vec;
private:
    double Re_;
    double Im_;
public:
    bool isvalid;
    
    // default constructor for complex number
    Complex_num();

    // two number constructor for complex number
    Complex_num(double Re, double Im);

    // desructor for complex number
    ~Complex_num();
    // move constructor
    Complex_num(Complex_num&& cnum);
    Complex_num(const Complex_num& cnum);

    // arithmetic operators for complex number
    Complex_num operator+(const Complex_num &cnum);
    Complex_num operator+(const Complex_num &cnum) const;
    Complex_num& operator=(Complex_num &&cnum);
    Complex_num operator-(const Complex_num &cnum);
    Complex_num operator-(const Complex_num &cnum) const;
    Complex_num operator*(const Complex_num &cnum);
    Complex_num operator*(const Complex_num &cnum) const; 
    Complex_num& operator=(const Complex_num &cnum);

    // output function for complex number
    friend std::ostream& operator << (std::ostream &out, const Complex_num& cnum);

    // interface
    const double& get_re();
    const double& get_im();
    const double& get_re() const;
    const double& get_im() const;
};

#endif
