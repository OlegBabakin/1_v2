#include "ComplexNumber.hpp"

class Complex_vec
{
    private:
    public:
    bool type; // type for subclass
    std::vector<Complex_num> vec; // vector, which contains complex coordinates of vector
    size_t len;

    // Constructors
    Complex_vec(); // Default constructor
    Complex_vec(const std::vector<Complex_num> &other); // By vector constructor

    // Destructor
    ~Complex_vec();

    virtual int output(const char *file_name = NULL)=0;

};

class Complex_vec_0 : public Complex_vec
{
    public:
    int output(const char *file_name);
    friend Complex_vec_0 operator+(const Complex_vec &cvec1, const Complex_vec &cvec2);
     
};
Complex_vec_0 operator+(const Complex_vec &cvec1, const Complex_vec &cvec2);
class Complex_vec_1 : public Complex_vec
{
    public:
    int output(const char *file_name);
    //friend Complex_vec_1 operator+(const Complex_vec &cvec1, const Complex_vec &cvec2);
};