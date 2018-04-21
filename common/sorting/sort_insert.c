#include <stdio.h>
#include <stddef.h>

#include "sort_common.h"

/*! \brief simple insertion sorting algorithm implement
 *  \param array[i/o] array of unsorted numbers
 *  \param len lenght of numbers to sort
 *  \note stable
 * */
void sort_insert(array_t array){
	size_t j = 0;
	for(size_t i = 1; i < array.len; i++){ //!< i-->[1,len-1]
		j = i;
		for(j=i; j > 0; j--){  //!< j-->[i,1]
			if(array.value[j-1] > array.value[j])
				//! insert smaller to start
				swap_item(array.value+j-1,array.value+j);
		}
	}
}

