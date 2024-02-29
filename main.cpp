#include "ComplexVector.hpp"

int main(void)
{
    std::vector<Complex_vec *> v;
    Complex_vec::Input("data.txt", v);
//    Complex_num num0(1, 5);
//    Complex_num num1(6, 3);
//    Complex_num num2(2, 4);
//    // Complex_num num2;
//    // num2= num+num;
//    // std::cout << "num1 = " << num << "\n";

//    Complex_vec_0 v;
//    v.vec.push_back(num0);
//    v.vec.push_back(num1);
//    v.vec.push_back(num2);
//    v = v + v;

//    // // v.output("");
    std::cout << (*v[0]).vec[0] << "\n";
    std::cout << (*v[0]).vec[1] << "\n";
    std::cout << (*v[0]).vec[2] << "\n";
    std::cout << (*v[0]).filename_ << "\n";
    (*v[1]) = (*v[1]) + (*v[0]);
    std::cout << "\n";
    std::cout << (*v[1]).vec[0] << "\n";
    std::cout << (*v[1]).vec[1] << "\n";
    std::cout << (*v[1]).vec[2] << "\n";
    for(size_t i = 0; i < v.size(); ++i)
    {
        delete v[i];
    }
    return 0;
}
