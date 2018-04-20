#include <stddef.h>

#include "sort_common.h"

/*! \brief simple selection sorting algorithm implement
 *  \param array[i/o] array to sort
 *  \param len length of array to sort
 *  \note nonstable
 * */
void sort_select(array_t array){
	size_t i,j;   
	size_t jMin;

	for(i=0; i<array.len-1; i++){  //!< i-->[0,len-2]
		jMin = i;
		for(j=i+1; j<array.len; j++){  //!< j-->[i+1,len-1]
			if(array.value[j] < array.value[jMin]){
				jMin = j;  //!< index of min value in [i+1,len-1]
			}
		}
		if(jMin != i){  //!< swap min value to left
			swap_item(array.value+i, array.value+jMin);
		}
	}
}

