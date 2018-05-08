#ifndef _SORT_COMMON_H_
#define _SORT_COMMON_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stddef.h>
#include <stdio.h>

/*  \brief print array 
 *  \param array array to print
 * */
#define println_array(array)  do{\
		for(size_t _i = 0; _i < array.len; _i++){\
			printf("%d,",array.value[_i]);\
		}\
		printf("\n");\
	}while(0);

/*  \brief swap item value by pointer
 *  \param a pointer to item a
 *  \param b pointer to item b
 * */
void swap_item(int * a, int * b);

typedef struct array {
	int * value;  //!< array 
	size_t len;  //!< length of array
} array_t;

#ifdef __cplusplus
	}
#endif

#endif

