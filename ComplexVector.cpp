#include "ComplexVector.hpp"

Complex_vec::Complex_vec()
{
    this->len = 0;
}

Complex_vec::Complex_vec(const std::vector<Complex_num> &other)
{
    this->len = other.size();
    for(unsigned int i = 0; i < other.size(); ++i)
    {
        this->vec.push_back(other[i]);
    }
}

Complex_vec::~Complex_vec()
{
}

Complex_vec_0::Complex_vec_0() : Complex_vec()
{}

Complex_vec_0::Complex_vec_0(const std::vector<Complex_num> &other) : Complex_vec(other)
{}

int Complex_vec_0::output(const char *file_name)
{
    std::cout << "==0==\n";
    return 1;
}

int Complex_vec_1::output(const char *file_name)
{
    std::cout << "==1==\n";
    return 1;
}

Complex_vec_0 operator+(Complex_vec &cvec1, Complex_vec &cvec2)
{
    std::cout << "-----+-----\n";
    size_t len = cvec1.vec.size();
    std::cout << len << "\n";
    std::vector<Complex_num> cvec(len);
	for(size_t i = 0; i < len; ++i)
	{
		cvec[i] = cvec1.vec[i] + cvec2.vec[i];
	}
	return Complex_vec_0(cvec);
}
