#ifndef __H_CVECTOR  // recompilation protection
#define __H_CVECTOR

#include "ComplexNumber.hpp"

class Complex_vec
{
    protected:
    std::string filename_; // name for output file 
    bool type_; // type for subclass
    std::vector<Complex_num> vec_; // vector, which contains complex coordinates of vector
    size_t len_; // size of vector

    public:

    // Constructors
    Complex_vec(); // Default constructor
    Complex_vec(const Complex_vec &other); // Copy constructor

    virtual void output(/*const char *file_name*/)=0;
    static int Input(const char *name, std::vector <Complex_vec *> &v);

    Complex_num &operator[](size_t i);
    const Complex_num &operator[](size_t i) const;


    // Destructor
    virtual ~Complex_vec();

    friend int sum_test(const Complex_vec &vect1, const Complex_vec &vect2, const Complex_vec &sum);
	friend int difference_test(const Complex_vec &vect1, const Complex_vec &vect2, const Complex_vec &diff);
	friend int scalarprod_test(const Complex_vec &vect1, const Complex_vec &vect2, const Complex_num &prod);

    // Interface
    const std::string& file_name();
    const bool& type();
    void push_back(const Complex_num& cnum);
    const size_t& size();
    const std::string& file_name() const;
    const bool& type() const;
    // void push_back(const Complex_num& cnum) const;
    const size_t& size() const;
};

// First dirived class
class Complex_vec_0 : public Complex_vec
{
    public:
    Complex_vec_0(); // Default constructor
    Complex_vec_0(const Complex_vec &other); // Copy constructor

    void output(/*const char *file_name*/);
    friend Complex_vec_0 operator+(const Complex_vec &cvec1, const Complex_vec &cvec2);
    friend Complex_vec_0 operator-(const Complex_vec &cvec1, const Complex_vec &cvec2);
    friend Complex_num operator*(const Complex_vec &cvec1, const Complex_vec &cvec2);
    
    Complex_vec_0 &operator=(const Complex_vec &other);

    ~Complex_vec_0();
};

// Second dirived class
class Complex_vec_1 : public Complex_vec
{
    public:
    Complex_vec_1(); // Default constructor
    Complex_vec_1(const Complex_vec &other); // Copy constructor

    void output(/*const char *file_name*/);
    Complex_vec_1 &operator=(const Complex_vec &other);
    
    ~Complex_vec_1();
};

// Inicialisation for friend operators
Complex_vec_0 operator+(const Complex_vec &cvec1, const Complex_vec &cvec2);
Complex_vec_0 operator-(const Complex_vec &cvec1, const Complex_vec &cvec2);
Complex_num operator*(const Complex_vec &cvec1, const Complex_vec &cvec2);

#endif