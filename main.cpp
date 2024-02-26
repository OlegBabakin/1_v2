#include "ComplexVector.hpp"

int main(void)
{
    Complex_num num0(1, 5);
    Complex_num num1(6, 3);
    Complex_num num2(2, 4);
    // Complex_num num2;
    // num2= num+num;
    // std::cout << "num1 = " << num << "\n";

    Complex_vec_0 v;
    v.vec.push_back(num0);
    v.vec.push_back(num1);
    v.vec.push_back(num2);
    v = v + v;

    // // v.output("pidor0");
    std::cout << v.vec[0] << "\n";
    std::cout << v.vec[1] << "\n";
    std::cout << v.vec[2] << "\n";
    return 0;
}
