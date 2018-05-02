/*! \brief simple implement of limit mean filter algorithm
 *  \author Shylock Hg
 *  \date 2018-05-02
 *  \email tcath2s@gmail.com
 * */

#include "../sorting/sort_common.h"

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

void filter_limit_mean(array_t array, size_t start, size_t window, int limit){
	if(array.len-1 == start)  //!< end of recursive
		return ;

	//< limit filter
	if(0 < start){  //!< not compare first item
		if(limit < array.value[start]-array.value[start-1])
			array.value[start] = array.value[start-1];
	}

	//< mean filter
	array.value[start] = mean(array.value+start, window);
	
	filter_limit_mean(array, start+1, window, limit);
}

