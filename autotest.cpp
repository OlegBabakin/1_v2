#include "ComplexVector.hpp"
#include "autotest.hpp"

int sum_test(const Complex_vec &vect1, const Complex_vec &vect2, const Complex_vec &sum)
{
    size_t len = sum.len;
	for(size_t i = 0; i < len; ++i)
	{
		 
		 if((fabs((vect1[i].get_re() + vect2[i].get_re()) - sum[i].get_re()) >= DBL_EPSILON) 
         || (fabs((vect1[i].get_im() + vect2[i].get_im()) - sum[i].get_im()) >= DBL_EPSILON))
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
		 if((fabs((vect1[i].get_re() - vect2[i].get_re()) - diff[i].get_re()) >= DBL_EPSILON) 
		 	|| (fabs((vect1[i].get_im() - vect2[i].get_im()) - diff[i].get_im()) >= DBL_EPSILON))
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

	if(((test_prod.get_re() - prod.get_re()) >= DBL_EPSILON) || ((test_prod.get_im() - prod.get_im()) >= DBL_EPSILON))
	{
		return -1;
	}
	else
	{
		return 1;
	}
}