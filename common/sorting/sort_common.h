#ifndef _SORT_COMMON_H_
#define _SORT_COMMON_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stddef.h>
#include <stdio.h>

#define println_array(array)  do{\
		for(size_t _i = 0; _i < array.len; _i++){\
			printf("%d,",array.value[_i]);\
		}\
		printf("\n");\
	}while(0);

void swap_item(int * a, int * b);

typedef struct array {
	int * value;
	size_t len;
} array_t;

#ifdef __cplusplus
	}
#endif

#endif
