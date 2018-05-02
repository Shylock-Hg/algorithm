/*! \brief simple implement of siding arithmetic average algorithm
 *  \author Shylock Hg
 *  \date 2018-05-01
 *  \email tcath2s@gmail.com
 * */

#include <stddef.h>

#include "../sorting/sort_common.h"

/*  \brief get average of array
 *  \param array array to compute avarage
 *  \param len length of array
 *  \retval avarage value of array
 * */
static int average(int array[], size_t len){
	int averag = 0;
	for(size_t i=0; i<len; i++){
		averag += array[i];
	}

	return averag;
}

void filter_arithmetic_average(array_t array, size_t start, size_t window){
	if(array.len-1 == start)
		return ;

	array.value[start] = average(array.value+start, window);

	filter_arithmetic_average(array, start+1, window);
}

