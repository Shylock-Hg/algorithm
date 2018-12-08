/*! \brief  simple merge sort algorithm implement
 *  \author Shylock Hg
 *  \date 2018-04-20
 *  \email tcath2s@gmail.com
 * */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "sort_common.h"

static void merge(array_t array, size_t lo, size_t mid, size_t hi){
        int temp[array.len];

	size_t i_lo = lo;
	size_t i_hi = mid;
	size_t i_it = lo;

	//< merge and sort two sub-array to temp
	//< sub[lo,mid), sub[mid,hi) --> partion[lo,hi)
	while(i_lo < mid || i_hi < hi){  
		if(i_lo == mid){
			temp[i_it] = array.value[i_hi];
			i_hi++;
		}else if(i_hi == hi){
			temp[i_it] = array.value[i_lo];
			i_lo++;
		}else if(array.value[i_lo] < array.value[i_hi]){
			temp[i_it] = array.value[i_lo];
			i_lo++;
		}else{
			temp[i_it] = array.value[i_hi];
			i_hi++;
		}
		i_it++;
	}

	//< update origin partion-array[lo,hi)
	for(i_it=lo; i_it<hi; i_it++){  
		array.value[i_it] = temp[i_it];
	}
	//memcpy(array.value+lo,temp+lo,hi-lo); error for bytes order
}

static void sort_merge_origin(array_t array, size_t lo, size_t hi){
	if(lo < hi-1){  //!< divide to one element
		int mid = lo + (hi - lo)/2;  //!< divide array
		sort_merge_origin(array,lo,mid);
		sort_merge_origin(array,mid,hi);

		merge(array,lo,mid,hi);
	}
}

void sort_merge(array_t array){
	assert(NULL != array.value && 0 != array.len);
	if(NULL == array.value || 0 == array.len)
		return ;

	sort_merge_origin(array,0,array.len);
}

