#include "ComplexVector.hpp"
#include "autotest.hpp"

int sum_test(const Complex_vec &vect1, const Complex_vec &vect2, const Complex_vec &sum)
{
    size_t len = sum.len;
	for(size_t i = 0; i < len; ++i)
	{
		 
		 if((fabs((vect1.vec[i].Re_ + vect2.vec[i].Re_) - sum.vec[i].Re_) >= DBL_EPSILON) 
         || (fabs((vect1.vec[i].Im_ + vect2.vec[i].Im_) - sum.vec[i].Im_) >= DBL_EPSILON))
		 {
		 	return -1;
		 }
	}
	return 1;
}

int difference_test(const Complex_vec &vect1, const Complex_vec &vect2, const Complex_vec &diff)
{
	size_t len = diff.len;
	for(size_t i = 0; i < len; ++i)
	{
		 if((fabs((vect1.vec[i].Re_ - vect2.vec[i].Re_) - diff.vec[i].Re_) >= DBL_EPSILON) 
		 	|| (fabs((vect1.vec[i].Im_ - vect2.vec[i].Im_) - diff.vec[i].Im_) >= DBL_EPSILON))
		 {
		 	return -1;
		 }
	}
	return 1;
}

int scalarprod_test(Complex_vec &vect1, const Complex_vec &vect2, const Complex_num &prod)
{
	Complex_num test_prod;
    size_t len = vect1.len;
	for(size_t i = 0; i < len; ++i)
    {
        test_prod = test_prod + (vect1[i] * vect2[i]);
    }

	if(((test_prod.Re_ - prod.Re_) >= DBL_EPSILON) || ((test_prod.Im_ - prod.Im_) >= DBL_EPSILON))
	{
		return -1;
	}
	else
	{
		return 1;
	}
}