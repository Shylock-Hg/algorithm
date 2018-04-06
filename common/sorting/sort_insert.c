#include <stdio.h>
#include <stddef.h>

/*! \brief swap two item value in array
 *  \param a pointer to item in array
 *  \parma b pointer to item in array
 * */
static inline void swap_item(int * a, int * b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*! \brief simple insertion sorting algorithm implement
 *  \param array array of unsorted numbers
 *  \param len lenght of numbers to sort
 *  \note stable
 * */
void sort_insert(int array[], size_t len){
	size_t j = 0;
	for(size_t i = 1; i < len; i++){ //!< i-->[1,len-1]
		j = i;
		for(j=i; j > 0; j--){  //!< j-->[i,1]
			if( array[j-1] > array[j])
				//! insert to 
				swap_item(array+j-1,array+j);
		}
	}
}

