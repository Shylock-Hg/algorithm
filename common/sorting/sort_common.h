#ifndef _SORT_COMMON_H_
#define _SORT_COMMON_H_

#ifdef __cplusplus
	extern "C" {
#endif

void swap_item(int * a, int * b);

typedef struct array {
	int * value;
	size_t len;
} array_t;

#ifdef __cplusplus
	}
#endif

#endif
