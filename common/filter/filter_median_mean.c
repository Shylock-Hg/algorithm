/*! \brief simple implement of sliding median mean filter algorithm
 *  \author Shylock Hg
 *  \date 2018-05-01
 *  \email tcath2s@gmail.com
 * */

#include "../sorting/sort_insert.h"

/*  \brief get mean of array
 *  \param array array to comput mean value
 *  \param len length of array
 *  \retval mean value
 * */
static int mean(int array[], size_t len){
	int mean = 0;
	for(size_t i=0; i<len; i++){
		mean += array[i];
	}

	return mean;
}

void filter_median_mean(array_t array, size_t start, size_t window){
	if(3 > window)  //!< unsupported
		return ;
	if(array.len-1 == start)
		return ;

	array_t temp = {array.value+start, window};
	sort_insert(temp);
	array.value[start] = mean(temp.value+1,temp.len-2);

	filter_median_mean(array, start+1, window);
}

