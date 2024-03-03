#include "ComplexVector.hpp"

Complex_vec::Complex_vec()
{
    this->len = 0;
}

Complex_vec::Complex_vec(const Complex_vec &other)
{
    if(other.len < 0)
    {
        if (this != &other)
        {
            this->vec.clear();
            for(size_t i=0; i < other.len; i++)
            {
                vec.push_back(other.vec[i]);
            }
        }
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
        int i = 0;
        while (getline(f, str))
        {
            i = 0;
            std::stringstream ss(str); 
            std::istream_iterator<std::string> it;
            it = ss;
            if (it != std::istream_iterator<std::string>())
            {
                    if (fabs(std::stod(*it) - 0) < eps)
                    {
                        ++it;
                        Complex_num tmp;
                        Complex_vec_0 *w = new Complex_vec_0;
                        w->filename_.append(*it);
                        w->filename_.append(".txt");
                        ++it;
                        for (; it != std::istream_iterator<std::string>(); ++it)
                        {
                            if(i % 2 == 0)
                            {
                                tmp.Re_ = std::stod(*it);
                            }
                            else
                            {
                                tmp.Im_ = std::stod(*it);
                                (*w).vec.push_back(tmp);
                            }
                            ++i;
                        }
                        (*w).len = (*w).vec.size();
                        v.push_back(w);
                    }
                    if (fabs(std::stod(*it) - 1) < eps)
                    {
                        ++it;
                        Complex_num tmp;
                        Complex_vec_1 *w = new Complex_vec_1;
                        w->filename_.append(*it);
                        w->filename_.append(".txt");
                        ++it;
                        for (; it != std::istream_iterator<std::string>(); ++it)
                        {
                            if(i % 2 == 0)
                            {
                                tmp.Re_ = std::stod(*it);
                            }
                            else
                            {
                                tmp.Im_ = std::stod(*it);
                                (*w).vec.push_back(tmp);
                            }
                            ++i;
                        }
                        (*w).len = (*w).vec.size();
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

Complex_vec_0 &Complex_vec_0::operator=(const Complex_vec &other)
{
    if(other.len < 0)
    {
        if (this != &other)
        {
            this->vec.clear();
            for(size_t i=0; i < other.len; i++)
            {
                vec.push_back(other.vec[i]);
            }
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
    // std::cout << "-----'+'-----\n";
    Complex_vec_0 cvec;
    if((cvec1.len != cvec2.len) || (cvec1.len <= 0))
    {
        std::cout << "Wrong length\n";
        cvec.len = -1;
    }
    else
    {
        size_t len = cvec1.vec.size();
        cvec.len = len;
        cvec.filename_ = cvec1.filename_;
        cvec.type = cvec1.type;
        // std::cout << len << "\n";
        for(size_t i = 0; i < len; ++i)
        {
            cvec.vec.push_back(cvec1[i] + cvec2[i]);
        }
    }
    return cvec;
}

Complex_vec_0 operator-(const Complex_vec &cvec1, const Complex_vec &cvec2)
{
    // std::cout << "-----'-'-----\n";
    Complex_vec_0 cvec;
    if((cvec1.len != cvec2.len) || (cvec1.len <= 0))
    {
        std::cout << "Wrong length\n";
        cvec.len = -1;
    }
    else
    {
        size_t len = cvec1.vec.size();
        cvec.len = len;
        cvec.filename_ = cvec1.filename_;
        cvec.type = cvec1.type;
        // std::cout << len << "\n";
        for(size_t i = 0; i < len; ++i)
        {
            cvec.vec.push_back(cvec1[i] - cvec2[i]);
        }
    }
    return cvec;
}

Complex_num operator*(const Complex_vec &cvec1, const Complex_vec &cvec2)
{
    // std::cout << "-----'*'-----\n";
    Complex_num cnum;
    if((cvec1.len != cvec2.len) || (cvec1.len <= 0))
    {
        std::cout << "Wrong length\n";
        cnum.isvalid = false;
    }
    else
    {
        cnum.isvalid = true;
        size_t len = cvec1.vec.size();
        std::cout << len << "\n";
        for(size_t i = 0; i < len; ++i)
        {
            cnum = cnum + (cvec1[i] * cvec2[i]);
            // std::cout << (cvec1[i] * cvec2[i]) << "\n";
        }
    }
    return cnum;
}

void Complex_vec_0::output()
{
    std::ofstream fout(this->filename_.c_str(), std::ios_base::app);

    fout << "Cvector0: \n";

    for (size_t i = 0; i < this->len; ++i)
    {
        fout << (*this)[i] << " ";
    }

    fout << "\n";
}

void Complex_vec_1::output()
{
    std::ofstream fout(this->filename_.c_str(), std::ios_base::app);

    fout << "Cvector1:\n";

    for (size_t i = 0; i < this->len; ++i)
    {
        fout << (*this)[i] << "\n";
    }
        
    fout << "\n";
}