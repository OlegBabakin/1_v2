#include "ComplexVector.hpp"
#include "autotest.hpp"

int autotest();

int main(void)
{
    std::vector<Complex_vec *> v;
    Complex_vec::Input("data.txt", v);
    autotest();
    for(size_t i = 0; i < v.size(); ++i)
    {
        (*v[i]).output();
    }

    for(size_t i = 0; i < v.size(); ++i)
    {
        delete v[i];
    }
    return 0;
}


int autotest()
{
    for(int i = 0; i < 100; ++i)
    {
        Complex_vec_0 cvec1;
        Complex_vec_0 cvec2;
        for(int i = 0; i < 10; ++i)
        {
            cvec1.push_back(Complex_num());
            cvec2.push_back(Complex_num());
        }
        if(sum_test(cvec1, cvec2 , cvec1 + cvec2))
        {
            std::cout << "Autotest \"+\" success\n";
        }
        else
        {
            std::cout << "Autotest \"+\" fail\n";
            return -1;
        }

        if(difference_test(cvec1, cvec2 , cvec1 - cvec2))
        {
            std::cout << "Autotest \"-\" success\n";
        }
        else
        {
            std::cout << "Autotest \"-\" fail\n";
            return -1;
        }

        if(scalarprod_test(cvec1, cvec2 , cvec1 * cvec2))
        {
            std::cout << "Autotest \"*\" success\n";
        }
        else
        {
            std::cout << "Autotest \"*\" fail\n";
            return -1;
        }
    }
    return 1;
}