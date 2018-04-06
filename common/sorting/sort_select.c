#include <stddef.h>

#include "sort_common.h"

/*! \brief simple selection sorting algorithm implement
 *  \param array[i/o] array to sort
 *  \param len length of array to sort
 *  \note nonstable
 * */
void sort_select(int array[], size_t len){
	size_t i,j;   
	size_t jMin;

	for(i=0; i<len-1; i++){  //!< i-->[0,len-2]
		jMin = i;
		for(j=i+1; j<len; j++){  //!< j-->[i+1,len-1]
			if(array[j] < array[jMin]){
				jMin = j;  //!< index of min value in [i+1,len-1]
			}
		}
		if(jMin != i){  //!< swap min value to left
			swap_item(array[i], array[jMin]);
		}
	}
}

