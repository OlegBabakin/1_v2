#include "ComplexVector.hpp"

Complex_vec::Complex_vec()
{
    this->len = 0;
}

Complex_vec::Complex_vec(const Complex_vec &other)
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

const Complex_num &Complex_vec::operator[](size_t i) const 
{
    return vec[i];
}

int Complex_vec::Input(const char *name, std::vector<Complex_vec *> &v)
{
        std::ifstream f(name);
        std::string str;
        while (getline(f, str))
        {
                std::stringstream ss(str); 
                std::istream_iterator<std::string> it;
                std::istream_iterator<std::string> it_min1;
                it = ss;
                it_min1 = it;
                if (it != std::istream_iterator<std::string>())
                {
                        if (fabs(std::stod(*it) - 0) < eps)
                        {
                            ++it;
                            Complex_vec_0 *w = new Complex_vec_0;
                            w->filename_.append(*it);
                            w->filename_.append(".txt");
                            ++it;
                            for (; it_min1 != std::istream_iterator<std::string>(); ++it)
                            {
                                double tmp = std::stod(*it);
                                it_min1 = it;
                                ++it;
                                Complex_num num(std::stod(*it),tmp);
                                (*w).vec.push_back(num);
                            }
                            v.push_back(w);
                        }
                        if (fabs(std::stod(*it) - 1) < eps)
                        {
                            ++it;
                            Complex_vec_1 *w = new Complex_vec_1;
                            w->filename_.append(*it);
                            w->filename_.append(".txt");
                            ++it;
                            for (; it_min1 != std::istream_iterator<std::string>(); ++it)
                            {
                                double tmp = std::stod(*it);
                                it_min1 = it;
                                ++it;
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

size_t Complex_vec::size()
{
    return this->len;
}

size_t Complex_vec::size() const
{
    return this->len;
}


Complex_vec_0::Complex_vec_0() : Complex_vec()
{}

Complex_vec_0::Complex_vec_0(const Complex_vec &other) : Complex_vec(other)
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

Complex_vec_1::Complex_vec_1(const Complex_vec &other) : Complex_vec(other)
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

Complex_vec_0 operator+(const Complex_vec &cvec1, const Complex_vec &cvec2)
{
    std::cout << "-----'+'-----\n";
    size_t len = cvec1.vec.size();
    std::cout << len << "\n";
    Complex_vec_0 cvec;
    for(size_t i = 0; i < len; ++i)
    {
        cvec.vec.push_back(cvec1[i] + cvec2[i]);
    }
    return cvec;
}

Complex_vec_0 operator-(const Complex_vec &cvec1, const Complex_vec &cvec2)
{
    std::cout << "-----'-'-----\n";
    size_t len = cvec1.vec.size();
    std::cout << len << "\n";
    Complex_vec_0 cvec;
    for(size_t i = 0; i < len; ++i)
    {
        cvec.vec.push_back(cvec1[i] - cvec2[i]);
    }
    return cvec;
}
