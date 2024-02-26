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

Complex_num &Complex_vec::operator[](size_t i)
{
    return vec[i];
}

int Complex_vec::Input(const char *name, std::vector<Complex_vec *> &v)
{
        std::ifstream f(name);
        std::string str;
        while (getline(f, str))
        {
                std::stringstream ss(str); std::istream_iterator<std::string> it;
                it = ss;
                if (it != std::istream_iterator<std::string>())
                {
                        if (fabs(std::stod(*it) - 1) < eps)
                        {
                                Complex_vec_0 *w = new Complex_vec_0;
                                ++it;
                                //cout << "\n|" << *it << "|\n"; ++it;
                                for (; it != std::istream_iterator<std::string>(); ++it)
                                {
                                    double tmp = std::stod(*it);
                                    ++it;
                                    Complex_num num(std::stod(*it),tmp);
                                    (*w).vec.push_back(num);
                                }
                                v.push_back(w);
                        }
                        if (fabs(stod(*it) - 2) < eps)
                        {
                                Complex_vec_1 *w = new Complex_vec_1;
                                ++it;
                                //cout << "\n|" << *it << "|\n"; ++it;
                                for (; it != std::istream_iterator<std::string>(); ++it)
                                {
                                    double tmp = std::stod(*it);
                                    ++it;
                                    if(it == std::istream_iterator<std::string>())
                                    {
                                        break;
                                    }
                                    Complex_num num(std::stod(*it),tmp);
                                    (*w).vec.push_back(num);
                                }
                                v.push_back(w);
                        }
                }
        }
        return 0;

}

Complex_vec::~Complex_vec()
{
}

Complex_vec_0::Complex_vec_0() : Complex_vec()
{}

Complex_vec_0::Complex_vec_0(const std::vector<Complex_num> &other) : Complex_vec(other)
{}

int Complex_vec_0::output(/*const char *file_name*/)
{
    std::cout << "==0==\n";
    return 1;
}

Complex_vec_0 &Complex_vec_0::operator=(const Complex_vec &other)
{
    if (this != &other)
    {
        this->vec.clear();
        for(size_t i=0; i < other.len; i++)
        {
            vec.push_back(other.vec[i]);
        }
    }
    return *this;
}

Complex_vec_0::~Complex_vec_0()
{
}

Complex_vec_1::Complex_vec_1() : Complex_vec()
{}

int Complex_vec_1::output(/*const char *file_name*/)
{
    std::cout << "==1==\n";
    return 1;
}

Complex_vec_1 &Complex_vec_1::operator=(const Complex_vec &other)
{
    if (this != &other)
    {
        this->vec.clear();
        for(size_t i=0; i < other.len; i++)
        {
            vec.push_back(other.vec[i]);
        }
    }
    return *this;
}

Complex_vec_1::~Complex_vec_1()
{
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
