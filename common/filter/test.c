/*! \brief unit test of filter algorithm
 *  \author Shylock Hg
 *  \date 2018-04-29
 *  \email tcath2s@gmail.com
 * */

#include "filter_limit.h"
#include "filter_median.h"
#include "filter_arithmetic_average.h"
#include "filter_median_mean.h"
#include "filter_limit_mean.h"

int buf[] = {2,5,2,8,-1,3,5,2,6,99,2,5,7,3,5,0,4,3,5,8};

int main(int argc, char * argv[]){
	array_t array = {buf,sizeof(buf)/sizeof(buf[0])};
	//filter_limit(array,3);
	//filter_median(array,0,1);
	//filter_arithmetic_average(array,0,3);
	//filter_median_mean(array,0,5);
	filter_limit_mean(array, 0, 5, 3);
	println_array(array);

	return 0;
}

