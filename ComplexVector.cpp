#include "ComplexVector.hpp"

Complex_vec::Complex_vec()
{
    this->len_ = 0;
}

Complex_vec::Complex_vec(const Complex_vec &other)
{
    if (this != &other)
    {
        this->len_ = other.len_;
        this->filename_ = other.filename_;
        this->type_ = other.type_;
        this->vec_.clear();
        for(size_t i=0; i < other.len_; i++)
        {
            this->vec_.push_back(other.vec_[i]);
        }
    }
}

Complex_num &Complex_vec::operator[](size_t i)
{
    return this->vec_[i];
}

const Complex_num &Complex_vec::operator[](size_t i) const 
{
    return this->vec_[i];
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
                    if (fabs(std::stod(*it) - 0) < DBL_EPSILON)
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
                                (*w).push_back(tmp);
                            }
                            ++i;
                        }
                        v.push_back(w);
                    }
                    if (fabs(std::stod(*it) - 1) < DBL_EPSILON)
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
                                (*w).push_back(tmp);
                            }
                            ++i;
                        }
                        v.push_back(w);
                    }
            }
        }
        return 0;

}

Complex_vec::~Complex_vec()
{}

const size_t& Complex_vec::size()
{
    return this->len_;
}

const size_t& Complex_vec::size() const
{
    return this->len_;
}

const std::string& Complex_vec::file_name()
{
    return this->filename_;
}

const bool& Complex_vec::type()
{
    return this->type_;
}

void Complex_vec::push_back(const Complex_num& cnum)
{
    this->vec_.push_back(cnum);
    this->len_++;
}

const std::string& Complex_vec::file_name() const
{
    return this->filename_;
}

const bool& Complex_vec::type() const
{
    return this->type_;
}

// void Complex_vec::push_back(const Complex_num& cnum) const
// {
//     this->push_back(cnum);
//     this->len_++;
// }

Complex_vec_0::Complex_vec_0() : Complex_vec()
{}

Complex_vec_0::Complex_vec_0(const Complex_vec &other) : Complex_vec(other)
{}

Complex_vec_0 &Complex_vec_0::operator=(const Complex_vec &other)
{
    if (this != &other)
    {
        this->len_ = other.size();
        this->filename_ = other.file_name();
        this->type_ = other.type();
        this->vec_.clear();
        for(size_t i=0; i < other.size(); i++)
        {
            vec_.push_back(other[i]);
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
        this->vec_.clear();
        for(size_t i=0; i < other.size(); i++)
        {
            vec_.push_back(other[i]);
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
    // if((cvec1.len_ != cvec2.len_) || (cvec1.len_ <= 0))
    // {
    //     std::cout << "Wrong length\n";
    //     cvec.len_ = -1;
    // }
    // else
    // {
    size_t len = cvec1.size();
    cvec.len_ = len;
    cvec.filename_ = cvec1.file_name();
    cvec.type_ = cvec1.type();
    // std::cout << len << "\n";
    for(size_t i = 0; i < len; ++i)
    {
        cvec.push_back(cvec1[i] + cvec2[i]);
    }
    // }
    return cvec;
}

Complex_vec_0 operator-(const Complex_vec &cvec1, const Complex_vec &cvec2)
{
    // std::cout << "-----'-'-----\n";
    Complex_vec_0 cvec;
    // if((cvec1.len_ != cvec2.len_) || (cvec1.len_ <= 0))
    // {
    //     std::cout << "Wrong length\n";
    //     cvec.len_ = -1;
    // }
    // else
    // {
    size_t len = cvec1.size();
    cvec.len_ = len;
    cvec.filename_ = cvec1.file_name();
    cvec.type_ = cvec1.type();
    // std::cout << len << "\n";
    for(size_t i = 0; i < len; ++i)
    {
        cvec.push_back(cvec1[i] - cvec2[i]);
    }
    // }
    return cvec;
}

Complex_num operator*(const Complex_vec &cvec1, const Complex_vec &cvec2)
{
    // std::cout << "-----'*'-----\n";
    Complex_num cnum;
    // if((cvec1.len_ != cvec2.len_) || (cvec1.len_ <= 0))
    // {
    //     std::cout << "Wrong length\n";
    //     cnum.isvalid = false;
    // }
    // else
    // {
    cnum.isvalid = true;
    size_t len = cvec1.size();
    std::cout << len << "\n";
    for(size_t i = 0; i < len; ++i)
    {
        cnum = cnum + (cvec1[i] * cvec2[i]);
        // std::cout << (cvec1[i] * cvec2[i]) << "\n";
    }
    // }
    return cnum;
}

void Complex_vec_0::output()
{
    std::ofstream fout(this->filename_.c_str(), std::ios_base::app);

    fout << "Cvector0: \n";

    for (size_t i = 0; i < this->len_; ++i)
    {
        fout << (*this)[i] << " ";
    }

    fout << "\n";
}

void Complex_vec_1::output()
{
    std::ofstream fout(this->filename_.c_str(), std::ios_base::app);

    fout << "Cvector1:\n";

    for (size_t i = 0; i < this->len_; ++i)
    {
        fout << (*this)[i] << "\n";
    }
        
    fout << "\n";
}