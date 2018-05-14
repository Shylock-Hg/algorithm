/*! \brief simple implement of interpolation search
 *  \author Shylock Hg
 *  \date 2018-05-08
 *  \email tcath2s@gmail.com
 * */

#include <stddef.h>
#include <assert.h>

#include "../sorting/sort_common.h"

int search_interpolation(array_t array, int x){
	assert(NULL != array.value && 0 != array.len);
	if(NULL == array.value || 0 == array.len)
		return -1;

	//< initialize iterator
	size_t lo = 0, hi = (array.len-1);

	while(lo<hi && x>=array.value[lo] && x<=array.value[hi]){
		//< calculate index of interpolation
		size_t pos = lo + (((double)(hi-lo)/(array.value[hi]-array.value[lo]))*(x-array.value[lo]));
		//< check pos value
		if(array.value[pos] == x)
			return pos;

		//< scroll boundary of sub-array
		if(array.value[pos] < x)
			lo = pos;
		else
			hi = pos;
	}

	return -1;
}

