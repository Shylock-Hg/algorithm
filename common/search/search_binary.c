/*! \brief simple implement of binary search algorithm
 *  \author Shylock Hg
 *  \date 2018-04-29
 *  \email tcath2s@gmail.com
 * */
#include <assert.h>

#include <stddef.h>

int search_binary(int array[], size_t lo, size_t hi, int x){
	assert(NULL != array && lo <= hi);
	if(NULL == array || lo > hi)
		return -1;

	if(lo == hi){
		if(array[lo] == x)
			return lo;
		else
			return -1;
	}

	size_t mid = (hi-lo)/2+lo;

	//< aschiing
	if(x <= array[mid]){
		return search_binary(array,lo,mid,x);
	}else{
		return search_binary(array,mid+1,hi,x);
	}
}

