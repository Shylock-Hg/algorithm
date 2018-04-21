/*! \brief simple implement of quick sort
 *  \author Shylock Hg
 *  \date 2018-04-21
 *  \email tcath2s@gmail.com
 * */

#include <stddef.h>
#include <stdio.h>

#include "sort_common.h"

static int pivot(array_t array, int lo, int hi){
	int pivot = array.value[hi];
	int i = lo;
	for(int j=lo; j<hi; j++){  //!< j-->[lo,hi)
		if(array.value[j] < pivot){
			//< swap smaller to start
			swap_item(array.value+i,array.value+j);  
			i++;  //!< point to last unswap item
		}
	}
	swap_item(array.value+i,array.value+hi);  //!< swap pivot
	return i;
}

static void sort_quick_origin(array_t array, int lo, int hi){
	if(lo < hi){  //!< divide by pivot until one element
		int p = pivot(array,lo,hi);

		//< nonnegetive index will cause interger overflow
		sort_quick_origin(array,lo,p-1);  
		sort_quick_origin(array,p+1,hi);
	}
}

//  divide array by pivot
void sort_quick(array_t array){
	sort_quick_origin(array,0,array.len-1);
}

