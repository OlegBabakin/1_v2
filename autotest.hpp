#ifndef __H_AUTOTEST  // recompilation protection
#define __H_AUTOTEST

#include "ComplexVector.hpp"

int sum_test(const Complex_vec &vect1, const Complex_vec &vect2, const Complex_vec &sum);
int difference_test(const Complex_vec &vect1, const Complex_vec &vect2, const Complex_vec &diff);
int scalarprod_test(Complex_vec &vect1, const Complex_vec &vect2, const Complex_num &prod);
 
#endif 