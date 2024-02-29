#ifndef __H_CVECTOR  // recompilation protection
#define __H_CVECTOR

#include "ComplexNumber.hpp"

class Complex_vec
{
    private:
    public:

    std::string filename_; // name for output file 
    bool type; // type for subclass
    std::vector<Complex_num> vec; // vector, which contains complex coordinates of vector
    size_t len; // size of vector

    // Constructors
    Complex_vec(); // Default constructor
    Complex_vec(const Complex_vec &other); // Copy constructor

    virtual int output(/*const char *file_name*/)=0;
    static int Input(const char *name, std::vector <Complex_vec *> &v);
    size_t size();
    size_t size() const;

    Complex_num &operator[](size_t i);
    const Complex_num &operator[](size_t i) const;

    // Destructor
    virtual ~Complex_vec();

};

class Complex_vec_0 : public Complex_vec
{
    public:
    Complex_vec_0(); // Default constructor
    Complex_vec_0(const Complex_vec &other); // Copy constructor

    int output(/*const char *file_name*/);
    friend Complex_vec_0 operator+(Complex_vec &cvec1, Complex_vec &cvec2);
    Complex_vec_0 &operator=(const Complex_vec &other);

    ~Complex_vec_0();
     
};
Complex_vec_0 operator+(const Complex_vec &cvec1, const Complex_vec &cvec2);

class Complex_vec_1 : public Complex_vec
{
    public:
    Complex_vec_1(); // Default constructor
    Complex_vec_1(const Complex_vec &other); // Copy constructor

    int output(/*const char *file_name*/);
    Complex_vec_1 &operator=(const Complex_vec &other);
    //friend Complex_vec_1 operator+(const Complex_vec &cvec1, const Complex_vec &cvec2);
    
    ~Complex_vec_1();
};

#endif
